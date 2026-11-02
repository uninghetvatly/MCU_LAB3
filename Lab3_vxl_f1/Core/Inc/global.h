#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_


#include <stdint.h>
#include "main.h"
#include "Led7Seg_Display.h"
#include "software_timer.h"
#include "traffic_light.h"


#define AUTOMATiC 0
#define MANUAL 1
#define SETTING_0 2
#define SETTING_1 3
#define SETTING_2 4

///button
#define MAX_METHOD 5
extern uint16_t button0_value;
extern uint16_t button1_value;
extern uint16_t button2_value;


//init value
extern int config_value_red;
extern int config_value_yellow;
extern int config_value_green;

//value 7 segment
extern uint16_t value_7seg_red_0;
extern uint16_t value_7seg_red_01;
extern uint16_t value_7seg_red_02;
extern uint16_t value_7seg_yellow_0;
extern uint16_t value_7seg_green_0;

extern uint16_t value_7seg_red2_0;
extern uint16_t value_7seg_yellow2_0;
extern uint16_t value_7seg_green2_0;


void System_scan_value_led_init();

#endif /* INC_GLOBAL_H_ */
