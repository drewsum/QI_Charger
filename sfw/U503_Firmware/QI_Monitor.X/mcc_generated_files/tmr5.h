/**
  TMR5 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr5.h

  @Summary
    This is the generated header file for the TMR5 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for TMR5.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F27K40
        Driver Version    :  2.11
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

#ifndef TMR5_H
#define TMR5_H

/**
  Section: Included Files
*/

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif


/**
  Section: TMR5 APIs
*/

/**
  @Summary
    Initializes the TMR5

  @Description
    This routine initializes the TMR5.
    This routine must be called before any other TMR5 routine is called.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example
    <code>
    main()
    {
        // Initialize TMR5 module
        TMR5_Initialize();

        // Do something else...
    }
    </code>
*/
void TMR5_Initialize(void);

/**
  @Summary
    This function starts the TMR5.

  @Description
    This function starts the TMR5 operation.
    This function must be called after the initialization of TMR5.

  @Preconditions
    Initialize  the TMR5 before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    // Initialize TMR5 module

    // Start TMR5
    TMR5_StartTimer();

    // Do something else...
    </code>
*/
void TMR5_StartTimer(void);

/**
  @Summary
    This function stops the TMR5.

  @Description
    This function stops the TMR5 operation.
    This function must be called after the start of TMR5.

  @Preconditions
    Initialize  the TMR5 before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    // Initialize TMR5 module

    // Start TMR5
    TMR5_StartTimer();

    // Do something else...

    // Stop TMR5;
    TMR5_StopTimer();
    </code>
*/
void TMR5_StopTimer(void);

/**
  @Summary
    Reads the TMR5 register.

  @Description
    This function reads the TMR5 register value and return it.

  @Preconditions
    Initialize  the TMR5 before calling this function.

  @Param
    None

  @Returns
    This function returns the current value of TMR5 register.

  @Example
    <code>
    // Initialize TMR5 module

    // Start TMR5
    TMR5_StartTimer();

    // Read the current value of TMR5
    if(0 == TMR5_ReadTimer())
    {
        // Do something else...

        // Reload the TMR value
        TMR5_Reload();
    }
    </code>
*/
uint16_t TMR5_ReadTimer(void);

/**
  @Summary
    Writes the TMR5 register.

  @Description
    This function writes the TMR5 register.
    This function must be called after the initialization of TMR5.

  @Preconditions
    Initialize  the TMR5 before calling this function.

  @Param
    timerVal - Value to write into TMR5 register.

  @Returns
    None

  @Example
    <code>
    #define PERIOD 0x80
    #define ZERO   0x00

    while(1)
    {
        // Read the TMR5 register
        if(ZERO == TMR5_ReadTimer())
        {
            // Do something else...

            // Write the TMR5 register
            TMR5_WriteTimer(PERIOD);
        }

        // Do something else...
    }
    </code>
*/
void TMR5_WriteTimer(uint16_t timerVal);

/**
  @Summary
    Reload the TMR5 register.

  @Description
    This function reloads the TMR5 register.
    This function must be called to write initial value into TMR5 register.

  @Preconditions
    Initialize  the TMR5 before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    while(1)
    {
        if(TMR5IF)
        {
            // Do something else...

            // clear the TMR5 interrupt flag
            TMR5IF = 0;

            // Reload the initial value of TMR5
            TMR5_Reload();
        }
    }
    </code>
*/
void TMR5_Reload(void);

/**
  @Summary
    Starts the single pulse acquisition in TMR5 gate operation.

  @Description
    This function starts the single pulse acquisition in TMR5 gate operation.
    This function must be used when the TMR5 gate is enabled.

  @Preconditions
    Initialize  the TMR5 with gate enable before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    uint16_t xVal;
    uint16_t yVal;

    // enable TMR5 singlepulse mode
    TMR5_StartSinglePulseAcquistion();

    // check TMR5 gate status
    if(TMR5_CheckGateValueStatus()== 0)
        xVal = TMR5_ReadTimer();

    // wait untill gate interrupt occured
    while(TMR5GIF == 0)
    {
    }

    yVal = TMR5_ReadTimer();
    </code>
*/
void TMR5_StartSinglePulseAcquisition(void);

/**
  @Summary
    Check the current state of Timer1 gate.

  @Description
    This function reads the TMR5 gate value and return it.
    This function must be used when the TMR5 gate is enabled.

  @Preconditions
    Initialize  the TMR5 with gate enable before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    uint16_t xVal;
    uint16_t yVal;

    // enable TMR5 singlepulse mode
    TMR5_StartSinglePulseAcquistion();

    // check TMR5 gate status
    if(TMR5_CheckGateValueStatus()== 0)
        xVal = TMR5_ReadTimer();

    // wait untill gate interrupt occured
    while(TMR5IF == 0)
    {
    }

    yVal = TMR5_ReadTimer();
    </code>
*/
uint8_t TMR5_CheckGateValueStatus(void);

/**
  @Summary
    Boolean routine to poll or to check for the overflow flag on the fly.

  @Description
    This function is called to check for the timer overflow flag.
    This function is usd in timer polling method.

  @Preconditions
    Initialize  the TMR5 module before calling this routine.

  @Param
    None

  @Returns
    true - timer overflow has occured.
    false - timer overflow has not occured.

  @Example
    <code>
    while(1)
    {
        // check the overflow flag
        if(TMR5_HasOverflowOccured())
        {
            // Do something else...

            // clear the TMR5 interrupt flag
            TMR5IF = 0;

            // Reload the TMR5 value
            TMR5_Reload();
        }
    }
    </code>
*/
bool TMR5_HasOverflowOccured(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // TMR5_H
/**
 End of File
*/
