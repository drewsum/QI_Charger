
#include "freq_meas.h"

// This function enables captures for both POS5 FSW and QI FSW
void freqMeasStartCaptures(void) {

    // Enable capture for POS5 FSW
    // CCP1CONbits.EN = 1;
    
    // Enable capture for QI FSW
    CCP2CONbits.EN = 1;
    
    // Disable flag
    freq_meas_start_flag = false;
    
}

// This function converts the raw CCP capture value to a floating point number representing frequency
void freqMeasConvert(void) {
    
    // Convert raw POS5 Capture value to frequency
    double pos5_period = ((((float) freq_meas_results.POS5_Freq_Meas_Raw + 1) / 16.0) * 0.00000063);
    freq_meas_results.POS5_Freq_Meas = 1.0 / pos5_period;
    
    // Convert raw QI Capture value to frequency
    double qi_period = ((((float) freq_meas_results.QI_Freq_Meas_Raw + 1) / 16.0) * 0.00000063);
    freq_meas_results.QI_Freq_Meas = 1.0 / qi_period;
    
    
}

