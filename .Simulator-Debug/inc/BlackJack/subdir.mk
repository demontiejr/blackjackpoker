################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../inc/BlackJack/SmartTimer.cpp 

OBJS += \
./inc/BlackJack/SmartTimer.o 

CPP_DEPS += \
./inc/BlackJack/SmartTimer.d 


# Each subdirectory must supply rules for building sources it contributes
inc/BlackJack/%.o: ../inc/BlackJack/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.1.0b1/include" -I"C:/bada/1.1.0b1/IDE/workspace/blackjackpoker/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.1.0b1/include" -I"C:/bada/1.1.0b1/IDE/workspace/blackjackpoker/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.1.0b1/IDE/workspace/repository/blackjackpoker/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


