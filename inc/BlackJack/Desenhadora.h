/*
 * Desenhadora.h
 * Created on: 29/09/2011
 * Author: Catharine
 */

#ifndef DESENHADORA_H_
#define DESENHADORA_H_

#include <FGraphics.h>
#include <FBase.h>
#include "BlackJack/Mao.h"
#include "BlackJack/Carta.h"

using namespace Osp::Base::Collection;
using namespace Osp::Graphics;

class Desenhadora {
public:

	Desenhadora();
	void Construct();
	void DesenhaCarta(Carta* carta, int x, int y, Canvas* pCanvas);
	void DesenhaCartaVirada(int x, int y, Canvas* pCanvas);
	void DesenhaMao(Mao* m, int x, int y, Canvas* pCanvas);
	void DesenhaMaoMesaParcial(Mao* m, int x, int y, Canvas* pCanvas);
	virtual ~Desenhadora();

private:
	Bitmap* bitmapEspadas;
	Bitmap* bitmapPaus;
	Bitmap* bitmapOuros;
	Bitmap* bitmapCopas;

	Bitmap* bitmapFundoNormal;
	Bitmap* bitmapFundoBonus;
	Bitmap* bitmapFundoVerso;

	ArrayList listaBitmapsVermelhos;
	ArrayList listaBitmapsPretos;
};

#endif /* DESENHADORA_H_ */
