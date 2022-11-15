/*
 * tasks.c
 *
 *  Created on: Nov 15, 2022
 *      Author: loing
 */

#include "tasks.h"
#include "main.h"


void led1_toggle() {
	HAL_GPIO_TogglePin(GPIOB, LED1_Pin);
}

void led2_toggle() {
	HAL_GPIO_TogglePin(GPIOB, LED2_Pin);
}

void led3_toggle() {
	HAL_GPIO_TogglePin(GPIOB, LED3_Pin);
}

void led4_toggle() {
	HAL_GPIO_TogglePin(GPIOB, LED4_Pin);
}

void led5_toggle() {
	HAL_GPIO_TogglePin(GPIOB, LED4_Pin);
}
