
#include <xc.h>
#include <string.h>
#include <stdio.h>

#include "heartbeat_timer.h"

#include "pin_macros.h"

#include "mcc_generated_files/mcc.h"

#include "LM73_I2C.h"

#include "oled.h"

#include "freq_meas.h"
#include "adc_postprocessing.h"

#include "ring_buffer_LUT.h"

#include "double_to_EEPROM.h"

// This is the heartbeat timer handler function that is called by a timer ISR.
// It blinks an LED, updates on time, and clears the watchdog timer
void heartbeatTimerHandler(void) {

    // Toggle heartbeat LED
    HEARTBEAT_LED_PIN = ~(HEARTBEAT_LED_PIN);
    
    // Increment on time
    device_on_time++;
    
    // Increment charge time if we're charging
    if (nxq_charge_state == QI_Charging || nxq_charge_state == QI_Fully_Charged) QI_charge_time++;
    else QI_charge_time = 0;
    
    // Increment output charge from QI current
    if (nxq_charge_state == QI_Charging || nxq_charge_state == QI_Fully_Charged) adc_calculations.output_charge += adc_results.qi_isns_adc_result;
    else adc_calculations.output_charge = 0.0;
    
    // Increment output energy from output power
    if (nxq_charge_state == QI_Charging || nxq_charge_state == QI_Fully_Charged) adc_calculations.output_energy += adc_calculations.output_power;
    else adc_calculations.output_energy = 0.0;
    
    // Kick the dog
    CLRWDT();
    
    // Request a new LM73 temperature acquisiton
    LM73_start_flag = true;
    
    // Request an OLED update if needed
    if (device_on_time % OLED_update_time == 0) OLED_update_flag = true;
    
    // Request a new frequency measurement capture
    freq_meas_start_flag = true;
    
    // If we need to stream data over UART, request a print message
    if (live_measurement_enable_flag) live_measurement_request_flag = true;
    
    // Save new min and max data to eeprom every 60 seconds
    if (device_on_time % 60 == 0) nvm_update_flag = true;
    
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

// This function returns the number of years that have passed based on the device on time counter
uint8_t getYearsFromOnTime(uint32_t input_seconds) {
 
    uint8_t years;
    return years = input_seconds / (60 * 60 * 24 * 365);
    
}

// This function returns the number of days that have passed based on the device on time counter
uint8_t getDaysFromOnTime(uint32_t input_seconds) {
    
    uint8_t years, days;
    years = input_seconds / (60 * 60 * 24 * 365);
    input_seconds -= years * (60 * 60 * 24 * 365);
    return days = input_seconds / (60 * 60 * 24);
    
}

// This function returns the number of hours that have passed based on the device on time counter
uint8_t getHoursFromOnTime(uint32_t input_seconds) {
    
    uint8_t years, days, hours;
    years = input_seconds / (60 * 60 * 24 * 365);
    input_seconds -= years * (60 * 60 * 24 * 365);
    days = input_seconds / (60 * 60 * 24);
    input_seconds -= days * (60 * 60 * 24);
    return hours = input_seconds / (60 * 60);
    
}

// This function returns the number of minutes that have passed based on the device on time counter
uint8_t getMinutesFromOnTime(uint32_t input_seconds) {
    
    uint8_t years, days, hours, minutes;
    years = input_seconds / (60 * 60 * 24 * 365);
    input_seconds -= years * (60 * 60 * 24 * 365);
    days = input_seconds / (60 * 60 * 24);
    input_seconds -= days * (60 * 60 * 24);
    hours = input_seconds / (60 * 60);
    input_seconds -= hours * (60 * 60);
    return minutes = input_seconds / 60;
    
}

// This function returns the number of seconds that have passed based on the device on time counter
uint8_t getSecondsFromOnTime(uint32_t input_seconds) {
    
    uint8_t years, days, hours, minutes, seconds;
    years = input_seconds / (60 * 60 * 24 * 365);
    input_seconds -= years * (60 * 60 * 24 * 365);
    days = input_seconds / (60 * 60 * 24);
    input_seconds -= days * (60 * 60 * 24);
    hours = input_seconds / (60 * 60);
    input_seconds -= hours * (60 * 60);
    minutes = input_seconds / 60;
    input_seconds -= minutes * 60;
    return seconds = input_seconds;
    
}


