################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/tinyxml2/tinyxml2.cpp 

OBJS += \
./Sources/tinyxml2/tinyxml2.o 

CPP_DEPS += \
./Sources/tinyxml2/tinyxml2.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/tinyxml2/%.o: ../Sources/tinyxml2/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


