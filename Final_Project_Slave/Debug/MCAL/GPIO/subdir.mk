################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GPIO/STM32_F103C6_GPIO_Driver.c 

OBJS += \
./MCAL/GPIO/STM32_F103C6_GPIO_Driver.o 

C_DEPS += \
./MCAL/GPIO/STM32_F103C6_GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GPIO/STM32_F103C6_GPIO_Driver.o: ../MCAL/GPIO/STM32_F103C6_GPIO_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/fadye/Desktop/Final_Project_Slave/MCAL/Inc" -I../Inc -I"C:/Users/fadye/Desktop/Final_Project_Slave/HAL/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Slave/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Slave/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/GPIO/STM32_F103C6_GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

