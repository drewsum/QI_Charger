
#include <xc.h>

#include <stdio.h>

#include "NXQ_charge_state.h"

#include "pin_macros.h"

// This function returns a string that matches the NXQ charge state enum
char * getNXQChargeStateString(void) {
 
    switch (nxq_charge_state) {
     
        case Idle:
            return "idle";
            break;
            
        case Charging:
            return "charging";
            break;
            
        case Fully_Charged:
            return "fully charged";
            break;
            
        case Error:
            return "error";
            break;
            
        default:
            return "undefined";
            break;
            
    }
    
}

// This is the QI_Idle signal IOC handler
void QIIdleIOCHandler(void) {
       
    if (QI_IDLE_PIN_FALL == 1) {
        
        TMR6_StartTimer();
        
    }
         
}

// This is the QI_Charge signal IOC handler
void QIChargeIOCHandler(void) {
    
    TMR6_StopTimer();
    TMR6_WriteTimer(0);
    
    if (QI_CHARGE_PIN_FALL && QI_IDLE_PIN == 1) {
        
        nxq_charge_state = Charging;
        
    }
    
    else if ((nxq_charge_state == Charging || nxq_charge_state == Idle) && QI_CHARGE_PIN_RISE && QI_IDLE_PIN == 1) {
        
        nxq_charge_state = Fully_Charged;
        
    }
    
}

// This function should be called by a 800 ms timer that is started on the falling edge on both IDLE and CHARGE signals
void QIIdleTimerHandler(void) {
     
    if (QI_IDLE_PIN == 1 && QI_CHARGE_PIN == 0) {
     
        nxq_charge_state = Error;
        
    }
    
    else if (QI_CHARGE_PIN == 0 && QI_IDLE_PIN == 0) {
     
        nxq_charge_state = Idle;
        
    }
    
    TMR6_StopTimer();
    TMR6_WriteTimer(0);
    
}
