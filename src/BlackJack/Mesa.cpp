/*
 * Mesa.cpp
 *
 *  Created on: 05/10/2011
 *      Author: Arthur Holanda
 */

#include "BlackJack/Mesa.h"

Mesa::Mesa() {}

Mesa::~Mesa() {
	// TODO Auto-generated destructor stub
}

void Mesa::IniciarPartida() {
	this->mao->LimparMao();
}

void Mesa::Jogar() {
}

void Mesa::TerminouJogada() {
}

void Mesa::SetControlador(Controlador *controlador) {
	this->controlador = controlador;
}

void Mesa::PuxarCarta() {
	Carta* c = this->controlador->GetBaralho()->DarCarta();
	this->mao->PegarCarta(c);
}

void Mesa::Parar() {
}

Mao *Mesa::GetMao() {
	return this->mao;
}

void Mesa::Construct() {
	this->mao = new Mao();
}

