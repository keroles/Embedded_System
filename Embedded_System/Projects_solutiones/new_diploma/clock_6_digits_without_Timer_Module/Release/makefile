################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
clock_6_digits.lss \

FLASH_IMAGE += \
clock_6_digits.hex \

EEPROM_IMAGE += \
clock_6_digits.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: clock_6_digits.elf secondary-outputs

# Tool invocations
clock_6_digits.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,clock_6_digits.map -mmcu=atmega32 -o "clock_6_digits.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

clock_6_digits.lss: clock_6_digits.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S clock_6_digits.elf  >"clock_6_digits.lss"
	@echo 'Finished building: $@'
	@echo ' '

clock_6_digits.hex: clock_6_digits.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex clock_6_digits.elf  "clock_6_digits.hex"
	@echo 'Finished building: $@'
	@echo ' '

clock_6_digits.eep: clock_6_digits.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex clock_6_digits.elf  "clock_6_digits.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: clock_6_digits.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 clock_6_digits.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) clock_6_digits.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
