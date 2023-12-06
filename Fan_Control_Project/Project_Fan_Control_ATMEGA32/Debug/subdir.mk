################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App.c \
../Gpio.c \
../Lcd.c \
../Lm35_Sensor.c \
../adc.c \
../dcmotor.c \
../pwm_driver.c 

OBJS += \
./App.o \
./Gpio.o \
./Lcd.o \
./Lm35_Sensor.o \
./adc.o \
./dcmotor.o \
./pwm_driver.o 

C_DEPS += \
./App.d \
./Gpio.d \
./Lcd.d \
./Lm35_Sensor.d \
./adc.d \
./dcmotor.d \
./pwm_driver.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


