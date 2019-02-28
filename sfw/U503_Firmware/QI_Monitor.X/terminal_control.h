/* ************************************************************************** */
/** Terminal Control Functions for serial terminals
 */
/* ************************************************************************** */

#ifndef _TERMINAL_CONTROL_H    /* Guard against multiple inclusion */
#define _TERMINAL_CONTROL_H


// Enumeration holding attributes data for setting text fanciness
typedef enum {
    
    NORMAL,
    BOLD,
    UNDERSCORE,
    BLINK,
    REVERSE,
    CONCEALED
            
} text_attribute_t;

// Enumeration for setting text color attributes
typedef enum {
    
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
            
} text_color_t;

// Terminal manipulation functions
void terminalClearScreen(void);  // clears the whole terminal
void terminalSetCursorHome(void);  // Sets cursor to home position (top left)
void terminalClearLine(void);      // clears the current line where the cursor appears
void terminalSaveCursor(void);     // Saves the current position of the cursor
void terminalReturnCursor(void);   // Returns the cursor to saved position

// Text attributes function
void terminalTextAttributes(text_color_t foreground_color,
        text_color_t background_color,
        text_attribute_t input_attribute);

// Reset to white foreground, black background, no fancy stuff
void terminalTextAttributesReset(void);

// This function tests terminal control
void terminalPrintTestMessage(void);



#endif /* _TERMINAL_CONTROL_H */

/* *****************************************************************************
 End of File
 */
