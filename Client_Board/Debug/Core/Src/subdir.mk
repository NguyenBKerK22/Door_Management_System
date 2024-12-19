################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/MFRC522.c \
../Core/Src/button_processing.c \
../Core/Src/buttons_control_block.c \
../Core/Src/door_control_block.c \
../Core/Src/door_management_system.c \
../Core/Src/global.c \
../Core/Src/i2c_lcd.c \
../Core/Src/keypad.c \
../Core/Src/lcd_control_block.c \
../Core/Src/list_person.c \
../Core/Src/main.c \
../Core/Src/password.c \
../Core/Src/queue.c \
../Core/Src/rfid_control_block.c \
../Core/Src/rgb_control_block.c \
../Core/Src/rtc_control_block.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/timer.c 

OBJS += \
./Core/Src/MFRC522.o \
./Core/Src/button_processing.o \
./Core/Src/buttons_control_block.o \
./Core/Src/door_control_block.o \
./Core/Src/door_management_system.o \
./Core/Src/global.o \
./Core/Src/i2c_lcd.o \
./Core/Src/keypad.o \
./Core/Src/lcd_control_block.o \
./Core/Src/list_person.o \
./Core/Src/main.o \
./Core/Src/password.o \
./Core/Src/queue.o \
./Core/Src/rfid_control_block.o \
./Core/Src/rgb_control_block.o \
./Core/Src/rtc_control_block.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/timer.o 

C_DEPS += \
./Core/Src/MFRC522.d \
./Core/Src/button_processing.d \
./Core/Src/buttons_control_block.d \
./Core/Src/door_control_block.d \
./Core/Src/door_management_system.d \
./Core/Src/global.d \
./Core/Src/i2c_lcd.d \
./Core/Src/keypad.d \
./Core/Src/lcd_control_block.d \
./Core/Src/list_person.d \
./Core/Src/main.d \
./Core/Src/password.d \
./Core/Src/queue.d \
./Core/Src/rfid_control_block.d \
./Core/Src/rgb_control_block.d \
./Core/Src/rtc_control_block.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/MFRC522.cyclo ./Core/Src/MFRC522.d ./Core/Src/MFRC522.o ./Core/Src/MFRC522.su ./Core/Src/button_processing.cyclo ./Core/Src/button_processing.d ./Core/Src/button_processing.o ./Core/Src/button_processing.su ./Core/Src/buttons_control_block.cyclo ./Core/Src/buttons_control_block.d ./Core/Src/buttons_control_block.o ./Core/Src/buttons_control_block.su ./Core/Src/door_control_block.cyclo ./Core/Src/door_control_block.d ./Core/Src/door_control_block.o ./Core/Src/door_control_block.su ./Core/Src/door_management_system.cyclo ./Core/Src/door_management_system.d ./Core/Src/door_management_system.o ./Core/Src/door_management_system.su ./Core/Src/global.cyclo ./Core/Src/global.d ./Core/Src/global.o ./Core/Src/global.su ./Core/Src/i2c_lcd.cyclo ./Core/Src/i2c_lcd.d ./Core/Src/i2c_lcd.o ./Core/Src/i2c_lcd.su ./Core/Src/keypad.cyclo ./Core/Src/keypad.d ./Core/Src/keypad.o ./Core/Src/keypad.su ./Core/Src/lcd_control_block.cyclo ./Core/Src/lcd_control_block.d ./Core/Src/lcd_control_block.o ./Core/Src/lcd_control_block.su ./Core/Src/list_person.cyclo ./Core/Src/list_person.d ./Core/Src/list_person.o ./Core/Src/list_person.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/password.cyclo ./Core/Src/password.d ./Core/Src/password.o ./Core/Src/password.su ./Core/Src/queue.cyclo ./Core/Src/queue.d ./Core/Src/queue.o ./Core/Src/queue.su ./Core/Src/rfid_control_block.cyclo ./Core/Src/rfid_control_block.d ./Core/Src/rfid_control_block.o ./Core/Src/rfid_control_block.su ./Core/Src/rgb_control_block.cyclo ./Core/Src/rgb_control_block.d ./Core/Src/rgb_control_block.o ./Core/Src/rgb_control_block.su ./Core/Src/rtc_control_block.cyclo ./Core/Src/rtc_control_block.d ./Core/Src/rtc_control_block.o ./Core/Src/rtc_control_block.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/timer.cyclo ./Core/Src/timer.d ./Core/Src/timer.o ./Core/Src/timer.su

.PHONY: clean-Core-2f-Src

