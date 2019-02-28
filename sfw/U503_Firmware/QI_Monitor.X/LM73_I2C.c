
#include <xc.h>

#include "mcc_generated_files/i2c2.h"

#include "LM73_I2C.h"

#include "error_handling.h"

// I2C2_MESSAGE_STATUS I2C_STATUS;

// This function initializes the three temperature sensors
void LM73TempSensorInitialize(void) {
    
    // Disable cap touch interrupts
    PIE0bits.INT1IE = 0;
    PIE0bits.INT2IE = 0;
    
    while(I2C_STATUS == I2C2_MESSAGE_PENDING);
    
    // Write config data to config register on QI temp sensor
    uint8_t length;    
    uint8_t output_data_array[2];
    output_data_array[0] = LM73_CONFIG_REG;
    output_data_array[1] = LM73_CONFIG_REG_DATA;
    length = 2;    
    I2C2_MasterWrite(output_data_array, length, QI_TEMP_SENSE_ADDR, &I2C_STATUS);
    while(I2C_STATUS == I2C2_MESSAGE_PENDING);
    if (    I2C_STATUS == I2C2_MESSAGE_FAIL ||
            I2C_STATUS == I2C2_STUCK_START ||
            I2C_STATUS == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            I2C_STATUS == I2C2_DATA_NO_ACK ||
            I2C_STATUS == I2C2_LOST_STATE      ) {
        error_handler.I2C_QI_Temp_Sense_error_flag = true;
    }

    // Write config data to config register on POS5 temp sensor
    I2C2_MasterWrite(output_data_array, length, POS5_TEMP_SENSE_ADDR, &I2C_STATUS);
    while(I2C_STATUS == I2C2_MESSAGE_PENDING);
    if (    I2C_STATUS == I2C2_MESSAGE_FAIL ||
            I2C_STATUS == I2C2_STUCK_START ||
            I2C_STATUS == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            I2C_STATUS == I2C2_DATA_NO_ACK ||
            I2C_STATUS == I2C2_LOST_STATE      ) {
        error_handler.I2C_POS5_Temp_Sense_error_flag = true;
    }
    
    // Write config data to config register on Ambient temp sensor
    I2C2_MasterWrite(output_data_array, length, AMBIENT_TEMP_SENSE_ADDR, &I2C_STATUS);
    while(I2C_STATUS == I2C2_MESSAGE_PENDING);
    if (    I2C_STATUS == I2C2_MESSAGE_FAIL ||
            I2C_STATUS == I2C2_STUCK_START ||
            I2C_STATUS == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            I2C_STATUS == I2C2_DATA_NO_ACK ||
            I2C_STATUS == I2C2_LOST_STATE      ) {
        error_handler.I2C_Ambient_Temp_Sense_error_flag = true;
    }
    
    // Write status data into status register on QI temp sensor
    output_data_array[0] = LM73_STATUS_REG;
    output_data_array[1] = LM73_STATUS_REG_DATA;
    length = 2;    
    I2C2_MasterWrite(output_data_array, length, QI_TEMP_SENSE_ADDR, &I2C_STATUS);
    while(I2C_STATUS == I2C2_MESSAGE_PENDING);
    if (    I2C_STATUS == I2C2_MESSAGE_FAIL ||
            I2C_STATUS == I2C2_STUCK_START ||
            I2C_STATUS == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            I2C_STATUS == I2C2_DATA_NO_ACK ||
            I2C_STATUS == I2C2_LOST_STATE      ) {
        error_handler.I2C_QI_Temp_Sense_error_flag = true;
    }
    
    // Write status data into status register on POS5 temp sensor
    I2C2_MasterWrite(output_data_array, length, POS5_TEMP_SENSE_ADDR, &I2C_STATUS);
    while(I2C_STATUS == I2C2_MESSAGE_PENDING);
    if (    I2C_STATUS == I2C2_MESSAGE_FAIL ||
            I2C_STATUS == I2C2_STUCK_START ||
            I2C_STATUS == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            I2C_STATUS == I2C2_DATA_NO_ACK ||
            I2C_STATUS == I2C2_LOST_STATE      ) {
        error_handler.I2C_POS5_Temp_Sense_error_flag = true;
    }

    // Write status data into status register on Ambient temp sensor
    I2C2_MasterWrite(output_data_array, length, AMBIENT_TEMP_SENSE_ADDR, &I2C_STATUS);
    while(I2C_STATUS == I2C2_MESSAGE_PENDING);
    if (    I2C_STATUS == I2C2_MESSAGE_FAIL ||
            I2C_STATUS == I2C2_STUCK_START ||
            I2C_STATUS == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            I2C_STATUS == I2C2_DATA_NO_ACK ||
            I2C_STATUS == I2C2_LOST_STATE      ) {
        error_handler.I2C_Ambient_Temp_Sense_error_flag = true;
    }
 
    // Enable cap touch interrupts
    PIE0bits.INT1IE = 1;
    PIE0bits.INT2IE = 1;
    
}

// This function accesses temperature sensor data over I2C
void LM73AcquisitionHandler(void) {

    // Disable cap touch interrupts
    PIE0bits.INT1IE = 0;
    PIE0bits.INT2IE = 0;
    
    while(I2C_STATUS == I2C2_MESSAGE_PENDING);
    
    // QI Temp Sensor
    // Write temp reg addr to read back temp sensor data
    I2C2_MasterWrite(LM73_TEMP_REG, 1, QI_TEMP_SENSE_ADDR, &I2C_STATUS);
    while(I2C_STATUS == I2C2_MESSAGE_PENDING);
    if (    I2C_STATUS == I2C2_MESSAGE_FAIL ||
            I2C_STATUS == I2C2_STUCK_START ||
            I2C_STATUS == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            I2C_STATUS == I2C2_DATA_NO_ACK ||
            I2C_STATUS == I2C2_LOST_STATE      ) {
        error_handler.I2C_QI_Temp_Sense_error_flag = true;
    }
    // Read two bytes from temp reg
    I2C2_MasterRead(LM73_temp_results.QI_data_raw, 2, QI_TEMP_SENSE_ADDR, &I2C_STATUS);
    while(I2C_STATUS == I2C2_MESSAGE_PENDING);
    if (    I2C_STATUS == I2C2_MESSAGE_FAIL ||
            I2C_STATUS == I2C2_STUCK_START ||
            I2C_STATUS == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            I2C_STATUS == I2C2_DATA_NO_ACK ||
            I2C_STATUS == I2C2_LOST_STATE      ) {
        error_handler.I2C_QI_Temp_Sense_error_flag = true;
    }
    
    // POS5 Temp Sensor
    // Write temp reg addr to read back temp sensor data
    I2C2_MasterWrite(LM73_TEMP_REG, 1, POS5_TEMP_SENSE_ADDR, &I2C_STATUS);
    while(I2C_STATUS == I2C2_MESSAGE_PENDING);
    if (    I2C_STATUS == I2C2_MESSAGE_FAIL ||
            I2C_STATUS == I2C2_STUCK_START ||
            I2C_STATUS == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            I2C_STATUS == I2C2_DATA_NO_ACK ||
            I2C_STATUS == I2C2_LOST_STATE      ) {
        error_handler.I2C_POS5_Temp_Sense_error_flag = true;
    }
    // Read two bytes from temp reg
    I2C2_MasterRead(LM73_temp_results.POS5_data_raw, 2, POS5_TEMP_SENSE_ADDR, &I2C_STATUS);
    while(I2C_STATUS == I2C2_MESSAGE_PENDING);
    if (    I2C_STATUS == I2C2_MESSAGE_FAIL ||
            I2C_STATUS == I2C2_STUCK_START ||
            I2C_STATUS == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            I2C_STATUS == I2C2_DATA_NO_ACK ||
            I2C_STATUS == I2C2_LOST_STATE      ) {
        error_handler.I2C_POS5_Temp_Sense_error_flag = true;
    }
    
    // Ambient Temp Sensor
    // Write temp reg addr to read back temp sensor data
    I2C2_MasterWrite(LM73_TEMP_REG, 1, AMBIENT_TEMP_SENSE_ADDR, &I2C_STATUS);
    while(I2C_STATUS == I2C2_MESSAGE_PENDING);
    if (    I2C_STATUS == I2C2_MESSAGE_FAIL ||
            I2C_STATUS == I2C2_STUCK_START ||
            I2C_STATUS == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            I2C_STATUS == I2C2_DATA_NO_ACK ||
            I2C_STATUS == I2C2_LOST_STATE      ) {
        error_handler.I2C_Ambient_Temp_Sense_error_flag = true;
    }
    // Read two bytes from temp reg
    I2C2_MasterRead(LM73_temp_results.Ambient_data_raw, 2, AMBIENT_TEMP_SENSE_ADDR, &I2C_STATUS);
    while(I2C_STATUS == I2C2_MESSAGE_PENDING);
    if (    I2C_STATUS == I2C2_MESSAGE_FAIL ||
            I2C_STATUS == I2C2_STUCK_START ||
            I2C_STATUS == I2C2_MESSAGE_ADDRESS_NO_ACK ||
            I2C_STATUS == I2C2_DATA_NO_ACK ||
            I2C_STATUS == I2C2_LOST_STATE      ) {
        error_handler.I2C_Ambient_Temp_Sense_error_flag = true;
    }
    
    // Convert acquired data to floating point variables
    LM73Convert();
    
    LM73_start_flag = false;
    
}

// This function converts raw data from the LM73 to a floating point number
void LM73Convert(void) {
 
    uint16_t QI_Conv, POS5_Conv, Ambient_Conv;
    
    // Move bitfield into proper positions
    QI_Conv = LM73_temp_results.QI_data_raw[0] << 6 | LM73_temp_results.QI_data_raw[1] >> 2;

    // Determine sign
    // Negative case
    if ((LM73_temp_results.QI_data_raw[0] >> 6) == 1) {
        QI_Conv = ~(QI_Conv);
        // Get rid of sign bit in conversion
        QI_Conv = QI_Conv & 0x1FFF;
        LM73_temp_results.QI_temp_result = -0.03125 * QI_Conv;
    }
    // Positive case
    else {
        // Get rid of sign bit in conversion
        QI_Conv = QI_Conv & 0x1FFF;
        LM73_temp_results.QI_temp_result = 0.03125 * QI_Conv;
    }
    
    // Move bitfield into proper positions
    POS5_Conv = LM73_temp_results.POS5_data_raw[0] << 6 | LM73_temp_results.POS5_data_raw[1] >> 2;

    // Determine sign
    // Negative case
    if ((LM73_temp_results.POS5_data_raw[0] >> 6) == 1) {
        POS5_Conv = ~(POS5_Conv);
        // Get rid of sign bit in conversion
        POS5_Conv = POS5_Conv & 0x1FFF;
        LM73_temp_results.POS5_temp_result = -0.03125 * POS5_Conv;
    }
    // Positive case
    else {
        // Get rid of sign bit in conversion
        POS5_Conv = POS5_Conv & 0x1FFF;
        LM73_temp_results.POS5_temp_result = 0.03125 * POS5_Conv;
    }
    
    // Move bitfield into proper positions
    Ambient_Conv = LM73_temp_results.Ambient_data_raw[0] << 6 | LM73_temp_results.Ambient_data_raw[1] >> 2;

    // Determine sign
    // Negative case
    if ((LM73_temp_results.Ambient_data_raw[0] >> 6) == 1) {
        Ambient_Conv = ~(Ambient_Conv);
        // Get rid of sign bit in conversion
        Ambient_Conv = Ambient_Conv & 0x1FFF;
        LM73_temp_results.Ambient_temp_result = -0.03125 * Ambient_Conv;
    }
    // Positive case
    else {
        // Get rid of sign bit in conversion
        Ambient_Conv = Ambient_Conv & 0x1FFF;
        LM73_temp_results.Ambient_temp_result = 0.03125 * Ambient_Conv;
    }
    
    // Enable cap touch interrupts
    PIE0bits.INT1IE = 1;
    PIE0bits.INT2IE = 1;
    
}
