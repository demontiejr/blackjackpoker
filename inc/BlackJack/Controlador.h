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
#include "BlackJack/Mesa.h"
#include "BlackJack/Ranking.h"

using namespace Osp::Graphics;
using namespace Osp::Base;

class Jogador;
class Mesa;

enum StatusJogo {PARADO = 0, INICIO_PARTIDA=1, APOSTANDO=2, JOGADOR_JOGANDO=3, MESA_JOGANDO=4, PAGANDO=5, TERMINADO=6};

class Controlador {
public:

	virtual ~Controlador();
	void Construct();

	void InicioJogadaJogador();
	void JogadorPuxaCarta();
	void JogadorDobra();
	void FimJogadaJogador();

	void InicioJogadaMesa();
	void MesaPuxaCarta();
	void JogadaMesa();
	void FimJogadaMesa();

	void IniciarPartida();
	void FimPartida();

	void AtualizarAposta();

	void PagarVencedor();

	void SetListener(IListenerControlador* listener);
	void SetJogador(Jogador* jogador);
	void SetValorPote(int valor);
	StatusJogo GetStatus();
    bool JogadorGanhou();
    bool Empate();

    bool constructed;

protected:
	Baralho* baralho;

	Jogador* jogador;
	Mesa* mesa;

	int valorApostaAcumulado;
	StatusJogo status;

	IListenerControlador* listener;

public:
	int GetValorPote();

	Baralho* GetBaralho();
	Jogador* GetJogador();
	Mesa* GetMesa();
	static Controlador* GetInstance();

private:

	static Controlador* controlador;
	Controlador();
};

#endif /* CONTROLADOR_H_ */
