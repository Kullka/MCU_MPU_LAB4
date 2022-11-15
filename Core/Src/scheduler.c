/*
 * scheduler.c
 *
 *  Created on: Nov 15, 2022
 *      Author: loing
 */

#include "scheduler.h"
#include "software_timer.h"
#include "main.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];

void SCH_init(void) {
	uint16_t i;
	for (i=0; i<SCH_MAX_TASKS; i++) {
		SCH_delete_task(i);
	}
//	error_code_G = 0;
	timer_init();
}

void SCH_update(void) {
	uint16_t index;
	update_timer();
	for (index=0; index<SCH_MAX_TASKS; index++) {
		if (SCH_tasks_G[index].pTask) {
			if (SCH_tasks_G[index].delay==0) {
				SCH_tasks_G[index].runMe += 1;
				if (SCH_tasks_G[index].period)
					SCH_tasks_G[index].delay = SCH_tasks_G[index].period;
				else ;
			}
			else
				SCH_tasks_G[index].delay -= 1;
		}
	}
}

uint16_t SCH_add_task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD) {
	uint16_t index = 0;
	while ( (SCH_tasks_G[index].pTask != 0) && (index < SCH_MAX_TASKS) )
		index++;
	if (index==SCH_MAX_TASKS)
		return SCH_MAX_TASKS;
	SCH_tasks_G[index].pTask = pFunction;
	SCH_tasks_G[index].delay = DELAY;
	SCH_tasks_G[index].period = PERIOD;
	SCH_tasks_G[index].runMe = 0;

	return index;
}

void SCH_dispatch_tasks(void) {
	uint16_t index;
	for (index = 0; index<SCH_MAX_TASKS; index++) {
		if (SCH_tasks_G[index].runMe>0) {
			(*SCH_tasks_G[index].pTask)();
			SCH_tasks_G[index].runMe -= 1;
			if (SCH_tasks_G[index].period==0)
				SCH_delete_task(index);
		}
	}
}

uint16_t SCH_delete_task(const uint16_t TASK_INDEX) {
	SCH_tasks_G[TASK_INDEX].delay = 0;
	SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
	SCH_tasks_G[TASK_INDEX].delay = 0;
	SCH_tasks_G[TASK_INDEX].runMe = 0;
	return TASK_INDEX;
}

//void SCH_report_error(void);

