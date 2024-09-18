/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Fady Emad
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/*
 * Created: 15/9/2024 6:19:28 PM
 * Author : Fady Emad
 */

typedef enum Buttom_status{
	Idle,
	NoPress,
	PB1_Press,
	PB2_Press,
	TwoPress,
	Error
}Buttom_status_t;

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F103x6.h"

/* MCAL */
#include "STM32_F103C6_GPIO_Driver.h"
#include "STM32_F103C6_SPI_Driver.h"
#include "STM32_F103C6_USART_Driver.h"
#include "STM32_F103C6_SYSTICK_DRIVER.h"
#include "Timer.h"
#include "PB_interface.h"

/* RTOS STACK */
#include "KERNEL_interface.h"
/* MACROS */
#define PB1		GPIO_PIN_1
#define PB2		GPIO_PIN_2

/* GLOBAL Variables */
volatile u8 PB1_Flag = Idle;
volatile u8 PB2_Flag = Idle;
u8 ch= Idle;
u8 ch_temp= Idle;
u8 LastProcess;
u8 lastMessage = Idle;


/* PROTOTYPES */
void init(void);
void Read_Button_State(void);
void SPI_Send_Message(void);
void Uart_Send_State(void);



/* GLOBAL Functions */



int main(void)
{
	/* Replace with your application code */
	init();
	RTOS_createTask(0,50,&Read_Button_State);
	RTOS_createTask(1,50,&SPI_Send_Message);
	//	RTOS_createTask(2,50,&Uart_Send_State);
	RTOS_start();
	while (1)
	{
	}
}


void Read_Button_State(void){
	u8 retval1=0,retval2=0;
	PB2_Flag = 0 ;
	PB1_Flag = 0;

	/**********		PB2 check		*************/
	if(MCAL_GPIO_ReadPin(GPIOA, PB2)){
		dms(20);
		if(MCAL_GPIO_ReadPin(GPIOA, PB2)){
			retval2 = PB2_Press;
		}else {
			retval2 = NoPress;
		}
	}else {
		retval2 = NoPress;
	}
	PB2_Flag = retval2;
	//if(HAL_button_u8read(GPIOA, PB2)==1){
	//	dms(20);
	//	if(HAL_button_u8read(GPIOA, PB2)==1){
	//		retval2 = PB2_Press;
	//		}else {
	//			retval2 = NoPress;
	//		}
	//	}else {
	//		retval2 = NoPress;
	//	}
	//	PB2_Flag = retval2;

	/**********		PB1 check		*************/
	if(HAL_button_u8read(GPIOA, PB1)){
		dms(20);
		if(HAL_button_u8read(GPIOA, PB1)){
			retval1 = PB1_Press;
		}else {
			retval1 = NoPress;
		}
	}else {
		retval1 = NoPress;
	}
	PB1_Flag = retval1;



}

void SPI_Send_Message(void)
{
	if (PB1_Flag == PB1_Press && PB2_Flag == PB2_Press) {
		ch= TwoPress;
	} else if(PB1_Flag == PB1_Press ) {
		ch= PB1_Press;
	}else if (PB2_Flag == PB2_Press) {
		ch= PB2_Press;
	}else{
		ch=NoPress;
	}
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	ch_temp = ch;
	Uart_Send_State();
	MCAL_SPI_SendData(SPI1, &ch, Pollingenable);
	//	MCAL_SPI_TX_RX(SPI1, &ch, Pollingenable);
	//set NSS pin from GPIO
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
	//ch = ch_temp;
}

void Uart_Send_State(void)
{	u8 Message[10];
	ch = ch_temp;
	switch (lastMessage) {
			case 'A':
				lastMessage = PB1_Press;
				break;
			case 'B':
				lastMessage = PB2_Press;
				break;
			case 'C':
				lastMessage = TwoPress;
				break;
			case 'F':
				lastMessage = NoPress;
				break;
			default:
				break;
	}
	if (lastMessage == ch) {

	} else {
		//send new
		switch (ch) {
		case PB1_Press:
			ch = 'A';
			break;
		case PB2_Press:
			ch = 'B';
			break;
		case TwoPress:
			ch = 'C';
			break;
		case NoPress:
			ch = 'F';
			break;
		default:
			break;
		}
		MCAL_UART_SendData(USART1, &ch, enable);
		//save new
		lastMessage = ch;
	}
}


void init(void){
	/* Enable clock for GPIOA*/
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	/* Init Push Buttons PA1 & PA2 as input floating */
	HAL_button_vInit(GPIOA, &PB1config);
	//HAL_button_vInit(GPIOA, &PB2config);
	GPIO_PINConfig_t PB_A2;
	PB_A2.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	PB_A2.GPIO_PinNumber = GPIO_PIN_2;
	MCAL_GPIO_Init(GPIOA, &PB_A2);

	/* Systick Init*/
	MCAL_SYSTICK_Init(&SystickConfig);

	/* Timer2 Init*/
	Timer2_init();

	/* Uart1 Init*/
	//PA9	TX
	//PA10	RX
	//PA11	CTS
	//PA12	RTS
	UART_Config uartCFG;
	uartCFG.BaudRate = UART_BaudRate_115200;
	uartCFG.HwFlowCtl = UART_HwFlowCtl_NONE;
	uartCFG.Parity = UART_Parity__NONE;
	uartCFG.Payload_Length = UART_Payload_Length_8B;
	uartCFG.StopBits = UART_StopBits__1;
	uartCFG.USART_Mode = UART_MODE_TX_RX;
	uartCFG.IRQ_Enable = UART_IRQ_Enable_NONE;	//when RXNEIE is set go to irq handler to receive(read data from register)
	uartCFG.P_IRQ_CallBack = NULL ;    // address of function without brackets!!!!!!
	MCAL_UART_Init(USART1,&uartCFG);
	MCAL_UART_GPIO_Set_Pins(USART1);

	/*************** SPI1 Init ********************/
	//PA4	NSS
	//PA5	SCK
	//PA6	MISO
	//PA7	MOSI
	SPI_Config_t SPI1CFG;
	GPIO_PINConfig_t PinCnfg;
	//Common Configuration between master and slave
	SPI1CFG.CLKPhase 			  =	SPI_Clock_Phase_2EDGE_first_data_capture_edge;
	SPI1CFG.CLKPolarity			  =	SPI_CLKPolarity_HIGH_when_idle;
	SPI1CFG.DataSize 			  =	SPI_DataSize_8BIT;
	SPI1CFG.Frame_Format		  =	SPI_Frame_Format_MSB_transmitted_first;
	//assume pclk2 8MHZ by default (NOT MODIFIED)
	SPI1CFG.SPI_BAUDRATEPRESCALER =	SPI_BAUDRATEPRESCALER_8;
	SPI1CFG.Communication_Mode    =	SPI_DIRECTION_2LINES;
	SPI1CFG.Device_Mode		  = SPI_Device_Mode_MASTER;
	SPI1CFG.IRQ_Enable	      = SPI_IRQ_Enable_NONE;
	SPI1CFG.NSS	              = SPI_NSS_Soft_NSSInternalSoft_Set;		//you are the only master on the bus
	SPI1CFG.P_IRQ_CallBack	  = NULL;
	MCAL_SPI_Init(SPI1, &SPI1CFG);
	MCAL_SPI_GPIO_Set_Pins(SPI1);
	/*	Configure slave PA4		*/
	PinCnfg.GPIO_PinNumber 	  = GPIO_PIN_4;
	PinCnfg.GPIO_MODE		  = GPIO_MODE_OUTPUT_PP;
	PinCnfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &PinCnfg);
	//Force slave select pin high
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
}
