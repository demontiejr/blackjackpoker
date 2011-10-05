#include "BlackJack/FormJogo.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Base::Utility;
using namespace Osp::App;
using namespace Osp::Media;
using namespace Osp::Graphics;

FormJogo::FormJogo(void) {

}

FormJogo::~FormJogo(void) {
	//	delete myVibrator;
}

bool FormJogo::Initialize() {
	// Construct an XML form
	Construct(L"IDF_FORM_JOGO");
	controlador = new Controlador();

	return true;
}

result FormJogo::OnInitializing(void) {
	result r = E_SUCCESS;

	__pButtonPuxar = static_cast<Button *> (GetControl(L"BUTTON_PUXAR"));
	if (__pButtonPuxar != null)
	{
		__pButtonPuxar->SetActionId(ID_BUTTON_PUXAR);
		__pButtonPuxar->AddActionEventListener(*this);
	}

	__pButtonParar = static_cast<Button *>(GetControl(L"BUTTON_PARAR"));
	if (__pButtonParar != null)
	{
		__pButtonParar->SetActionId(ID_BUTTON_PARAR);
		__pButtonParar->AddActionEventListener(*this);
	}

	__pButtonReiniciar = static_cast<Button *>(GetControl(L"BUTTON_REINICIAR"));
	if (__pButtonReiniciar != null)
	{
		__pButtonReiniciar->SetActionId(ID_BUTTON_REINICIAR);
		__pButtonReiniciar->AddActionEventListener(*this);
	}

	__pLabelPontos = static_cast<Label *>(GetControl(L"LABEL_PONTOS"));

	return r;
}

result FormJogo::OnTerminating(void) {
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void FormJogo::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {

	switch (actionId) {
	case ID_BUTTON_PUXAR: {
		/*
		 int pontos = controlador->puxarCarta();
		 __pLabelPontos->SetText("Pontos: " + Integer::ToString(pontos));
		 __pLabelPontos->RequestRedraw();
		 desenharCartas();
		 if (pontos >= 21) {
		 __pButtonPuxar->SetEnabled(false);
		 __pButtonPuxar->RequestRedraw();
		 }
		 */
	}
		break;
	case ID_BUTTON_PARAR: {
		/*
		 String s = controlador->parar();

		 __pLabelPontos->SetText(s);
		 __pLabelPontos->RequestRedraw();
		 */
	}
		break;

	case ID_BUTTON_REINICIAR: {
		/*
		 String mao = controlador->reiniciar();

		 __pLabelPontos->SetText(mao);
		 desenharCartas();
		 __pLabelPontos->RequestRedraw();

		 __pButtonPuxar->SetEnabled(true);
		 */
	}
	default:
		break;
	}

	RequestRedraw(true);
}

void FormJogo::desenharCartas() {

}

result FormJogo::OnDraw(void) {
	/*
	 Image *pImage = new Image();

	 result r = pImage->Construct();

	 if (IsFailed(r))
	 return r;

	 Bitmap *pBitmap = pImage->DecodeN("/Home/background.png",
	 BITMAP_PIXEL_FORMAT_ARGB8888);

	 Canvas* pCanvas = GetCanvasN();
	 if(pCanvas){
	 pCanvas->Clear();

	 pCanvas->DrawBitmap(Point(0, 0), *pBitmap);
	 controlador->desenharCartas(pCanvas);

	 pCanvas->Show();

	 delete pCanvas;
	 }

	 delete pImage;
	 delete pBitmap;

	 return r;
	 */

	return E_SUCCESS;
}

//TODO - implementar os metodos da interface

void FormJogo::OnFimJogadaMesa() {
	//TODO - adicionar acao
	controlador->FimPartida();
}

void FormJogo::OnInicioPartida() {
	//TODO - adicionar acao
	controlador->InicioJogadaJogador();
}

void FormJogo::OnInicioJogadaMesa() {
	//TODO - adicionar acao
	controlador->JogadaMesa();
}

void FormJogo::OnFimJogadaJogador() {
	//TODO - adicionar acao
	controlador->InicioJogadaMesa();
}

void FormJogo::OnMesaPuxaCarta() {
	//TODO - adicionar acao
	controlador->JogadaMesa();
}

void FormJogo::OnJogadorPuxaCarta() {
	//TODO - adicionar acao
}

void FormJogo::OnPagarVencedor() {
	//TODO - adicionar acao
	controlador->FimPartida();
}

void FormJogo::OnInicioJogadaJogador() {
	//TODO - adicionar acao
}

void FormJogo::OnFimPartida() {
	//TODO - adicionar acao
}
