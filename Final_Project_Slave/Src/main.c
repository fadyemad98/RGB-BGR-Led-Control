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
 *
 * Created: 15/9/2024 6:19:28 PM
 * Author : Fady Emad
 */

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
u8 ch,ch1;
u32 count=0;

/* MCAL */
#include "STM32_F103C6_GPIO_Driver.h"
#include "STM32_F103C6_SPI_Driver.h"
#include "STM32_F103C6_USART_Driver.h"
#include "STM32_F103C6_SYSTICK_DRIVER.h"


/* RTOS STACK */
#include "KERNEL_interface.h"

/* Macros */
#define LED_Red		GPIO_PIN_0
#define LED_Green	GPIO_PIN_1
#define LED_Blue	GPIO_PIN_2

/* GLOBAL Variables */
u8 ch,STATE;
typedef enum{
	NOPress,
	CW,
	CCW,
	_ERROR
}ProcessState_t;

typedef enum Receive{
	Ideal,
	NoPress,
	PB1_Press,
	PB2_Press,
	TwoPress,
	Error
}Receive_status_t;

/* PROTOTYPES */
void Init(void);
void LEDS_Proccess(void);
void SPIReceive(void);

int main(void)
{	Init();
/* Replace with your application code */
RTOS_createTask(0,5,&LEDS_Proccess);
RTOS_createTask(1,10,&SPIReceive);
RTOS_start();

while (1)
{
}
}

void LEDS_Proccess(void){
	if (STATE == CW) {
		MCAL_GPIO_TogglePin(GPIOB, LED_Red);
		dms(1000);
		MCAL_GPIO_TogglePin(GPIOB, LED_Red);
		MCAL_GPIO_TogglePin(GPIOB, LED_Green);
		dms(1000);
		MCAL_GPIO_TogglePin(GPIOB, LED_Green);
		MCAL_GPIO_TogglePin(GPIOB, LED_Blue);
		dms(1000);
		MCAL_GPIO_TogglePin(GPIOB, LED_Blue);
	} else if (STATE == CCW) {
		MCAL_GPIO_TogglePin(GPIOB, LED_Blue);
		dms(1000);
		MCAL_GPIO_TogglePin(GPIOB, LED_Blue);
		MCAL_GPIO_TogglePin(GPIOB, LED_Green);
		dms(1000);
		MCAL_GPIO_TogglePin(GPIOB, LED_Green);
		MCAL_GPIO_TogglePin(GPIOB, LED_Red);
		dms(1000);
		MCAL_GPIO_TogglePin(GPIOB, LED_Red);
	}else{
		if (STATE == _ERROR ) {
			MCAL_GPIO_TogglePin(GPIOB, LED_Red);
			MCAL_GPIO_TogglePin(GPIOB, LED_Green);
			MCAL_GPIO_TogglePin(GPIOB, LED_Blue);
			dms(1000);
			MCAL_GPIO_TogglePin(GPIOB, LED_Red);
			MCAL_GPIO_TogglePin(GPIOB, LED_Green);
			MCAL_GPIO_TogglePin(GPIOB, LED_Blue);
		} else {
			if(count==10000){
				MCAL_GPIO_TogglePin(GPIOB, LED_Green);
							dms(1000);
							MCAL_GPIO_TogglePin(GPIOB, LED_Green);
			}

		}
	}


}


void Init(void){
	/* Enable clock for GPIOA*/
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	/* Init LEDS */
	GPIO_PINConfig_t LEDR,LEDG,LEDB;
	LEDR.GPIO_PinNumber =LED_Red;
	LEDR.GPIO_MODE =GPIO_MODE_OUTPUT_PP;
	LEDR.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &LEDR);
	MCAL_GPIO_WritePin(GPIOB, LED_Red, 0);


	LEDG.GPIO_PinNumber =LED_Green;
	LEDG.GPIO_MODE =GPIO_MODE_OUTPUT_PP;
	LEDG.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &LEDG);
	MCAL_GPIO_WritePin(GPIOB, LED_Green, 0);


	LEDB.GPIO_PinNumber =LED_Blue;
	LEDB.GPIO_MODE =GPIO_MODE_OUTPUT_PP;
	LEDB.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &LEDB);
	MCAL_GPIO_WritePin(GPIOB, LED_Blue, 0);

	/* Systick Init*/
	MCAL_SYSTICK_Init(&SystickConfig);

	/* Timer2 Init*/
	Timer2_init();
	/* Uart1 Init*/
	UART_Config uartCFG;
	//PA9	TX
	//PA10	RX
	//PA11	CTS
	//PA12	RTS
	uartCFG.BaudRate = UART_BaudRate_115200;
	uartCFG.HwFlowCtl = UART_HwFlowCtl_NONE;
	uartCFG.Parity = UART_Parity__NONE;
	uartCFG.Payload_Length = UART_Payload_Length_8B;
	uartCFG.StopBits = UART_StopBits__1;
	uartCFG.USART_Mode = UART_MODE_RX;
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
	SPI1CFG.Device_Mode		  	  = SPI_Device_Mode_SLAVE;
	SPI1CFG.IRQ_Enable	          = SPI_IRQ_Enable_NONE;
	SPI1CFG.NSS	                  = SPI_NSS_Hard_Slave;		//you are the only master on the bus
	SPI1CFG.P_IRQ_CallBack	      = NULL;
	MCAL_SPI_Init(SPI1, &SPI1CFG);
	MCAL_SPI_GPIO_Set_Pins(SPI1);
	//NSS Pin config
	PinCnfg.GPIO_PinNumber 	      = GPIO_PIN_4;
	PinCnfg.GPIO_MODE		      = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinCnfg);
}

void SPIReceive(void){

			MCAL_SPI_ReceiveData(SPI1, &ch, Pollingenable);
			switch (ch) {
			case PB1_Press:
				ch1 = 'A';
				count=0;
				break;
			case PB2_Press:
				ch1 = 'B';
				count=0;
				break;
			case TwoPress:
				ch1 = 'C';
				count=0;
				break;
			case NoPress:
				ch1 = 'F';
				count++;
				break;
			default:
				break;
			}
			MCAL_UART_SendData(USART1, &ch1, enable);
			if (ch == PB1_Press ) {
				STATE = CW;

			} else if(ch == PB2_Press ){
				STATE = CCW;

			}else if(ch == TwoPress){
				STATE = _ERROR;

			}else{
				STATE = NOPress;

			}

}





