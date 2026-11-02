#include "fsm_automatic.h"

// Renamed state enum to avoid global namespace conflicts with other FSMs
typedef enum {s0, s1, s2, s3} auto_state; 

// Renamed from pre_state for clarity
static auto_state current_state = s0; 

void fsm_automatic_init() {
    current_state = s0;
    update_value_7segment(); // Reset all countdown values
}

void fsm_automatic(){
    switch (current_state) {
        case s0:
            updateClockBuffer(value_7seg_red_0, value_7seg_green2_0);
            decoder_Led(0);

            if(flag_timer[1]){
                //traffic 1
                --value_7seg_red_01;
                --value_7seg_red_0;
                //traffic 2
                --value_7seg_green2_0;

                if(value_7seg_red_01 < 1){
                    current_state = s1;
                }

                flag_timer[1] = 0;
            }
            break;

        case s1:
            updateClockBuffer(value_7seg_red_0, value_7seg_yellow2_0);
            decoder_Led(1);
            
            if(flag_timer[1]){
                --value_7seg_red_02;
                --value_7seg_red_0;
                //traffic 2
                --value_7seg_yellow2_0;

                if(value_7seg_red_02 < 1){
                    current_state = s2;
                }

                flag_timer[1] = 0;
            }
            break;

        case s2:
            updateClockBuffer(value_7seg_green_0, value_7seg_red2_0);
            decoder_Led(2);
            
            if(flag_timer[1]){
                --value_7seg_green_0;
                //traffic 2
                --value_7seg_red2_0;
                
                if(value_7seg_green_0 < 1){
                    current_state = s3;
                }

                flag_timer[1] = 0;
            }
            break;

        case s3:
            updateClockBuffer(value_7seg_yellow_0, value_7seg_red2_0);
            decoder_Led(3);
            
            if(flag_timer[1]){
                --value_7seg_yellow_0;
                //traffic 2
                --value_7seg_red2_0;

                if(value_7seg_yellow_0 < 1){
                    current_state = s0;
                    update_value_7segment();
                }

                flag_timer[1] = 0;
            }
            break;

        default:
            break;
    }
    
    // Note: If scan_led() relies on hardware timers for multiplexing 
    // the 4 7-seg displays, ensure fsm_automatic() is called frequently 
    // enough in your main while(1) loop so it doesn't flicker.
    scan_led(); 
}