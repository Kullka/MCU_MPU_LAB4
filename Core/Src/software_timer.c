/*
 * software_timer.c
 *
 *  Created on: Nov 15, 2022
 *      Author: loing
 */

#include "software_timer.h"
#include "led.h"

uint32_t time;

void timer_init() {
	time = 0;
}

unsigned int get_timer() {
	return time;
}

void update_timer() {
	time++;
}


