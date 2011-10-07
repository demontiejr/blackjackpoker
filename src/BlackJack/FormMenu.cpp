/*
 * FormMenu.cpp
 * Created on: 21/09/2011
 * Author: Catharine
 */

#include "BlackJack/FormMenu.h"
#include "BlackJack/FormMgr.h"
#include "BlackJack/Controlador.h"
#include "BlackJack/Jogador.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Media;
using namespace Osp::Graphics;

FormMenu::FormMenu() {
	// TODO Auto-generated constructor stub

}

FormMenu::~FormMenu() {
	// TODO Auto-generated destructor stub
}

bool FormMenu::Initialize() {
	Construct(L"IDF_FORM_MENU");

	return true;
}

result FormMenu::OnInitializing(void) {
	result r = E_SUCCESS;

	__pButtonNovoJogo = static_cast<Button *> (GetControl(L"IDC_BUTTON_NOVO_JOGO"));
	if (__pButtonNovoJogo != null)
	{
		__pButtonNovoJogo->SetActionId(ID_BUTTON_NOVO_JOGO);
		__pButtonNovoJogo->AddActionEventListener(*this);
	}

	__pButtonRanking = static_cast<Button *>(GetControl(L"IDC_BUTTON_RANKING"));
	if (__pButtonRanking != null)
	{
		__pButtonRanking->SetActionId(ID_BUTTON_RANKING);
		__pButtonRanking->AddActionEventListener(*this);
	}

	__pButtonInstrucoes = static_cast<Button *> (GetControl(L"IDC_BUTTON_INSTRUCOES"));
	if (__pButtonInstrucoes != null)
	{
		__pButtonInstrucoes->SetActionId(ID_BUTTON_INSTRUCOES);
		__pButtonInstrucoes->AddActionEventListener(*this);
	}

	__pButtonSair = static_cast<Button *> (GetControl(L"IDC_BUTTON_SAIR"));
	if (__pButtonSair != null)
	{
		__pButtonSair->SetActionId(ID_BUTTON_SAIR);
		__pButtonSair->AddActionEventListener(*this);
	}

	//TODO pegar nome a partir da entrada do usuario
	nomeJogador = L"Arthur";

	return r;
}

result FormMenu::OnTerminating(void) {
	result r = E_SUCCESS;

	return r;
}

void FormMenu::CriaJogador() {
	Controlador* controlador = Controlador::GetInstance();
	Jogador* j = new Jogador();
	j->Construct(nomeJogador);
	j->Receber(100);
	j->SetControlador(controlador);
	controlador->SetJogador(j);
}

void FormMenu::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {
	Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
	switch (actionId) {

	case ID_BUTTON_NOVO_JOGO: {
		AppLog("NOVO JOGO Button is clicked! \n");
		CriaJogador();
		FormMgr *pFormMgr = static_cast<FormMgr *> (pFrame->GetControl(
				"FormMgr"));
		if (pFormMgr != null)
			pFormMgr->SendUserEvent(FormMgr::REQUEST_FORM_LOBBY, null);
	}
	break;

	case ID_BUTTON_RANKING: {
		AppLog("RANKING Button is clicked! \n");
		FormMgr *pFormMgr = static_cast<FormMgr *> (pFrame->GetControl(
				"FormMgr"));
		if (pFormMgr != null)
			pFormMgr->SendUserEvent(FormMgr::REQUEST_FORM_RANKING, null);
	}
	break;

	case ID_BUTTON_INSTRUCOES: {
		AppLog("INSTRUCOES Button is clicked! \n");
		FormMgr *pFormMgr = static_cast<FormMgr *> (pFrame->GetControl(
				"FormMgr"));
		if (pFormMgr != null)
			pFormMgr->SendUserEvent(FormMgr::REQUEST_FORM_INSTRUCOES, null);
	}
	break;

	case ID_BUTTON_SAIR: {
		AppLog("SAIR Button is clicked! \n");
		Application::GetInstance()->Terminate();
	}
	break;

	default:
		break;
	}

}

result FormMenu::OnDraw(void) {

	Image *pImage = new Image();
	result r = pImage->Construct();
	if (IsFailed(r))
		return r;
	Bitmap *pBitmap = pImage->DecodeN("/Home/imagensblackjack/background.jpg",
			BITMAP_PIXEL_FORMAT_ARGB8888);

	Label *pLabel = new Label();
	pLabel->Construct(Rectangle(0, 0, 240, 400), null);
	pLabel->SetBackgroundBitmap(*pBitmap);
	AddControl(*pLabel);
	delete pImage;
	delete pBitmap;
	__pButtonNovoJogo->RequestRedraw(true);
	__pButtonRanking->RequestRedraw(true);
	__pButtonInstrucoes->RequestRedraw(true);
	__pButtonSair->RequestRedraw(true);

	return r;
}