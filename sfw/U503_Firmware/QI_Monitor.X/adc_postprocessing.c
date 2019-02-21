
#include <xc.h>
#include <float.h>

#include "adc_postprocessing.h"
#include "mcc_generated_files/adcc.h"

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
            
//            if ((adc_results.avss_adc_result > 0.01) || ADCC_HasAccumulatorOverflowed()) {
//             
//                // error_handler.AVSS_ADC_error_flag = true;
//                return;
//                
//            }
            
            next_adc_channel = channel_FVR_buf1;
            
            break;
        
        // FVR Buffer 1 ADC post processing
        case channel_FVR_buf1:
            
            adc_results.fvr_adc_result = (ADCC_GetConversionResult()) * (5.0/1023.0) + adc_results.avss_adc_result;
            adc_result_scaling = 4.096/adc_results.fvr_adc_result;
            
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
            adc_results.pos12_isns_adc_result = (((ADCC_GetFilterValue()) * (adc_results.pos5_adc_result/1023.0)) * 0.501002004 - adc_results.avss_adc_result) * adc_result_scaling;
            
            next_adc_channel = QI_ISNS_ADC;
            break;
            
        case QI_ISNS_ADC:
            adc_results.pos12_isns_adc_result = (((ADCC_GetFilterValue()) * (adc_results.pos5_adc_result/1023.0)) * 1.004016064 - adc_results.avss_adc_result) * adc_result_scaling;
            
            next_adc_channel = channel_Temp;
            break;
            
        case channel_Temp:
            adc_results.die_temp_adc_result = ((0.659 - (adc_results.pos5_adc_result/4.0) * (1 - ADCC_GetConversionResult()/1023.0)) / .00132) - 40.0 + Temp_ADC_Offset;
            
            next_adc_channel = channel_VSS;
            break;
            
        // Default case, there was an error
        // This should not happen
        default:
//            error_handler.ADC_general_error_flag = true;
            break;
        
    }
    
//    if (ADCC_GetCurrentCountofConversions() != 255) {
//        error_handler.ADC_general_error_flag = true;
//    }
//    
//    if (ADCC_HasAccumulatorOverflowed()) {
//        error_handler.ADC_general_error_flag = true;
//    }
    

    
}

// This is the ADC conversion timer handler function
// It sets up to ADC to make conversions at a fixed rate
void ADC_acquisitionTimerHandler(void) {
 
    // Empty sampling cap
    ADCC_DischargeSampleCapacitor();
    
    // Clear filter accumulator, start fresh with new channel
    ADCC_ClearAccumulator();
    
    // Start conversion with next channel to convert
    ADCC_StartConversion(next_adc_channel);
    
}
