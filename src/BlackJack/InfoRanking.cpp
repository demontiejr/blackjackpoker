/*
 * InfoRanking.cpp
 *
 *  Created on: 22/09/2011
 *      Author: Arthur Holanda
 */

#include "BlackJack/InfoRanking.h"

InfoRanking::InfoRanking() {
	this->nome = "";
	nome.Append("      -");
	this->pontuacao = 0;
}

void InfoRanking::Construct(String nome, int pontuacao) {
	this->nome = nome;
	this->pontuacao = pontuacao;
}

InfoRanking::InfoRanking(String nome, int pontuacao) {
	this->nome = nome;
	this->pontuacao = pontuacao;
}

InfoRanking::~InfoRanking() {}

String InfoRanking::GetNome() {
	return this->nome;
}

int InfoRanking::GetPontos() {
	return this->pontuacao;
}

String InfoRanking::ToString() {
	String result =  "    " + nome;

	int length = result.GetLength();
	for (int i = length; i <= 30; i++){
		result.Append(" ");
	}

	result.Append(this->pontuacao);
	return result;
}
