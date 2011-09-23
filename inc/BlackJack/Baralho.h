/*
 * Baralho.h
 *
 *  Created on: 22/09/2011
 *      Author: Junior
 */

#ifndef BARALHO_H_
#define BARALHO_H_

#include "BlackJack/Carta.h"

class Baralho {
public:
	Baralho();
	virtual ~Baralho();
	void embaralhar();
	Carta* darCarta();
	void reporCartas();
	int topo;

private:
	Carta *cartas[52];
	Carta* criaCarta(int numero, int naipe);
};

#endif /* BARALHO_H_ */
