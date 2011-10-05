#include "BlackJack/FormLobby.h"
#include "BlackJack/FormMgr.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::App;

FormLobby::FormLobby(void)
{
}

FormLobby::~FormLobby(void)
{
}

bool
FormLobby::Initialize()
{
	Form::Construct(L"IDF_FORM_LOBBY");

	return true;
}

result
FormLobby::OnInitializing(void)
{
	result r = E_SUCCESS;

	__pButtonMesa1 = static_cast<Button*> (GetControl(L"IDC_BUTTON_MESA1"));
	if(__pButtonMesa1 != null){
		__pButtonMesa1->SetActionId(ID_BUTTON_MESA1);
		__pButtonMesa1->AddActionEventListener(*this);
	}

	__pButtonMesa2 = static_cast<Button*> (GetControl(L"IDC_BUTTON_MESA2"));
	if(__pButtonMesa2 != null){
		__pButtonMesa2->SetActionId(ID_BUTTON_MESA2);
		__pButtonMesa2->AddActionEventListener(*this);
	}

	__pButtonMesa3 = static_cast<Button*> (GetControl(L"IDC_BUTTON_MESA3"));
	if(__pButtonMesa3 != null){
		__pButtonMesa3->SetActionId(ID_BUTTON_MESA3);
		__pButtonMesa3->AddActionEventListener(*this);
	}

	__pButtonVoltar = static_cast<Button*> (GetControl(L"IDC_BUTTON_VOLTAR"));
	if(__pButtonVoltar != null){
		__pButtonVoltar->SetActionId(ID_BUTTON_VOLTAR);
		__pButtonVoltar->AddActionEventListener(*this);
	}

	return r;
}

result
FormLobby::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void FormLobby::IrParaMesa1()
{
	AppLog("Mesa 1");
	Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
	FormMgr *pFormMgr = static_cast<FormMgr *> (pFrame->GetControl(
			"FormMgr"));
	if (pFormMgr != null)
		pFormMgr->SendUserEvent(FormMgr::REQUEST_FORM_JOGO, null);
}

void FormLobby::IrParaMesa2()
{
	AppLog("Mesa 2");
	Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
	FormMgr *pFormMgr = static_cast<FormMgr *> (pFrame->GetControl(
				"FormMgr"));
		if (pFormMgr != null)
			pFormMgr->SendUserEvent(FormMgr::REQUEST_FORM_JOGO, null);
}

void FormLobby::IrParaMesa3()
{
	AppLog("Mesa 3");
	Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
	FormMgr *pFormMgr = static_cast<FormMgr *> (pFrame->GetControl(
				"FormMgr"));
		if (pFormMgr != null)
			pFormMgr->SendUserEvent(FormMgr::REQUEST_FORM_JOGO, null);
}

void FormLobby::IrParaMenu()
{
	Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
	FormMgr *pFormMgr = static_cast<FormMgr *> (pFrame->GetControl(
				"FormMgr"));
		if (pFormMgr != null)
			pFormMgr->SendUserEvent(FormMgr::REQUEST_FORM_MENU, null);
}

void FormLobby::OnActionPerformed(const Osp::Ui::Control & source, int actionId) {
	switch (actionId) {
	case ID_BUTTON_MESA1:
		IrParaMesa1();
		break;
	case ID_BUTTON_MESA2:
		IrParaMesa2();
		break;
	case ID_BUTTON_MESA3:
		IrParaMesa3();
		break;
	case ID_BUTTON_VOLTAR:
		IrParaMenu();
		break;
	default:
		break;
	}
}




