

#include "double_to_EEPROM.h"

#include "adc_postprocessing.h"
#include "LM73_I2C.h"
#include "freq_meas.h"

// This function writes a double to EEPROM starting at the given address
void writeDoubleToEEPROM(double input_double, uint16_t starting_address) {
 
    // Create an array of bytes from the input data
    double_bytes_t input_data;
    input_data.double_t = input_double;
    
    // Iterate over all bytes in double and save to EEPROM
    for (int byte_index = 0; byte_index < sizeof(double); byte_index++) {
     
        DATAEE_WriteByte((starting_address + byte_index), input_data.byte_array_t[byte_index]);
        
    }
    
}

// This function retrieves a double from EEPROM from the starting address
double readDoubleFromEEPROM(uint16_t starting_address) {
 
    // Create an array of bytes to read and return to function caller
    double_bytes_t output_data;
    
    // Iterate over all bytes in double and save to output array
    for (int byte_index = 0; byte_index < sizeof(double); byte_index++) {
     
        output_data.byte_array_t[byte_index] = DATAEE_ReadByte(starting_address + byte_index);
        
    }
    
    // Kick back interpreted double to function caller
    return output_data.double_t;
    
}

// This function writes a float to EEPROM starting at the given address
void writeFloatToEEPROM(float input_float, uint16_t starting_address) {
    
    // Create an array of bytes from the input data
    float_bytes_t input_data;
    input_data.float_t = input_float;
    
    // Iterate over all bytes in float and save to EEPROM
    for (int byte_index = 0; byte_index < sizeof(float); byte_index++) {
     
        DATAEE_WriteByte((starting_address + byte_index), input_data.byte_array_t[byte_index]);
        
    }
    
    
}

// This function retrieves a float from EEPROM from the starting address
float readFloatFromEEPROM(uint16_t starting_address) {
    
    // Create an array of bytes to read and return to function caller
    float_bytes_t output_data;
    
    // Iterate over all bytes in double and save to output array
    for (int byte_index = 0; byte_index < sizeof(float); byte_index++) {
     
        output_data.byte_array_t[byte_index] = DATAEE_ReadByte(starting_address + byte_index);
        
    }
    
    // Kick back interpreted double to function caller
    return output_data.float_t;
    
}

// This function updates min/max variables in ram alias, which will later be stored in eeprom
void updataMinMaxRAMAliases(void) {
    
    // Save POS12 max and min values
    if (adc_results.pos12_adc_result > eeprom_ram_aliases.POS12_Max_Result) eeprom_ram_aliases.POS12_Max_Result = adc_results.pos12_adc_result;
    else if (adc_results.pos12_adc_result < eeprom_ram_aliases.POS12_Min_Result && adc_results.pos12_adc_result != 0.0) eeprom_ram_aliases.POS12_Min_Result = adc_results.pos12_adc_result;
    
    // Save POS5 max and min values
    if (adc_results.pos5_adc_result > eeprom_ram_aliases.POS5_Max_Result) eeprom_ram_aliases.POS5_Max_Result = adc_results.pos5_adc_result;
    else if (adc_results.pos5_adc_result < eeprom_ram_aliases.POS5_Min_Result && adc_results.pos5_adc_result != 0.0) eeprom_ram_aliases.POS5_Min_Result = adc_results.pos5_adc_result;
    
    // Save POS12_Current max and min values
    if (adc_results.pos12_isns_adc_result > eeprom_ram_aliases.POS12_Current_Max_Result) eeprom_ram_aliases.POS12_Current_Max_Result = adc_results.pos12_isns_adc_result;
    else if (adc_results.pos12_isns_adc_result < eeprom_ram_aliases.POS12_Current_Min_Result && adc_results.pos12_isns_adc_result != 0.0) eeprom_ram_aliases.POS12_Current_Min_Result = adc_results.pos12_isns_adc_result;
    
    // Save QI_Current max and min values
    if (adc_results.qi_isns_adc_result > eeprom_ram_aliases.QI_Current_Max_Result) eeprom_ram_aliases.QI_Current_Max_Result = adc_results.qi_isns_adc_result;
    else if (adc_results.qi_isns_adc_result < eeprom_ram_aliases.QI_Current_Min_Result && adc_results.qi_isns_adc_result != 0.0) eeprom_ram_aliases.QI_Current_Min_Result = adc_results.qi_isns_adc_result;
    
    // Save Input Power max and min values
    if (adc_calculations.input_power > eeprom_ram_aliases.Input_Power_Max_Result) eeprom_ram_aliases.Input_Power_Max_Result = adc_calculations.input_power;
    else if (adc_calculations.input_power < eeprom_ram_aliases.Input_Power_Min_Result && adc_calculations.input_power != 0.0) eeprom_ram_aliases.Input_Power_Min_Result = adc_calculations.input_power;
    
    // Save Output Power max and min values
    if (adc_calculations.output_power > eeprom_ram_aliases.Output_Power_Max_Result) eeprom_ram_aliases.Output_Power_Max_Result = adc_calculations.output_power;
    else if (adc_calculations.output_power < eeprom_ram_aliases.Output_Power_Min_Result && adc_calculations.output_power != 0.0) eeprom_ram_aliases.Output_Power_Min_Result = adc_calculations.output_power;
    
    // Save Efficiency max and min values
    if (adc_calculations.efficiency > eeprom_ram_aliases.Efficiency_Max_Result) eeprom_ram_aliases.Efficiency_Max_Result = adc_calculations.efficiency;
    else if (adc_calculations.efficiency < eeprom_ram_aliases.Efficiency_Min_Result && adc_calculations.efficiency != 0.0) eeprom_ram_aliases.Efficiency_Min_Result = adc_calculations.efficiency;
    
    // Save Load Energy max values
    if (adc_calculations.output_energy > eeprom_ram_aliases.Load_Energy_Max_Result) eeprom_ram_aliases.Load_Energy_Max_Result = adc_calculations.output_energy;
    
    // Save Load Charge max values
    if (adc_calculations.output_charge > eeprom_ram_aliases.Load_Charge_Max_Result) eeprom_ram_aliases.Load_Charge_Max_Result = adc_calculations.output_charge;
    
    // Save QI FSW max and min values
    if (freq_meas_results.QI_Freq_Meas > eeprom_ram_aliases.QI_FSW_Max_Result) eeprom_ram_aliases.QI_FSW_Max_Result = freq_meas_results.QI_Freq_Meas;
    else if (freq_meas_results.QI_Freq_Meas < eeprom_ram_aliases.QI_FSW_Min_Result && freq_meas_results.QI_Freq_Meas != 0.0) eeprom_ram_aliases.QI_FSW_Min_Result = freq_meas_results.QI_Freq_Meas;
    
    // Save QI Temp max and min values
    if (LM73_temp_results.QI_temp_result > eeprom_ram_aliases.QI_Temp_Max_Result) eeprom_ram_aliases.QI_Temp_Max_Result = LM73_temp_results.QI_temp_result;
    else if (LM73_temp_results.QI_temp_result < eeprom_ram_aliases.QI_Temp_Min_Result && LM73_temp_results.QI_temp_result != 0.0) eeprom_ram_aliases.QI_Temp_Min_Result = LM73_temp_results.QI_temp_result;
    
    // Save POS5 Temp max and min values
    if (LM73_temp_results.POS5_temp_result > eeprom_ram_aliases.POS5_Temp_Max_Result) eeprom_ram_aliases.POS5_Temp_Max_Result = LM73_temp_results.POS5_temp_result;
    else if (LM73_temp_results.POS5_temp_result < eeprom_ram_aliases.POS5_Temp_Min_Result && LM73_temp_results.POS5_temp_result != 0.0) eeprom_ram_aliases.POS5_Temp_Min_Result = LM73_temp_results.POS5_temp_result;
    
    // Save Ambient Temp max and min values
    if (LM73_temp_results.Ambient_temp_result > eeprom_ram_aliases.Ambient_Temp_Max_Result) eeprom_ram_aliases.Ambient_Temp_Max_Result = LM73_temp_results.POS5_temp_result;
    else if (LM73_temp_results.POS5_temp_result < eeprom_ram_aliases.Ambient_Temp_Min_Result && LM73_temp_results.Ambient_temp_result != 0.0) eeprom_ram_aliases.Ambient_Temp_Min_Result = LM73_temp_results.POS5_temp_result;
    
    // Save Die Temp max and min values
    if (adc_results.die_temp_adc_result > eeprom_ram_aliases.Die_Temp_Max_Result) eeprom_ram_aliases.Die_Temp_Max_Result = adc_results.die_temp_adc_result;
    else if (adc_results.die_temp_adc_result < eeprom_ram_aliases.Die_Temp_Min_Result && adc_results.die_temp_adc_result != 0.0) eeprom_ram_aliases.Die_Temp_Min_Result = adc_results.die_temp_adc_result;
    
}

// This function retrieves all eeprom ram alias variables from eeprom into ram
void recoverEEPROMToRAM(void) {
    
    eeprom_ram_aliases.POS12_Max_Result             = readFloatFromEEPROM(POS12_MAX_EEPROM_ADDR);
    eeprom_ram_aliases.POS12_Min_Result             = readFloatFromEEPROM(POS12_MIN_EEPROM_ADDR);
    eeprom_ram_aliases.POS5_Max_Result              = readFloatFromEEPROM(POS5_MAX_EEPROM_ADDR);
    eeprom_ram_aliases.POS5_Min_Result              = readFloatFromEEPROM(POS5_MIN_EEPROM_ADDR);
    eeprom_ram_aliases.POS12_Current_Max_Result     = readFloatFromEEPROM(POS12_CURRENT_MAX_EEPROM_ADDR);
    eeprom_ram_aliases.POS12_Current_Min_Result     = readFloatFromEEPROM(POS12_CURRENT_MIN_EEPROM_ADDR);
    eeprom_ram_aliases.QI_Current_Max_Result        = readFloatFromEEPROM(QI_CURRENT_MAX_EEPROM_ADDR);
    eeprom_ram_aliases.QI_Current_Min_Result        = readFloatFromEEPROM(QI_CURRENT_MIN_EEPROM_ADDR);
    eeprom_ram_aliases.Input_Power_Max_Result       = readFloatFromEEPROM(INPUT_POWER_MAX_EEPROM_ADDR);
    eeprom_ram_aliases.Input_Power_Min_Result       = readFloatFromEEPROM(INPUT_POWER_MIN_EEPROM_ADDR);
    eeprom_ram_aliases.Output_Power_Max_Result      = readFloatFromEEPROM(OUTPUT_POWER_MAX_EEPROM_ADDR);
    eeprom_ram_aliases.Output_Power_Min_Result      = readFloatFromEEPROM(OUTPUT_POWER_MIN_EEPROM_ADDR);
    eeprom_ram_aliases.Efficiency_Max_Result        = readFloatFromEEPROM(EFFICIENCY_MAX_EEPROM_ADDR);
    eeprom_ram_aliases.Efficiency_Min_Result        = readFloatFromEEPROM(EFFICIENCY_MIN_EEPROM_ADDR);
    eeprom_ram_aliases.Load_Energy_Max_Result       = readFloatFromEEPROM(LOAD_ENERGY_MAX_EEPROM_ADDR);
    eeprom_ram_aliases.Load_Charge_Max_Result       = readFloatFromEEPROM(LOAD_CHARGE_MAX_EEPROM_ADDR);
    eeprom_ram_aliases.QI_FSW_Max_Result            = readFloatFromEEPROM(QI_FSW_MAX_EEPROM_ADDR);
    eeprom_ram_aliases.QI_FSW_Min_Result            = readFloatFromEEPROM(QI_FSW_MIN_EEPROM_ADDR);
    eeprom_ram_aliases.QI_Temp_Max_Result           = readFloatFromEEPROM(QI_TEMP_MAX_EEPROM_ADDR);
    eeprom_ram_aliases.QI_Temp_Min_Result           = readFloatFromEEPROM(QI_TEMP_MIN_EEPROM_ADDR);
    eeprom_ram_aliases.POS5_Temp_Max_Result         = readFloatFromEEPROM(POS5_TEMP_MAX_EEPROM_ADDR);
    eeprom_ram_aliases.POS5_Temp_Min_Result         = readFloatFromEEPROM(POS5_TEMP_MIN_EEPROM_ADDR);
    eeprom_ram_aliases.Ambient_Temp_Max_Result      = readFloatFromEEPROM(AMB_TEMP_MAX_EEPROM_ADDR);
    eeprom_ram_aliases.Ambient_Temp_Min_Result      = readFloatFromEEPROM(AMB_TEMP_MIN_EEPROM_ADDR);
    eeprom_ram_aliases.Die_Temp_Max_Result          = readFloatFromEEPROM(DIE_TEMP_MAX_EEPROM_ADDR);
    eeprom_ram_aliases.Die_Temp_Min_Result          = readFloatFromEEPROM(DIE_TEMP_MIN_EEPROM_ADDR);
    
}

// This function writes changed eeprom alias variables to eeprom from RAM
// It should not be called often, since EEPROM write cycles could be worn out
void writeEEPROMFromRAM(void) {
    
    nvm_update_flag = false;
    
    // Save POS12 Max and Min if needed
    if (eeprom_ram_aliases.POS12_Max_Result > readFloatFromEEPROM(POS12_MAX_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.POS12_Max_Result, POS12_MAX_EEPROM_ADDR);
    if (eeprom_ram_aliases.POS12_Min_Result < readFloatFromEEPROM(POS12_MIN_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.POS12_Min_Result, POS12_MIN_EEPROM_ADDR);
    
    // Save POS5 Max and Min if needed
    if (eeprom_ram_aliases.POS5_Max_Result > readFloatFromEEPROM(POS5_MAX_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.POS12_Max_Result, POS12_MAX_EEPROM_ADDR);
    if (eeprom_ram_aliases.POS5_Min_Result < readFloatFromEEPROM(POS5_MIN_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.POS5_Min_Result, POS5_MIN_EEPROM_ADDR);

    // Save POS12 Current Max and Min if needed
    if (eeprom_ram_aliases.POS12_Current_Max_Result > readFloatFromEEPROM(POS12_CURRENT_MAX_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.POS12_Current_Max_Result, POS12_CURRENT_MAX_EEPROM_ADDR);
    if (eeprom_ram_aliases.POS12_Current_Min_Result < readFloatFromEEPROM(POS12_CURRENT_MIN_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.POS12_Current_Min_Result, POS12_CURRENT_MIN_EEPROM_ADDR);

    // Save QI Current Max and Min if needed
    if (eeprom_ram_aliases.QI_Current_Max_Result > readFloatFromEEPROM(QI_CURRENT_MAX_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.QI_Current_Max_Result, QI_CURRENT_MAX_EEPROM_ADDR);
    if (eeprom_ram_aliases.QI_Current_Min_Result < readFloatFromEEPROM(QI_CURRENT_MIN_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.QI_Current_Min_Result, QI_CURRENT_MIN_EEPROM_ADDR);
    
    // Save Input Power Max and Min if needed
    if (eeprom_ram_aliases.Input_Power_Max_Result > readFloatFromEEPROM(INPUT_POWER_MAX_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.Input_Power_Max_Result, INPUT_POWER_MAX_EEPROM_ADDR);
    if (eeprom_ram_aliases.Input_Power_Min_Result < readFloatFromEEPROM(INPUT_POWER_MIN_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.Input_Power_Min_Result, INPUT_POWER_MIN_EEPROM_ADDR);
    
    // Save Output Power Max and Min if needed
    if (eeprom_ram_aliases.Output_Power_Max_Result > readFloatFromEEPROM(OUTPUT_POWER_MAX_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.Output_Power_Max_Result, OUTPUT_POWER_MAX_EEPROM_ADDR);
    if (eeprom_ram_aliases.Output_Power_Min_Result < readFloatFromEEPROM(OUTPUT_POWER_MIN_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.Output_Power_Min_Result, OUTPUT_POWER_MIN_EEPROM_ADDR);
    
    // Save Efficiency Max and Min if needed
    if (eeprom_ram_aliases.Efficiency_Max_Result > readFloatFromEEPROM(EFFICIENCY_MAX_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.Efficiency_Max_Result, EFFICIENCY_MAX_EEPROM_ADDR);
    if (eeprom_ram_aliases.Efficiency_Min_Result < readFloatFromEEPROM(EFFICIENCY_MIN_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.Efficiency_Min_Result, EFFICIENCY_MIN_EEPROM_ADDR);
    
    // Save Load Energy Max if needed
    if (eeprom_ram_aliases.Load_Energy_Max_Result > readFloatFromEEPROM(LOAD_ENERGY_MAX_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.Load_Energy_Max_Result, LOAD_ENERGY_MAX_EEPROM_ADDR);
    
    // Save Load Charge Max if needed
    if (eeprom_ram_aliases.Load_Charge_Max_Result > readFloatFromEEPROM(LOAD_CHARGE_MAX_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.Load_Charge_Max_Result, LOAD_CHARGE_MAX_EEPROM_ADDR);
        
    // Save QI FSW Max and Min if needed
    if (eeprom_ram_aliases.QI_FSW_Max_Result > readFloatFromEEPROM(QI_FSW_MAX_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.QI_FSW_Max_Result, QI_FSW_MAX_EEPROM_ADDR);
    if (eeprom_ram_aliases.QI_FSW_Min_Result < readFloatFromEEPROM(QI_FSW_MIN_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.QI_FSW_Min_Result, QI_FSW_MIN_EEPROM_ADDR);
    
    // Save QI Temp Max and Min if needed
    if (eeprom_ram_aliases.QI_Temp_Max_Result > readFloatFromEEPROM(QI_TEMP_MAX_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.QI_Temp_Max_Result, QI_TEMP_MAX_EEPROM_ADDR);
    if (eeprom_ram_aliases.QI_Temp_Min_Result < readFloatFromEEPROM(QI_TEMP_MIN_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.QI_Temp_Min_Result, QI_TEMP_MIN_EEPROM_ADDR);
    
    // Save POS5 Temp Max and Min if needed
    if (eeprom_ram_aliases.POS5_Temp_Max_Result > readFloatFromEEPROM(POS5_TEMP_MAX_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.POS5_Temp_Max_Result, POS5_TEMP_MAX_EEPROM_ADDR);
    if (eeprom_ram_aliases.POS5_Temp_Min_Result < readFloatFromEEPROM(POS5_TEMP_MIN_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.POS5_Temp_Min_Result, POS5_TEMP_MIN_EEPROM_ADDR);
    
    // Save Amb Temp Max and Min if needed
    if (eeprom_ram_aliases.Ambient_Temp_Max_Result > readFloatFromEEPROM(AMB_TEMP_MAX_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.Ambient_Temp_Max_Result, AMB_TEMP_MAX_EEPROM_ADDR);
    if (eeprom_ram_aliases.Ambient_Temp_Min_Result < readFloatFromEEPROM(AMB_TEMP_MIN_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.Ambient_Temp_Min_Result, AMB_TEMP_MIN_EEPROM_ADDR);
    
    // Save Die Temp Max and Min if needed
    if (eeprom_ram_aliases.Die_Temp_Max_Result > readFloatFromEEPROM(DIE_TEMP_MAX_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.Die_Temp_Max_Result, DIE_TEMP_MAX_EEPROM_ADDR);
    if (eeprom_ram_aliases.Die_Temp_Min_Result < readFloatFromEEPROM(DIE_TEMP_MIN_EEPROM_ADDR)) writeFloatToEEPROM(eeprom_ram_aliases.Die_Temp_Min_Result, DIE_TEMP_MIN_EEPROM_ADDR);
    
}

// This function initializes min and max variables to way out of bounds so that
// they can be accurately recorded later
void minMaxInitialize(void) {
 
    // Start with really low max values which will be replaced on next while(1) loop
    eeprom_ram_aliases.Ambient_Temp_Max_Result = -40.0;
    eeprom_ram_aliases.Die_Temp_Max_Result = -40.0;
    eeprom_ram_aliases.Efficiency_Max_Result = -40.0;
    eeprom_ram_aliases.Input_Power_Max_Result = -40.0;
    eeprom_ram_aliases.Load_Charge_Max_Result = -40.0;
    eeprom_ram_aliases.Load_Energy_Max_Result = -40.0;
    eeprom_ram_aliases.Output_Power_Max_Result = -40.0;
    eeprom_ram_aliases.POS12_Current_Max_Result = -40.0;
    eeprom_ram_aliases.POS12_Max_Result = -40.0;
    eeprom_ram_aliases.POS5_Max_Result = -40.0;
    eeprom_ram_aliases.POS5_Temp_Max_Result = -40.0;
    eeprom_ram_aliases.QI_Current_Max_Result = -40.0;
    eeprom_ram_aliases.QI_FSW_Max_Result = -40.0;
    eeprom_ram_aliases.QI_Temp_Max_Result = -40.0;
    
    // Start with really high min numbers which will be replaced on next while(1) loop
    eeprom_ram_aliases.Ambient_Temp_Min_Result = 200.0;
    eeprom_ram_aliases.Die_Temp_Min_Result = 200.0;
    eeprom_ram_aliases.Efficiency_Min_Result = 200.0;
    eeprom_ram_aliases.Input_Power_Min_Result = 200.0;
    eeprom_ram_aliases.Output_Power_Min_Result = 200.0;
    eeprom_ram_aliases.POS12_Current_Min_Result = 200.0;
    eeprom_ram_aliases.POS12_Min_Result = 200.0;
    eeprom_ram_aliases.POS5_Min_Result = 200.0;
    eeprom_ram_aliases.POS5_Temp_Min_Result = 200.0;
    eeprom_ram_aliases.QI_Current_Min_Result = 200.0;
    eeprom_ram_aliases.QI_FSW_Min_Result = 200.0;
    eeprom_ram_aliases.QI_Temp_Min_Result = 200.0;
    
}

// This function writes current max and min values into NVM
void forceEEPROMSave(void) {
    
    writeFloatToEEPROM(eeprom_ram_aliases.POS12_Max_Result, POS12_MAX_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.POS12_Min_Result, POS12_MIN_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.POS5_Max_Result, POS5_MAX_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.POS5_Min_Result, POS5_MIN_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.POS12_Current_Max_Result, POS12_CURRENT_MAX_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.POS12_Current_Min_Result, POS12_CURRENT_MIN_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.QI_Current_Max_Result, QI_CURRENT_MAX_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.QI_Current_Min_Result, QI_CURRENT_MIN_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.Input_Power_Max_Result, INPUT_POWER_MAX_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.Input_Power_Min_Result, INPUT_POWER_MIN_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.Output_Power_Max_Result, OUTPUT_POWER_MAX_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.Output_Power_Min_Result, OUTPUT_POWER_MIN_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.Efficiency_Max_Result, EFFICIENCY_MAX_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.Efficiency_Min_Result, EFFICIENCY_MIN_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.Load_Energy_Max_Result, LOAD_ENERGY_MAX_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.Load_Charge_Max_Result, LOAD_CHARGE_MAX_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.QI_FSW_Max_Result, QI_FSW_MAX_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.QI_FSW_Min_Result, QI_FSW_MIN_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.QI_Temp_Max_Result, QI_TEMP_MAX_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.QI_Temp_Min_Result, QI_TEMP_MIN_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.POS5_Temp_Max_Result, POS5_TEMP_MAX_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.POS5_Temp_Min_Result, POS5_TEMP_MIN_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.Ambient_Temp_Max_Result, AMB_TEMP_MAX_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.Ambient_Temp_Min_Result, AMB_TEMP_MIN_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.Die_Temp_Max_Result, DIE_TEMP_MAX_EEPROM_ADDR);
    writeFloatToEEPROM(eeprom_ram_aliases.Die_Temp_Min_Result, DIE_TEMP_MIN_EEPROM_ADDR);
    
}
