
#include "freq_meas.h"

// This function enables captures for both POS5 FSW and QI FSW
void freqMeasStartCaptures(void) {
    
    // Enable capture for QI FSW
    CCP2CONbits.EN = 1;
    
    // Disable flag
    freq_meas_start_flag = false;
    
}

// This function converts the raw CCP capture value to a floating point number representing frequency
void freqMeasConvert(void) {
    
    // Convert raw QI Capture value to frequency
    if (freq_meas_results.QI_Freq_Meas_Raw > 2) {
    
        double qi_period = ((((float) freq_meas_results.QI_Freq_Meas_Raw + 1) / 16.0) * 0.00000063);
        double qi_freq_scratch = 1.0 / qi_period;
        if (qi_freq_scratch > 100.0 && qi_freq_scratch < 500000.0) freq_meas_results.QI_Freq_Meas = (float) qi_freq_scratch;
    
    }
    
}

