/*
 * File:   error_handling.c
 * Author: Drew Maatman
 *
 * Created on November 13, 2018, 9:34 AM
 */

#include "error_handling.h"
#include "pin_macros.h"

// This function checks for ADC errors
bool getADCError(void) {
 
    // If an ADC error has been detected
    if (    error_handler.ADC_general_error_flag    ||
            error_handler.FVR_ADC_error_flag        ) {
        
        return true;
        
    }
    
    else {
     
        return false;
        
    }
    
}

// This function checks for UART errors
bool getUARTError(void) {

    return error_handler.USB_UART_COMM_error_flag;
    
}

// This function returns if an I2C error has occurred
bool getI2CError(void) {
    
    // If a UART error has been detected
    if (    error_handler.I2C_General_error_flag       ||
            error_handler.I2C_Ambient_Temp_Sense_error_flag ||
            error_handler.I2C_OLED_error_flag ||
            error_handler.I2C_POS5_Temp_Sense_error_flag ||
            error_handler.I2C_QI_Temp_Sense_error_flag ) {
        
        return true;
        
    }
    
    else {
     
        return false;
        
    }
    
}

// This function updates the error LEDs based on error handler state
void updateErrorLEDs(void) {
 
    // Signal ADC errors
    OTHER_ERROR_LED_PIN = getADCError();
    
    // Signal I2C errors
    I2C_ERROR_LED_PIN = getI2CError();
    
    // Signal UART errors
    USB_ERROR_LED_PIN = getUARTError();
    
}

// This function clears all ADC errors
void clearADCErrors(void) {
    
    // Clear error flags in error handler structure
    error_handler.FVR_ADC_error_flag          = false;
    error_handler.ADC_general_error_flag      = false;
    
    updateErrorLEDs();
    
}

// This function clears all COMM errors
void clearUARTErrors(void) {
    
    // Clear error flags in error handler structure
    error_handler.USB_UART_COMM_error_flag  = false;
    
    updateErrorLEDs();
    
}

// This function clears I2C error flags
void clearI2CErrors(void) {
 
    error_handler.I2C_Ambient_Temp_Sense_error_flag = false;
    error_handler.I2C_General_error_flag = false;
    error_handler.I2C_OLED_error_flag = false;
    error_handler.I2C_POS5_Temp_Sense_error_flag = false;
    error_handler.I2C_QI_Temp_Sense_error_flag = false;
    
    updateErrorLEDs();
    
}



