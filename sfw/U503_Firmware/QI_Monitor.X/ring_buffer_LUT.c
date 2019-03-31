
#include <xc.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

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
#include "double_to_EEPROM.h"

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
    else if (0 == strcmp(line, "MCU Status?")) {
     
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
        
        printf("    The cause of the most recent microcontroller reset was: %s\n\r",
                getCauseOfResetString(reset_cause));
        
        printf("\n\r");
        
        printf("    MCU on time since last reset condition is %s\n\r", getStringSecondsAsTime(device_on_time));
        
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
         
        printf("\n\r");
        
        terminalTextAttributes(GREEN, BLACK, BOLD);
        printf("Device Measurements at time of command call:\n\r");
        
        printf("\n\r");
        
        printCurrentMeasurements();
        
    } 
    
    else if (0 == strcmp(line, "Enable Live Measurements")) {
     
        live_measurement_enable_flag = 1;
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Enabling live measurements\n\r");
        terminalTextAttributesReset();
        __delay_ms(100);
        terminalClearScreen();
        
    }
    
    else if (0 == strcmp(line, "Max Measurements?")) {
     
        terminalTextAttributes(GREEN, BLACK, BOLD);
        printf("Maximum measurement results at time of command call:\n\r\n\r");
        terminalTextAttributesReset();
        
        printMaximumMeasurements();
        
        printf("\n\r");
        
    }
    
    else if (0 == strcmp(line, "Min Measurements?")) {
     
        terminalTextAttributes(GREEN, BLACK, BOLD);
        printf("Minimum measurement results at time of command call:\n\r\n\r");
        terminalTextAttributesReset();
        
        printMinimumMeasurements();
        
        printf("\n\r");
        
    }
    
    else if (0 == strcmp(line, "Clear Measurement Extremes")) {
     
        terminalTextAttributes(RED, BLACK, NORMAL);
        printf("Clearing measurement minimums and maximums from RAM and EEPROM\n\r");
        terminalTextAttributesReset();
        
        // Set mins and maxs to extreme opposites
        minMaxInitialize();
        
        // Save extremes to EEPROM
        forceEEPROMSave();
        
        // Next loop around while(1), save the "real" new minimums and maximums since
        // what's in NVM is the extremes, which will never actually be minimums and maximums
        nvm_update_flag = true;
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
                "    Max Measurements?: Prints the maximum recorded system level electrical measurements\n\r"
                "    Min Measurements?: Prints the minimum recorded system level electrical measurements\n\r"
                "    Clear Measurement Extremes: clears measurement min and max values, and resets values in EEPROM\n\r"
                "    Enable Live Measurements: Prints a continuous stream of measurement data to the terminal\n\r"
                "    MCU Status?: Prints digital monitoring microcontroller device status\n\r"
                "    Error Status? Prints if any system faults have been detected\n\r"
                "    Clear UART Errors: Clears UART error flags\n\r"
                "    Clear I2C Errors: Clears I2C error flags\n\r"
                "    Clear ADC Errors: Clears ADC error flags\n\r"
                "    Help: Lists available commands (this command)\n\r"
                );
        
        printf("\n\rHelp messages and neutral responses appear in yellow\n\r");
        
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Device parameters and affirmative responses appear in green\n\r");
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
        
        else if (live_measurement_enable_flag) {
        
            live_measurement_enable_flag = 0;
            terminalClearScreen();
            terminalSetCursorHome();
            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("Live measurement feed disabled\n\r");
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
    
        if (nxq_charge_state == QI_Error) { 
            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("    QI wireless power converter is in error State\033[K\n\r\033[K\n\r");
        }
        else if (nxq_charge_state == QI_Fully_Charged) {
            terminalTextAttributes(GREEN, BLACK, NORMAL);
            printf("    QI wireless power converter has fully charged load\033[K\n\r\033[K\n\r");
        }
        else {   
            terminalTextAttributes(GREEN, BLACK, NORMAL);
            printf("    QI wireless power converter is currently %s\033[K\n\r\033[K\n\r", getNXQChargeStateString());
        }
        
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        if (QI_charge_time > 0) printf("    Device has been charging a load for %s\033[K\n\r\033[K\n\r", getStringSecondsAsTime(QI_charge_time));
        else printf("    No load present, searching...\033[K\n\r\n\r");
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Device Voltages:\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        Input voltage measured as %+.3f Volts\033[K\n\r", adc_results.pos12_adc_result);
        printf("        +5V rail measured as %+.3f Volts\033[K\n\r\033[K\n\r", adc_results.pos5_adc_result);
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Device Currents:\033[K\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        Input current measured as %+.3f Amps\033[K\n\r", adc_results.pos12_isns_adc_result);
        printf("        QI converter current measured as %+.3f Amps\033[K\n\r\033[K\n\r", adc_results.qi_isns_adc_result);
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Device Power:\033[K\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        Electrical Input Power calculated as %+.3f Watts\033[K\n\r", adc_calculations.input_power);
        if (QI_charge_time > 0) printf("        Wireless Output Power calculated as %+.3f Watts\033[K\n\r\033[K\n\r", adc_calculations.output_power);
        else printf("        No load present, no effective wireless output power\033[K\n\r\n\r");
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        if (QI_charge_time > 0) printf("    Device Efficiency calculated as %.3f %%\033[K\n\r\033[K\n\r", adc_calculations.efficiency);
        else printf("    No load present, system efficiency is 0.0 %%\033[K\n\r\n\r");
        
        if (QI_charge_time > 0) printf("    Estimated energy consumed by the load while charging: %sJoules\033[K\n\r\033[K\n\r", floatToEngineeringFormat(adc_calculations.output_energy));
        else printf("    No load present, no energy consumed\033[K\n\r\n\r");
        
        if (QI_charge_time > 0) printf("    Estimated charge consumed by the load while charging: %sCoulombs\033[K\n\r\033[K\n\r", floatToEngineeringFormat(adc_calculations.output_charge));
        else printf("    No load present, no charge consumed\033[K\n\r\n\r");
        
        printf("    Device Switching Frequencies:\033[K\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        if (QI_charge_time == 0) printf("        POS5 Converter is in Burst Mode\033[K\n\r");
        else printf("        Current Buck Converter Switching Frequency measured as %+.1f MHz\033[K\n\r", 2.5);
        if (QI_charge_time == 0) printf("        QI Converter is in Burst Mode\033[K\n\r\033[K\n\r");
        else printf("        Current QI Switching Frequency measured as %+.3f kHz\033[K\n\r\033[K\n\r", freq_meas_results.QI_Freq_Meas / 1000.0);
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Device Temperatures:\033[K\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        QI Converter Temperature measured as %+.3f C\033[K\n\r", LM73_temp_results.QI_temp_result);
        printf("        Buck Converter Temperature measured as %+.3f C\033[K\n\r", LM73_temp_results.POS5_temp_result);
        printf("        Ambient Temperature measured as %+.3f C\033[K\n\r\033[K\n\r", LM73_temp_results.Ambient_temp_result);
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Microcontroller Parameters:\033[K\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        Microcontroller Die Temperature estimated as %+.3f C\033[K\n\r", adc_results.die_temp_adc_result);
        printf("        Internal Fixed Voltage Reference (FVR) Buffer 1 measured as %+.3f Volts, calibrated for +4.096 Volts\033[K\n\r", adc_results.fvr_adc_result);
        printf("        AVSS (Analog Ground Reference) measured as %+.3f Volts\033[K\n\r\033[K\n\r", adc_results.avss_adc_result);
        
        terminalTextAttributesReset();
    
    
}

// This function prints the maximum measurements message
void printMaximumMeasurements(void) {
    
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Maximum Device Voltages:\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        Maximum Input voltage measurement was %+.3f Volts\033[K\n\r", eeprom_ram_aliases.POS12_Max_Result);
        printf("        Maximum +5V rail measurement was %+.3f Volts\033[K\n\r\033[K\n\r", eeprom_ram_aliases.POS5_Max_Result);
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Maximum Device Currents:\033[K\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        Maximum Input current measurement was %+.3f Amps\033[K\n\r", eeprom_ram_aliases.POS12_Current_Max_Result);
        printf("        Maximum QI converter current measurement was %+.3f Amps\033[K\n\r\033[K\n\r", eeprom_ram_aliases.QI_Current_Max_Result);
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Maximum Device Power:\033[K\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        Maximum Electrical Input Power calculation was %+.3f Watts\033[K\n\r", eeprom_ram_aliases.Input_Power_Max_Result);
        printf("        Maximum Wireless Output Power calculation was %+.3f Watts\033[K\n\r\033[K\n\r", eeprom_ram_aliases.Output_Power_Max_Result);
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Maximum Device Efficiency calculation was %.3f%%\033[K\n\r\033[K\n\r", eeprom_ram_aliases.Efficiency_Max_Result);
        
        printf("    Maximum Estimated Energy consumed by the load while charging: %sJoules\033[K\n\r\033[K\n\r", floatToEngineeringFormat(eeprom_ram_aliases.Load_Energy_Max_Result));
        printf("    Maximum Estimated Charge consumed by the load while charging: %sCoulombs\033[K\n\r\033[K\n\r", floatToEngineeringFormat(eeprom_ram_aliases.Load_Charge_Max_Result));
        
        printf("    Maximum Device Switching Frequencies:\033[K\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("       Maximum QI Switching Frequency measurement was %+.3f kHz\033[K\n\r\033[K\n\r", eeprom_ram_aliases.QI_FSW_Max_Result / 1000.0);
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Maximum Device Temperatures:\033[K\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        Maximum QI Converter Temperature measurement was %+.3f C\033[K\n\r", eeprom_ram_aliases.QI_Temp_Max_Result);
        printf("        Maximum Buck Converter Temperature measurement was %+.3f C\033[K\n\r", eeprom_ram_aliases.POS5_Temp_Max_Result);
        printf("        Maximum Ambient Temperature measurement was %+.3f C\033[K\n\r\033[K\n\r", eeprom_ram_aliases.Ambient_Temp_Max_Result);
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Maximum Microcontroller Parameters:\033[K\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        Maximum Microcontroller Die Temperature measurement was %+.3f C\033[K\n\r", eeprom_ram_aliases.Die_Temp_Max_Result);
        
        terminalTextAttributesReset();
    
}

// This function prints the minimum  easurements message
void printMinimumMeasurements(void) {
    
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Minimum Device Voltages:\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        Minimum Input voltage measurement was %+.3f Volts\033[K\n\r", eeprom_ram_aliases.POS12_Min_Result);
        printf("        Minimum +5V rail measurement was %+.3f Volts\033[K\n\r\033[K\n\r", eeprom_ram_aliases.POS5_Min_Result);
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Minimum Device Currents:\033[K\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        Minimum Input current measurement was %+.3f Amps\033[K\n\r", eeprom_ram_aliases.POS12_Current_Min_Result);
        printf("        Minimum QI converter current measurement was %+.3f Amps\033[K\n\r\033[K\n\r", eeprom_ram_aliases.QI_Current_Min_Result);
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Minimum Device Power:\033[K\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        Minimum Electrical Input Power calculation was %+.3f Watts\033[K\n\r", eeprom_ram_aliases.Input_Power_Min_Result);
        printf("        Minimum Wireless Output Power calculation was %+.3f Watts\033[K\n\r\033[K\n\r", eeprom_ram_aliases.Output_Power_Min_Result);
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Minimum Device Efficiency calculation was %.3f%%\033[K\n\r\033[K\n\r", eeprom_ram_aliases.Efficiency_Min_Result);
        
        printf("    Minimum Device Switching Frequencies:\033[K\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("       Minimum QI Switching Frequency measurement was %+.3f kHz\033[K\n\r\033[K\n\r", eeprom_ram_aliases.QI_FSW_Min_Result / 1000.0);
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Minimum Device Temperatures:\033[K\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        Minimum QI Converter Temperature measurement was %+.3f C\033[K\n\r", eeprom_ram_aliases.QI_Temp_Min_Result);
        printf("        Minimum Buck Converter Temperature measurement was %+.3f C\033[K\n\r", eeprom_ram_aliases.POS5_Temp_Min_Result);
        printf("        Minimum Ambient Temperature measurement was %+.3f C\033[K\n\r\033[K\n\r", eeprom_ram_aliases.Ambient_Temp_Min_Result);
        
        terminalTextAttributes(CYAN, BLACK, BOLD);
        printf("    Minimum Microcontroller Parameters:\033[K\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("        Minimum Microcontroller Die Temperature measurement was %+.3f C\033[K\n\r", eeprom_ram_aliases.Die_Temp_Min_Result);
        
        terminalTextAttributesReset();
 
}

// This function returns a string representing a floating point number in
// engineering format. It will append the unit prefix on the end after
// three digits past the decimal point
char * floatToEngineeringFormat(float input_value) {

    static unsigned char result[30];
    unsigned char *res = result;

    double mag = abs(input_value);
    
    if (mag >=  1000000000.0) sprintf(res, "%.3f G", input_value * 0.000000001);
    else if (mag >=  1000000.0) sprintf(res, "%.3f M", input_value * 0.000001);
    else if (mag >=  1000.0) sprintf(res, "%.3f k", input_value * 0.001);
    else if (mag >=  1.0) sprintf(res, "%.3f ", input_value);
    else if (mag >=  0.001) sprintf(res, "%.3f m", input_value * 1000.0);
    else if (mag >=  0.000001) sprintf(res, "%.3f u", input_value * 1000000.0);
    else if (mag >=  0.000000001) sprintf(res, "%.3f n", input_value * 1000000000.0);
    else if (input_value == 0.0) sprintf(res, "0.0 ");
    
    return result;
    
}

