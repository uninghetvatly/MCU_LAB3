#include "Led7Seg_Display.h"

////////////////            DISPLAY-7SEG             ////////////////

void Led7Seg_int(GPIO_7SEG_Config GPIO_Config[7]){
    for (int i = 0; i < 7; i++) {
        Led_7Seg_Array[i] = GPIO_Config[i];
    }
}

static uint8_t A, B, C, D;
static bool a, b, c, d, e, f, g;

static void calculator_BCD_to_7SEG(int num){
    // num maps directly to the 4-bit binary value (0=0b0000, 9=0b1001)
    uint8_t buffer = (uint8_t)num; 

    // 4bit [3:0] -> [A:B]
    A = (buffer >> 3) & 1;
    B = (buffer >> 2) & 1;
    C = (buffer >> 1) & 1;
    D = (buffer >> 0) & 1;

    // f(ABCD)
    a = ((!B)&(!D)) | C | (B&D) | A;
    b = (!B) | ((!C)&(!D)) | (C&D);
    c = (!C) | D | B;
    d = ((!B)&(!D)) | ((!B)&C) | ((B&!C)&D) | (C&(!D)) | A;
    e = ((!B)&(!D)) | (C&(!D));
    f = ((!C)&(!D)) | (B&(!C)) | (B&(!D)) | A;
    g = ((!B)&C) | (B&(!C)) | A | (B&(!D));
}

void display7SEG(int num){
    calculator_BCD_to_7SEG(num);
    HAL_GPIO_WritePin(Led_7Seg_Array[0].Port, Led_7Seg_Array[0].Pin, !a);
    HAL_GPIO_WritePin(Led_7Seg_Array[1].Port, Led_7Seg_Array[1].Pin, !b);
    HAL_GPIO_WritePin(Led_7Seg_Array[2].Port, Led_7Seg_Array[2].Pin, !c);
    HAL_GPIO_WritePin(Led_7Seg_Array[3].Port, Led_7Seg_Array[3].Pin, !d);
    HAL_GPIO_WritePin(Led_7Seg_Array[4].Port, Led_7Seg_Array[4].Pin, !e);
    HAL_GPIO_WritePin(Led_7Seg_Array[5].Port, Led_7Seg_Array[5].Pin, !f);
    HAL_GPIO_WritePin(Led_7Seg_Array[6].Port, Led_7Seg_Array[6].Pin, !g);
}