
#include <xc.h>
#include <float.h>
#include <math.h>

#include "adc_postprocessing.h"
#include "mcc_generated_files/adcc.h"
#include "mcc_generated_files/tmr2.h"
#include "error_handling.h"

// This is the ADC postprocessing handler function
// it operates on raw ADC data to convert it to meaningful measurements
void ADC_PostProcessingHandler(void) {
    
    // If the ADC is still going, shut it off
    ADCC_StopConversion();
    
    // Current channel is what's left in ADC channel select register
    adcc_channel_t current_adc_channel = ADPCH;
    
    // Determine post processing based on current channel
    switch (current_adc_channel) {
        
        case channel_VSS:
            
            adc_results.avss_adc_result = (ADCC_GetConversionResult()) * (5.0/1023.0);
                        
            next_adc_channel = channel_FVR_buf1;
            
            break;
        
        // FVR Buffer 1 ADC post processing
        case channel_FVR_buf1:
            
            adc_results.fvr_adc_result = (ADCC_GetConversionResult()) * (5.0/1023.0) + adc_results.avss_adc_result;
            adc_result_scaling = 4.096/adc_results.fvr_adc_result;
            
            if (adc_results.fvr_adc_result > 5.0 || adc_results.fvr_adc_result < 3.9) {
             
                error_handler.FVR_ADC_error_flag = true;
                
            }
            
            next_adc_channel = POS5_ADC;
            
            break;
            
        case POS5_ADC:
            adc_results.pos5_adc_result = (((ADCC_GetFilterValue()) * (5.0/1023.0)) * 2.0 - adc_results.avss_adc_result) * adc_result_scaling;
            
            next_adc_channel = POS12_ADC;
            break;
            
        case POS12_ADC:
            adc_results.pos12_adc_result = (((ADCC_GetFilterValue()) * (adc_results.pos5_adc_result/1023.0)) * 2.96078 - adc_results.avss_adc_result) * adc_result_scaling;
            
            next_adc_channel = POS12_ISNS_ADC;
            break;
            
        case POS12_ISNS_ADC:
            
            pos12_isns_average_buffer[pos12_isns_average_index] = (((ADCC_GetFilterValue()) * (adc_results.pos5_adc_result/1023.0)) * 0.501002004 - adc_results.avss_adc_result) * adc_result_scaling;
            pos12_isns_average_index++;
            
            // If we've gathered set number of samples for averaging, reset count
            if (pos12_isns_average_index == POS12_ISNS_AVG_COUNT) {
                pos12_isns_average_index = 0;
                // Compute average of last few POS12_ISNS conversions, and scale
                adc_results.pos12_isns_adc_result = 0.0;
                for (uint8_t i = 0; i < POS12_ISNS_AVG_COUNT; i++) {
                    adc_results.pos12_isns_adc_result += fabs(pos12_isns_average_buffer[i]);
                }
                adc_results.pos12_isns_adc_result /= (float) POS12_ISNS_AVG_COUNT;
            }
            
            next_adc_channel = QI_ISNS_ADC;
            break;
            
        case QI_ISNS_ADC:

            qi_isns_average_buffer[qi_isns_average_index] = (((ADCC_GetFilterValue()) * (adc_results.pos5_adc_result/1023.0)) * 1.004016064 - adc_results.avss_adc_result) * adc_result_scaling;
            qi_isns_average_index++;
            
            // If we've gathered set number of samples for averaging, reset count
            if (qi_isns_average_index == QI_ISNS_AVG_COUNT) {
                qi_isns_average_index = 0;
                // Compute average of last few QI_ISNS conversions, and scale
                adc_results.qi_isns_adc_result = 0.0;
                for (uint8_t i = 0; i < QI_ISNS_AVG_COUNT; i++) {
                    adc_results.qi_isns_adc_result += fabs(qi_isns_average_buffer[i]);
                }
                adc_results.qi_isns_adc_result /= (float) QI_ISNS_AVG_COUNT;
            }
            
            next_adc_channel = channel_Temp;
            break;
            
        case channel_Temp:
            adc_results.die_temp_adc_result = ((0.659 - (5.0 / 4.0) * (1.0 - ADCC_GetFilterValue()/1023.0)) / .00132) - 40.0 + temp_adc_offset;
            
            next_adc_channel = channel_VSS;
            break;
            
        // Default case, there was an error
        // This should not happen
        default:
            error_handler.ADC_general_error_flag = true;
            break;
        
    }
    
    if (ADCC_GetCurrentCountofConversions() != 255) {
        error_handler.ADC_general_error_flag = true;
    }
    
    if (ADCC_HasAccumulatorOverflowed()) {
        error_handler.ADC_general_error_flag = true;
    }
    
    // Run post-processing calculations
    adc_calculations.input_power = adc_results.pos12_adc_result * adc_results.pos12_isns_adc_result;
    adc_calculations.output_power = adc_results.pos5_adc_result * adc_results.qi_isns_adc_result;
    adc_calculations.efficiency = (adc_calculations.output_power / adc_calculations.input_power) * 100.0;
    
    // Re-start Acq timer
    TMR2_StartTimer();
    
}

// This is the ADC conversion timer handler function
// It sets up to ADC to make conversions at a fixed rate
void ADC_acquisitionTimerHandler(void) {
 
    // Stop Acq timer and clear to be safe, give time for floating point math when
    // ADC conversion is done
    TMR2_StopTimer();
    TMR2 = 0;
    
    // Empty sampling cap
    ADCC_DischargeSampleCapacitor();
    
    // Clear filter accumulator, start fresh with new channel
    ADCC_ClearAccumulator();
    
    // Start conversion with next channel to convert
    ADCC_StartConversion(next_adc_channel);
    
}
