/*
 * Controlador.cpp
 * Created on: 23/09/2011
 * Author: Junior
 */

#include "BlackJack/Controlador.h"
#include "BlackJack/InfoRanking.h"

using namespace Osp::Base;
using namespace Osp::Graphics;
using namespace Osp::Media;

Controlador::Controlador() {
	constructed = false;
}

Controlador* Controlador::controlador = 0;
Controlador* Controlador::GetInstance() {
	if (!controlador) {
		controlador = new Controlador();
	}
	return controlador;
}

Controlador::~Controlador() {

}

void Controlador::InicioJogadaJogador() {
	status = JOGADOR_JOGANDO;

	if (listener != null) {
		listener->OnInicioJogadaJogador();
	}
}

void Controlador::MesaPuxaCarta() {
	mesa->PuxarCarta();

	if (listener != null) {
		listener->OnMesaPuxaCarta();
	}
}

void Controlador::JogadorPuxaCarta() {
	jogador->PuxarCarta();

	if (listener != null) {
		this->listener->OnJogadorPuxaCarta();
	}
}

void Controlador::JogadorDobra() {
	jogador->PuxarCarta();
	valorApostaAcumulado *= 2;

	if (listener != null) {
		this->listener->OnJogadorDobra();
	}
}

void Controlador::JogadaMesa() {
	if (mesa->GetMao()->GetValor() < 17) {
		MesaPuxaCarta();
	} else {
		FimJogadaMesa();
	}
}

Baralho* Controlador::GetBaralho() {
	return this->baralho;
}

void Controlador::IniciarPartida() {
	baralho->ReporCartas();
	jogador->IniciarPartida();

	mesa->IniciarPartida();
	jogador->PuxarCarta();
	mesa->PuxarCarta();
	jogador->PuxarCarta();

	mesa->PuxarCarta();

	status = APOSTANDO;

	if (listener != null) {
		listener->OnInicioPartida();
	} else {
		AppLog("[ERRO] Listener null");
	}
}

bool Controlador::JogadorGanhou() {
	//TODO decidir vencedor de forma correta
	bool jogadorEhMaior = (jogador->GetMao()->GetValor()
			> mesa->GetMao()->GetValor());
	bool jogadorEstourou = (jogador->GetMao()->GetValor() > 21);
	bool mesaEstourou = (mesa->GetMao()->GetValor() > 21);

	if (jogadorEstourou and !mesaEstourou) {
		return false;
	} else if (jogadorEstourou and mesaEstourou) {
		return false;
	} else if (!jogadorEstourou and mesaEstourou) {
		return true;
	} else {
		return jogadorEhMaior;
	}
}

void Controlador::Construct() {
	if(! constructed){
		constructed = true;
		mesa = new Mesa();
		mesa->Construct();
		mesa->SetControlador(this);
		baralho = new Baralho();
		valorApostaAcumulado = 0;
		status = PARADO;
	}
}

Mesa *Controlador::GetMesa() {
	return this->mesa;
}

int Controlador::GetValorPote() {
	return this->valorApostaAcumulado;
}

Jogador *Controlador::GetJogador() {
	return this->jogador;
}

void Controlador::SetValorPote(int valor) {
	valorApostaAcumulado = valor;
}

StatusJogo Controlador::GetStatus()
{
	return this->status;
}

bool Controlador::Empate() {
	//TODO decidir empate

	bool jogadorEstourou = (jogador->GetMao()->GetValor() > 21);
	bool mesaEstourou = (mesa->GetMao()->GetValor() > 21);
	bool saoIguais = (jogador->GetMao()->GetValor()
			== mesa->GetMao()->GetValor());

	if (JogadorGanhou()) {
		return false;
	} else if (jogadorEstourou && mesaEstourou) {
		return true;
	} else if (jogadorEstourou && !mesaEstourou) {
		return false;
	} else if (!jogadorEstourou && mesaEstourou) {
		return false;
	} else {
		return saoIguais;
	}

	return (jogador->GetMao()->GetValor() == mesa->GetMao()->GetValor());
}

void Controlador::PagarVencedor() {
	status = PAGANDO;

	if (JogadorGanhou()) {
		jogador->Receber(valorApostaAcumulado);
	} else if (Empate()) {
		jogador->Receber(valorApostaAcumulado / 2);
	}

	valorApostaAcumulado = 0;

	if (listener != null) {
		listener->OnPagarVencedor();
	}
}

void Controlador::FimJogadaJogador() {
	if (listener != null) {
		listener->OnFimJogadaJogador();
	}
}

void Controlador::FimPartida() {
	status = PARADO;

	if (listener != null) {
		listener->OnFimPartida();
	}
}

void Controlador::AtualizarAposta() {
}

void Controlador::FimJogadaMesa() {
	if (listener != null) {
		this->listener->OnFimJogadaMesa();
	}
}

void Controlador::InicioJogadaMesa() {
	status = MESA_JOGANDO;
	if (listener != null) {
		this->listener->OnInicioJogadaMesa();
	}
}

void Controlador::SetListener(IListenerControlador* listener) {
	this->listener = listener;
}

void Controlador::SetJogador(Jogador* jogador) {
	this->jogador = jogador;
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
