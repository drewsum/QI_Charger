
#include <stdio.h>

#include <xc.h>

#include "cap_touch_int.h"

#include "oled.h"

// This function is the Left Cap Touch Pushbutton Handler Function
void leftCapTouchHandler(void) {
    
    OLED_Frame--;
    if (OLED_Frame == OLED_FRAME_MIN - 1) OLED_Frame = OLED_FRAME_MAX;
    OLED_update_flag = true;

}

// This function is the Right Cap Touch Pushbutton Handler Function
void rightCapTouchHandler(void) {

    OLED_Frame++;
    if (OLED_Frame == OLED_FRAME_MAX + 1) OLED_Frame = OLED_FRAME_MIN;
    OLED_update_flag = true;
    
}