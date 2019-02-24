
#include <xc.h>

#include "mcc_generated_files/i2c2.h"

#include "LM73_I2C.h"

#include "error_handling.h"

I2C2_MESSAGE_STATUS LM73_I2C_Status;

// This function initializes the three temperature sensors
void LM73TempSensorInitialize(void) {
    
    // Write config data to config register on QI temp sensor
    uint8_t length;    
    uint8_t output_data_array[2];
    output_data_array[0] = LM73_CONFIG_REG;
    output_data_array[1] = LM73_CONFIG_REG_DATA;
    length = 2;    
    I2C2_MasterWrite(output_data_array, length, QI_TEMP_SENSE_ADDR, &LM73_I2C_Status);
    while(LM73_I2C_Status == I2C2_MESSAGE_PENDING);
    if (    LM73_I2C_Status == I2C2_MESSAGE_FAIL ||
            LM73_I2C_Status == I2C2_STUCK_START ||
            LM73_I2C_Status == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            LM73_I2C_Status == I2C2_DATA_NO_ACK ||
            LM73_I2C_Status == I2C2_LOST_STATE      ) {
        error_handler.I2C_QI_Temp_Sense_error_flag = true;
    }

    // Write config data to config register on POS5 temp sensor
    I2C2_MasterWrite(output_data_array, length, POS5_TEMP_SENSE_ADDR, &LM73_I2C_Status);
    while(LM73_I2C_Status == I2C2_MESSAGE_PENDING);
    if (    LM73_I2C_Status == I2C2_MESSAGE_FAIL ||
            LM73_I2C_Status == I2C2_STUCK_START ||
            LM73_I2C_Status == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            LM73_I2C_Status == I2C2_DATA_NO_ACK ||
            LM73_I2C_Status == I2C2_LOST_STATE      ) {
        error_handler.I2C_POS5_Temp_Sense_error_flag = true;
    }
    
    // Write config data to config register on Ambient temp sensor
    I2C2_MasterWrite(output_data_array, length, AMBIENT_TEMP_SENSE_ADDR, &LM73_I2C_Status);
    while(LM73_I2C_Status == I2C2_MESSAGE_PENDING);
    if (    LM73_I2C_Status == I2C2_MESSAGE_FAIL ||
            LM73_I2C_Status == I2C2_STUCK_START ||
            LM73_I2C_Status == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            LM73_I2C_Status == I2C2_DATA_NO_ACK ||
            LM73_I2C_Status == I2C2_LOST_STATE      ) {
        error_handler.I2C_Ambient_Temp_Sense_error_flag = true;
    }
    
    // Write status data into status register on QI temp sensor
    output_data_array[0] = LM73_STATUS_REG;
    output_data_array[1] = LM73_STATUS_REG_DATA;
    length = 2;    
    I2C2_MasterWrite(output_data_array, length, QI_TEMP_SENSE_ADDR, &LM73_I2C_Status);
    while(LM73_I2C_Status == I2C2_MESSAGE_PENDING);
    if (    LM73_I2C_Status == I2C2_MESSAGE_FAIL ||
            LM73_I2C_Status == I2C2_STUCK_START ||
            LM73_I2C_Status == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            LM73_I2C_Status == I2C2_DATA_NO_ACK ||
            LM73_I2C_Status == I2C2_LOST_STATE      ) {
        error_handler.I2C_QI_Temp_Sense_error_flag = true;
    }
    
    // Write status data into status register on POS5 temp sensor
    I2C2_MasterWrite(output_data_array, length, POS5_TEMP_SENSE_ADDR, &LM73_I2C_Status);
    while(LM73_I2C_Status == I2C2_MESSAGE_PENDING);
    if (    LM73_I2C_Status == I2C2_MESSAGE_FAIL ||
            LM73_I2C_Status == I2C2_STUCK_START ||
            LM73_I2C_Status == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            LM73_I2C_Status == I2C2_DATA_NO_ACK ||
            LM73_I2C_Status == I2C2_LOST_STATE      ) {
        error_handler.I2C_POS5_Temp_Sense_error_flag = true;
    }

    // Write status data into status register on Ambient temp sensor
    I2C2_MasterWrite(output_data_array, length, AMBIENT_TEMP_SENSE_ADDR, &LM73_I2C_Status);
    while(LM73_I2C_Status == I2C2_MESSAGE_PENDING);
    if (    LM73_I2C_Status == I2C2_MESSAGE_FAIL ||
            LM73_I2C_Status == I2C2_STUCK_START ||
            LM73_I2C_Status == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            LM73_I2C_Status == I2C2_DATA_NO_ACK ||
            LM73_I2C_Status == I2C2_LOST_STATE      ) {
        error_handler.I2C_Ambient_Temp_Sense_error_flag = true;
    }
    
}

