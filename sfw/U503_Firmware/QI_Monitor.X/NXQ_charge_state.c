
#include <xc.h>

#include "NXQ_charge_state.h"

#include "pin_macros.h"

// This function returns a string that matches the NXQ charge state enum
char * getNXQChargeStateString(void) {
 
    switch (nxq_charge_state) {
     
        case QI_Idle:
            return "idle";
            break;
            
        case QI_Charging:
            return "charging";
            break;
            
        case QI_Fully_Charged:
            return "fully charged";
            break;
            
        case QI_Error:
            return "error";
            break;
            
        default:
            return "undefined";
            break;
            
    }
    
}

// This function returns a capitalized string that matches the NXQ charge state enum
char * getNXQChargeStateStringCaps(void) {
 
    switch (nxq_charge_state) {
     
        case QI_Idle:
            return "Idle";
            break;
            
        case QI_Charging:
            return "Charging";
            break;
            
        case QI_Fully_Charged:
            return "Fully Charged";
            break;
            
        case QI_Error:
            return "Error";
            break;
            
        default:
            return "Undefined";
            break;
            
    }
    
}

// This is the QI_QI_Idle signal IOC handler
void QIIdleIOCHandler(void) {
       
    if (QI_IDLE_PIN_FALL == 1) {
        
        TMR3_Reload();
        TMR3_StartTimer();
        
        // TMR1_Reload();
        TMR1_StartTimer();
        
    }
         
}

// This is the QI_Charge signal IOC handler
void QIChargeIOCHandler(void) {
        
    if (QI_CHARGE_PIN_FALL && QI_IDLE_PIN == 1) {
        
        nxq_charge_state = QI_Charging;
        
    }
  
    TMR3_Reload();
    TMR3_StartTimer();
    
    TMR1_Reload();
    
}

// This function should be called by a 800 ms timer that is started on the falling edge on both IDLE and CHARGE signals
void QIIdleChargedTimerHandler(void) {
    
    if (QI_IDLE_PIN == 0 && QI_CHARGE_PIN == 0) {
     
        nxq_charge_state = QI_Idle;
        
    }
    
    else if (QI_IDLE_PIN == 1 && QI_CHARGE_PIN == 1) {
        
        nxq_charge_state = QI_Fully_Charged;
        
    }
    
    TMR3_StopTimer();
    TMR3_Reload();
    
}

// This function is called by a timer ISR and detects if an error condition has occurred
void QIErrorTimerHandler(void) {

    if (QI_IDLE_PIN == 1 && QI_CHARGE_PIN == 0) {
     
        nxq_charge_state = QI_Error;
        
    }

    TMR1_StopTimer();
    TMR1_Reload();
    
}

