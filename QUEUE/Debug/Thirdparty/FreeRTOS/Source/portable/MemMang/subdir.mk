################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Thirdparty/FreeRTOS/Source/portable/MemMang/heap_4.c 

OBJS += \
./Thirdparty/FreeRTOS/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./Thirdparty/FreeRTOS/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Thirdparty/FreeRTOS/Source/portable/MemMang/%.o Thirdparty/FreeRTOS/Source/portable/MemMang/%.su: ../Thirdparty/FreeRTOS/Source/portable/MemMang/%.c Thirdparty/FreeRTOS/Source/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/RTG3KOR/STM32CubeIDE/RTOSFINAL/QUEUE/Thirdparty/FreeRTOS" -I"C:/Users/RTG3KOR/STM32CubeIDE/RTOSFINAL/QUEUE/Thirdparty/FreeRTOS/Source/include" -I"C:/Users/RTG3KOR/STM32CubeIDE/RTOSFINAL/QUEUE/Thirdparty/FreeRTOS/Source/portable/GCC/ARM_CM4F" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Thirdparty-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang

clean-Thirdparty-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang:
	-$(RM) ./Thirdparty/FreeRTOS/Source/portable/MemMang/heap_4.d ./Thirdparty/FreeRTOS/Source/portable/MemMang/heap_4.o ./Thirdparty/FreeRTOS/Source/portable/MemMang/heap_4.su

.PHONY: clean-Thirdparty-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang

