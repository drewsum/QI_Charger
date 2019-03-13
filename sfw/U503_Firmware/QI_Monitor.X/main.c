/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F27K40
        Driver Version    :  2.00
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

#include <string.h>
#include <stdio.h>

#include "mcc_generated_files/mcc.h"

#include "pin_macros.h"
#include "terminal_control.h"
#include "heartbeat_timer.h"
#include "ring_buffer_interface.h"
#include "ring_buffer_LUT.h"
#include "cause_of_reset.h"
#include "adc_postprocessing.h"
#include "error_handling.h"
#include "LM73_I2C.h"
#include "cap_touch_int.h"
#include "NXQ_charge_state.h"
#include "oled.h"
#include "freq_meas.h"
#include "double_to_EEPROM.h"

// User IDs
#pragma config IDLOC0 = 0xD
#pragma config IDLOC1 = 0xE
#pragma config IDLOC2 = 0xA
#pragma config IDLOC3 = 0xD
#pragma config IDLOC4 = 0xB
#pragma config IDLOC5 = 0xE
#pragma config IDLOC6 = 0xE
#pragma config IDLOC7 = 0xF

/*
                         Main application
 */
void main(void)
{

    // Determine the cause of the most recent reset, save to enum
    reset_cause = getCauseOfReset();
    
    // Shine RESET LED for a little bit
    __delay_ms(250);
    
    // Initialize the device
    // These are MCC auto-generated instructions
    SYSTEM_Initialize();

    // Assign heartbeat timer handler to TMR0 ISR
    TMR0_SetInterruptHandler(heartbeatTimerHandler);

    // Assign ADC acquisitionTimerHandler to TMR2 ISR
    TMR2_SetInterruptHandler(ADC_acquisitionTimerHandler);
    
    // Call ADC callback upon ADCC interrupt
    ADCC_SetADTIInterruptHandler(ADC_PostProcessingHandler);
    
    // Assign Left Pushbutton Handler to INT1
    INT1_SetInterruptHandler(leftCapTouchHandler);
    
    // Assign Right Pushbutton Handler to INT2
    INT2_SetInterruptHandler(rightCapTouchHandler);
    
    // Assign QI Idle IOC Handler to IOC B2
    IOCBF2_SetInterruptHandler(QIIdleIOCHandler);
    
    // Assign QI Charge IOC Handler to IOC B3
    IOCBF3_SetInterruptHandler(QIChargeIOCHandler);
    
    // Assign idle /charged detection handler to TMR3 ISR
    TMR3_SetInterruptHandler(QIIdleChargedTimerHandler);
    TMR3_StopTimer();
    TMR3_Reload();
    
    // Assign error detection handler to TMR1 ISR
    TMR1_SetInterruptHandler(QIErrorTimerHandler);
    TMR1_StopTimer();
    TMR1_Reload();
    
    
    // Clear timer for QI FSW measurement
    TMR5_StopTimer();
    TMR5_WriteTimer(0);
    
    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();
    
    // Setup virtual COM port terminal
    terminalClearScreen();
    terminalSetCursorHome();

    OLED_Init();
    OLED_Clear();
    
    // Start OLED state machine, force callback
    OLED_Frame = OLED_Boot_Frame_1;
    OLED_updateHandler();
    
    // Setup I2C temp sensors
    LM73TempSensorInitialize();
    
    // print boot message
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("QI Charger with Digital Monitoring\n\r"
            "Boot Complete\n\r");
    
    // Set text color based on cause of reset
    if (    reset_cause != Power_On_Reset) {
    
        terminalTextAttributes(RED, BLACK, NORMAL);
        
    }
    
    else {
    
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        
    }
    
    // Print cause of reset
    printf("Cause of most recent device reset was: %s\n\r", getCauseOfResetString(reset_cause));

    terminalTextAttributes(GREEN, BLACK, NORMAL);    
    // Enable QI power conversion
    QI_STANDBY_PIN = 0;
    printf("QI Wireless Power Conversion Enabled\n\r");

    terminalTextAttributes(YELLOW, BLACK, NORMAL);
    printf("\n\rHelp messages and neutral responses appear in yellow\n\r");
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("System parameters and affirmative responses appear in green\n\r");
    terminalTextAttributes(CYAN, BLACK, NORMAL);
    printf("Measurement responses appear in cyan\n\r");
    terminalTextAttributes(RED, BLACK, NORMAL);
    printf("Errors and negative responses appear in red\n\r");
    terminalTextAttributesReset();
    printf("User input appears in white\n\r");
    terminalTextAttributes(YELLOW, BLACK, NORMAL);
    printf("\n\rCall 'Help' for list of supported commands\n\r");

    // Reset virtual COM port text attributes
    terminalTextAttributesReset();
    
    // See if we're starting idle or fully charged
    if (QI_CHARGE_PIN == 0 && QI_IDLE_PIN == 0) nxq_charge_state = QI_Idle;
    else if (QI_CHARGE_PIN == 1 && QI_IDLE_PIN == 1) nxq_charge_state = QI_Fully_Charged;
    
    // Get starting data
    LM73AcquisitionHandler();
    freqMeasStartCaptures();
    
    // Recover saved variables from NVM
    recoverEEPROMToRAM();
    
    // Endless loop
    while (1) {
        
        // If received terminal data is ready, process it
        if (eusart2RxStringReady) terminal_ringBufferPull();
        
        // If the OLED needs to be updated, update it
        if (OLED_update_flag) OLED_updateHandler();
        
        // If new LM73 data is requested, get it
        if (LM73_start_flag) LM73AcquisitionHandler();
        
        // If we need to start a new freq meas capture, start it
        if (freq_meas_start_flag) freqMeasStartCaptures();
        
        // If we need to print out live data to the terminal, do it.
        if (live_measurement_request_flag) {
         
            live_measurement_request_flag = 0;
            
            // terminalClearScreen();
            terminalSetCursorHome();
            
            terminalTextAttributes(GREEN, BLACK, BOLD);
            printf("Live Measurements:\033[K\n\r\033[K\n\r");
            
            printCurrentMeasurements();
            
            terminalTextAttributes(YELLOW, BLACK, REVERSE);
            printf("Press enter key to exit\033[K\n\r\033[K\n\r");
            terminalTextAttributesReset();
            
        }
        
        // Update error LEDs based on error handler state
        updateErrorLEDs();
        
        // Check for new min and max measurements to save off
        updataMinMaxRAMAliases();
        
        if (nvm_update_flag) writeEEPROMFromRAM();
        
    }
}
/**
 End of File
*/