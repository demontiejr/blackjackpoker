/*
 * JogadorPessoa.cpp
 *
 *  Created on: 25/09/2011
 *      Author: Arthur Holanda
 */

#include "BlackJack/JogadorPessoa.h"

JogadorPessoa::JogadorPessoa() {
}

JogadorPessoa::~JogadorPessoa() {
}

void JogadorPessoa::TerminouJogada() {
	if(controlador != null)
		controlador->FimJogadaJogador();
	else
		AppLog("[ERRO] Controlador nulo!");
}

void JogadorPessoa::Jogar() {} // a jogada do jogador é feita manualmente pela interface gráfica

