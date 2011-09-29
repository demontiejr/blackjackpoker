/*
 * JogadorMesa.h
 * Created on: 25/09/2011
 * Author: Arthur Holanda
 */

#ifndef JOGADORMESA_H_
#define JOGADORMESA_H_

#include "Jogador.h"

class JogadorMesa : Jogador{
public:
	JogadorMesa();
	virtual ~JogadorMesa();

	virtual void Jogar();
	virtual void TerminouJogada();
};

#endif /* JOGADORMESA_H_ */
