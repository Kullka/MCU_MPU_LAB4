/*
 * software_timer.c
 *
 *  Created on: Nov 15, 2022
 *      Author: loing
 */

#include "software_timer.h"
#include "led.h"

uint32_t time;
int timerFlag = 0;
int timerCounter = 0;

void set_timer(int duration) {
	timerCounter = duration/TICK;
	timerFlag = 0;
}

void timer_run() {
	time++;
	if (timerCounter>0) {
		timerCounter--;
		if (timerCounter==0)
			timerFlag = 1;
	}
}

void timer_init() {
	time = 0;
}

unsigned int get_timer() {
	return time;
}



