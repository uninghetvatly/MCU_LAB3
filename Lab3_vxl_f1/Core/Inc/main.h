/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SEG0_0_Pin GPIO_PIN_1
#define SEG0_0_GPIO_Port GPIOA
#define SEG0_1_Pin GPIO_PIN_2
#define SEG0_1_GPIO_Port GPIOA
#define SEG0_2_Pin GPIO_PIN_3
#define SEG0_2_GPIO_Port GPIOA
#define SEG0_3_Pin GPIO_PIN_4
#define SEG0_3_GPIO_Port GPIOA
#define SEG0_4_Pin GPIO_PIN_5
#define SEG0_4_GPIO_Port GPIOA
#define SEG0_5_Pin GPIO_PIN_6
#define SEG0_5_GPIO_Port GPIOA
#define SEG0_6_Pin GPIO_PIN_7
#define SEG0_6_GPIO_Port GPIOA
#define BUTTON_0_Pin GPIO_PIN_0
#define BUTTON_0_GPIO_Port GPIOB
#define BUTTON_1_Pin GPIO_PIN_1
#define BUTTON_1_GPIO_Port GPIOB
#define BUTTON_2_Pin GPIO_PIN_2
#define BUTTON_2_GPIO_Port GPIOB
#define EN0_Pin GPIO_PIN_9
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_10
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_11
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_12
#define EN3_GPIO_Port GPIOA
#define LED_1_Pin GPIO_PIN_14
#define LED_1_GPIO_Port GPIOA
#define LED_0_Pin GPIO_PIN_15
#define LED_0_GPIO_Port GPIOA
#define Led_Red_Pin GPIO_PIN_3
#define Led_Red_GPIO_Port GPIOB
#define Led_Yellow_Pin GPIO_PIN_4
#define Led_Yellow_GPIO_Port GPIOB
#define Led_Green_Pin GPIO_PIN_5
#define Led_Green_GPIO_Port GPIOB
#define Led_Red2_Pin GPIO_PIN_6
#define Led_Red2_GPIO_Port GPIOB
#define Led_Yellow2_Pin GPIO_PIN_7
#define Led_Yellow2_GPIO_Port GPIOB
#define Led_Green2_Pin GPIO_PIN_8
#define Led_Green2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
