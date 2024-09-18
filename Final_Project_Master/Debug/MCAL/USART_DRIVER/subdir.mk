################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/USART_DRIVER/STM32_F103C6_USART_Config.c \
../MCAL/USART_DRIVER/STM32_F103C6_USART_Driver.c 

OBJS += \
./MCAL/USART_DRIVER/STM32_F103C6_USART_Config.o \
./MCAL/USART_DRIVER/STM32_F103C6_USART_Driver.o 

C_DEPS += \
./MCAL/USART_DRIVER/STM32_F103C6_USART_Config.d \
./MCAL/USART_DRIVER/STM32_F103C6_USART_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/USART_DRIVER/STM32_F103C6_USART_Config.o: ../MCAL/USART_DRIVER/STM32_F103C6_USART_Config.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/fadye/Desktop/Final_Project_Master/MCAL/Inc" -I../Inc -I"C:/Users/fadye/Desktop/Final_Project_Master/HAL/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/USART_DRIVER/STM32_F103C6_USART_Config.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/USART_DRIVER/STM32_F103C6_USART_Driver.o: ../MCAL/USART_DRIVER/STM32_F103C6_USART_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/fadye/Desktop/Final_Project_Master/MCAL/Inc" -I../Inc -I"C:/Users/fadye/Desktop/Final_Project_Master/HAL/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/USART_DRIVER/STM32_F103C6_USART_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

