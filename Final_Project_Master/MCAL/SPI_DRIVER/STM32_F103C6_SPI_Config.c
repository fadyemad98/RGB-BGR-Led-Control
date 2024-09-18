/*
 * STM32_F103C6_SPI_Config.c
 *
 *  Created on: Sep 15, 2024
 *      Author: fadye
 */
#include "STM32_F103C6_SPI_Driver.h"
#include "STM32_F103C6_GPIO_Driver.h"
//extern void SPI_IRQ_Callback(void);
//const SPI_Config_t SPICONFIG = {
//		.Device_Mode = SPI_Device_Mode_MASTER,
//		.Communication_Mode=SPI_DIRECTION_2LINES,
//		.Frame_Format=SPI_Frame_Format_MSB_transmitted_first,
//		.DataSize=SPI_DataSize_8BIT,
//		.CLKPolarity=SPI_CLKPolarity_HIGH_when_idle,
//		.CLKPhase=SPI_Clock_Phase_2EDGE_first_data_capture_edge,
//		.NSS=SPI_NSS_Soft_NSSInternalSoft_Set,
//		.SPI_BAUDRATEPRESCALER=SPI_BAUDRATEPRESCALER_8,
//		.IRQ_Enable=SPI_IRQ_Enable_NONE,
//		.P_IRQ_CallBack = NULL
//};
//
//
//
///*	NSS PA4 Config "SLAVE Select pin"*/
//const GPIO_PINConfig_t spiNssPin = {
//		.GPIO_PinNumber = GPIO_PIN_4,
//		.GPIO_MODE = GPIO_MODE_OUTPUT_PP,
//		.GPIO_Output_Speed = GPIO_SPEED_10M
//};
