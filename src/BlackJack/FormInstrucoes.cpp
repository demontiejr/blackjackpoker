/*
 * FormInstrucoes.cpp
 * Created on: 21/09/2011
 * Author: Catharine
 */

#include "BlackJack/FormInstrucoes.h"

FormInstrucoes::FormInstrucoes() {
	// TODO Auto-generated constructor stub

}

FormInstrucoes::~FormInstrucoes() {
	// TODO Auto-generated destructor stub
}

bool FormInstrucoes::Initialize() {
	// Construct an XML form
	Construct(L"IDF_FORM_INSTRUCOES");

	return true;
}

result FormInstrucoes::OnInitializing(void) {
	result r = E_SUCCESS;

	/*__pButtonOK = static_cast<Button *>(GetControl(L"IDC_BUTTON_OK"));
	 if (__pButtonNovoJogo != null)
	 {
	 __pButtonOK->SetActionId(ID_BUTTON_OK);
	 __pButtonOK->AddActionEventListener(*this);
	 }

	 */

	return r;
}

result FormInstrucoes::OnTerminating(void) {
	result r = E_SUCCESS;

	//todo

	return r;
}

void FormInstrucoes::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {
	/*switch (actionId) {
	case ID_BUTTON_OK: {
		AppLog("OK Button is clicked! \n");
	}
		break;

	default:
		break;
	} */
}
