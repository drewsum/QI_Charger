/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef CAUSE_OF_RESET_H
#define	CAUSE_OF_RESET_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// The type of reset, stored in an enumeration
typedef enum reset_types{
    Undefined_Reset                 = 0,
    Power_On_Reset                  = 1,
    Brown_Out_Reset                 = 2,
    Master_Clear_Reset              = 3,
    Watch_Dog_Timer_Reset           = 4,
    Windowed_Watch_Dog_Timer_Reset  = 5,
    RESET_Instruction_Executed      = 6,
    Stack_Overflow_Reset            = 7,
    Stack_Underflow_Reset           = 8
} reset_t;

// This is the global enum for holding the cause of the most recent device reset
reset_t reset_cause;

// This function returns a pointer to a string describing the cause of the most
// recent device reset
reset_t getCauseOfReset(void);

// This function returns a string describing the given type of reset
inline char * getCauseOfResetString(reset_t r);

// This function gets a smaller cause of reset string
inline char * getCauseOfResetStringSmall(reset_t r);

#endif	/* CAUSE_OF_RESET_H */

