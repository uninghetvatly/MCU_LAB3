#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define MAX_BUTTON 3
#define NORMAL_STATE SET
#define PRESSED_STATE RESET

int isPressed(int number);
int isLongPressed(int number);

void button_init();
void getKeyInput();

#endif /* INC_BUTTON_H_ */