################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/Controleur.cpp \
../Sources/Etat.cpp \
../Sources/Parseur.cpp \
../Sources/Phenomene.cpp \
../Sources/Processus.cpp \
../Sources/Serveur.cpp \
../Sources/Simulation.cpp \
../Sources/main.cpp \
../Sources/xml_utils.cpp 

OBJS += \
./Sources/Controleur.o \
./Sources/Etat.o \
./Sources/Parseur.o \
./Sources/Phenomene.o \
./Sources/Processus.o \
./Sources/Serveur.o \
./Sources/Simulation.o \
./Sources/main.o \
./Sources/xml_utils.o 

CPP_DEPS += \
./Sources/Controleur.d \
./Sources/Etat.d \
./Sources/Parseur.d \
./Sources/Phenomene.d \
./Sources/Processus.d \
./Sources/Serveur.d \
./Sources/Simulation.d \
./Sources/main.d \
./Sources/xml_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


