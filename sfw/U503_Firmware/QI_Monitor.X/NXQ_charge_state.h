
// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _NXQ_CHARGE_STATE_H
#define	_NXQ_CHARGE_STATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include "pin_macros.h"

#include "mcc_generated_files/tmr3.h"
#include "mcc_generated_files/tmr1.h"

// 
enum nxq_charge_state_t {
    
    QI_Idle            = 0,
    QI_Charging        = 1,
    QI_Fully_Charged   = 2,
    QI_Error           = 3
    
} nxq_charge_state;

// This function returns a capitalized string that matches the NXQ charge state enum
char * getNXQChargeStateStringCaps(void);

// This function returns a string that matches the NXQ charge state enum
char * getNXQChargeStateString(void);

// This is the QI_Idle signal IOC handler
void QIIdleIOCHandler(void);

// This is the QI_Charge signal IOC handler
void QIChargeIOCHandler(void);

// This function should be called by a 750 ms timer that is started on the falling edge on CHARGE signal
void QIIdleChargedTimerHandler(void);

// This function is called by a timer ISR and detects if an error condition has occurred
void QIErrorTimerHandler(void);

#endif	/* _NXQ_CHARGE_STATE_H */

