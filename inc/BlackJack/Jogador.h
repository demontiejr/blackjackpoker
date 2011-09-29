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

using namespace  Osp::Base;

#define VALOR_APOSTA_INICIAL 10

enum StatusJogador {PAROU, JOGANDO};

class Controlador;//isso foi colocado aqui para resolver um problema "maluco" com c++

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

	/*
	 * Metodo que define como deve ser o comportamento da jogada de um jogador automatico s(mesa)
	 */
	virtual void Jogar() = 0;

	/*
	 * Esse metodo deve chamar um dos métodos de fim de jogada no controlador
	 */
	virtual void TerminouJogada() = 0;

protected:
	String nome;

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

	int GetMaxPontos();

	int GetMaxVitoriasConsecutivas();

	Mao* GetMao();

	void SetValorAposta(int valorAposta);
	int GetValorAposta(int valorAposta);

	void SetStatus(StatusJogador status);
	StatusJogador GetStatus();
};

#endif /* JOGADOR_H_ */
