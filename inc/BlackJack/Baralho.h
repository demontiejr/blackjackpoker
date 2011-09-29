/*
 * Baralho.h
 * Created on: 22/09/2011
 * Author: Junior
 */

#ifndef BARALHO_H_
#define BARALHO_H_

#include "BlackJack/Carta.h"

class Baralho {
public:
	Baralho();
	virtual ~Baralho();
	void Embaralhar();
	Carta* DarCarta();
	void ReporCartas();
	int topo;

private:
	Carta* cartas[52];
	Carta* CriaCarta(int numero, int naipe);
};

#endif /* BARALHO_H_ */
