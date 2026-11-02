#include "global.h"

// Initialize to Mode 1 (Normal Mode) 
uint16_t button0_value = 1; 
uint16_t button1_value = 0;
uint16_t button2_value = 0;

///value 7 segment
int config_value_red = 11;
int config_value_yellow = 4;
int config_value_green = 7;

uint16_t value_7seg_red_0 = 0;
uint16_t value_7seg_red_01 = 0;
uint16_t value_7seg_red_02 = 0;
uint16_t value_7seg_yellow_0 = 0;
uint16_t value_7seg_green_0 = 0;

uint16_t value_7seg_red2_0 = 0;
uint16_t value_7seg_yellow2_0 = 0;
uint16_t value_7seg_green2_0 = 0;

GPIO_7SEG_Config Led_7Seg_Array[7] = {
    {SEG0_0_GPIO_Port, SEG0_0_Pin},  //  a
    {SEG0_1_GPIO_Port, SEG0_1_Pin},  //  b
    {SEG0_2_GPIO_Port, SEG0_2_Pin},  //  c
    {SEG0_3_GPIO_Port, SEG0_3_Pin},  //  d
    {SEG0_4_GPIO_Port, SEG0_4_Pin},  //  e
    {SEG0_5_GPIO_Port, SEG0_5_Pin},  //  f
    {SEG0_6_GPIO_Port, SEG0_6_Pin}   //  g
};

void System_scan_value_led_init(){
    update_value_7segment();
    Led7Seg_int(Led_7Seg_Array);
    timer_init();

    //Data buffer   //Scan_led
    setTimer(0, 10);
    
    //timer step 1s for 7 segment
    setTimer(1, 1000);

    // timer blink led 
    setTimer(2, 250); 
}
