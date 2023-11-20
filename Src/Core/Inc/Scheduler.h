/*
 * Scheduler.h
 *
 *  Created on: Nov 23, 2022
 *      Author: phamk
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#define SCH_MAX_TASKS	40

#include <stdint.h>

typedef struct{
	void (*pTask)(void);
	uint32_t	Delay;
	uint32_t	Period;
	uint8_t		Runme;
	uint8_t		Runone;
	uint32_t	TaskID;
} sTasks;

void SCH_init();
int SCH_add_task(uint32_t inpDelay, uint32_t inpPeriod, uint8_t inpRunone, void (*pTask)(void));
void SCH_update();
void SCH_dispatch_task();
void SCH_delete_task(uint32_t TaskID);

#endif /* INC_SCHEDULER_H_ */
