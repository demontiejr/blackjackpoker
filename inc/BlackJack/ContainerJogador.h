/*
 * ContainerJogador.h
 * Created on: 05/10/2011
 * Author: Catharine
 */

#ifndef CONTAINERJOGADOR_H_
#define CONTAINERJOGADOR_H_

#include "BlackJack/JogadorPessoa.h"


class ContainerJogador {
public:
	virtual ~ContainerJogador();
	void SetJogador(JogadorPessoa* jogador);
	JogadorPessoa* GetJogador();
	ContainerJogador* GetInstance();

private:
	JogadorPessoa* jogador;
	ContainerJogador* containerJ;
	ContainerJogador();
};

#endif /* CONTAINERJOGADOR_H_ */
