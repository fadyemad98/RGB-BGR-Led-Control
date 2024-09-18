################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/RCC_DRIVER/STM32_F103C6_RCC_Driver.c 

OBJS += \
./MCAL/RCC_DRIVER/STM32_F103C6_RCC_Driver.o 

C_DEPS += \
./MCAL/RCC_DRIVER/STM32_F103C6_RCC_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/RCC_DRIVER/STM32_F103C6_RCC_Driver.o: ../MCAL/RCC_DRIVER/STM32_F103C6_RCC_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/fadye/Desktop/Final_Project_Master/MCAL/Inc" -I../Inc -I"C:/Users/fadye/Desktop/Final_Project_Master/HAL/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/RCC_DRIVER/STM32_F103C6_RCC_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

