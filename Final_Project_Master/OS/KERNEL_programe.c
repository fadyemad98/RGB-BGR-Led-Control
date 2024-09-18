/*
 * KERNEL_program.c
 *
 * Created: 10/9/2022 6:21:49 PM
 *  Author: Fady Emad
 */ 
 
 
/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//#include "ATMEGA32_REG.h"

/* MCAL */
#include "STM32_F103C6_SYSTICK_DRIVER.h"
//#include "GI_interface.h"

/* RTOS STACK */
#include "KERNEL_interface.h"
#include "KERNEL_config.h"


Task_t TaskArr[RTOS_TASK_NUM] = {{0}};

void RTOS_start(void)
{
//	TMR_timer0SetCompareMatchValue(249);
//	TMR_timer0_CTC_SetCallBack(&RTOS_scheduler);
//	GI_enable();
//	TMR_timer0Init();
	MCAL_SYSTICK_delay_ms(50);
}


void RTOS_createTask(u8 taskPriority, u16 taskPeriodicity, void(*pFunction)(void))
{
	if((pFunction != NULL) && (taskPriority<RTOS_TASK_NUM))
	{
		TaskArr[taskPriority].periodicity    = taskPeriodicity;
		TaskArr[taskPriority].pTaskFunc      = pFunction;
		TaskArr[taskPriority].suspendedState = RTOS_TASK_RESUMED;
	}
}


void RTOS_suspendTask(u8 taskPriority)
{
	TaskArr[taskPriority].suspendedState = RTOS_TASK_SUSPENDED;
}


void RTOS_resumeTask(u8 taskPriority)
{
	TaskArr[taskPriority].suspendedState = RTOS_TASK_RESUMED;
}


void RTOS_deleteTask(u8 taskPriority)
{
	TaskArr[taskPriority].pTaskFunc = 0;
}


void RTOS_scheduler(void)
{
	volatile static u16 TickCounter = 0;
	TickCounter++;
	
	u8 taskCounter;
	for(taskCounter=0;taskCounter<RTOS_TASK_NUM;taskCounter++)
	{
		if(TaskArr[taskCounter].suspendedState == RTOS_TASK_RESUMED)
		{
			if((TickCounter%TaskArr[taskCounter].periodicity) == 0)
			{
				if(TaskArr[taskCounter].pTaskFunc != NULL)
				{
					TaskArr[taskCounter].pTaskFunc();
				}
			}
		}
	}
}


