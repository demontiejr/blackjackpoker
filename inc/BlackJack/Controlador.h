/*
 * Controlador.h
 * Created on: 23/09/2011
 * Author: Junior
 */

#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_

#include "BlackJack/Carta.h"
#include "BlackJack/Mao.h"
#include "BlackJack/Baralho.h"
#include "BlackJack/Jogador.h"
#include "BlackJack/IListenerControlador.h"

using namespace Osp::Graphics;
using namespace Osp::Base;

class Jogador;

class Controlador {
public:
	Controlador();
	virtual ~Controlador();

	void InicioJogadaJogador();
	void JogadorPuxaCarta();
	void FimJogadaJogador();

	void InicioJogadaMesa();
	void MesaPuxaCarta();
	void JogadaMesa();
	void FimJogadaMesa();

	void IniciarPartida();
	void FimPartida();

	void AtualizarAposta();

	void PagarVencedor();

protected:
	Baralho* baralho;
	Jogador* jogador;
	Jogador* mesa;

	int valorApostaAcumulado;

	IListenerControlador* listener;

public:
	Baralho* GetBaralho();
private:
    bool JogadorGanhou();
    bool Empate();
};

#endif /* CONTROLADOR_H_ */
