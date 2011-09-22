################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BlackJack/Form1.cpp \
../src/BlackJack/FormInstrucoes.cpp \
../src/BlackJack/FormMenu.cpp \
../src/BlackJack/FormMgr.cpp \
../src/BlackJack/FormRanking.cpp \
../src/BlackJack/InfoRanking.cpp \
../src/BlackJack/Ranking.cpp \
../src/BlackJack/blackjackpoker.cpp \
../src/BlackJack/blackjackpokerEntry.cpp 

OBJS += \
./src/BlackJack/Form1.o \
./src/BlackJack/FormInstrucoes.o \
./src/BlackJack/FormMenu.o \
./src/BlackJack/FormMgr.o \
./src/BlackJack/FormRanking.o \
./src/BlackJack/InfoRanking.o \
./src/BlackJack/Ranking.o \
./src/BlackJack/blackjackpoker.o \
./src/BlackJack/blackjackpokerEntry.o 

CPP_DEPS += \
./src/BlackJack/Form1.d \
./src/BlackJack/FormInstrucoes.d \
./src/BlackJack/FormMenu.d \
./src/BlackJack/FormMgr.d \
./src/BlackJack/FormRanking.d \
./src/BlackJack/InfoRanking.d \
./src/BlackJack/Ranking.d \
./src/BlackJack/blackjackpoker.d \
./src/BlackJack/blackjackpokerEntry.d 


# Each subdirectory must supply rules for building sources it contributes
src/BlackJack/%.o: ../src/BlackJack/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.1.0b1/include" -I"C:/bada/1.1.0b1/IDE/workspace/blackjackpoker/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.1.0b1/include" -I"C:/bada/1.1.0b1/IDE/workspace/blackjackpoker/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.1.0b1/IDE/workspace/repository/blackjackpoker/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


