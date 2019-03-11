
#include <xc.h>
#include <string.h>
#include <stdio.h>

#include "terminal_control.h"
#include "ring_buffer_LUT.h"
#include "pin_macros.h"
#include "heartbeat_timer.h"
#include "device_IDs.h"
#include "heartbeat_timer.h"
#include "cause_of_reset.h"
#include "adc_postprocessing.h"
#include "error_handling.h"
#include "LM73_I2C.h"
#include "NXQ_charge_state.h"
#include "freq_meas.h"

void ringBufferLUT(char * line) {

// THIS IS WHERE WE DO THE ACTUAL PARSING OF RECEIVED STRING AND
// ACT ON IT

    // Clear Screen, reset
    if((0 == strcmp(line, "Reset"))) {
        
        // Clear the screen
        printf("\033[2J");

        // Move cursor to home
        printf("\033[H");

        // Reset
        RESET();

    }

    // Clear screen, don't reset
    else if((0 == strcmp(line, "Clear"))) {

        // Clear the screen
        printf("\033[2J");

        // Move cursor to home
        printf("\033[H");

    }

    // Identification string
    else if((0 == strcmp(line, "*IDN?"))) {

        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("QI Charger with Digital Monitoring, by Drew Maatman\n\r");
        terminalTextAttributesReset();

    }
    
    // Print microcontroller status
    else if (0 == strcmp(line, "Device Status?")) {
     
        printf("\n\r");
        
        terminalTextAttributes(GREEN, BLACK, BOLD);
        
        printf("Digital Monitoring Microcontroller Status:\n\r");
        
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        
        printf("\n\r");
        
        // Grab and print device ID from flash
        printf("    Device ID retrieved from flash: %s (0x%04X)\n\r",
                getDeviceIDString(getDeviceID()),
                getDeviceID());
        
        printf("\n\r");
        
        printf("    Device silicon revision ID retrieved from flash: %c%03d\n\r",
                ((char) getMajorRevisionID() + 65),getMinorRevisionID());
        
        printf("\n\r");
        
        printf("    The following User IDs have been retrieved from flash:\n\r");

        // Loop through all 8 user ID locations in flash
        for (int userID = 0; userID <= 7; userID++) {
         
            printf("        User ID Word %d (Flash address 0x20000%X): 0x%04X\n\r",
                    userID,
                    (2 * userID),
                    getUserID(userID));
            
        }
        
        printf("\n\r");
        
        printf("    The cause of the most recent device reset was: %s\n\r",
                getCauseOfResetString(reset_cause));
        
        printf("\n\r");
        
        printf("    Device on time since last reset condition is %s\n\r", getStringSecondsAsTime(device_on_time));
        
        printf("\n\r");
        
        printErrorHandlerStatus();
        
        printf("\n\r");
        
    }
    
    // Clear ADC error
    else if((0 == strcmp(line, "Clear ADC Errors"))) {
     
        clearADCErrors();
        
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("ADC Error(s) cleared\n\r");
        terminalTextAttributesReset();
        
    }
    
    
    else if((0 == strcmp(line, "Clear I2C Errors"))) {
    
        clearI2CErrors();
        
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("I2C error(s) cleared\n\r");
        terminalTextAttributesReset();
    
    }
    
    // Report POS3P3 ADC Conversion Result
    else if((0 == strcmp(line, "Clear UART Errors"))) {
    
        clearUARTErrors();
        
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("UART error(s) cleared\n\r");
        terminalTextAttributesReset();
    
    }
    
    else if ((0 == strcmp(line, "Error Status?"))) {
     
        printErrorHandlerStatus();
        
    }
    
    // Print all ADC and temperature measurements, as well as calculations
    else if (0 == strcmp(line, "Current Measurements?")) {
        
        printCurrentMeasurements();
        
    } 
    
    // help, print options
    else if((0 == strcmp(line, "Help"))) {

        printf("\n\r");
        
        terminalTextAttributes(YELLOW, BLACK, BOLD);

        printf("Available Commands:\n\r");
        
        terminalTextAttributes(YELLOW, BLACK, NORMAL);
        
        printf( "    *IDN?: Prints identification string\n\r"
                "    Reset: Executes software reset instruction\n\r"
                "    Clear: Clears the virtual COM port terminal\n\r"
                "    Current Measurements?: Prints instantaneous system level electrical measurements\n\r"
                "    Device Status?: Prints digital monitoring microcontroller device status\n\r"
                "    Error Status? Prints if any system faults have been detected\n\r"
                "    Clear UART Errors: Clears UART error flags\n\r"
                "    Clear I2C Errors: Clears I2C error flags\n\r"
                "    Clear ADC Errors: Clears ADC error flags\n\r"
                "    Help: Lists available commands (this command)\n\r"
                );
        
        printf("\n\rHelp messages and neutral responses appear in yellow\n\r");
        
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("System parameters and affirmative responses appear in green\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("Measurement responses appear in cyan\n\r");
        terminalTextAttributes(RED, BLACK, NORMAL);
        printf("Errors and negative responses appear in red\n\r");
        terminalTextAttributesReset();
        printf("User input appears in white\n\r");

        printf("\n\r");
        
    }
    
    // If we've gotten an unsupported command:
    else {
     
        if (strlen(line) >= 1) {

            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("Unsupported or mis-entered command\n\r");
            terminalTextAttributes(YELLOW, BLACK, NORMAL);
            printf("Commands are case sensitive, backspace is supported, command history is not supported\n\r");
            printf("Call 'Help' for list of supported commands\n\r");
            terminalTextAttributesReset();
        
        }
        
    }
    
}

// This function prints error status
void printErrorHandlerStatus(void) {
    
    if (getADCError()) {

        terminalTextAttributes(RED, BLACK, NORMAL);
        printf("    ADC error(s) detected!\n\r");
        printf("    The following channels caused an ADC error:\n\r");

        if (error_handler.ADC_general_error_flag) {
            printf("        General ADC error\n\r");
        }

        if (error_handler.FVR_ADC_error_flag) {
            printf("        FVR\n\r");
        }

        terminalTextAttributes(YELLOW, BLACK, NORMAL);
        printf("    Call 'Clear ADC Errors' to clear ADC error(s)\n\r");
        terminalTextAttributesReset();

    }

    else {

        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("    No ADC error(s) detected\n\r");
        terminalTextAttributesReset();

    }

    if (getI2CError()) {

        terminalTextAttributes(RED, BLACK, NORMAL);
        printf("    The following I2C Errors were detected:\n\r");

        if (error_handler.I2C_General_error_flag) {
            printf("        I2C General Error\n\r");
        }

        if (error_handler.I2C_Ambient_Temp_Sense_error_flag) {
            printf("        I2C Ambient Temp Sensor Error\n\r");
        }

        if (error_handler.I2C_POS5_Temp_Sense_error_flag) {
            printf("        I2C POS5 Temp Sensor Error\n\r");
        }

        if (error_handler.I2C_QI_Temp_Sense_error_flag) {
            printf("        I2C QI Temp Sensor Error\n\r");
        }

        if (error_handler.I2C_OLED_error_flag) {
            printf("        I2C OLED Display Error\n\r");
        }

        terminalTextAttributes(YELLOW, BLACK, NORMAL);
        printf("    Call 'Clear I2C Errors' to clear communications error(s)\n\r");
        terminalTextAttributesReset();

    }

    else {

        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("    No I2C error(s) detected\n\r");
        terminalTextAttributesReset();

    }

    if (getUARTError()) {

        terminalTextAttributes(RED, BLACK, NORMAL);
        printf("    USB UART Error Detected\n\r");

        terminalTextAttributes(YELLOW, BLACK, NORMAL);
        printf("    Call 'Clear UART Errors' to clear communications error(s)\n\r");
        terminalTextAttributesReset();

    }

    else {

        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("    No UART error(s) detected\n\r");
        terminalTextAttributesReset();

    }
    
}

// This function prints the current measurements message
void printCurrentMeasurements(void) {
 
        printf("\n\r");
        
        terminalTextAttributes(GREEN, BLACK, BOLD);
        printf("System Measurements at time of command call:\n\r");
        
        printf("\n\r");
        
        if (nxq_charge_state == QI_Error) { 
            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("    QI Charger is in Error State\n\r");
        }
        else if (nxq_charge_state == QI_Fully_Charged) {
            terminalTextAttributes(GREEN, BLACK, NORMAL);
            printf("    QI wireless power converter has fully charged phone\n\r");
        }
        else {   
            terminalTextAttributes(GREEN, BLACK, NORMAL);
            printf("    QI wireless power converter is currently %s\n\r", getNXQChargeStateString());
        }
        
        printf("\n\r");
        
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        if (QI_charge_time > 0) printf("    System has been charging a phone for %s\n\r\n\r", getStringSecondsAsTime(QI_charge_time));
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    System Voltages:\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        +12V rail measured as %+.3f Volts\n\r", adc_results.pos12_adc_result);
        printf("        +5V rail measured as %+.3f Volts\n\r", adc_results.pos5_adc_result);
        
        printf("\n\r");
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    System Currents:\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        +12V input current measured as %+.3f Amps\n\r", adc_results.pos12_isns_adc_result);
        printf("        QI converter current measured as %+.3f Amps\n\r", adc_results.qi_isns_adc_result);
        
        printf("\n\r");
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    System Power:\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        Electrical Input Power calculated as %+.3f Watts\n\r", adc_calculations.input_power);
        printf("        Wireless Output Power calculated as %+.3f Watts\n\r", adc_calculations.output_power);
        
        printf("\n\r");
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    System Efficiency calculated as %.3f%%\n\r", adc_calculations.efficiency);
        
        printf("\n\r");
        
        printf("    System Switching Frequencies:\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        if (nxq_charge_state == QI_Idle || nxq_charge_state == QI_Error) printf("        POS5 Converter is in Burst Mode\n\r");
        else printf("        Current +5V Switching Frequency measured as %+.1f MHz\n\r", 2.5);
        if (nxq_charge_state == QI_Idle || nxq_charge_state == QI_Error) printf("        QI Converter is in Burst Mode\n\r");
        else printf("        Current QI Switching Frequency measured as %+.3f kHz\n\r", freq_meas_results.QI_Freq_Meas / 1000.0);
        
        printf("\n\r");
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    System Temperatures:\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        QI Converter Temperature measured as %+.3f C\n\r", LM73_temp_results.QI_temp_result);
        printf("        +5V Converter Temperature measured as %+.3f C\n\r", LM73_temp_results.POS5_temp_result);
        printf("        Ambient Temperature measured as %+.3f C\n\r", LM73_temp_results.Ambient_temp_result);
        
        printf("\n\r");
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Microcontroller Parameters:\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        Microcontroller Die Temperature measured as %+.3f C\n\r", adc_results.die_temp_adc_result);
        printf("        Fixed Voltage Reference Buffer 1 measured as %+.3f Volts, calibrated for +4.096 Volts\n\r", adc_results.fvr_adc_result);
        printf("        AVSS measured as %+.3f Volts\n\r", adc_results.avss_adc_result);
        
        printf("\n\r");
        
        terminalTextAttributesReset();
    
    
}

