/*
 * Controlador.cpp
 * Created on: 23/09/2011
 * Author: Junior
 */

#include "BlackJack/Controlador.h"

using namespace Osp::Base;
using namespace Osp::Graphics;
using namespace Osp::Media;

Controlador::Controlador() {
}

Controlador::~Controlador() {

}

void Controlador::InicioJogadaJogador() {
}

Baralho* Controlador::GetBaralho() {
}

void Controlador::IniciarPartida() {
}

void Controlador::PagarVencedor() {
}

void Controlador::FimJogadaJogador() {
}

void Controlador::FimPartida() {
}

void Controlador::AtualizarAposta() {
}

void Controlador::FimJogadaMesa() {
}

void Controlador::InicioJogadaMesa() {
}

/*

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
 */
