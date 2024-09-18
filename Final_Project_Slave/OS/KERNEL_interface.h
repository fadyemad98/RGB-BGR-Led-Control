/*
 * KERNEL_interface.h
 *
 * Created: 10/9/2022 6:22:01 PM
 *  Author: Fady Emad
 *
 */ 


#ifndef KERNEL_INTERFACE_H_
#define KERNEL_INTERFACE_H_
#include "STD_TYPES.h"

#define RTOS_TASK_SUSPENDED      1
#define RTOS_TASK_RESUMED        2

typedef struct
{
	void(*pTaskFunc)(void);
	u16 periodicity;
	u8  suspendedState;
}Task_t;


void RTOS_start      (void);
void RTOS_createTask (u8 taskPriority, u16 taskPeriodicity, void(*pFunction)(void));
void RTOS_suspendTask(u8 taskPriority);
void RTOS_resumeTask (u8 taskPriority);
void RTOS_deleteTask (u8 taskPriority);
void RTOS_scheduler  (void);


#endif /* KERNEL_INTERFACE_H_ */
