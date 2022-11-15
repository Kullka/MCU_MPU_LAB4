/*
 * software_timer.h
 *
 *  Created on: Nov 15, 2022
 *      Author: loing
 */

#ifndef SRC_SOFTWARE_TIMER_H_
#define SRC_SOFTWARE_TIMER_H_

#include "main.h"

extern unsigned int time;

void timer_init();
unsigned int get_timer();
void update_timer();

#endif /* SRC_SOFTWARE_TIMER_H_ */
