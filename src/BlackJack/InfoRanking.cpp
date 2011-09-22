/*
 * InfoRanking.cpp
 *
 *  Created on: 22/09/2011
 *      Author: Arthur Holanda
 */

#include "BlackJack/InfoRanking.h"

InfoRanking::InfoRanking() {
	this->nome = "-";
	this->pontuacao = 0;
	this->vitorias = 0;
}

void InfoRanking::Construct(String nome, int pontuacao, int vitorias) {
	this->nome = nome;
	this->pontuacao = pontuacao;
	this->vitorias = vitorias;
}

InfoRanking::InfoRanking(String nome, int pontuacao, int vitorias) {
	this->nome = nome;
	this->pontuacao = pontuacao;
	this->vitorias = vitorias;
}

InfoRanking::~InfoRanking() {}

String InfoRanking::GetNome() {
	return this->nome;
}

int InfoRanking::GetVitorias() {
	return this->vitorias;
}

int InfoRanking::GetPontos() {
	return this->pontuacao;
}
