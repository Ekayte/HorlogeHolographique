################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/bsp/VL53L0X/X-NUCLEO-53L0A1.c \
../lib/bsp/VL53L0X/vl53_demo.c \
../lib/bsp/VL53L0X/vl53l0a1-f103msp.c \
../lib/bsp/VL53L0X/vl53l0x_api.c \
../lib/bsp/VL53L0X/vl53l0x_api_calibration.c \
../lib/bsp/VL53L0X/vl53l0x_api_core.c \
../lib/bsp/VL53L0X/vl53l0x_api_ranging.c \
../lib/bsp/VL53L0X/vl53l0x_api_strings.c \
../lib/bsp/VL53L0X/vl53l0x_platform.c \
../lib/bsp/VL53L0X/vl53l0x_platform_log.c 

OBJS += \
./lib/bsp/VL53L0X/X-NUCLEO-53L0A1.o \
./lib/bsp/VL53L0X/vl53_demo.o \
./lib/bsp/VL53L0X/vl53l0a1-f103msp.o \
./lib/bsp/VL53L0X/vl53l0x_api.o \
./lib/bsp/VL53L0X/vl53l0x_api_calibration.o \
./lib/bsp/VL53L0X/vl53l0x_api_core.o \
./lib/bsp/VL53L0X/vl53l0x_api_ranging.o \
./lib/bsp/VL53L0X/vl53l0x_api_strings.o \
./lib/bsp/VL53L0X/vl53l0x_platform.o \
./lib/bsp/VL53L0X/vl53l0x_platform_log.o 

C_DEPS += \
./lib/bsp/VL53L0X/X-NUCLEO-53L0A1.d \
./lib/bsp/VL53L0X/vl53_demo.d \
./lib/bsp/VL53L0X/vl53l0a1-f103msp.d \
./lib/bsp/VL53L0X/vl53l0x_api.d \
./lib/bsp/VL53L0X/vl53l0x_api_calibration.d \
./lib/bsp/VL53L0X/vl53l0x_api_core.d \
./lib/bsp/VL53L0X/vl53l0x_api_ranging.d \
./lib/bsp/VL53L0X/vl53l0x_api_strings.d \
./lib/bsp/VL53L0X/vl53l0x_platform.d \
./lib/bsp/VL53L0X/vl53l0x_platform_log.d 


# Each subdirectory must supply rules for building sources it contributes
lib/bsp/VL53L0X/%.o: ../lib/bsp/VL53L0X/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32F1 -DNUCLEO_F103RB -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp/MPU6050" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp/iks01a1" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp/iks01a1/Common" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp/iks01a1/hts221" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp/iks01a1/lis3mdl" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp/iks01a1/lps22hb" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp/iks01a1/lps25hb" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp/iks01a1/lsm6ds0" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp/iks01a1/lsm6ds3" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp/tft_ili9341" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp/tft_pcd8544" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp/MCP23S17" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/hal/inc" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp/Common" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp/lcd2x16" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp/MLX90614" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp/MatrixKeyboard" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/bsp/MatrixLed" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/CMSIS/core" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/CMSIS/device" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/middleware/FatFs" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/middleware/FatFs/src" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/lib/middleware/FatFs/src/drivers" -I"Z:/B2/ProjetEON/VentilateurHolographique/Projet/soft/appli"  -Og -g3 -Wall -Wextra -Wconversion -fmessage-length=0 -ffunction-sections -fdata-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


