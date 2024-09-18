################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/SYSTICK_DRIVER/STM32_F103C6_SYSTICK_Config.c \
../MCAL/SYSTICK_DRIVER/STM32_F103C6_SYSTICK_DRIVER.c 

OBJS += \
./MCAL/SYSTICK_DRIVER/STM32_F103C6_SYSTICK_Config.o \
./MCAL/SYSTICK_DRIVER/STM32_F103C6_SYSTICK_DRIVER.o 

C_DEPS += \
./MCAL/SYSTICK_DRIVER/STM32_F103C6_SYSTICK_Config.d \
./MCAL/SYSTICK_DRIVER/STM32_F103C6_SYSTICK_DRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/SYSTICK_DRIVER/STM32_F103C6_SYSTICK_Config.o: ../MCAL/SYSTICK_DRIVER/STM32_F103C6_SYSTICK_Config.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/fadye/Desktop/Final_Project_Slave/MCAL/Inc" -I../Inc -I"C:/Users/fadye/Desktop/Final_Project_Slave/HAL/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Slave/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Slave/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/SYSTICK_DRIVER/STM32_F103C6_SYSTICK_Config.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/SYSTICK_DRIVER/STM32_F103C6_SYSTICK_DRIVER.o: ../MCAL/SYSTICK_DRIVER/STM32_F103C6_SYSTICK_DRIVER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/fadye/Desktop/Final_Project_Slave/MCAL/Inc" -I../Inc -I"C:/Users/fadye/Desktop/Final_Project_Slave/HAL/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Slave/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Slave/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/SYSTICK_DRIVER/STM32_F103C6_SYSTICK_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

