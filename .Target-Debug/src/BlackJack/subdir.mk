################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BlackJack/Baralho.cpp \
../src/BlackJack/Carta.cpp \
../src/BlackJack/Controlador.cpp \
../src/BlackJack/Form1.cpp \
../src/BlackJack/FormInstrucoes.cpp \
../src/BlackJack/FormJogo.cpp \
../src/BlackJack/FormMenu.cpp \
../src/BlackJack/FormMgr.cpp \
../src/BlackJack/FormRanking.cpp \
../src/BlackJack/IListenerControlador.cpp \
../src/BlackJack/InfoRanking.cpp \
../src/BlackJack/Jogador.cpp \
../src/BlackJack/JogadorMesa.cpp \
../src/BlackJack/JogadorPessoa.cpp \
../src/BlackJack/Mao.cpp \
../src/BlackJack/Ranking.cpp \
../src/BlackJack/blackjackpoker.cpp \
../src/BlackJack/blackjackpokerEntry.cpp 

OBJS += \
./src/BlackJack/Baralho.o \
./src/BlackJack/Carta.o \
./src/BlackJack/Controlador.o \
./src/BlackJack/Form1.o \
./src/BlackJack/FormInstrucoes.o \
./src/BlackJack/FormJogo.o \
./src/BlackJack/FormMenu.o \
./src/BlackJack/FormMgr.o \
./src/BlackJack/FormRanking.o \
./src/BlackJack/IListenerControlador.o \
./src/BlackJack/InfoRanking.o \
./src/BlackJack/Jogador.o \
./src/BlackJack/JogadorMesa.o \
./src/BlackJack/JogadorPessoa.o \
./src/BlackJack/Mao.o \
./src/BlackJack/Ranking.o \
./src/BlackJack/blackjackpoker.o \
./src/BlackJack/blackjackpokerEntry.o 

CPP_DEPS += \
./src/BlackJack/Baralho.d \
./src/BlackJack/Carta.d \
./src/BlackJack/Controlador.d \
./src/BlackJack/Form1.d \
./src/BlackJack/FormInstrucoes.d \
./src/BlackJack/FormJogo.d \
./src/BlackJack/FormMenu.d \
./src/BlackJack/FormMgr.d \
./src/BlackJack/FormRanking.d \
./src/BlackJack/IListenerControlador.d \
./src/BlackJack/InfoRanking.d \
./src/BlackJack/Jogador.d \
./src/BlackJack/JogadorMesa.d \
./src/BlackJack/JogadorPessoa.d \
./src/BlackJack/Mao.d \
./src/BlackJack/Ranking.d \
./src/BlackJack/blackjackpoker.d \
./src/BlackJack/blackjackpokerEntry.d 


# Each subdirectory must supply rules for building sources it contributes
src/BlackJack/%.o: ../src/BlackJack/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"C:/bada/1.1.0b1/include" -I"C:/bada/1.1.0b1/IDE/workspace/blackjackpoker/inc" -O0 -g -Wall -c -fpic -fshort-wchar -mcpu=arm9 -mfloat-abi=soft -mlittle-endian -mthumb-interwork -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"C:/bada/1.1.0b1/include" -I"C:/bada/1.1.0b1/IDE/workspace/blackjackpoker/inc" -O0 -g -Wall -E -fpic -fshort-wchar -mcpu=arm9 -mfloat-abi=soft -mlittle-endian -mthumb-interwork -o"C:/bada/1.1.0b1/IDE/workspace/repository/blackjackpoker/Target-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


