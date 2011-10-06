/*
 * Mesa.h
 *
 *  Created on: 05/10/2011
 *      Author: Arthur Holanda
 */

#ifndef MESA_H_
#define MESA_H_

#include "BlackJack/Controlador.h"
#include "BlackJack/Jogador.h"

class Controlador;

class Mesa {
public:
	Mesa();
	virtual ~Mesa();

	void Construct();

	void PuxarCarta();
	void Parar();

	void IniciarPartida();

	/*
	 * Metodo que define como deve ser o comportamento da jogada de um jogador automatico s(mesa)
	 */
	virtual void Jogar();

	/*
	 * Esse metodo deve chamar um dos métodos de fim de jogada no controlador
	 */
	virtual void TerminouJogada();

protected:
	//StatusJogador status;

	Mao* mao;
	Controlador* controlador;

public: //getters e setters
	void SetControlador(Controlador* controlador);

	Mao* GetMao();
};

#endif /* MESA_H_ */
