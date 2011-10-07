/*
 * FormInstrucoes.cpp
 * Created on: 21/09/2011
 * Author: Catharine
 */

#include "BlackJack/FormInstrucoes.h"
#include "BlackJack/FormMgr.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Media;
using namespace Osp::Graphics;

FormInstrucoes::FormInstrucoes() {
}

FormInstrucoes::~FormInstrucoes() {
}

bool FormInstrucoes::Initialize() {
	// Construct an XML form
	Construct(L"IDF_FORM_INSTRUCOES");

	return true;
}

result FormInstrucoes::OnInitializing(void) {
	result r = E_SUCCESS;

	__pButtonVoltar = static_cast<Button *> (GetControl(L"IDC_BUTTON_VOLTAR"));
	if (__pButtonVoltar != null)
	{
		__pButtonVoltar ->SetActionId(ID_BUTTON_VOLTAR);
		__pButtonVoltar ->AddActionEventListener(*this);
	}

	return r;
}

result FormInstrucoes::OnTerminating(void) {
	result r = E_SUCCESS;
	return r;
}

void FormInstrucoes::OnActionPerformed(const Osp::Ui::Control& source,
		int actionId) {
	Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
	switch (actionId) {
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

result FormInstrucoes::OnDraw(void) {
	Image *pImage = new Image();
	result r = pImage->Construct();
	if (IsFailed(r))
		return r;
	Bitmap *pBitmap = pImage->DecodeN("/Home/background-instr.png",
			BITMAP_PIXEL_FORMAT_ARGB8888);

	Label *pLabel = new Label();
	pLabel->Construct(Rectangle(0, 0, 240, 400), null);
	pLabel->SetBackgroundBitmap(*pBitmap);
	AddControl(*pLabel);
	delete pImage;
	delete pBitmap;
	__pButtonVoltar->RequestRedraw(true);

	return r;
}
