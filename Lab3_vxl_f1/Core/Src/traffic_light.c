#include "traffic_light.h"

void decoder_Led(int index){
    switch (index) {
        case 0:
            //traffic light 1
            HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 0);
            HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 1);
            HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 1);
            //traffic light 2
            HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 1);
            HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 1);
            HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 0);
            break;
        case 1:
            //traffic light 1
            HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 0);
            HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 1);
            HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 1);
            //traffic light 2
            HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 1);
            HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 0);
            HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 1);
            break;
        case 2:
            //traffic light 1
            HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 1);
            HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 1);
            HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 0);
            //traffic light 2
            HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 0);
            HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 1);
            HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 1);
            break;
        case 3:
            //traffic light 1
            HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 1);
            HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 0);
            HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 1);
            //traffic light 2
            HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 0);
            HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 1);
            HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 1);
            break;
        default:
            break;
    }
}

void blink_Led(int index, int index1){
    if(index1 == 1){
        switch (index) {
            case 0: // Blink Red
                HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 0);
                HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 1);
                HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 1);
                
                HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 0);
                HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 1);
                HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 1);
                break;
            case 1: // Blink Yellow
                HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 1);
                HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 0);
                HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 1);

                HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 1);
                HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 0);
                HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 1);
                break;
            case 2: // Blink Green
                HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 1);
                HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 1);
                HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 0);

                HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 1);
                HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 1);
                HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 0);
                break;
            default:
                break;
        }
    }
    else {
        // Turn off all LEDs
        HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 1);
        HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 1);
        HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 1);

        HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 1);
        HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 1);
        HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 1);
    }
}

//////////////////////////////// LED 7 SEG ////////////////////////////

// Declared as static to confine them strictly to this file
static unsigned Led_Pos[4] = {1, 1, 1, 1};
static unsigned En_Led_Pos[4] = {0b1110, 0b1101, 0b1011, 0b0111};
static unsigned Led_Buffer[4] = {0, 0, 0, 0};
static uint8_t index_led = 0;
static const uint8_t Max_Led = 4;
static uint8_t Buffer = 0;

static void En_led_7_seg(){
    HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, Led_Pos[0]);
    HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, Led_Pos[1]);
    HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, Led_Pos[2]);
    HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, Led_Pos[3]);
}

void updateClockBuffer(uint16_t value_7seg0, uint16_t value_7seg1 ){
    Led_Buffer[0] = value_7seg0 / 10;
    Led_Buffer[1] = value_7seg0 % 10;
    Led_Buffer[2] = value_7seg1 / 10;
    Led_Buffer[3] = value_7seg1 % 10;
}

void update_value_7segment(){
    //traffic 1
    value_7seg_red_0 = config_value_red;
    value_7seg_yellow_0 = config_value_yellow;
    value_7seg_green_0 = config_value_green;

    value_7seg_red_01 = value_7seg_red_0 - value_7seg_yellow_0;
    value_7seg_red_02 = value_7seg_red_0 - value_7seg_green_0;

    //traffic 2
    value_7seg_red2_0 = config_value_red;
    value_7seg_yellow2_0 = config_value_yellow;
    value_7seg_green2_0 = config_value_green;
}

static void update7SEG(int index){
    // 1. Turn OFF all digits first to prevent ghosting (1 = OFF for PNP)
    HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
    HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
    HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
    HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);

    // 2. Set the segments for the new number
    Buffer = Led_Buffer[index];
    display7SEG(Buffer);

    // 3. Turn ON the correct digit
    for(int i = 0; i < Max_Led; i++){
        Led_Pos[i] = (En_Led_Pos[index] >> i) & 0b1;
    }
    En_led_7_seg();
}

void scan_led(){
    if(flag_timer[0]){
        update7SEG(index_led++);
        if(index_led > Max_Led - 1) index_led = 0;
        flag_timer[0] = 0;
    }
}
