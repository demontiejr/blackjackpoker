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

	__pLabelRanking = static_cast<Label *>(GetControl(L"IDC_LABEL_RANKING"));
	__pLabelNomes = static_cast<Label *>(GetControl(L"IDC_LABEL_NOMES"));

	//Criando lista do ranking
	__pLabelPosicao1 = static_cast<Label *>(GetControl(L"IDC_LABEL_POSICAO1"));
	__pLabelPosicao2 = static_cast<Label *>(GetControl(L"IDC_LABEL_POSICAO2"));
	__pLabelPosicao3 = static_cast<Label *>(GetControl(L"IDC_LABEL_POSICAO3"));
	__pLabelPosicao4 = static_cast<Label *>(GetControl(L"IDC_LABEL_POSICAO4"));
	__pLabelPosicao5 = static_cast<Label *>(GetControl(L"IDC_LABEL_POSICAO5"));

	RetrieveData();

	return r;
}

result FormRanking::OnTerminating(void) {
	result r = E_SUCCESS;

	//todo

	return r;
}

void FormRanking::RetrieveData() {
	InfoRanking* info = ranking.GetInfoPorPosicaoInserir(1);
	__pLabelPosicao1->SetText(info->ToString());

	info = ranking.GetInfoPorPosicaoInserir(2);
	__pLabelPosicao2->SetText(info->ToString());

	info = ranking.GetInfoPorPosicaoInserir(3);
	__pLabelPosicao3->SetText(info->ToString());

	info = ranking.GetInfoPorPosicaoInserir(4);
	__pLabelPosicao4->SetText(info->ToString());

	info = ranking.GetInfoPorPosicaoInserir(5);
	__pLabelPosicao5->SetText(info->ToString());
}

void FormRanking::OnActionPerformed(const Osp::Ui::Control& source,
		int actionId) {
	Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
	switch (actionId) {
	case ID_BUTTON_LIMPAR: {
		AppLog("LIMPAR Button is clicked! \n");
		ranking.Limpar();
		RetrieveData();
		RedesenhaLabels();
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
	__pLabelRanking->RequestRedraw(true);
	__pLabelNomes->RequestRedraw(true);

	__pButtonLimpar->RequestRedraw(true);
	__pButtonVoltar->RequestRedraw(true);
	RedesenhaLabels();

	return r;
}

void FormRanking::RedesenhaLabels() {
	__pLabelPosicao1->RequestRedraw(true);
	__pLabelPosicao2->RequestRedraw(true);
	__pLabelPosicao3->RequestRedraw(true);
	__pLabelPosicao4->RequestRedraw(true);
	__pLabelPosicao5->RequestRedraw(true);
}
