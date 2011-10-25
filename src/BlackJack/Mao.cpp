/*
 * Mao.cpp
 * Created on: 22/09/2011
 * Author: Junior
 */

#include "BlackJack/Mao.h"

using namespace Osp::Base;

Mao::Mao(){
	qtdCartas = 0;
	status = 0;
}

Mao::~Mao() {
	// TODO Auto-generated destructor stub
}

void Mao::PegarCarta(Carta*  c)
{
	cartas[qtdCartas] = c;
	qtdCartas++;
}


bool Mao::Estourou()
{
	return GetValor() > 21;
}

int Mao::GetStatus()
{
	return status;
}

void Mao::SetStatus(int status)
{
	this->status = status;
}

String Mao::MostrarMao()
{
	String show = "Pontos: " + Integer::ToString(GetValor());

	//for(int i  = 0; i < qtdCartas; i++ ){

	//	show += "\n";
	//	show += cartas[i].getNome();
	//}

	return show;
}

Carta* Mao::GetCarta(int indice)
{
	return cartas[indice];
}

int Mao::CalcularValor()
{
	int soma = 0;

	for (int i = 0; i < qtdCartas; ++i) {
		soma += cartas[i]->GetValor();
	}

	if(soma > 21){
		for (int i = 0; i < qtdCartas; ++i) {
			if(cartas[i]->GetNumero() == AS){
				soma -= 10;
				if(soma <= 21){
					break;
				}
			}
		}
	}

	return soma;
}

int Mao::GetValor()
{
	return CalcularValor();
}

void Mao::LimparMao()
{
	qtdCartas = 0;
	status  = 0;
}

int Mao::NumeroCartas(){
	return this->qtdCartas;
}
