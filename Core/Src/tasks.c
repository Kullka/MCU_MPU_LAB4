/*
 * tasks.c
 *
 *  Created on: Nov 15, 2022
 *      Author: loing
 */

#include "tasks.h"
#include "main.h"
#include "software_timer.h"
#include "led.h"

void led1_toggle() {
	HAL_GPIO_TogglePin(GPIOA, LED1_Pin);
}

void led2_toggle() {
	HAL_GPIO_TogglePin(GPIOA, LED2_Pin);
}

void led3_toggle() {
	HAL_GPIO_TogglePin(GPIOA, LED3_Pin);
}

void led4_toggle() {
	HAL_GPIO_TogglePin(GPIOA, LED4_Pin);
}

void led5_toggle() {
	HAL_GPIO_TogglePin(GPIOA, LED5_Pin);
}

void display_timer() {
	uint32_t value = get_timer();
	value = value/50;
	display_7SEG1(value/10);
	display_7SEG2(value%10);
}

void init_tasks() {
	void (*ptask0)(void);
	void (*pTask1)(void);
	void (*pTask2)(void);
	void (*pTask3)(void);
	void (*pTask4)(void);
	void (*pTask5)(void);
	ptask0 = display_timer;
	pTask1 = led1_toggle;
	pTask2 = led2_toggle;
	pTask3 = led3_toggle;
	pTask4 = led4_toggle;
	pTask5 = led5_toggle;
	SCH_add_task(ptask0, 0, 50);
	SCH_add_task(pTask1, 5, 50);
	SCH_add_task(pTask2, 10, 100);
	SCH_add_task(pTask3, 15, 150);
	SCH_add_task(pTask4, 20, 200);
	SCH_add_task(pTask5, 25, 250);
}
