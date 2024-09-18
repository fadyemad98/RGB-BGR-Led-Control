/*
 * PB_program.c
 *
 *  Created on: Aug 14, 2024
 *      Author: fadye
 */
#include "PB_interface.h"
#include "STM32_F103C6_GPIO_Driver.h"




void HAL_button_vInit(GPIO_TypeDef *GPIOx,GPIO_PINConfig_t *Pinconfig){
	MCAL_GPIO_Init(GPIOx, &Pinconfig);
}



uint8_t HAL_button_u8read(GPIO_TypeDef *GPIOx,uint8_t GPIO_PinNumber){
	return MCAL_GPIO_ReadPin(GPIOx, GPIO_PinNumber);
}
