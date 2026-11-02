#ifndef INC_LED7SEG_DISPLAY_H_
#define INC_LED7SEG_DISPLAY_H_

#include "main.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"

//#include "stm32f4xx.h"   // stm32 f4
#include "stm32f1xx.h" // stm32 f1

//config port and pin Led 7 seg
typedef struct {
	GPIO_TypeDef* Port; // port GPIO
	uint16_t Pin;		// Port GPIO
} GPIO_7SEG_Config;

extern GPIO_7SEG_Config Led_7Seg_Array[7]; //// Array config port and pin

///

void Led7Seg_int(GPIO_7SEG_Config GPIO_Config[7]);
void display7SEG(int num);


#endif /* INC_LED7SEG_DISPLAY_H_ */
