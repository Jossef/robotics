################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Behaviors/Behavior.cpp \
../Behaviors/GoForward.cpp \
../Behaviors/GoLeft.cpp \
../Behaviors/GoRandomDirection.cpp \
../Behaviors/GoRight.cpp 

OBJS += \
./Behaviors/Behavior.o \
./Behaviors/GoForward.o \
./Behaviors/GoLeft.o \
./Behaviors/GoRandomDirection.o \
./Behaviors/GoRight.o 

CPP_DEPS += \
./Behaviors/Behavior.d \
./Behaviors/GoForward.d \
./Behaviors/GoLeft.d \
./Behaviors/GoRandomDirection.d \
./Behaviors/GoRight.d 


# Each subdirectory must supply rules for building sources it contributes
Behaviors/%.o: ../Behaviors/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


