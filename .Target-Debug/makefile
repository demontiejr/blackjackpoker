################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

REPOSITORY_ROOT := C:/bada/1.1.0b1/IDE/workspace/repository/blackjackpoker/Target-Debug

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/BlackJack/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: blackjackpoker.exe

# Tool invocations
blackjackpoker.exe: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: bada C++ Linker'
	@echo 'ldflags: -nostdlib -lc-newlib -lm-newlib -L"C:/bada/1.1.0b1/Model/WaveWQ_LP1/Target" -L"C:/bada/1.1.0b1/Tools/Toolchains/ARM/arm-samsung-nucleuseabi/lib" -L"C:/bada/1.1.0b1/Tools/Toolchains/ARM/lib/gcc/arm-samsung-nucleuseabi/4.4.1" -L"C:/bada/1.1.0b1/IDE/workspace/blackjackpoker/lib" -shared -o"blackjackpoker.exe" ./src/BlackJack/Baralho.o ./src/BlackJack/Carta.o ./src/BlackJack/Controlador.o ./src/BlackJack/Form1.o ./src/BlackJack/FormInstrucoes.o ./src/BlackJack/FormJogo.o ./src/BlackJack/FormMenu.o ./src/BlackJack/FormMgr.o ./src/BlackJack/FormRanking.o ./src/BlackJack/IListenerControlador.o ./src/BlackJack/InfoRanking.o ./src/BlackJack/Jogador.o ./src/BlackJack/JogadorMesa.o ./src/BlackJack/JogadorPessoa.o ./src/BlackJack/Mao.o ./src/BlackJack/Ranking.o ./src/BlackJack/blackjackpoker.o ./src/BlackJack/blackjackpokerEntry.o '
	arm-samsung-nucleuseabi-ld @ldflags @ldobjs  $(USER_OBJS) $(LIBS) -lstdc++ -lgcc_s
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(CXX_DEPS)$(C_UPPER_DEPS) blackjackpoker.exe $(REPOSITORY_ROOT)/*
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
