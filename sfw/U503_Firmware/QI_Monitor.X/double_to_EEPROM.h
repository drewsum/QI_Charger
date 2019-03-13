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
#ifndef DOUBLE_TO_EEPROM_H
#define	DOUBLE_TO_EEPROM_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include "mcc_generated_files/memory.h"

// These macros set the starting locations of saved floats in EEPROM
#define POS12_MAX_EEPROM_ADDR           0x0000
#define POS12_MIN_EEPROM_ADDR           0x0004
#define POS5_MAX_EEPROM_ADDR            0x0008
#define POS5_MIN_EEPROM_ADDR            0x000C
#define POS12_CURRENT_MAX_EEPROM_ADDR   0x0010
#define POS12_CURRENT_MIN_EEPROM_ADDR   0x0014
#define QI_CURRENT_MAX_EEPROM_ADDR      0x0018
#define QI_CURRENT_MIN_EEPROM_ADDR      0x001C
#define INPUT_POWER_MAX_EEPROM_ADDR     0x0020
#define INPUT_POWER_MIN_EEPROM_ADDR     0x0024
#define OUTPUT_POWER_MAX_EEPROM_ADDR    0x0028
#define OUTPUT_POWER_MIN_EEPROM_ADDR    0x002C
#define EFFICIENCY_MAX_EEPROM_ADDR      0x0030
#define EFFICIENCY_MIN_EEPROM_ADDR      0x0034
#define LOAD_ENERGY_MAX_EEPROM_ADDR     0x0038
#define LOAD_CHARGE_MAX_EEPROM_ADDR     0x003C
#define QI_FSW_MAX_EEPROM_ADDR          0x0040
#define QI_FSW_MIN_EEPROM_ADDR          0x0044
#define QI_FSW_MAX_EEPROM_ADDR          0x0040
#define QI_FSW_MIN_EEPROM_ADDR          0x0044
#define QI_TEMP_MAX_EEPROM_ADDR         0x0048
#define QI_TEMP_MIN_EEPROM_ADDR         0x004C
#define POS5_TEMP_MAX_EEPROM_ADDR       0x0050
#define POS5_TEMP_MIN_EEPROM_ADDR       0x0054
#define AMB_TEMP_MAX_EEPROM_ADDR        0x0058
#define AMB_TEMP_MIN_EEPROM_ADDR        0x005C
#define DIE_TEMP_MAX_EEPROM_ADDR        0x0060
#define DIE_TEMP_MIN_EEPROM_ADDR        0x0064

// This flag requests that NVM variables be saved to EEPROM if they are changed
bool nvm_update_flag;

// This structure holds all variable in RAM that can be saved as values in EEPROM
struct eeprom_ram_alias_t {
    
    float POS12_Max_Result;
    float POS12_Min_Result;
    float POS5_Max_Result;
    float POS5_Min_Result;
    float POS12_Current_Max_Result;
    float POS12_Current_Min_Result;
    float QI_Current_Max_Result;
    float QI_Current_Min_Result;
    float Input_Power_Max_Result;
    float Input_Power_Min_Result;
    float Output_Power_Max_Result;
    float Output_Power_Min_Result;
    float Efficiency_Max_Result;
    float Efficiency_Min_Result;
    float Load_Energy_Max_Result;
    float Load_Charge_Max_Result;
    float QI_FSW_Max_Result;
    float QI_FSW_Min_Result;
    float QI_Temp_Max_Result;
    float QI_Temp_Min_Result;
    float POS5_Temp_Max_Result;
    float POS5_Temp_Min_Result;
    float Ambient_Temp_Max_Result;
    float Ambient_Temp_Min_Result;
    float Die_Temp_Max_Result;
    float Die_Temp_Min_Result;
    
} eeprom_ram_aliases;

// This union allows the interpretation of a double data type as an array of bytes
typedef union {
       double double_t;
       unsigned char byte_array_t[sizeof(double)];
} double_bytes_t;

// This union allows the interpretation of a float data type as an array of bytes
typedef union {
       float float_t;
       unsigned char byte_array_t[sizeof(float)];
} float_bytes_t;


// This function writes a double to EEPROM starting at the given address
void writeDoubleToEEPROM(double input_double, uint16_t starting_address);

// This function retrieves a double from EEPROM from the starting address
double readDoubleFromEEPROM(uint16_t starting_address);

// This function writes a float to EEPROM starting at the given address
void writeFloatToEEPROM(float input_float, uint16_t starting_address);

// This function retrieves a float from EEPROM from the starting address
float readFloatFromEEPROM(uint16_t starting_address);

// This function updates min/max variables in ram alias, which will later be stored in eeprom
void updataMinMaxRAMAliases(void);

// This function retrieves all eeprom ram alias variables from eeprom into ram
void recoverEEPROMToRAM(void);

// This function writes changed eeprom alias variables to eeprom from RAM
// It should not be called often, since EEPROM write cycles could be worn out
void writeEEPROMFromRAM(void);

// This function initializes min and max variables to way out of bounds so that
// they can be accurately recorded later
void minMaxInitialize(void);

// This function writes current max and min values into NVM
void forceEEPROMSave(void);

#endif	/* DOUBLE_TO_EEPROM_H */

