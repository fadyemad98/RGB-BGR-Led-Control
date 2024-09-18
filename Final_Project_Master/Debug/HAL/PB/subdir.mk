################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/PB/PB_config.c \
../HAL/PB/PB_program.c 

OBJS += \
./HAL/PB/PB_config.o \
./HAL/PB/PB_program.o 

C_DEPS += \
./HAL/PB/PB_config.d \
./HAL/PB/PB_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/PB/PB_config.o: ../HAL/PB/PB_config.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/fadye/Desktop/Final_Project_Master/MCAL/Inc" -I../Inc -I"C:/Users/fadye/Desktop/Final_Project_Master/HAL/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/PB/PB_config.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/PB/PB_program.o: ../HAL/PB/PB_program.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/fadye/Desktop/Final_Project_Master/MCAL/Inc" -I../Inc -I"C:/Users/fadye/Desktop/Final_Project_Master/HAL/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/PB/PB_program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

