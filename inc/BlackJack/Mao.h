/*
 * Mao.h
 *
 *  Created on: 22/09/2011
 *      Author: Junior
 */

#ifndef MAO_H_
#define MAO_H_

#include <FBase.h>
#include "BlackJack/Carta.h"

using namespace std;

class Mao {
public:
	static const int JOGANDO = 0;
	static const int PAROU = 1;

	Mao();
	virtual ~Mao();
	int getValor();
	void pegarCarta(Carta &c);
	void limparMao();
	String mostrarMao();
	bool estourou();
	void setStatus(int);
	int getStatus();
	Carta *getCarta(int indice);
	int numeroCartas();

private:
	int calcularValor();
	Carta cartas[20];
	int qtdCartas;
	bool status;//1 = parou de jogar, 0 = continua jogando
};

#endif /* MAO_H_ */
