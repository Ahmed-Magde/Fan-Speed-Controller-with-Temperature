################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../dc_motor.c \
../gpio.c \
../lcd_driver.c \
../lm35.c \
../mini_project3.c \
../pwm.c 

OBJS += \
./adc.o \
./dc_motor.o \
./gpio.o \
./lcd_driver.o \
./lm35.o \
./mini_project3.o \
./pwm.o 

C_DEPS += \
./adc.d \
./dc_motor.d \
./gpio.d \
./lcd_driver.d \
./lm35.d \
./mini_project3.d \
./pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


