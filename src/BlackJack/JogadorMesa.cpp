/*
 * JogadorMesa.cpp
 *
 *  Created on: 25/09/2011
 *      Author: Arthur Holanda
 */

#include "BlackJack/JogadorMesa.h"

JogadorMesa::JogadorMesa() {
	// TODO Auto-generated constructor stub
}

JogadorMesa::~JogadorMesa() {
	// TODO Auto-generated destructor stub
}

void JogadorMesa::Jogar() {
	//TODO -implementar forma de jogar da mesa
}

void JogadorMesa::TerminouJogada() {
	if(controlador != null)
		controlador->FimJogadaMesa();
	else
		AppLog("[ERRO] Controlador nulo!");
}
