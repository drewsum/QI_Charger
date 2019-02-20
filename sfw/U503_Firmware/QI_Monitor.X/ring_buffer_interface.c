
#include <xc.h>

#include "ring_buffer_interface.h"

void terminal_ringBufferPull(void) {

    int charNumber = eusart2RxCount;
            
    // Clear line buffer
    for (int index = 0; index < EUSART_2_RX_BUFFER_SIZE; index++) {

        line[index] = '\0';

    }

    // Fill line from ring buffer
    for(int index = 0; index < charNumber; index++){

        line[index] = EUSART2_Read();

    }

    // Reset ring buffer
    eusart2RxTail = eusart2RxHead;

    // Try to kill off ending returns/newlines
    while((line[strlen(line) - 1] == (int) '\n') ||
          (line[strlen(line) - 1] == (int) '\r')) {
     
        // NULL
        line[strlen(line) - 1] = '\0';
        
    }
    

    // Clear ready flag
    eusart2RxStringReady = 0;

    // Check to see if line matches a command
    ringBufferLUT(line);

    
}
