################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OS/KERNEL_programe.c 

OBJS += \
./OS/KERNEL_programe.o 

C_DEPS += \
./OS/KERNEL_programe.d 


# Each subdirectory must supply rules for building sources it contributes
OS/KERNEL_programe.o: ../OS/KERNEL_programe.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/fadye/Desktop/Final_Project_Master/MCAL/Inc" -I../Inc -I"C:/Users/fadye/Desktop/Final_Project_Master/HAL/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"OS/KERNEL_programe.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

