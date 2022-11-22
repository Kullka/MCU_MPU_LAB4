/*
 * software_timer.h
 *
 *  Created on: Nov 15, 2022
 *      Author: loing
 */

#ifndef SRC_SOFTWARE_TIMER_H_
#define SRC_SOFTWARE_TIMER_H_

#include "main.h"

#define TICK 10
#define TIME 10
extern uint32_t time;
extern int timerFlag;
extern int timerCounter;

void timer_init();
unsigned int get_timer();
void update_timer();
void set_timer(int duration);
void timer_run();

#endif /* SRC_SOFTWARE_TIMER_H_ */
