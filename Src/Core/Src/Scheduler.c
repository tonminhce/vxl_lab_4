 /*
 * Scheduler.c
 *
 *  Created on: Nov 26, 2022
 *      Author: phamk
 */

#include "Scheduler.h"

sTasks SCH_task_array[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

void SCH_Init(){
	current_index_task = 0;
}

int SCH_add_task(uint32_t inpDelay, uint32_t inpPeriod, uint8_t inpRunone, void (*inpTask)(void)){
	if (current_index_task < SCH_MAX_TASKS){
	SCH_task_array[current_index_task].Delay = inpDelay;
	SCH_task_array[current_index_task].Period = inpPeriod;
	SCH_task_array[current_index_task].Runone = inpRunone;
	SCH_task_array[current_index_task].pTask = inpTask;

	if (inpDelay == 0){
		SCH_task_array[current_index_task].Runme = 1;
	}
	else{
		SCH_task_array[current_index_task].Runme = 0;
	}

	current_index_task++;
	}

	return current_index_task-1;

	// return (current_index_task == 0) ? SCH_MAX_TASKS : current_index_task-1;
}

void SCH_update(){
	for (uint32_t i = 0; i < current_index_task; i++){
		if (SCH_task_array[i].Delay > 0)
			SCH_task_array[i].Delay--;
		else{
			SCH_task_array[i].Delay = SCH_task_array[i].Period;
			SCH_task_array[i].Runme += 1;
		}
	}
}

void SCH_dispatch_task(){
	for (uint32_t i = 0; i < current_index_task; i++){
		if (SCH_task_array[i].Runme >= 1){
			SCH_task_array[i].Runme--;
			if (SCH_task_array[i].Runone == 0 || SCH_task_array[i].Runone == 1){
				(*SCH_task_array[i].pTask)();

				if (SCH_task_array[i].Runone == 1){
					SCH_task_array[i].Runone = 2;
				}
			}
		}
	}
}
