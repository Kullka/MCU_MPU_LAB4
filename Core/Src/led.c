/*
 * led.c
 *
 *  Created on: Nov 15, 2022
 *      Author: loing
 */

#include "led.h"
#include <stdio.h>
#include "main.h"

void turn_off_singleLed(unsigned int index) {
	int shift = 3 + index;
	GPIOA->ODR |= (0x1<<shift);
}

void reset_7SEG1() {
	GPIOB->ODR |= 0x7F;
}

void reset_7SEG2() {
	GPIOB->ODR |= (0x7F<<7);
}

uint16_t segmentArray[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void display_7SEG1(int number) {
	reset_7SEG1();
	GPIOB->ODR &= ~segmentArray[number];
}

void display_7SEG2(int number) {
	reset_7SEG2();
	GPIOB->ODR &= ~(segmentArray[number]<<7);
}

void turn_off_all_7seg() {
	reset_7SEG1();
	reset_7SEG2();
}
