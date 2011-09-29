/*
 * Jogador.cpp
 * Created on: 25/09/2011
 * Author: Arthur Holanda
 */

#include "BlackJack/Jogador.h"

using namespace Osp::Base::Utility;

Jogador::Jogador() {
	this->nome = "Ainda sem nome";
	this->pontos = 0;
	this->maxPontos = 0;
	this->vitoriasConsecutivas = 0;
	this->maxVitoriasConsecutivas = 0;
	this->valorAposta = VALOR_APOSTA_INICIAL;
	this->status = JOGANDO;
}

void Jogador::Construct(String nome) {
	this->nome = nome;
	this->mao = new Mao();
}

Jogador::~Jogador() {
	delete mao;
}

int Jogador::GetMaxVitoriasConsecutivas() {
	return this->maxVitoriasConsecutivas;
}

int Jogador::Receber(int valor) {
	this->pontos += valor;
	this->maxPontos = Math::Max(maxPontos, pontos);
}

void Jogador::SetValorAposta(int valorAposta) {
	if (this->pontos >= valorAposta) {
		this->valorAposta = valorAposta;
	}
}

String Jogador::GetNome() {
	return this->nome;
}

int Jogador::GetMaxPontos() {
	return this->maxPontos;
}

int Jogador::GetValorAposta(int valorAposta) {
	return this->valorAposta;
}

void Jogador::Ganhou() {
	this->vitoriasConsecutivas += 1;
	this->maxVitoriasConsecutivas = Math::Max(vitoriasConsecutivas,
			maxVitoriasConsecutivas);
}

Mao* Jogador::GetMao() {
	return this->mao;
}

void Jogador::Perdeu() {
	this->vitoriasConsecutivas = 0;
}

void Jogador::PuxarCarta() {
	Carta* c = this->controlador->GetBaralho()->DarCarta();
	this->mao->PegarCarta(c);
}

int Jogador::Apostar(int valorAposta) {
	pontos -= valorAposta;
}

void Jogador::SetControlador(Controlador *controlador) {
	this->controlador = controlador;
}

void Jogador::Parar()
{
	this->status = PAROU;
}

void Jogador::IniciarPartida()
{
	this->status = JOGANDO;
	//TODO - implementar limpar mão
}

StatusJogador Jogador::GetStatus()
{
	return this->status;
}

void Jogador::SetStatus(StatusJogador status)
{
	this->status = status;
}
