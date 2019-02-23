/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _ADC_POSTPROCESSING_H
#define	_ADC_POSTPROCESSING_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include "mcc_generated_files/adcc.h"

// The number of POS12_ISNS ADC acquisitions to average
#define POS12_ISNS_AVG_COUNT        16
// A scaling factor for the averaged POS12_ISNS_ADC conversion
#define POS12_ISNS_AVG_SCALING_FACT  1.0

// The number of POS12_ISNS ADC acquisitions to average
#define QI_ISNS_AVG_COUNT        16
// A scaling factor for the averaged POS12_ISNS_ADC conversion
#define QI_ISNS_AVG_SCALING_FACT  1.0


// Global variables
adcc_channel_t next_adc_channel = channel_VSS;                      // The next channel for the ADC to convert

// This structure holds ADC measurement results
struct adc_results_t {
    
    double avss_adc_result;                 // This is the ADC conversion result for measuring AVSS
    double fvr_adc_result;                  // This is the ADC conversion result for the fixed voltage reference
    double pos5_adc_result;                 // This is the ADC conversion result for POS5
    double pos12_adc_result;                // ADC Conversion result for POS12
    double pos12_isns_adc_result;           // ADC conversion result for POS12 current
    double qi_isns_adc_result;              // ADC conversion result for QI converter current
    double die_temp_adc_result;             // ADC conversion result for die temperature
    
} adc_results;

// This structure holds calculations based off of ADC measurement results
struct adc_calculations_t {
    
    float input_power;                     // POS12 * POS12_ISNS
    float output_power;                    // POS5 * QI_ISNS
    float efficiency;                      // output_power / input_power * 100.0
    
} adc_calculations;

// This array holds POS12_ISNS_AVG_COUNT values for averaging POS12_ISNS
double pos12_isns_average_buffer[POS12_ISNS_AVG_COUNT];
// This uint8_t keeps track of which average index we're saving data into for pos12_isns_average
uint8_t pos12_isns_average_index = 0;

// This array holds QI_ISNS_AVG_COUNT values for averaging QI_ISNS
double qi_isns_average_buffer[QI_ISNS_AVG_COUNT];
// This uint8_t keeps track of which average index we're saving data into for qi_isns_average
uint8_t qi_isns_average_index = 0;

// This is a scaling factor that is applied to all ADC conversion results
double adc_result_scaling;

// This is an offset added to the die temperature ADC conversion result
double Temp_ADC_Offset = 0.0;

// This is the ADC postprocessing handler function
// it operates on raw ADC data to convert it to meaningful measurements
void ADC_PostProcessingHandler(void);

// This is the ADC conversion timer handler function
// It sets up to ADC to make conversions at a fixed rate
void ADC_acquisitionTimerHandler(void);

#endif	/* _ADC_POSTPROCESSING_H */

