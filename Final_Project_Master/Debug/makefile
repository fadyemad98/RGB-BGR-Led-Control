################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include OS/subdir.mk
-include MCAL/USART_DRIVER/subdir.mk
-include MCAL/TIMER_DRIVER/subdir.mk
-include MCAL/SYSTICK_DRIVER/subdir.mk
-include MCAL/SPI_DRIVER/subdir.mk
-include MCAL/RCC_DRIVER/subdir.mk
-include MCAL/GPIO/subdir.mk
-include HAL/PB/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Final_Project_Master.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Final_Project_Master.list \

OBJCOPY_HEX += \
Final_Project_Master.hex \

OBJCOPY_BIN += \
Final_Project_Master.bin \


# All Target
all: Final_Project_Master.elf secondary-outputs

# Tool invocations
Final_Project_Master.elf: $(OBJS) $(USER_OBJS) C:\Users\fadye\Desktop\Final_Project_Master\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "Final_Project_Master.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\fadye\Desktop\Final_Project_Master\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Final_Project_Master.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Final_Project_Master.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Final_Project_Master.list"
	@echo 'Finished building: $@'
	@echo ' '

Final_Project_Master.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Final_Project_Master.hex"
	@echo 'Finished building: $@'
	@echo ' '

Final_Project_Master.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Final_Project_Master.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
