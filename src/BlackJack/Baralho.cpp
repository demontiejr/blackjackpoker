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


	long long ticks;
	SystemTime::GetTicks(ticks);
	Math::Srand((unsigned int) ticks);

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
	if (this->topo <= 0){
		AppLog("Deu carta nula.");
		return null;
	}

	Carta* cartaRetirada = cartas[--this->topo];

	if(cartaRetirada == null){
		AppLog("Manipulando carta nula.");
	}

	//decide se eh bonus
	int bonusNumber = Math::Rand() % 200;

	cartaRetirada->SetBonus(bonusNumber <= 10);

	return cartaRetirada;
}

void Baralho::Embaralhar() {
	int posicao;
	for (posicao = 0; posicao < topo - 1; posicao++) {
		// escolhe uma posi��o aleat�ria entre posi��o e n�meroDeCartas()-1
		int posAleatoria = posicao + (Math::Rand() % (topo - posicao));
		// troca as cartas em posi��o e posAleat�ria
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
