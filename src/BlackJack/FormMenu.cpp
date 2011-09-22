/*
 * FormMenu.cpp
 * Created on: 21/09/2011
 * Author: Catharine
 */

#include "BlackJack/FormMenu.h"

FormMenu::FormMenu() {
	// TODO Auto-generated constructor stub

}

FormMenu::~FormMenu() {
	// TODO Auto-generated destructor stub
}

bool FormMenu::Initialize() {
	// Construct an XML form
	Construct(L"IDF_FORM_MENU");

	return true;
}

result FormMenu::OnInitializing(void) {
	result r = E_SUCCESS;

	/*__pButtonNovoJogo = static_cast<Button *>(GetControl(L"IDC_BUTTON_NOVO_JOGO"));
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
	 __pButtonInstrucoes->SetActionId(ID_BUTTON_RANKING);
	 __pButtonInstrucoes->AddActionEventListener(*this);
	 }  */

	return r;
}

result FormMenu::OnTerminating(void) {
	result r = E_SUCCESS;

	//todo

	return r;
}

void FormMenu::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {
	switch (actionId) {
	case ID_BUTTON_NOVO_JOGO: {
		AppLog("NOVO JOGO Button is clicked! \n");
	}
		break;

	case ID_BUTTON_RANKING: {
		AppLog("RANKING Button is clicked! \n");
	}
		break;

	case ID_BUTTON_INSTRUCOES: {
		AppLog("INSTRUCOES Button is clicked! \n");
	}
		break;

	default:
		break;
	}
}
