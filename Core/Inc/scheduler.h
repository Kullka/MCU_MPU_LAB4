/*
 * scheduler.h
 *
 *  Created on: Nov 15, 2022
 *      Author: loing
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include <stdio.h>

typedef struct {
	void (*pTask)(void);
	uint32_t delay;
	uint32_t period;
	uint8_t runMe;
} sTask;

#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0

void SCH_init(void);
void SCH_update(void);
uint16_t SCH_add_task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD);
void SCH_dispatch_tasks(void);
uint16_t SCH_delete_task(const uint16_t TASK_INDEX);
void SCH_report_error(void);

#endif /* INC_SCHEDULER_H_ */
