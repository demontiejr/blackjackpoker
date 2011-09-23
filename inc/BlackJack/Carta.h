/*
 * Carta.h
 *
 *  Created on: 22/09/2011
 *      Author: Junior
 */

#ifndef CARTA_H_
#define CARTA_H_

#include <FMedia.h>
#include <FBase.h>
#include <FUi.h>

#define ESPADAS 0
#define COPAS 1
#define PAUS 2
#define OUROS 3

#define AS 0
#define DOIS 1
#define TRES 2
#define QUATRO 3
#define CINCO 4
#define SEIS 5
#define SETE 6
#define OITO 7
#define NOVE 8
#define DEZ 9
#define VALETE 10
#define DAMA 11
#define REI 12

using namespace Osp::Base;

class Carta {
public:
	Carta();
	Carta(int numero, int naipe);
	virtual ~Carta();
	int getValor();
	String toString();
	int getNumero();
	int valor;
	int naipe;

private:
	String nome;
	int numero;
};

#endif /* CARTA_H_ */