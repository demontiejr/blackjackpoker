/*
 * JogadorPessoa.h
 *
 *  Created on: 25/09/2011
 *      Author: Arthur Holanda
 */

#ifndef JOGADORPESSOA_H_
#define JOGADORPESSOA_H_

#include "Jogador.h"

class JogadorPessoa : Jogador{
public:
	JogadorPessoa();
	virtual ~JogadorPessoa();

	virtual void Jogar();
	virtual void TerminouJogada();
};

#endif /* JOGADORPESSOA_H_ */
