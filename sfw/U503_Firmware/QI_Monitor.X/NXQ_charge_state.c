
#include <xc.h>

#include "NXQ_charge_state.h"

#include "pin_macros.h"

#include "mcc_generated_files/tmr3.h"

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
 
    TMR3_StopTimer();
    TMR3_Reload();
    
    if (QI_IDLE_PIN_RISE && QI_CHARGE_PIN == 0 
            && (nxq_charge_state == Charging || nxq_charge_state == Fully_Charged)) {
     
        nxq_charge_state = Error;
        
    }
        
    QI_IDLE_PIN_RISE = 0;
    QI_IDLE_PIN_FALL = 0;
    
    TMR3_StartTimer();
    
}

// This is the QI_Charge signal IOC handler
void QIChargeIOCHandler(void) {
 
    TMR3_StopTimer();
    TMR3_Reload();
    
    if (QI_CHARGE_PIN_FALL && QI_IDLE_PIN == 1) {
     
        nxq_charge_state = Charging;
        
    }
    
    else if ((nxq_charge_state == Charging || nxq_charge_state == Idle) && QI_IDLE_PIN == 1) {
        
        nxq_charge_state = Fully_Charged;
        
    }
    
    QI_CHARGE_PIN_RISE = 0;
    QI_CHARGE_PIN_FALL = 0;
    
    TMR3_StartTimer();
    
}

// This function should be called by a 1250 ms timer that is started on the falling edge on both IDLE and CHARGE signals
void QIIdleTimerHandler(void) {
 
    if (QI_CHARGE_PIN == 0 && QI_IDLE_PIN == 0) {
     
        nxq_charge_state = Idle;
        
    }
    
    TMR3_StopTimer();
    TMR3_Reload();
    
}