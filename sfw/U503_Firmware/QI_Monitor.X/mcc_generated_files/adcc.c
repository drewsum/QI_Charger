/**
  ADCC Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    adcc.c

  @Summary
    This is the generated driver implementation file for the ADCC driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides implementations for driver APIs for ADCC.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F27K40
        Driver Version    :  2.13
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB             :  MPLAB X 4.15
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
#include "adcc.h"

/**
  Section: ADCC Module Variables
*/
void (*ADCC_ADTI_InterruptHandler)(void);

/**
  Section: ADCC Module APIs
*/

void ADCC_Initialize(void)
{
    // set the ADCC to the options selected in the User Interface
    // ADLTHL 0; 
    ADLTHL = 0x00;
    // ADLTHH 0; 
    ADLTHH = 0x00;
    // ADUTHL 0; 
    ADUTHL = 0x00;
    // ADUTHH 0; 
    ADUTHH = 0x00;
    // ADSTPTL 0; 
    ADSTPTL = 0x00;
    // ADSTPTH 0; 
    ADSTPTH = 0x00;
    // ADRPT 255; 
    ADRPT = 0xFF;
    // ADPCH ANA0; 
    ADPCH = 0x00;
    // ADCAP Additional uC disabled; 
    ADCAP = 0x00;
    // ADDSEN disabled; ADGPOL digital_low; ADIPEN disabled; ADPPOL VSS; 
    ADCON1 = 0x00;
    // ADCRS 0; ADMD Low_pass_filter_mode; ADACLR disabled; ADPSIS ADRES; 
    ADCON2 = 0x04;
    // ADCALC Filtered value vs setpoint; ADTMD enabled; ADSOI ADGO is cleared; 
    ADCON3 = 0x5F;
    // ADAOV ACC or ADERR not Overflowed; 
    ADSTAT = 0x00;
    // ADNREF external; ADPREF external; 
    ADREF = 0x12;
    // ADACT disabled; 
    ADACT = 0x00;
    // ADCS FOSC/64; 
    ADCLK = 0x1F;
    // ADGO stop; ADFM right; ADON enabled; ADCONT enabled; ADCS FOSC/ADCLK; 
    ADCON0 = 0xC4;
    // ADACQ 255; 
    ADACQ = 0xFF;
    

    // Clear the ADC Threshold interrupt flag
    PIR1bits.ADTIF = 0;
    // Enabling ADCC threshold interrupt.
    PIE1bits.ADTIE = 1;

    ADCC_SetADTIInterruptHandler(ADCC_DefaultInterruptHandler);
}

void ADCC_StartConversion(adcc_channel_t channel)
{
    // select the A/D channel
    ADPCH = channel;      
  
    // Turn on the ADC module
    ADCON0bits.ADON = 1;

    // Start the conversion
    ADCON0bits.ADGO = 1;
}

bool ADCC_IsConversionDone()
{
    // Start the conversion
    return ((unsigned char)(!ADCON0bits.ADGO));
}

adc_result_t ADCC_GetConversionResult(void)
{
    // Return the result
    return ((adc_result_t)((ADRESH << 8) + ADRESL));
}

adc_result_t ADCC_GetSingleConversion(adcc_channel_t channel)
{
    // select the A/D channel
    ADPCH = channel;  

    // Turn on the ADC module
    ADCON0bits.ADON = 1;
	
    //Disable the continuous mode.
    ADCON0bits.ADCONT = 0;    

    // Start the conversion
    ADCON0bits.ADGO = 1;


    // Wait for the conversion to finish
    while (ADCON0bits.ADGO)
    {
        CLRWDT();
    }
    
    
    // Conversion finished, return the result
    return ((adc_result_t)((ADRESH << 8) + ADRESL));
}

void ADCC_StopConversion(void)
{
    //Reset the ADGO bit.
    ADCON0bits.ADGO = 0;
}

void ADCC_SetStopOnInterrupt(void)
{
    //Set the ADSOI bit.
    ADCON3bits.ADSOI = 1;
}

void ADCC_DischargeSampleCapacitor(void)
{
    //Set the ADC channel to AVss.
    ADPCH = 0x3c;   
}

void ADCC_LoadAcquisitionRegister(uint8_t acquisitionValue)
{
    //Load the ADACQ register.
    ADACQ = acquisitionValue;   
}

void ADCC_SetPrechargeTime(uint8_t prechargeTime)
{
    //Load the ADPRE register.
    ADPRE = prechargeTime;  
}

void ADCC_SetRepeatCount(uint8_t repeatCount)
{
    //Load the ADRPT register.
    ADRPT = repeatCount;   
}

uint8_t ADCC_GetCurrentCountofConversions(void)
{
    //Return the contents of ADCNT register
    return ADCNT;
}

void ADCC_ClearAccumulator(void)
{
    //Reset the ADCON2bits.ADACLR bit.
    ADCON2bits.ADACLR = 1;
}

uint16_t ADCC_GetAccumulatorValue(void)
{
    //Return the contents of ADACCH and ADACCL registers
    return ((uint16_t)((ADACCH << 8) + ADACCL));
}

bool ADCC_HasAccumulatorOverflowed(void)
{
    //Return the status of ADSTATbits.ADAOV
    return ADSTATbits.ADAOV;
}

uint16_t ADCC_GetFilterValue(void)
{
    //Return the contents of ADFLTRH and ADFLTRL registers
    return ((uint16_t)((ADFLTRH << 8) + ADFLTRL));
}

uint16_t ADCC_GetPreviousResult(void)
{
    //Return the contents of ADPREVH and ADPREVL registers
    return ((uint16_t)((ADPREVH << 8) + ADPREVL));
}

void ADCC_DefineSetPoint(uint16_t setPoint)
{
    //Sets the ADSTPTH and ADSTPTL registers
    ADSTPTH = setPoint >> 8;
    ADSTPTL = setPoint;
}

void ADCC_SetUpperThreshold(uint16_t upperThreshold)
{
    //Sets the ADUTHH and ADUTHL registers
    ADUTHH = upperThreshold >> 8;
    ADUTHL = upperThreshold;
}

void ADCC_SetLowerThreshold(uint16_t lowerThreshold)
{
    //Sets the ADLTHH and ADLTHL registers
    ADLTHH = lowerThreshold >> 8;
    ADLTHL = lowerThreshold;
}

uint16_t ADCC_GetErrorCalculation(void)
{
	//Return the contents of ADERRH and ADERRL registers
	return ((uint16_t)((ADERRH << 8) + ADERRL));
}

void ADCC_EnableDoubleSampling(void)
{
    //Sets the ADCON1bits.ADDSEN
    ADCON1bits.ADDSEN = 1;
}

void ADCC_EnableContinuousConversion(void)
{
    //Sets the ADCON0bits.ADCONT
    ADCON0bits.ADCONT = 1;
}

void ADCC_DisableContinuousConversion(void)
{
    //Resets the ADCON0bits.ADCONT
    ADCON0bits.ADCONT = 0;
}

bool ADCC_HasErrorCrossedUpperThreshold(void)
{
    //Returns the value of ADSTATbits.ADUTHR bit.
    return ADSTATbits.ADUTHR;
}

bool ADCC_HasErrorCrossedLowerThreshold(void)
{
    //Returns the value of ADSTATbits.ADLTHR bit.
    return ADSTATbits.ADLTHR;
}

uint8_t ADCC_GetConversionStageStatus(void)
{
    //Returns the contents of ADSTATbits.ADSTAT field.
    return ADSTATbits.ADSTAT;
}


void ADCC_ThresholdISR(void)
{
    // Clear the ADCC Threshold interrupt flag
    PIR1bits.ADTIF = 0;

    if (ADCC_ADTI_InterruptHandler)
        ADCC_ADTI_InterruptHandler();
}

void ADCC_SetADTIInterruptHandler(void (* InterruptHandler)(void)){
    ADCC_ADTI_InterruptHandler = InterruptHandler;
}
void ADCC_DefaultInterruptHandler(void){
    // add your ADCC interrupt custom code
    // or set custom function using ADCC_SetADIInterruptHandler() or ADCC_SetADTIInterruptHandler()
}
/**
 End of File
*/
