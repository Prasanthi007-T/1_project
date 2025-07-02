################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Thirdparty/FreeRTOS/Source/croutine.c \
../Thirdparty/FreeRTOS/Source/event_groups.c \
../Thirdparty/FreeRTOS/Source/list.c \
../Thirdparty/FreeRTOS/Source/queue.c \
../Thirdparty/FreeRTOS/Source/stream_buffer.c \
../Thirdparty/FreeRTOS/Source/tasks.c \
../Thirdparty/FreeRTOS/Source/timers.c 

OBJS += \
./Thirdparty/FreeRTOS/Source/croutine.o \
./Thirdparty/FreeRTOS/Source/event_groups.o \
./Thirdparty/FreeRTOS/Source/list.o \
./Thirdparty/FreeRTOS/Source/queue.o \
./Thirdparty/FreeRTOS/Source/stream_buffer.o \
./Thirdparty/FreeRTOS/Source/tasks.o \
./Thirdparty/FreeRTOS/Source/timers.o 

C_DEPS += \
./Thirdparty/FreeRTOS/Source/croutine.d \
./Thirdparty/FreeRTOS/Source/event_groups.d \
./Thirdparty/FreeRTOS/Source/list.d \
./Thirdparty/FreeRTOS/Source/queue.d \
./Thirdparty/FreeRTOS/Source/stream_buffer.d \
./Thirdparty/FreeRTOS/Source/tasks.d \
./Thirdparty/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Thirdparty/FreeRTOS/Source/%.o Thirdparty/FreeRTOS/Source/%.su: ../Thirdparty/FreeRTOS/Source/%.c Thirdparty/FreeRTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/RTG3KOR/STM32CubeIDE/RTOSFINAL/QUEUE/Thirdparty/FreeRTOS" -I"C:/Users/RTG3KOR/STM32CubeIDE/RTOSFINAL/QUEUE/Thirdparty/FreeRTOS/Source/include" -I"C:/Users/RTG3KOR/STM32CubeIDE/RTOSFINAL/QUEUE/Thirdparty/FreeRTOS/Source/portable/GCC/ARM_CM4F" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Thirdparty-2f-FreeRTOS-2f-Source

clean-Thirdparty-2f-FreeRTOS-2f-Source:
	-$(RM) ./Thirdparty/FreeRTOS/Source/croutine.d ./Thirdparty/FreeRTOS/Source/croutine.o ./Thirdparty/FreeRTOS/Source/croutine.su ./Thirdparty/FreeRTOS/Source/event_groups.d ./Thirdparty/FreeRTOS/Source/event_groups.o ./Thirdparty/FreeRTOS/Source/event_groups.su ./Thirdparty/FreeRTOS/Source/list.d ./Thirdparty/FreeRTOS/Source/list.o ./Thirdparty/FreeRTOS/Source/list.su ./Thirdparty/FreeRTOS/Source/queue.d ./Thirdparty/FreeRTOS/Source/queue.o ./Thirdparty/FreeRTOS/Source/queue.su ./Thirdparty/FreeRTOS/Source/stream_buffer.d ./Thirdparty/FreeRTOS/Source/stream_buffer.o ./Thirdparty/FreeRTOS/Source/stream_buffer.su ./Thirdparty/FreeRTOS/Source/tasks.d ./Thirdparty/FreeRTOS/Source/tasks.o ./Thirdparty/FreeRTOS/Source/tasks.su ./Thirdparty/FreeRTOS/Source/timers.d ./Thirdparty/FreeRTOS/Source/timers.o ./Thirdparty/FreeRTOS/Source/timers.su

.PHONY: clean-Thirdparty-2f-FreeRTOS-2f-Source

