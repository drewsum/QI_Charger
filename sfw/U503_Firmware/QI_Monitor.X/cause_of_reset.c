/*
 * File:   reset_cause.c
 * Author: Drew Maatman
 *
 * Created on January 10, 2018, 10:07 PM
 */


#include "cause_of_reset.h"

reset_t getCauseOfReset(void) {
 
    reset_t return_reset_cause;
    
    // Per page 98 of PIC18(L)F67K40
   
    // Determine the cause of the last reset
    if (PCON0bits.STKOVF == 1) {
        
        return_reset_cause = Stack_Overflow_Reset;
        
    }
    
    else if (PCON0bits.STKUNF == 1) {
     
        return_reset_cause = Stack_Underflow_Reset;
        
    }
    
    else if (PCON0bits.nWDTWV == 0) {
        
        return_reset_cause = Windowed_Watch_Dog_Timer_Reset;
        
    }
    
    else if (PCON0bits.nRWDT == 0) {
     
        return_reset_cause = Watch_Dog_Timer_Reset;
        
    }
    
    else if (PCON0bits.nRMCLR == 0) {
     
        return_reset_cause = Master_Clear_Reset;
        
    }
    
    else if (PCON0bits.nRI == 0) {
        
        return_reset_cause = RESET_Instruction_Executed;
        
    }
    
    else if (PCON0bits.nPOR == 0) {
     
        return_reset_cause = Power_On_Reset;
        
    }
    
    else if (PCON0bits.nBOR == 0) {
        
        return_reset_cause = Brown_Out_Reset;
        
    }
    
    else {
     
        return_reset_cause = Undefined_Reset;
        
    }
    
    // Clear all reset flags, reset to default states
    PCON0bits.STKOVF    = 0;
    PCON0bits.STKUNF    = 0;
    PCON0bits.nWDTWV    = 1;
    PCON0bits.nRWDT     = 1;
    PCON0bits.nRMCLR    = 1;
    PCON0bits.nRI       = 1;
    PCON0bits.nPOR      = 1;
    PCON0bits.nBOR      = 1;
    
    return return_reset_cause;
    
}


inline char *getCauseOfResetString(reset_t r) {
   
    // The ordering MUST match the ordering of the reset_type enumeration
    static char *strings[] = {
        "Undefined Reset",
        "Power On Reset",
        "Brown Out Reset",
        "Master Clear Reset",
        "Watch Dog Timer Violation Reset",
        "Windowed Watch Dog Timer Violation Reset",
        "RESET Instruction Executed",
        "Stack Overflow Reset",
        "Stack Underflow Reset",
    };

    // Do some error checking    
    if (r <= 8) {

        return strings[r];

    }
    
    else {

        return "Undefined Reset";

    }

}

// This function gets a smaller cause of reset string
inline char * getCauseOfResetStringSmall(reset_t r) {
 
    // The ordering MUST match the ordering of the reset_type enumeration
    static char *strings[] = {
        "Undefined",
        "POR Reset",
        "BOR Reset",
        "MCLR Reset",
        "WDT Reset",
        "WWDT Reset",
        "RESET Executed",
        "STOF Reset",
        "STUF Reset",
    };

    // Do some error checking    
    if (r <= 8) {

        return strings[r];

    }
    
    else {

        return "Undefined";

    }
    
}