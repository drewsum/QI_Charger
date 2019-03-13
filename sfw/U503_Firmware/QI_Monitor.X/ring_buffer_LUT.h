/* 
 * File:   ring_buffer_LUT.h
 * Author: Drew Maatman
 *
 * Created on January 17, 2018, 8:00 PM
 */

#include "mcc_generated_files/mcc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <xc.h>

#include "ring_buffer_interface.h"

#ifndef RING_BUFFER_LUT_H
#define	RING_BUFFER_LUT_H
  

// This flag enable live measurement printing
uint8_t live_measurement_enable_flag;

// This flag request a live measurement print
uint8_t live_measurement_request_flag;

/*
  @Summary
    This routine compares the string passed to it and acts on it if it matches
    any of the strings entered. This is how commands should be programmed.

  @Description
    

  @Preconditions
    Having an MCC generated UART driver, and adding the stuff listed below
    Some variables in this file should be edited to use correct EUSART module
    if there are multiple modules within the microcontroller being used

  @Param
    Pointer to a string to be checked and acted on

  @Returns
    None

  @Comment
    

  @Example

*/
void ringBufferLUT(char * line);

// This function prints error status message
void printErrorHandlerStatus(void);

// This function prints the current measurements message
void printCurrentMeasurements(void);

// This function prints the maximum measurements message
void printMaximumMeasurements(void);

// This function prints the minimum measurements message
void printMinimumMeasurements(void);

// This function returns a string representing a floating point number in
// engineering format. It will append the unit prefix on the end after
// three digits past the decimal point
char * floatToEngineeringFormat(float input_value);


#endif	/* RING_BUFFER_LUT_H */

