#include "fsm_setting.h"

int var_blink = 0;

void update_led_time(){
    // condition update_led_time
    // red = green + yellow, red > green > yellow
    if(((config_value_red - (config_value_green + config_value_yellow)) == 0)
            && ((config_value_red > config_value_green) && (config_value_green > config_value_yellow)))
    {
        value_7seg_red_0 = config_value_red;
        value_7seg_yellow_0 = config_value_yellow;
        value_7seg_green_0 = config_value_green;

        value_7seg_red2_0 = config_value_red;
        value_7seg_yellow2_0 = config_value_yellow;
        value_7seg_green2_0 = config_value_green;

        value_7seg_red_01 = value_7seg_red_0 - value_7seg_yellow_0;
        value_7seg_red_02 = value_7seg_red_0 - value_7seg_green_0;
    }
}

void check_value_led(){
    // Enforce strict 1-99 range
    if(config_value_green > 99) config_value_green = 1;
    if(config_value_yellow > 99) config_value_yellow = 1;
    if(config_value_red > 99) config_value_red = 1;

    // Treat < 1 rather than < 0 to prevent unsigned int underflow bugs
    if(config_value_green < 1) config_value_green = 99;
    if(config_value_yellow < 1) config_value_yellow = 99;
    if(config_value_red < 1) config_value_red = 99;
}

void fsm_setting(int index){
    switch (index) {
        case SETTING_0: // Modify Red Mode
            updateClockBuffer(config_value_red, button0_value);
            blink_Led(0, var_blink);
            
            if(flag_timer[2]){
                var_blink = !var_blink;
                flag_timer[2] = 0;
            }
            
            // Button 2 increases
            if(isPressed(1)){
                config_value_red++;
            }
            if(isLongPressed(1)){
                config_value_red--;
            }
            
            // Button 3 sets the value
            if(isPressed(2)){
                update_led_time();
            }
            break;

        case SETTING_1: // Modify Amber (Yellow) Mode
            updateClockBuffer(config_value_yellow, button0_value);
            blink_Led(1, var_blink);
            
            if(flag_timer[2]){
                var_blink = !var_blink;
                flag_timer[2] = 0;
            }

            if(isPressed(1)){
                config_value_yellow++;
            }
            if(isLongPressed(1)){
                config_value_yellow--;
            }
            
            if(isPressed(2)){
                update_led_time();
            }
            break;

        case SETTING_2: // Modify Green Mode
            updateClockBuffer(config_value_green, button0_value);
            blink_Led(2, var_blink);
            
            if(flag_timer[2]){
                var_blink = !var_blink;
                flag_timer[2] = 0;
            }

            if(isPressed(1)){
                config_value_green++;
            }
            if(isLongPressed(1)){
                config_value_green--;
            }
            
            if(isPressed(2)){
                update_led_time();
            }
            break;

        default:
            break;
    }
    
    check_value_led(); // Ensure values stay in 1-99 bounds before drawing
    scan_led();
}