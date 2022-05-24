################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include lib/hal/src/Legacy/subdir.mk
-include lib/hal/src/subdir.mk
-include lib/bsp/tft_ili9341/subdir.mk
-include lib/bsp/iks01a1/lsm6ds3/subdir.mk
-include lib/bsp/iks01a1/lsm6ds0/subdir.mk
-include lib/bsp/iks01a1/lps25hb/subdir.mk
-include lib/bsp/iks01a1/lps22hb/subdir.mk
-include lib/bsp/iks01a1/lis3mdl/subdir.mk
-include lib/bsp/iks01a1/hts221/subdir.mk
-include lib/bsp/iks01a1/subdir.mk
-include lib/bsp/VL53L0X/subdir.mk
-include lib/bsp/SEN0188_Fingerprint/subdir.mk
-include lib/bsp/MatrixLed/subdir.mk
-include lib/bsp/MPU6050/subdir.mk
-include lib/bsp/MCP23017/subdir.mk
-include lib/bsp/HC-SR04/subdir.mk
-include lib/bsp/GPS/subdir.mk
-include lib/bsp/subdir.mk
-include lib/subdir.mk
-include appli/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: soft.elf

# Tool invocations
soft.elf: $(OBJS) $(USER_OBJS) ../lib/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -u_printf_float -T"../lib/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "soft.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "soft.elf" "soft.bin"
	arm-none-eabi-size "soft.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
