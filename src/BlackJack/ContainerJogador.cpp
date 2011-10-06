/*
 * ContainerJogador.cpp
 * Created on: 05/10/2011
 * Author: Catharine
 */

#include "BlackJack/ContainerJogador.h"

ContainerJogador::ContainerJogador() {
}

ContainerJogador::~ContainerJogador() {
}

void ContainerJogador::SetJogador(JogadorPessoa* j) {
	this.jogador = j;
}

JogadorPessoa* ContainerJogador::GetJogador() {
	return jogador;
}

ContainerJogador* ContainerJogador::GetInstance() {
	if (containerJ == null) {
		containerJ = new ContainerJogador();
	}
	return containerJ;
}
