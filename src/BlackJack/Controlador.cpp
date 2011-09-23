/*
 * Controlador.cpp
 *
 *  Created on: 23/09/2011
 *      Author: Junior
 */

#include "BlackJack/Controlador.h"

using namespace Osp::Base;
using namespace Osp::Graphics;
using namespace Osp::Media;

Controlador::Controlador() {
//	delete this->imagem;

	player = new Mao();
	mesa = new Mao();
	baralho = new Baralho();

	this->valorAcumulado = 200;
	this->valorDaAposta = 5;

	Image image;
	image.Construct();
	imagem = image.DecodeN(L"/Res/cards.png", BITMAP_PIXEL_FORMAT_ARGB8888);
}

Controlador::~Controlador() {
	delete player;
	delete mesa;
	delete baralho;
}

void Controlador::aumentarAposta() {
	//TODO mudar a regra de negocio
	if (this->valorDaAposta < 100)
		this->valorDaAposta += 5;
}

void Controlador::diminuirAposta() {
	//TODO mudar a regra de negocio
	if (this->valorDaAposta > 5)
		this->valorDaAposta -= 5;
}

int Controlador::puxarCarta() {
	if (player->getValor() < 21) { //TODO se pontos >= 21, deixar botao inativo
		Carta *c = baralho->darCarta();
		player->pegarCarta(*c);
	}
	return player->getValor();
}

String Controlador::parar() {
	String s = "";

	int pl = player->getValor();
	int ms = mesa->getValor();

	s += "Mesa: " + Integer::ToString(mesa->getValor()) + "\n";

	if (pl > 21 && ms > 21) {
		s += "EMPATE!";
	} else if (ms > 21) {
		s += "VOCE GANHOU!";
		this->valorAcumulado += this->valorDaAposta;
	} else if (pl > 21) {
		s += "MESA GANHOU";
		this->valorAcumulado -= this->valorDaAposta;
	} else if (pl <= 21 && ms <= 21) {
		if (pl > ms) {
			s += "VOCE GANHOU!";
			this->valorAcumulado += this->valorDaAposta;
		} else if (ms > pl) {
			s += "MESA GANHOU";
			this->valorAcumulado -= this->valorDaAposta;
		} else {
			s += "EMPATE";
		}
	}

	return s;
}

String Controlador::reiniciar() {
	baralho->reporCartas();
	player->limparMao();
	mesa->limparMao();

	Carta *c;
	c = baralho->darCarta();
	player->pegarCarta(*c);
	c = baralho->darCarta();
	player->pegarCarta(*c);

	c = baralho->darCarta();
	mesa->pegarCarta(*c);
	c = baralho->darCarta();
	mesa->pegarCarta(*c);

	while (mesa->getValor() < 18) {
		c = baralho->darCarta();
		mesa->pegarCarta(*c);
	}

	return player->mostrarMao();
}

void Controlador::desenharCartas(Canvas *pCanvas) {
	AppLog("chamou desenhar");

	Osp::Graphics::Bitmap *pBitmapCarta = new Bitmap();

	float escala = 1.29;

	Carta *cartaAtual;

	float x, y;

	if (pCanvas != null) {

		for(int i = 0; i < player->numeroCartas(); i++){

			cartaAtual = player->getCarta(i);

			if(cartaAtual->naipe == ESPADAS)
				y = 3*123 + 1;
			else if(cartaAtual->naipe == COPAS)
				y  = 2*123 + 1;
			else if(cartaAtual->naipe == PAUS)
				y = 0;
			else
				y = 123 + 1;

			x = 79*cartaAtual->getNumero();

			x = x * escala;
			y = y * escala;

			pBitmapCarta->Construct(*(imagem), Rectangle(x, y, 80*escala, 124*escala));
			pBitmapCarta->Scale(Dimension(52, 80));

			if(i < 3)
				pCanvas->DrawBitmap(Point((30 + i*135)/2, (230)/2), *(pBitmapCarta));
			else
				pCanvas->DrawBitmap(Point((30 + (i%3)*135)/2, (410)/2), *(pBitmapCarta));
		}
	}

	delete pBitmapCarta;

}
