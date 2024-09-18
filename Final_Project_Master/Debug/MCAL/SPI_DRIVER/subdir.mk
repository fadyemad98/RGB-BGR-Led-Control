################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/SPI_DRIVER/STM32_F103C6_SPI_Config.c \
../MCAL/SPI_DRIVER/STM32_F103C6_SPI_Driver.c 

OBJS += \
./MCAL/SPI_DRIVER/STM32_F103C6_SPI_Config.o \
./MCAL/SPI_DRIVER/STM32_F103C6_SPI_Driver.o 

C_DEPS += \
./MCAL/SPI_DRIVER/STM32_F103C6_SPI_Config.d \
./MCAL/SPI_DRIVER/STM32_F103C6_SPI_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/SPI_DRIVER/STM32_F103C6_SPI_Config.o: ../MCAL/SPI_DRIVER/STM32_F103C6_SPI_Config.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/fadye/Desktop/Final_Project_Master/MCAL/Inc" -I../Inc -I"C:/Users/fadye/Desktop/Final_Project_Master/HAL/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/SPI_DRIVER/STM32_F103C6_SPI_Config.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/SPI_DRIVER/STM32_F103C6_SPI_Driver.o: ../MCAL/SPI_DRIVER/STM32_F103C6_SPI_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/fadye/Desktop/Final_Project_Master/MCAL/Inc" -I../Inc -I"C:/Users/fadye/Desktop/Final_Project_Master/HAL/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/Inc" -I"C:/Users/fadye/Desktop/Final_Project_Master/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/SPI_DRIVER/STM32_F103C6_SPI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

