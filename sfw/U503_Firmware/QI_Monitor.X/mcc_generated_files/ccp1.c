/**
  CCP1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    ccp1.c

  @Summary
    This is the generated driver implementation file for the CCP1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides implementations for driver APIs for CCP1.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F27K40
        Driver Version    :  2.12
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
         MPLAB 	          :  MPLAB X 4.15
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "ccp1.h"

#include "../freq_meas.h"
#include "tmr1.h"

/**
  Section: Capture Module APIs:
*/

void CCP1_Initialize(void)
{
    // Set the CCP1 to the options selected in the User Interface
	
	// MODE 16th rising edge; EN enabled; FMT right_aligned; 
	CCP1CON = 0x87;
	
	// CCP1CTS0 CCP1 pin; 
	CCP1CAP = 0x00;    
	
	// RH 0; 
	CCPR1H = 0x00;    
	
	// RL 0; 
	CCPR1L = 0x00;    

	// Selecting Timer 1
	CCPTMRSbits.C1TSEL = 0x1;
    
    // Clear the CCP1 interrupt flag
    PIR6bits.CCP1IF = 0;

    // Enable the CCP1 interrupt
    PIE6bits.CCP1IE = 1;
    
    POS5_current_edge = pos5_period_rising_1;
    
}

void CCP1_CaptureISR(void)
{
    CCP1_PERIOD_REG_T module;

    // Clear the CCP1 interrupt flag
    PIR6bits.CCP1IF = 0;
    
    // Copy captured value.
    module.ccpr1l = CCPR1L;
    module.ccpr1h = CCPR1H;
    
    // Return 16bit captured value
    CCP1_CallBack(module.ccpr1_16Bit);
}

void CCP1_CallBack(uint16_t capturedValue)
{
    
    switch (POS5_current_edge) {
    
        case pos5_period_rising_1:
            
            // Start Timer 1
            TMR1H = 0;
            TMR1L = 0;
            T1CONbits.ON = 1;
        
            // Next edge will be for calculating period
            POS5_current_edge = pos5_period_rising_2;
            
            break;
            
        case pos5_period_rising_2:
            
            // Stop Timer 1
            T1CONbits.ON = 0;

            // Grab the 16 bit capture value
            freq_meas_results.POS5_Freq_Meas_Raw = capturedValue;
    
            // Clear Timer 1
            TMR1H = 0;
            TMR1L = 0;

            POS5_current_edge = pos5_period_rising_1;
            
            // Convert to frequency
            freqMeasConvert();
            
            break;
        
    }
    
}
/**
 End of File
*/