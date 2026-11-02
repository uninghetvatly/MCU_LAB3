#include "button.h"

// 100 ticks * 10ms = 1s initial delay
#define TIME_OUT_LONG_PRESS 100 
// 50 ticks * 10ms = 0.5s auto-repeat
#define TIME_OUT_REPEAT 50      

static uint16_t key_reg[MAX_BUTTON][4]; // [button id][register id]
static uint16_t press_time_out[MAX_BUTTON];
static uint16_t button_flag[MAX_BUTTON] = {0};
static uint16_t button_long_pressed[MAX_BUTTON] = {0};

void button_init() {
    for (int i = 0; i < MAX_BUTTON; i++) {
        for (int j = 0; j < 4; j++) {
            key_reg[i][j] = NORMAL_STATE;
        }
        press_time_out[i] = TIME_OUT_LONG_PRESS;
    }
}

static void button_init_gpi(int i) {
    switch (i) {
        case 0:
            key_reg[i][0] = HAL_GPIO_ReadPin(BUTTON_0_GPIO_Port, BUTTON_0_Pin);
            break;
        case 1:
            key_reg[i][0] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
            break;
        case 2:
            key_reg[i][0] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
            break;
        default:
            break;
    }
}

int isPressed(int number) {
    if(button_flag[number] == 1) {
        button_flag[number] = 0;
        return 1;
    }
    return 0;
}

int isLongPressed(int number) {
    if(button_long_pressed[number] == 1) {
        button_long_pressed[number] = 0;
        return 1;
    }
    return 0;
}

void getKeyInput() {
    for (int i = 0; i < MAX_BUTTON; i++) {
        key_reg[i][2] = key_reg[i][1];
        key_reg[i][1] = key_reg[i][0];
    }
    for (int i = 0; i < MAX_BUTTON; i++) {
        button_init_gpi(i);
        if ((key_reg[i][1] == key_reg[i][0]) && (key_reg[i][1] == key_reg[i][2])) {
            if (key_reg[i][2] != key_reg[i][3]) {
                key_reg[i][3] = key_reg[i][2];
                if (key_reg[i][3] == PRESSED_STATE) {
                    press_time_out[i] = TIME_OUT_LONG_PRESS; // Reset to initial 1s delay
                    button_flag[i] = 1;
                }
            } else {
                press_time_out[i]--;
                if (press_time_out[i] == 0) {
                    press_time_out[i] = TIME_OUT_REPEAT; // Switch to 0.5s auto-repeat interval
                    if (key_reg[i][3] == PRESSED_STATE) {
                        button_long_pressed[i] = 1;
                    }
                }
            }
        }
    }
}