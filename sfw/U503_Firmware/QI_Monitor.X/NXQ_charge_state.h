
// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _NXQ_CHARGE_STATE_H
#define	_NXQ_CHARGE_STATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include "pin_macros.h"

#include "mcc_generated_files/tmr6.h"

// 
enum nxq_charge_state_t {
    
    Idle            = 0,
    Charging        = 1,
    Fully_Charged   = 2,
    Error           = 3
    
} nxq_charge_state;

// This function returns a string that matches the NXQ charge state enum
char * getNXQChargeStateString(void);

// This is the QI_Idle signal IOC handler
void QIIdleIOCHandler(void);

// This is the QI_Charge signal IOC handler
void QIChargeIOCHandler(void);

// This function should be called by a 750 ms timer that is started on the falling edge on CHARGE signal
void QIIdleTimerHandler(void);

#endif	/* _NXQ_CHARGE_STATE_H */

