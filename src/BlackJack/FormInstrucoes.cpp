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
		__pButtonVoltar->SetActionId(ID_BUTTON_VOLTAR);
		__pButtonVoltar->AddActionEventListener(*this);
	}

	__pButtonVoltarPagina = static_cast<Button *> (GetControl(L"IDC_BUTTON_VOLTAR_PAGINA"));
	if (__pButtonVoltarPagina != null)
	{
		__pButtonVoltarPagina->SetActionId(ID_BUTTON_VOLTAR_PAGINA);
		__pButtonVoltarPagina->AddActionEventListener(*this);
		__pButtonVoltarPagina->SetShowState(false);
	}

	__pButtonAvancarPagina = static_cast<Button *> (GetControl(L"IDC_BUTTON_AVANCAR_PAGINA"));
	if (__pButtonAvancarPagina != null)
	{
		__pButtonAvancarPagina->SetActionId(ID_BUTTON_AVANCAR_PAGINA);
		__pButtonAvancarPagina->AddActionEventListener(*this);
	}

	this->paginasInstrucoes = new Osp::Base::Collection::ArrayList();
	this->paginasInstrucoes->Construct();
	this->paginaAtual = 0;
	AdicionaPaginasInstrucoes();

	desenhadora.Construct();

	return r;
}

void FormInstrucoes::AdicionaPaginasInstrucoes() {
	paginasInstrucoes->Add(*new String(L"/Home/instrucoes/background1.png"));
	paginasInstrucoes->Add(*new String(L"/Home/instrucoes/background2.png"));
	paginasInstrucoes->Add(*new String(L"/Home/instrucoes/background3.png"));
	paginasInstrucoes->Add(*new String(L"/Home/instrucoes/background4.png"));
	paginasInstrucoes->Add(*new String(L"/Home/instrucoes/background5.png"));
	AppLog("adicionou paginas de instrucoes");
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

	case ID_BUTTON_VOLTAR_PAGINA: {
		this->paginaAtual--;
		AtualizaBotoes();
	}
		break;

	case ID_BUTTON_AVANCAR_PAGINA: {
		this->paginaAtual++;
		AtualizaBotoes();
	}
			break;

	default:
		break;
	}

	RequestRedraw(true);

}

void FormInstrucoes::AtualizaBotoes() {
	AppLog("Pagina atual: %d/%d", paginaAtual, paginasInstrucoes->GetCount()-1);
	__pButtonVoltarPagina->SetShowState(paginaAtual > 0);
	__pButtonAvancarPagina->SetShowState(paginaAtual < (paginasInstrucoes->GetCount()-1));
}

result FormInstrucoes::OnDraw(void) {
	Canvas* pCanvas = GetCanvasN();
	if (pCanvas != null) {
		desenhadora.DesenhaBackground(pCanvas,
				*static_cast<String*>(paginasInstrucoes->GetAt(paginaAtual)));

		pCanvas->Show();

		delete pCanvas;
	}

	return E_SUCCESS;
}
