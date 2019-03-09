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
#ifndef _HEARTBEAT_TIMER_H
#define	_HEARTBEAT_TIMER_H

#include <xc.h> // include processor files - each processor file is guarded. 
#include <stdint.h>

// This is the device on time counter variable
unsigned long device_on_time;

// This is the heartbeat timer handler function that is called by a timer ISR.
// It blinks an LED, updates on time, and clears the watchdog timer
void heartbeatTimerHandler(void);

// This function returns a string of a large number of seconds in a human readable format
char * getStringSecondsAsTime(uint32_t input_seconds);

// This function returns the number of years that have passed based on the device on time counter
uint8_t getYearsFromOnTime(uint32_t input_seconds);

// This function returns the number of days that have passed based on the device on time counter
uint8_t getDaysFromOnTime(uint32_t input_seconds);

// This function returns the number of hours that have passed based on the device on time counter
uint8_t getHoursFromOnTime(uint32_t input_seconds);

// This function returns the number of minutes that have passed based on the device on time counter
uint8_t getMinutesFromOnTime(uint32_t input_seconds);

// This function returns the number of seconds that have passed based on the device on time counter
uint8_t getSecondsFromOnTime(uint32_t input_seconds);


#endif	/* _HEARTBEAT_TIMER_H */

