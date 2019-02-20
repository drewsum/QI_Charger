
#include <xc.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "terminal_control.h"
// #include "usb_uart.h"


// This function clears the terminal
void terminalClearScreen(void) {
    printf("\033[2J");
}

// This function moves the terminal cursor to top left corner
void terminalSetCursorHome(void) {
    printf("\033[H");
}

// This function clears the line the cursor is currently at on the terminal
void terminalClearLine(void) {
    printf("\033[K");
}

// This function saves the current cursor position on the terminal
void terminalSaveCursor(void) {
    printf("\033[s");
}

// This function returns the cursor to saved position on terminal
void terminalReturnCursor(void) {
    printf("\033[u");
}

// Text attributes function
// See attributes enums in "USB_UART.h"
// Call like so:
/*

    USB_UART_textAttributes(<TEXT COLOR (ALL CAPS)>, 
                            <BACKGROUND COLOR (ALL CAPS)>, 
                            <TEXT EFFECT (ALL CAPS)>);

*/

void terminalTextAttributes(text_color_t foreground_color,
        text_color_t background_color,
        text_attribute_t input_attribute) {
    
    char print_string[16];
    
    // Null print string
    uint8_t i;
    for (i = 0; i < sizeof(print_string); i++) {
     
        print_string[i] = '\0';
        
    }
    
    strncpy(print_string, "\033[", sizeof(print_string));
    
    switch (input_attribute) {
     
        case NORMAL:
            strcat(print_string,"0");
            break;
        case BOLD:
            strcat(print_string,"1");
            break;
        case UNDERSCORE:
            strcat(print_string,"4");
            break;
        case BLINK:
            strcat(print_string,"5");
            break;
        case REVERSE:
            strcat(print_string,"7");
            break;
        case CONCEALED:
            strcat(print_string,"8");
            break;

        default:
            strcat(print_string,"0");
            break;
    }
    
    strcat(print_string,";");
    
    switch (foreground_color) {
     
        case BLACK:
            strcat(print_string,"30");
            break;
        case RED:
            strcat(print_string,"31");
            break;
        case GREEN:
            strcat(print_string,"32");
            break;
        case YELLOW:
            strcat(print_string,"33");
            break;
        case BLUE:
            strcat(print_string,"34");
            break;
        case MAGENTA:
            strcat(print_string,"35");
            break;
        case CYAN:
            strcat(print_string,"36");
            break;
        case WHITE:
            strcat(print_string,"37");
            break;
            
        default:
            strcat(print_string,"37");
            break;
    }
    
    strcat(print_string,";");
    
    switch (background_color) {
     
        case BLACK:
            strcat(print_string,"40");
            break;
        case RED:
            strcat(print_string,"41");
            break;
        case GREEN:
            strcat(print_string,"42");
            break;
        case YELLOW:
            strcat(print_string,"43");
            break;
        case BLUE:
            strcat(print_string,"44");
            break;
        case MAGENTA:
            strcat(print_string,"45");
            break;
        case CYAN:
            strcat(print_string,"46");
            break;
        case WHITE:
            strcat(print_string,"47");
            break;
            
        default:
            strcat(print_string,"40");
            break;
    }
    
    strcat(print_string,"m");
    
    printf(print_string);
    
}

// Reset text attributes to white text, black background, no effects
void terminalTextAttributesReset(void) {
 
    // USB_UART_textAttributes(WHITE, BLACK, NORMAL);
    printf("\033[0;37;40m");
    
}

// tests all the function written for this example
void terminalPrintTestMessage(void) {
    
    // Set starting text color white, background black, no fancy stuff
    // Print COM port settings
    terminalTextAttributesReset();
    terminalClearScreen();
    terminalSetCursorHome();
    printf("USB UART Test\n\r\n\r");
//    printf("COM Port Settings:\n\r");
//    printf("    Baud Rate: %s\n\r", USB_UART_BAUD_RATE_STR);
//    printf("    Data Length: %s\n\r", USB_UART_DATA_LENGTH_STR);
//    printf("    Parity: %\n\r", USB_UART_PARITY_STR);
//    printf("    Stop Bits: %s\n\r", USB_UART_STOP_BITS_STR);
//    printf("    Flow Control: %s\n\r\n\r", USB_UART_FLOW_CONTROL_STR);
//        
    // Test text attributes
    printf("Testing text attributes:\n\r");

    // Print some black text
    terminalTextAttributesReset();
    terminalTextAttributes(BLACK, WHITE, NORMAL);
    printf("This text is black\n\r");

    terminalTextAttributesReset();
    terminalTextAttributes(RED, BLACK, NORMAL);
    printf("This text is red\n\r");

    terminalTextAttributesReset();
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("This text is green\n\r");

    terminalTextAttributesReset();
    terminalTextAttributes(YELLOW, BLACK, NORMAL);
    printf("This text is yellow\n\r");

    terminalTextAttributesReset();
    terminalTextAttributes(BLUE, WHITE, NORMAL);
    printf("This text is blue\n\r");

    terminalTextAttributesReset();
    terminalTextAttributes(MAGENTA, BLACK, NORMAL);
    printf("This text is magenta\n\r");

    terminalTextAttributesReset();
    terminalTextAttributes(CYAN, BLACK, NORMAL);
    printf("This text is cyan\n\r");
    
    terminalTextAttributesReset();
    terminalTextAttributes(WHITE, BLACK, NORMAL);
    printf("This text has a black background\n\r");
    
    terminalTextAttributesReset();
    terminalTextAttributes(BLACK, RED, NORMAL);
    printf("This text has a red background\n\r");

    terminalTextAttributesReset();
    terminalTextAttributes(BLACK, GREEN, NORMAL);
    printf("This text has a green background\n\r");
    
    terminalTextAttributesReset();
    terminalTextAttributes(BLACK, YELLOW, NORMAL);
    printf("This text has a yellow background\n\r");
    
    terminalTextAttributesReset();
    terminalTextAttributes(WHITE, BLUE, NORMAL);
    printf("This text has a blue background\n\r");
    
    terminalTextAttributesReset();
    terminalTextAttributes(BLACK, MAGENTA, NORMAL);
    printf("This text has a magenta background\n\r");
    
    terminalTextAttributesReset();
    terminalTextAttributes(BLACK, CYAN, NORMAL);
    printf("This text has a cyan background\n\r");
    
    terminalTextAttributesReset();
    terminalTextAttributes(BLACK, WHITE, NORMAL);
    printf("This text has a white background\n\r");
    
    terminalTextAttributesReset();
    terminalTextAttributes(WHITE, BLACK, BOLD);
    printf("This text is bold\n\r");

    terminalTextAttributesReset();
    terminalTextAttributes(WHITE, BLACK, UNDERSCORE);
    printf("This text is underscored\n\r");

    terminalTextAttributesReset();
    terminalTextAttributes(WHITE, BLACK, BLINK);
    printf("This text is blinking\n\r");

    terminalTextAttributesReset();
    terminalTextAttributes(WHITE, BLACK, REVERSE);
    printf("This text is reversed\n\r");

    terminalTextAttributesReset();
    printf("This text is normal\n\r\n\r");
    
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("Finished test message, type 'Help' for list of commands\n\r\n\r");
    terminalTextAttributesReset();

}
