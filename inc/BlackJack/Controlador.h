/*
 * Controlador.h
 *
 *  Created on: 23/09/2011
 *      Author: Junior
 */

#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_

#include "BlackJack/Carta.h"
#include "BlackJack/Mao.h"
#include "BlackJack/Baralho.h"

using namespace Osp::Graphics;
using namespace Osp::Base;

class Controlador {
public:
	Controlador();
	virtual ~Controlador();
	void desenharCartas(Canvas *pCanvas);
	int puxarCarta();
	String parar();
	String reiniciar();
	void aumentarAposta();
	void diminuirAposta();

protected:
	Baralho *baralho;
	Mao *player;
	Mao *mesa;
	int valorAcumulado;
	int valorDaAposta;
	Osp::Graphics::Bitmap *imagem;
};

#endif /* CONTROLADOR_H_ */
