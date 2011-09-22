/*
 * FormRanking.cpp
 * Created on: 21/09/2011
 * Author: Catharine
 */

#include "BlackJack/FormRanking.h"

FormRanking::FormRanking() {
	// TODO Auto-generated constructor stub

}

FormRanking::~FormRanking() {
	// TODO Auto-generated destructor stub
}

bool FormRanking::Initialize() {
	// Construct an XML form
	Construct(L"IDF_FORM_RANKING");

	return true;
}

result FormRanking::OnInitializing(void) {
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

result FormRanking::OnTerminating(void) {
	result r = E_SUCCESS;

	//todo

	return r;
}

void FormRanking::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {
	/*switch (actionId) {
	case ID_BUTTON_OK: {
		AppLog("OK Button is clicked! \n");
	}
		break;

	default:
		break;
	} */
}
