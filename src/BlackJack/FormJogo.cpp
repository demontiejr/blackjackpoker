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
	Construct(L"IDF_FORM1");
	controlador = new Controlador();
//	this->SetBackgroundColor(Osp::Graphics::Color(0, 128, 0));

	return true;
}

result FormJogo::OnInitializing(void) {
	result r = E_SUCCESS;

	//myPlayer = new AudioPlayer();

	__pButtonPuxar = static_cast<Button *>(GetControl(L"BUTTON_PUXAR"));
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

	/*
	Image image;
	image.Construct();
	Osp::Graphics::Bitmap *imagem = image.DecodeN(L"/Res/bj.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	Canvas* pCanvas = GetCanvasN();
	if (pCanvas != null) {
		AppLog("Desenhou");
		pCanvas->Clear();
		pCanvas->DrawBitmap(Point(1, 210), *(imagem));
		pCanvas->Show();
		RequestRedraw(true);
	}
	delete pCanvas;
	 */

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
		int pontos = controlador->puxarCarta();
		__pLabelPontos->SetText("Pontos: " + Integer::ToString(pontos));
		__pLabelPontos->RequestRedraw();
		desenharCartas();
		if (pontos >= 21) {
			__pButtonPuxar->SetEnabled(false);
			__pButtonPuxar->RequestRedraw();
		}
	}
	break;
	case ID_BUTTON_PARAR: {
		String s = controlador->parar();

		__pLabelPontos->SetText(s);
		__pLabelPontos->RequestRedraw();
	}
	break;

	case ID_BUTTON_REINICIAR: {
		String mao = controlador->reiniciar();

		__pLabelPontos->SetText(mao);
		desenharCartas();
		__pLabelPontos->RequestRedraw();

	}
	default:
		break;
	}

	Canvas* pCanvas = GetCanvasN();
	controlador->desenharCartas(pCanvas);
}

void FormJogo::desenharCartas() {
	Canvas* pCanvas = GetCanvasN();
	controlador->desenharCartas(pCanvas);
}

result FormJogo::OnDraw(void) {
        Image *pImage = new Image();
        result r = pImage->Construct();
        if (IsFailed(r))
                return r;
        Bitmap *pBitmap = pImage->DecodeN("/Home/background.jpg",
                        BITMAP_PIXEL_FORMAT_ARGB8888);

        Label *pLabel = new Label();
        pLabel->Construct(Rectangle(0, 0, 479, 799), null);
        pLabel->SetBackgroundBitmap(*pBitmap);
        AddControl(*pLabel);
        delete pImage;
        delete pBitmap;
        __pButtonPuxar->RequestRedraw(true);
        __pButtonParar->RequestRedraw(true);
        __pButtonReiniciar->RequestRedraw(true);
        __pLabelPontos->RequestRedraw(true);

        desenharCartas();//TODO ver se eh necessario

        return r;
}
