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
#ifndef _LM73_I2C_H
#define	_LM73_I2C_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include "mcc_generated_files/i2c2.h"

// 7-bit I2C addresses for three LM73 devices on board
#define QI_TEMP_SENSE_ADDR          0x4D
#define POS5_TEMP_SENSE_ADDR        0x4C
#define AMBIENT_TEMP_SENSE_ADDR     0x4E

// LM73 I2C Registers
#define LM73_TEMP_REG               0x00
#define LM73_CONFIG_REG             0x01
#define LM73_THIGH_REG              0x02
#define LM73_TLOW_REG               0x03
#define LM73_STATUS_REG             0x04
#define LM73_IDENT_REG              0x07

// Control data to setup devices
#define LM73_CONFIG_REG_DATA        0b01000000
#define LM73_STATUS_REG_DATA        0b11100000

// This structure holds calculated temperatures and raw 14 bit conversion results
struct LM73_temp_results_t {
    
    float QI_temp_result;
    float POS5_temp_result;
    float Ambient_temp_result;
    uint8_t QI_data_raw[2];
    uint8_t POS5_data_raw[2];
    uint8_t Ambient_data_raw[2];
    
} LM73_temp_results;

// This is a flag that starts the acquisition of data from the LM73 sensors
bool LM73_start_flag;

// This function initializes the three temperature sensors
void LM73TempSensorInitialize(void);

// This function accesses temperature sensor data over I2C
void LM73AcquisitionHandler(void);

// This function converts raw data from the LM73 to a floating point number
void LM73Convert(void);

#endif	/* _LM73_I2C_H */

