/*
 * Mao.cpp
 *
 *  Created on: 22/09/2011
 *      Author: Junior
 */

#include "BlackJack/Mao.h"

using namespace Osp::Base;

Mao::Mao(){
	qtdCartas = 0;
	status = 0;
}

Mao::~Mao() {
	// TODO Auto-generated destructor stub
}

void Mao::pegarCarta(Carta &c)
{
	cartas[qtdCartas] = c;
	qtdCartas++;
}


bool Mao::estourou()
{
	return getValor() > 21;
}

int Mao::getStatus()
{
	return status;
}

void Mao::setStatus(int status)
{
	this->status = status;
}

String Mao::mostrarMao()
{
	String show = "Pontos: " + Integer::ToString(getValor());

	//for(int i  = 0; i < qtdCartas; i++ ){

	//	show += "\n";
	//	show += cartas[i].getNome();
	//}

	return show;
}

Carta *Mao::getCarta(int indice)
{
	return &(cartas[indice]);
}

int Mao::calcularValor()
{
	int soma = 0;

	for (int i = 0; i < qtdCartas; ++i) {
		soma += cartas[i].getValor();
	}

	if(soma > 21){
		soma = 0;
		for (int i = 0; i < qtdCartas; ++i) {
			if(cartas[i].getNumero() == AS)
				soma += 1;
			else
				soma += cartas[i].getValor();
		}
	}

	return soma;
}

int Mao::getValor()
{
	return calcularValor();
}

void Mao::limparMao()
{
	qtdCartas = 0;
	status  = 0;
}

int Mao::numeroCartas(){
	return this->qtdCartas;
}
