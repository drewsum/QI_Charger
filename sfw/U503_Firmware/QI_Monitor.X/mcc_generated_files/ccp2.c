/**
  CCP2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    ccp2.c

  @Summary
    This is the generated driver implementation file for the CCP2 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides implementations for driver APIs for CCP2.
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
#include "ccp2.h"

#include "../freq_meas.h"
#include "tmr5.h"

/**
  Section: Capture Module APIs:
*/

void CCP2_Initialize(void)
{
    // Set the CCP2 to the options selected in the User Interface
	
	// MODE 16th rising edge; EN enabled; FMT right_aligned; 
	CCP2CON = 0x87;    
	
	// CCP2CTS0 CCP2 pin; 
	CCP2CAP = 0x00;    
	
	// RH 0; 
	CCPR2H = 0x00;    
	
	// RL 0; 
	CCPR2L = 0x00;    

	// Selecting Timer 5
	CCPTMRSbits.C2TSEL = 0x3;
    
    // Clear the CCP2 interrupt flag
    PIR6bits.CCP2IF = 0;

    // Enable the CCP2 interrupt
    PIE6bits.CCP2IE = 1;
    
    QI_current_edge = qi_period_rising_1;
}

void CCP2_CaptureISR(void)
{
    
    CCP2_PERIOD_REG_T module;

    // Clear the CCP2 interrupt flag
    PIR6bits.CCP2IF = 0;
    
    // Copy captured value.
    module.ccpr2l = CCPR2L;
    module.ccpr2h = CCPR2H;
    
    // Return 16bit captured value
    CCP2_CallBack(module.ccpr2_16Bit);
}

void CCP2_CallBack(uint16_t capturedValue)
{
    // Add your code here
    switch (QI_current_edge) {
    
        case qi_period_rising_1:
            
            // Start Timer 5
            TMR5H = 0;
            TMR5L = 0;
            T5CONbits.ON = 1;
        
            // Next edge will be for calculating period
            QI_current_edge = qi_period_rising_2;
            
            break;
            
        case qi_period_rising_2:
            
            // Stop Timer 5
            T5CONbits.ON = 0;

            // Grab the 16 bit capture value
            freq_meas_results.QI_Freq_Meas_Raw = capturedValue;
    
            // Clear Timer 1
            TMR5H = 0;
            TMR5L = 0;

            QI_current_edge = qi_period_rising_1;
            
            // Convert to frequency
            freqMeasConvert();
            
            break;
        
    }
}
/**
 End of File
*/