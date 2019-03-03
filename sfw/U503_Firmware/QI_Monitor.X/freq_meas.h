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
#ifndef _FREQ_MEAS_H
#define	_FREQ_MEAS_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include "mcc_generated_files/ccp1.h"

// Structure to hold computed results
struct {
    
    float POS5_Freq_Meas;
    uint16_t POS5_Freq_Meas_Raw;
    float QI_Freq_Meas;
    uint16_t QI_Freq_Meas_Raw;
    
} freq_meas_results;

// This enum keeps track of which edge we're measuring for CCP1
enum pos5_edge_type{
    pos5_period_rising_1 = 0,
    pos5_period_rising_2 = 1
} POS5_current_edge;


// This enum keeps track of which edge we're measuring for CCP2
enum qi_edge_type{
    qi_period_rising_1 = 0,
    qi_period_rising_2 = 1
} QI_current_edge;


// This flag requests a frequency measurement capture
bool freq_meas_start_flag;

// This function enables captures for both POS5 FSW and QI FSW
void freqMeasStartCaptures(void);

// This function converts the raw CCP capture value to a floating point number representing frequency
void freqMeasConvert(void);


#endif	/* _FREQ_MEAS_H */

