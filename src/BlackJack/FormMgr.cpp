#include "BlackJack/FormMgr.h"
#include "BlackJack/FormJogo.h"
#include "BlackJack/FormMenu.h"
#include "BlackJack/FormInstrucoes.h"
#include "BlackJack/FormRanking.h"
#include "BlackJack/FormLobby.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

FormMgr::FormMgr(void) :
		__pPreviousForm(null)
		{
		}

FormMgr::~FormMgr(void)
{
}

bool FormMgr::Initialize()
{
	result r = E_SUCCESS;
	r = Form::Construct(FORM_STYLE_NORMAL);
	SetName(L"FormMgr");

	return true;
}

bool FormMgr::SetStarterForm(RequestId requestId, Osp::Base::Collection::IList* pArgs)
{
	Form *pCurrentForm = Application::GetInstance()->GetAppFrame()->GetFrame()->GetCurrentForm();

	if (pCurrentForm == this)
		SwitchToForm(requestId, pArgs);
	else
		return false;

	return true;
}

void FormMgr::OnUserEventReceivedN(RequestId requestId, Osp::Base::Collection::IList* pArgs)
{
	SwitchToForm(requestId, pArgs);
}

void FormMgr::SwitchToForm(RequestId requestId, Osp::Base::Collection::IList* pArgs)
{
	Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();

	switch(requestId)
	{
	case REQUEST_FORM_JOGO:
	{
		FormJogo *pFormJogo = new FormJogo();
		pFormJogo->Initialize();
		Integer apostaMinima = *static_cast<Integer*>(pArgs->GetAt(0));
		Integer apostaMaxima = *static_cast<Integer*>(pArgs->GetAt(1));
		String imgPath = *static_cast<String*>(pArgs->GetAt(2));
		pFormJogo->SetAtributos(apostaMinima, apostaMaxima, imgPath);
		pFrame->AddControl(*pFormJogo);
		pFrame->SetCurrentForm(*pFormJogo);
		pFormJogo->Draw();
		pFormJogo->Show();
		if (__pPreviousForm != null)
			pFrame->RemoveControl(*__pPreviousForm);
		__pPreviousForm = pFormJogo;
	}
	break;
	case REQUEST_FORM_MENU:
	{
		FormMenu *pFormMenu = new FormMenu();
		pFormMenu->Initialize();
		pFrame->AddControl(*pFormMenu);
		pFrame->SetCurrentForm(*pFormMenu);
		pFormMenu->Draw();
		pFormMenu->Show();
		if (__pPreviousForm != null)
			pFrame->RemoveControl(*__pPreviousForm);
		__pPreviousForm = pFormMenu;
	}
	break;
	case REQUEST_FORM_INSTRUCOES:
	{
		FormInstrucoes *pFormInstrucoes = new FormInstrucoes();
		pFormInstrucoes->Initialize();
		pFrame->AddControl(*pFormInstrucoes);
		pFrame->SetCurrentForm(*pFormInstrucoes);
		pFormInstrucoes->Draw();
		pFormInstrucoes->Show();
		if (__pPreviousForm != null)
			pFrame->RemoveControl(*__pPreviousForm);
		__pPreviousForm = pFormInstrucoes;
	}
	break;
	case REQUEST_FORM_RANKING:
	{
		FormRanking *pFormRanking = new FormRanking();
		pFormRanking->Initialize();
		pFrame->AddControl(*pFormRanking);
		pFrame->SetCurrentForm(*pFormRanking);
		pFormRanking->Draw();
		pFormRanking->Show();
		if (__pPreviousForm != null)
			pFrame->RemoveControl(*__pPreviousForm);
		__pPreviousForm = pFormRanking;
	}
	break;

	case REQUEST_FORM_LOBBY:
	{
		FormLobby *pFormLobby = new FormLobby();
		pFormLobby->Initialize();
		pFrame->AddControl(*pFormLobby);
		pFrame->SetCurrentForm(*pFormLobby);
		pFormLobby->Draw();
		pFormLobby->Show();
		if (__pPreviousForm != null)
			pFrame->RemoveControl(*__pPreviousForm);
		__pPreviousForm = pFormLobby;
	}
	break;
	default:
		break;
	}
}
