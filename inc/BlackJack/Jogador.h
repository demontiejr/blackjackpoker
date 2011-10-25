/*
 * Jogador.h
 * Created on: 25/09/2011
 * Author: Arthur Holanda
 */

#ifndef JOGADOR_H_
#define JOGADOR_H_

#include <FBase.h>
#include "BlackJack/Controlador.h"
#include "BlackJack/Mao.h"

using namespace Osp::Base;

#define VALOR_APOSTA_INICIAL 10

typedef enum  {PAROU, JOGANDO} StatusJogador;

class Controlador;

class Jogador {

public:
	Jogador();
	void Construct(String nome);
	virtual ~Jogador();

	int Apostar(int valorAposta);
	int Receber(int valor);

	void Perdeu();
	void Ganhou();

	void PuxarCarta();
	void Parar();

	void IniciarPartida();
	void TerminouJogada();

protected:
	String nome;

	bool podeDobrar;
	int pontos;
	int maxPontos;
	int valorAposta;
	int vitoriasConsecutivas;
	int maxVitoriasConsecutivas;
	StatusJogador status;

	Mao* mao;
	Controlador* controlador;

public: //getters e setters
	void SetControlador(Controlador* controlador);

	String GetNome();

	int GetPontos();
	int GetMaxPontos();

	int GetMaxVitoriasConsecutivas();

	Mao* GetMao();

	bool PodeDobrar();

	void SetValorAposta(int valorAposta);
	int GetValorAposta(int valorAposta);

	void SetStatus(StatusJogador status);
	StatusJogador GetStatus();
};

#endif /* JOGADOR_H_ */
