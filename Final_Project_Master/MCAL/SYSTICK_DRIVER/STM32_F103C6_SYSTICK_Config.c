/*
 * STM32_F103C6_SYSTICK_Config.c
 *
 *  Created on: Sep 16, 2024
 *      Author: fadye
 */


#include "STM32_F103C6_SYSTICK_DRIVER.h"
#include "KERNEL_interface.h"
Systick_Config_t SystickConfig = {
		.CLKSOURCE = CLKSOURCE_AHB_8,
		.SYSTICK_INT = SYSTICK_INT_enable,
		.pSystick_Call_back = &RTOS_scheduler
};

