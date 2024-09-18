################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIMER_DRIVER/Timer.c 

OBJS += \
./MCAL/TIMER_DRIVER/Timer.o 

C_DEPS += \
./MCAL/TIMER_DRIVER/Timer.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIMER_DRIVER/Timer.o: ../MCAL/TIMER_DRIVER/Timer.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/fadye/Desktop/Final_Project_Master/MCAL/Inc" -I../Inc -I"C:/Users/fadye/Desktop/Final_Project_Master/HAL/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/TIMER_DRIVER/Timer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

