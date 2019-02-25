
#include <xc.h>
#include <string.h>
#include <stdio.h>

#include "heartbeat_timer.h"

#include "pin_macros.h"

#include "mcc_generated_files/mcc.h"

// This is the heartbeat timer handler function that is called by a timer ISR.
// It blinks an LED, updates on time, and clears the watchdog timer
void heartbeatTimerHandler(void) {

    // Toggle heartbeat LED
    HEARTBEAT_LED_PIN = ~(HEARTBEAT_LED_PIN);
    
    // Increment on time
    device_on_time++;
    
    // Kick the dog
    CLRWDT();
    
    // Clear Timer 0
    TMR0 = 0;
    
    // clear the TMR0 interrupt flag
    PIR0bits.TMR0IF = 0;
    
}

// This function returns a string of a large number of seconds in a human readable format
char * getStringSecondsAsTime(uint32_t input_seconds) {
 
    uint8_t years, days, hours, minutes, seconds, remainder;
    static char return_string[40];
    
    // clear return string
    uint8_t i;
    for (i = 0; i < strlen(return_string); i++) {
     
        return_string[i] = '\0';
        
    }
    
    char buff[20];
    
    years = input_seconds / (60 * 60 * 24 * 365);
    input_seconds -= years * (60 * 60 * 24 * 365);
    days = input_seconds / (60 * 60 * 24);
    input_seconds -= days * (60 * 60 * 24);
    hours = input_seconds / (60 * 60);
    input_seconds -= hours * (60 * 60);
    minutes = input_seconds / 60;
    input_seconds -= minutes * 60;
    seconds = input_seconds;
    
    if (years > 0) {
        
        if (years == 1) {
         
            sprintf(buff, "%d year, ", years);
            
        }
        
        else {
         
            sprintf(buff, "%d years, ", years);
            
        }
        
        strcat(return_string, buff);
        
    }
    
    if (days > 0) {
     
        if (days == 1) {
         
            sprintf(buff, "%d day, ", days);
            
        }
        
        else {
         
            sprintf(buff, "%d days, ", days);
            
        }
        
        strcat(return_string, buff);
    }
    
    if (hours > 0) {
     
        if (hours == 1) {
         
            sprintf(buff, "%d hour, ", hours);
            
        }
        
        else {
         
            sprintf(buff, "%d hours, ", hours);
            
        }
        
        strcat(return_string, buff);
        
    }
    
    if (minutes > 0) {
     
        if (minutes == 1) {
         
            sprintf(buff, "%d minute, ", minutes);
            
        }
        
        else {
         
            sprintf(buff, "%d minutes, ", minutes);
            
        }
        
        strcat(return_string, buff);
        
    }
    
    if (seconds > 0) {
     
        if (seconds == 1) {
         
            sprintf(buff, "%d second", seconds);
            
        }
        
        else {
         
            sprintf(buff, "%d seconds", seconds);
            
        }
        
        strcat(return_string, buff);
        
    }
    
    return return_string;
    
}


