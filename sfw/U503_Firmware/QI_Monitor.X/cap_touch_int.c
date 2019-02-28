
#include <stdio.h>

#include <xc.h>

#include "cap_touch_int.h"

#include "oled.h"

// This function is the Left Cap Touch Pushbutton Handler Function
void leftCapTouchHandler(void) {

    OLED_Frame++;
    if (OLED_Frame == 20) OLED_Frame = 4;
    OLED_update_flag = true;
    
}

// This function is the Right Cap Touch Pushbutton Handler Function
void rightCapTouchHandler(void) {

    OLED_Frame--;
    if (OLED_Frame == 3) OLED_Frame = 19;
    OLED_update_flag = true;

}