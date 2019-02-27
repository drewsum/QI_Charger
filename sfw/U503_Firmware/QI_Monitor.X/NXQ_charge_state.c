
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
     
        printf("Starting TMR6\n\r");
        
        TMR6_StartTimer();
        
    }
    
    QI_IDLE_PIN_RISE = 0;
    QI_IDLE_PIN_FALL = 0;
     
}

// This is the QI_Charge signal IOC handler
void QIChargeIOCHandler(void) {
    
    printf("Charge IOC ISR\n\r");
    
    TMR6_StopTimer();
    TMR6_WriteTimer(0);
    
    if (QI_CHARGE_PIN_FALL && QI_IDLE_PIN == 1) {
    
        printf("Charging\n\r");
        
        nxq_charge_state = Charging;
        
    }
    
    else if ((nxq_charge_state == Charging || nxq_charge_state == Idle) && QI_CHARGE_PIN_RISE && QI_IDLE_PIN == 1) {
        
        nxq_charge_state = Fully_Charged;
        
    }
        
    QI_CHARGE_PIN_RISE = 0;
    QI_CHARGE_PIN_FALL = 0;
    IOCBFbits.IOCBF3 = 0;
    
}

// This function should be called by a 800 ms timer that is started on the falling edge on both IDLE and CHARGE signals
void QIIdleTimerHandler(void) {
     
    if (QI_IDLE_PIN == 1 && QI_CHARGE_PIN == 0) {
     
        printf("Error\n\r");
        
        nxq_charge_state = Error;
        
    }
    
    else if (QI_CHARGE_PIN == 0 && QI_IDLE_PIN == 0) {
     
        printf("Idle\n\r");
        nxq_charge_state = Idle;
        QI_CHARGE_PIN_RISE = 0;
        QI_CHARGE_PIN_FALL = 0;
        QI_IDLE_PIN_RISE = 0;
        QI_IDLE_PIN_FALL = 0;
        IOCBFbits.IOCBF2 = 0;
        IOCBFbits.IOCBF3 = 0;
        
    }
    
    TMR6_StopTimer();
    TMR6_WriteTimer(0);
    
}
