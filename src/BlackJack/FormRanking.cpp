/*
 * FormRanking.cpp
 * Created on: 21/09/2011
 * Author: Catharine
 */

#include "BlackJack/FormRanking.h"
#include "BlackJack/FormMgr.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Media;
using namespace Osp::Graphics;

FormRanking::FormRanking() {

}

FormRanking::~FormRanking() {
}

bool FormRanking::Initialize() {
	// Construct an XML form
	Construct(L"IDF_FORM_RANKING");

	return true;
}

result FormRanking::OnInitializing(void) {
	result r = E_SUCCESS;

	ranking.Construct();

	__pButtonLimpar = static_cast<Button *>(GetControl(L"IDC_BUTTON_LIMPAR"));
	if (__pButtonLimpar != null)
	{
		__pButtonLimpar->SetActionId(ID_BUTTON_LIMPAR);
		__pButtonLimpar->AddActionEventListener(*this);
	}

	__pButtonVoltar = static_cast<Button *>(GetControl(L"IDC_BUTTON_VOLTAR"));
	if (__pButtonVoltar != null)
	{
		__pButtonVoltar->SetActionId(ID_BUTTON_VOLTAR);
		__pButtonVoltar->AddActionEventListener(*this);
	}

	//Criando lista do ranking
	__pEditAreaRanking = static_cast<EditArea *>(GetControl(L"IDC_EDITAREA_RANKING"));
	if (__pEditAreaRanking != null)
	{
		__pEditAreaRanking->SetEnabled(false);
	}

	RetrieveData();

	return r;
}

result FormRanking::OnTerminating(void) {
	result r = E_SUCCESS;

	//todo

	return r;
}

void FormRanking::RetrieveData() {
	String text;
	for (int i=1; i <= 5; i++) {
		InfoRanking* info = ranking.GetInfoPorPosicaoInserir(i);
		text.Append(info->ToString());
		text.Append("\n");
	}
	__pEditAreaRanking->SetText(text);
}

//void FormRanking::Add() {
//	InfoRanking* info = new InfoRanking();
//
//	String nome = __pEditFieldNome->GetText();
//
//	int pontos;
//	Integer::Parse(__pEditFieldPontos->GetText(), pontos);
//
//	int vitorias;
//	Integer::Parse(__pEditFieldVitorias->GetText(), vitorias);
//
//	info->Construct(nome, pontos, vitorias);
//
//	ranking.Inserir(info);
//}

//void FormRanking::Get() {
//	int posicao;
//	Integer::Parse(__pEditFieldPosicao->GetText(), posicao);
//
//	InfoRanking* info = ranking.GetInfoPorPosicaoInserir(posicao);
//
//	__pLabelNome->SetText(info->GetNome());
//	__pLabelPontos->SetText(Integer::ToString(info->GetPontos()));
//	__pLabelVitorias->SetText(Integer::ToString(info->GetVitorias()));
//
//	RequestRedraw(true);
//
//}

void FormRanking::OnActionPerformed(const Osp::Ui::Control& source,
		int actionId) {
	Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
	switch (actionId) {
	case ID_BUTTON_LIMPAR: {
		AppLog("LIMPAR Button is clicked! \n");
		ranking.Limpar();
		RetrieveData();
		__pEditAreaRanking->RequestRedraw(true);
	}
		break;

	case ID_BUTTON_VOLTAR: {
		AppLog("VOLTAR Button is clicked! \n");
		FormMgr *pFormMgr = static_cast<FormMgr *> (pFrame->GetControl(
				"FormMgr"));
		if (pFormMgr != null)
			pFormMgr->SendUserEvent(FormMgr::REQUEST_FORM_MENU, null);

	}
		break;

	default:
		break;
	}
}

result FormRanking::OnDraw(void) {
	Image *pImage = new Image();
	result r = pImage->Construct();
	if (IsFailed(r))
		return r;
	Bitmap *pBitmap = pImage->DecodeN("/Home/background.jpg",
			BITMAP_PIXEL_FORMAT_ARGB8888);

	Label *pLabel = new Label();
	pLabel->Construct(Rectangle(0, 0, 240, 400), null);
	pLabel->SetBackgroundBitmap(*pBitmap);
	AddControl(*pLabel);
	delete pImage;
	delete pBitmap;
	__pButtonLimpar->RequestRedraw(true);
	__pButtonVoltar->RequestRedraw(true);
	__pEditAreaRanking->RequestRedraw(true);

	return r;
}
