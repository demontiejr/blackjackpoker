/*
 * Baralho.cpp
 *
 *  Created on: 22/09/2011
 *      Author: Junior
 */

#include "BlackJack/Baralho.h"
#include <stdlib.h>

using namespace std;

Baralho::Baralho() {
	this->topo = 52;

	int i = 0;

	for (int naipe = 0; naipe < 4; naipe++) {
		for (int numero = 0; numero < 13; numero++) {
			cartas[i] = criaCarta(numero, naipe);
			i++;
		}
	}

	embaralhar();
}

Carta* Baralho::criaCarta(int numero, int naipe) {
	return new Carta(numero, naipe);
}

Carta* Baralho::darCarta() {
	if (this->topo <= 0)
		return NULL;
	Carta* cartaRetirada = cartas[--this->topo];
	return cartaRetirada;
}

void Baralho::embaralhar() {
	int posicao;
	for (posicao = 0; posicao < topo - 1; posicao++) {
		// escolhe uma posição aleatória entre posição e númeroDeCartas()-1
		int posAleatoria = posicao + (rand() % (topo - posicao));
		// troca as cartas em posição e posAleatória
		Carta* temp = cartas[posicao];
		cartas[posicao] = cartas[posAleatoria];
		cartas[posAleatoria] = temp;
	}
}

void Baralho::reporCartas()
{
	this->topo = 52;
	embaralhar();
}

Baralho::~Baralho() {
	// TODO Auto-generated destructor stub
}
