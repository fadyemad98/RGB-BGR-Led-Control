/*
 * PB_interface.h
 *
 *  Created on: Aug 14, 2024
 *      Author: fady emad
 */

#ifndef INC_PB_INTERFACE_H_
#define INC_PB_INTERFACE_H_
#include "STM32F103x6.h"
#include "STM32_F103C6_GPIO_Driver.h"

extern GPIO_PINConfig_t PB1config;
extern GPIO_PINConfig_t PB2config;




/*
Function Name        : HAL_button_vInit
Function Returns     : void
Function Arguments   : unsigned char port,unsigned char pin
Function Description : define the given pin in the given port as input pin
*/
void HAL_button_vInit(GPIO_TypeDef *GPIOx,GPIO_PINConfig_t  *Pinconfig);
/*
Function Name        : HAL_button_u8read
Function Returns     : unsigned char
Function Arguments   : unsigned char port,unsigned char pin
Function Description : Returns 0 or 1 depend on the status of the button(pressed or not) and the type of connection (pull up or pull down)
*/
uint8_t HAL_button_u8read(GPIO_TypeDef *GPIOx,uint8_t GPIO_PinNumber);


#endif /* INC_PB_INTERFACE_H_ */
