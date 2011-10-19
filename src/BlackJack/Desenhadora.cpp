/*
 * Desenhadora.cpp
 * Created on: 29/09/2011
 * Author: Catharine
 */

#include "BlackJack/Desenhadora.h"
#include <FMedia.h>

using namespace Osp::Media;
using namespace Osp::Graphics;

Desenhadora::Desenhadora() {
}

void Desenhadora::DesenhaMaoMesaParcial(Mao *m, int x, int y, Canvas *pCanvas)
{

	if(m->NumeroCartas() == 2){
		DesenhaCarta(m->GetCarta(0), x, y, pCanvas);
		DesenhaCartaVirada(x+60, y, pCanvas);

	}
}

void Desenhadora::DesenhaCartaVirada(int x, int y, Canvas *pCanvas)
{
	pCanvas->DrawBitmap(Point(x, y), *bitmapFundoVerso);
}

void Desenhadora::DesenhaBackground(Canvas* pCanvas)
{
	pCanvas->DrawBitmap(Point(0,0), *bitmapBackground);
}

void Desenhadora::DesenhaBackground(Canvas* pCanvas, String imgPath)
{
	Image decoder;
	decoder.Construct();
	Bitmap* img = decoder.DecodeN(imgPath, BITMAP_PIXEL_FORMAT_ARGB8888);
	pCanvas->DrawBitmap(Point(0,0), *img);
	delete img;//tinha leak aqui...
}

Desenhadora::~Desenhadora() {
	delete bitmapEspadas;
	delete bitmapPaus;
	delete bitmapOuros;
	delete bitmapCopas;
	delete bitmapFundoNormal;
	delete bitmapFundoBonus;
	listaBitmapsPretos.RemoveAll(true);
	listaBitmapsVermelhos.RemoveAll(true);
}

void Desenhadora::Construct() {

	//locais das pastas
	String PASTA_VERMELHOS = L"/Home/cartas/numeros/vermelhos/";
	String PASTA_PRETOS = L"/Home/cartas/numeros/pretos/";
	String PASTA_FUNDOS = L"/Home/cartas/";
	String PASTA_NAIPES = L"/Home/cartas/naipes/";

	//constroi listas
			listaBitmapsPretos.Construct(13);
			listaBitmapsVermelhos.Construct(13);

			//cria decoder
			Image decoder;
			decoder.Construct();

			//constroi bitmaps naipes
			bitmapEspadas = decoder.DecodeN(PASTA_NAIPES + "espadas.png",BITMAP_PIXEL_FORMAT_ARGB8888);
	bitmapPaus = decoder.DecodeN(PASTA_NAIPES + "paus.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	bitmapCopas = decoder.DecodeN(PASTA_NAIPES + "copas.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	bitmapOuros = decoder.DecodeN(PASTA_NAIPES + "ouros.png", BITMAP_PIXEL_FORMAT_ARGB8888);

	//constroi bitmaps fundos
	bitmapFundoNormal = decoder.DecodeN(PASTA_FUNDOS + "fundo-normal.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	bitmapFundoBonus = decoder.DecodeN(PASTA_FUNDOS + "fundo-bonus.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	bitmapFundoVerso = decoder.DecodeN(PASTA_FUNDOS + "fundo-verso.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	bitmapBackground = decoder.DecodeN("/Home/background.png", BITMAP_PIXEL_FORMAT_ARGB8888);

	Bitmap* temp;

	//constroi bitmaps pretos
	temp = decoder.DecodeN(PASTA_PRETOS + "a-preto.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	listaBitmapsPretos.Add(*temp);

	String num;
	for (int i = 2; i <= 10; i++) {
		num = Integer::ToString(i);
		temp = decoder.DecodeN(PASTA_PRETOS + num + "-preto.png", BITMAP_PIXEL_FORMAT_ARGB8888);
		listaBitmapsPretos.Add(*temp);
	}

	temp = decoder.DecodeN(PASTA_PRETOS + "j-preto.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	listaBitmapsPretos.Add(*temp);
	temp = decoder.DecodeN(PASTA_PRETOS + "q-preto.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	listaBitmapsPretos.Add(*temp);
	temp = decoder.DecodeN(PASTA_PRETOS + "k-preto.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	listaBitmapsPretos.Add(*temp);

	//constroi bitmaps vermelhos
	temp = decoder.DecodeN(PASTA_VERMELHOS + "a-vermelho.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	listaBitmapsVermelhos.Add(*temp);

	for (int i = 2; i <= 10; i++) {
		num = Integer::ToString(i);
		temp = decoder.DecodeN(PASTA_VERMELHOS + num + "-vermelho.png", BITMAP_PIXEL_FORMAT_ARGB8888);
		listaBitmapsVermelhos.Add(*temp);
	}

	temp = decoder.DecodeN(PASTA_VERMELHOS + "j-vermelho.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	listaBitmapsVermelhos.Add(*temp);
	temp = decoder.DecodeN(PASTA_VERMELHOS + "q-vermelho.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	listaBitmapsVermelhos.Add(*temp);
	temp = decoder.DecodeN(PASTA_VERMELHOS + "k-vermelho.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	listaBitmapsVermelhos.Add(*temp);

}

void Desenhadora::DesenhaCarta(Carta *carta, int x, int y, Canvas *pCanvas) {
	if (pCanvas != null) {
		Bitmap* fundo;
		Bitmap* numero;
		Bitmap* naipe;
		bool ehPreta;

		if (carta->IsBonus()) {
			fundo = bitmapFundoBonus;
		} else {
			fundo = bitmapFundoNormal;
		}

		switch (carta->naipe) {
		case ESPADAS:
			naipe = bitmapEspadas;
			ehPreta = true;
			break;
		case PAUS:
			naipe = bitmapPaus;
			ehPreta = true;
			break;
		case COPAS:
			naipe = bitmapCopas;
			ehPreta = false;
			break;
		case OUROS:
			naipe = bitmapOuros;
			ehPreta = false;
			break;

		default:
			break;
		}

		if(ehPreta){
			numero = (Bitmap*) listaBitmapsPretos.GetAt(carta->numero);
		}else{
			numero = (Bitmap*) listaBitmapsVermelhos.GetAt(carta->numero);
		}

		pCanvas->DrawBitmap(Point(x, y), *fundo);
		pCanvas->DrawBitmap(Point(x, y), *numero);
		pCanvas->DrawBitmap(Point(x, y), *naipe);
	}
}

void Desenhadora::DesenhaMao(Mao *m, int x, int y, Canvas *pCanvas) {

	//2 linhas
	//4 colunas

	int linha;
	int coluna;

	for (int i = 0; i < m->NumeroCartas(); ++i) {
		linha = i/4;
		coluna = i%4;

		DesenhaCarta(m->GetCarta(i), x + coluna*60, y + linha*85, pCanvas);
	}
}

