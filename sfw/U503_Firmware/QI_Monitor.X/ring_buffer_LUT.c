
#include <xc.h>
#include <string.h>

#include "terminal_control.h"
#include "ring_buffer_LUT.h"
#include "pin_macros.h"
#include "heartbeat_timer.h"
#include "device_IDs.h"
#include "heartbeat_timer.h"
#include "cause_of_reset.h"

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
    
    // print Device ID
    else if((0 == strcmp(line, "Cause of Reset?"))) {

        terminalTextAttributes(GREEN, BLACK, NORMAL);
        
        // Determine cause of reset and print
        printf("The cause of the most recent device reset was: %s\n\r",
                getCauseOfResetString(reset_cause));
       
        terminalTextAttributesReset();

    }

    // Identification string
    else if((0 == strcmp(line, "*IDN?")) || (0 == strcmp(line, "IDN"))) {

        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("QI Charger with Digital Monitoring, by Drew Maatman\n\r");
        terminalTextAttributesReset();

    }
    
    // print Device ID
    else if((0 == strcmp(line, "Device ID?"))) {

        terminalTextAttributes(GREEN, BLACK, NORMAL);
        
        // Grab and print device ID from flash
        printf("Device ID stored in Flash is: %s (0x%04X)\n\r",
                getDeviceIDString(getDeviceID()),
                getDeviceID());

        terminalTextAttributesReset();

    }
    
    // print Revision ID
    else if((0 == strcmp(line, "Revision ID?"))) {

        terminalTextAttributes(GREEN, BLACK, NORMAL);
        
        // Grab and print revision ID from flash
        printf("Device silicon revision ID as stored in Flash is: %c%03d\n\r",
                ((char) getMajorRevisionID() + 65),getMinorRevisionID());

        terminalTextAttributesReset();

    }
    
    // print User IDs
    else if((0 == strcmp(line, "User IDs?"))) {

        terminalTextAttributes(GREEN, BLACK, NORMAL);
        
        printf("The following User IDs have been retrieved from flash memory:\n\r");

        // Loop through all 8 user ID locations in flash
        for (int userID = 0; userID <= 7; userID++) {
         
            printf("    User ID Word %d (Flash address 0x20000%X): 0x%04X\n\r",
                    userID,
                    (2 * userID),
                    getUserID(userID));
            
        }

        terminalTextAttributesReset();

    }
    
    // Report microcontroller on time since last reset
    else if((0 == strcmp(line, "Device On Time?"))) {
     
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Device on time since last reset condition is: %s\n\r", getStringSecondsAsTime(device_on_time));
        terminalTextAttributesReset();
         
    }
    
    // Turn on QI circuit
    else if ((0 == strcmp(line, "Enable QI"))) {
     
        // Pull QI circuit out of standby
        QI_STANDBY_PIN = 0;
        
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("QI Wireless Power Conversion Enabled\n\r");
        terminalTextAttributesReset();
        
    }
    
    // Turn off QI circuit
    else if ((0 == strcmp(line, "Disable QI"))) {
     
        // Set QI converter to Standby
        QI_STANDBY_PIN = 1;
        
        terminalTextAttributes(RED, BLACK, NORMAL);
        printf("QI Wireless Power Conversion Disabled\n\r");
        terminalTextAttributesReset();
        
    }

    
//    // Report POS3P3 ADC Conversion Result
//    else if((0 == strcmp(line, "ADC Errors?"))) {
//     
//        if (getADCError()) {
//            
//            terminalTextAttributes(RED, BLACK, NORMAL);
//            printf("ADC error(s) detected!\n\r");
//            printf("The following channels caused an ADC error:\n\r");
//            
//            if (error_handler.ADC_general_error_flag) {
//                printf("    General ADC error\n\r");
//            }
//            
//            if (error_handler.AVSS_ADC_error_flag) {
//                printf("    AVSS\n\r");
//            }
//            
//            if (error_handler.FVR_ADC_error_flag) {
//                printf("    FVR\n\r");
//            }
//            
//            if (error_handler.ISNS_ADC_error_flag) {
//                printf("    ISNS\n\r");
//            }
//            
//            if (error_handler.POS12_ADC_error_flag) {
//                printf("    POS12\n\r");
//            }
//            
//            if (error_handler.POS3P3_ADC_error_flag) {
//                printf("    POS3P3\n\r");
//            }
//            
//            if (error_handler.Temp_ADC_error_flag) {
//                printf("    Die Temp\n\r");
//            }
//            
//            terminalTextAttributes(YELLOW, BLACK, NORMAL);
//            printf("Call 'Clear ADC Errors' to clear ADC error(s)\n\r");
//            terminalTextAttributesReset();
//            
//        }
//        
//        else {
//         
//            terminalTextAttributes(GREEN, BLACK, NORMAL);
//            printf("No ADC error(s) detected\n\r");
//            terminalTextAttributesReset();
//        
//        }
//        
//    }
//    
//    // Clear ADC error
//    else if((0 == strcmp(line, "Clear ADC Errors"))) {
//     
//        clearADCErrors();
//        
//        terminalTextAttributes(GREEN, BLACK, NORMAL);
//        printf("ADC Error(s) cleared\n\r");
//        terminalTextAttributesReset();
//        
//    }
    
//    // Report POS3P3 ADC Conversion Result
//    else if((0 == strcmp(line, "Comm Errors?"))) {
//       
//        if (getCOMMError()) {
//        
//            terminalTextAttributes(RED, BLACK, NORMAL);
//            printf("Communications error(s) detected! Interfaces causing error(s):\n\r");
//            
//            if (error_handler.I2C_COMM_error_flag) {
//                printf("    OLED Display I2C\n\r");
//            }
//            
//            if (error_handler.USB_UART_COMM_error_flag) {
//                printf("    USB UART (this interface)\n\r");
//            }
//            
//            terminalTextAttributes(YELLOW, BLACK, NORMAL);
//            printf("Call 'Clear Comm Errors' to clear communications error(s)\n\r");
//            terminalTextAttributesReset();
//        
//        }
//        
//        else {
//            
//            terminalTextAttributes(GREEN, BLACK, NORMAL);
//            printf("No communications error(s) detected\n\r");
//            terminalTextAttributesReset();
//            
//        }   
//    }
//    
//        // Report POS3P3 ADC Conversion Result
//    else if((0 == strcmp(line, "Clear Comm Errors"))) {
//    
//        clearCOMMErrors();
//        
//        terminalTextAttributes(GREEN, BLACK, NORMAL);
//        printf("Communications error(s) cleared\n\r");
//        terminalTextAttributesReset();
//    
//    }
    
    
//    // Report POS3P3 ADC Conversion Result
//    else if((0 == strcmp(line, "Measure POS3P3?"))) {
//
//        terminalTextAttributes(CYAN, BLACK, NORMAL);
//        printf("+3.3V rail measured as +%.3f Volts\n\r", POS3P3_ADC_Result);
//        terminalTextAttributesReset();
//        
//    }
//    
//    // Report POS12 ADC Conversion Result
//    else if((0 == strcmp(line, "Measure POS12?"))) {
//     
//        terminalTextAttributes(CYAN, BLACK, NORMAL);
//        printf("+12V rail measured as +%.3f Volts\n\r", POS12_ADC_Result);
//        terminalTextAttributesReset();
//        
//    }
//    
//    // Report Die temp ADC Conversion Result
//    else if((0 == strcmp(line, "Measure Die Temp?"))) {
//     
//        terminalTextAttributes(CYAN, BLACK, NORMAL);
//        printf("Die Temperature measured as %.3fC\n\r", Temp_ADC_Result);
//        terminalTextAttributesReset();
//
//        
//        
//    }
//    
//    // Report FVR buffer 1 ADC Conversion Result
//    else if((0 == strcmp(line, "Measure FVR?"))) {
//     
//        terminalTextAttributes(CYAN, BLACK, NORMAL);
//        printf("Fixed Voltage Reference Buffer 1 measured as %.3f Volts\n\r", FVR_ADC_Result);
//        terminalTextAttributesReset();
//        
//    }
//    
//    // Report VSS ADC Conversion Result
//    else if((0 == strcmp(line, "Measure AVSS?"))) {
//     
//        terminalTextAttributes(CYAN, BLACK, NORMAL);
//        printf("AVSS measured as %.3f Volts\n\r", AVSS_ADC_Result);
//        terminalTextAttributesReset();
//        
//    }    
    
    // help, print options
    else if((0 == strcmp(line, "Help"))) {

        terminalTextAttributes(YELLOW, BLACK, NORMAL);

        printf("Available Commands:\n\r");
        
        printf( "    Help: Lists available commands\n\r"
                "    *IDN?: Prints identification string\n\r"
                "    Reset: Executes software reset instruction\n\r"
                "    Clear: Clears the virtual COM port terminal\n\r"
                "    Cause of Reset?: Prints the cause of the most recent device reset\n\r"
                "    Device ID?: Prints the microchip device ID\n\r"
                "    Revision ID?: Prints the microchip silicon revision ID\n\r"
                "    User IDs?: Prints a list of User IDs saved in Flash\n\r"
                "    Device On Time?: Prints the device on time since last device reset\n\r"
                "    Enable QI: Enabled QI wireless power conversion\n\r"
                "    Disable QI: Disables QI wireless power conversion\n\r"
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
