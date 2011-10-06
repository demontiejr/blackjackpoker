/*
 * Baralho.cpp
 * Created on: 22/09/2011
 * Author: Junior
 */

#include "BlackJack/Baralho.h"
#include <stdlib.h>

using namespace Osp::System;
using namespace Osp::Base::Utility;
using namespace std;

Baralho::Baralho() {
	this->topo = 52;

	int i = 0;

	for (int naipe = 0; naipe < 4; naipe++) {
		for (int numero = 0; numero < 13; numero++) {
			cartas[i] = CriaCarta(numero, naipe);
			i++;
		}
	}

	Embaralhar();
}

Carta* Baralho::CriaCarta(int numero, int naipe) {
	return new Carta(numero, naipe);
}

Carta* Baralho::DarCarta() {
	if (this->topo <= 0)
		return NULL;
	Carta* cartaRetirada = cartas[--this->topo];
	return cartaRetirada;
}

void Baralho::Embaralhar() {
	int posicao;
	long long ticks;
	SystemTime::GetTicks(ticks);
	Math::Srand((unsigned int) ticks);
	for (posicao = 0; posicao < topo - 1; posicao++) {
		// escolhe uma posição aleatória entre posição e númeroDeCartas()-1
		int posAleatoria = posicao + (rand() % (topo - posicao));
		// troca as cartas em posição e posAleatória
		Carta* temp = cartas[posicao];
		cartas[posicao] = cartas[posAleatoria];
		cartas[posAleatoria] = temp;
	}
}

void Baralho::ReporCartas()
{
	this->topo = 52;
	Embaralhar();
}

Baralho::~Baralho() {
	// TODO Auto-generated destructor stub
}
