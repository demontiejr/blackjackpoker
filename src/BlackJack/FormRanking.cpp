/*
 * FormRanking.cpp
 * Created on: 21/09/2011
 * Author: Catharine
 */

#include "BlackJack/FormRanking.h"

using namespace Osp::Ui::Controls;

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

	ranking.Construct();

	__pButtonAdd = static_cast<Button *> (GetControl(L"IDC_BUTTON_ADD"));
	if (__pButtonAdd != null)
	{
		__pButtonAdd->SetActionId(ID_BUTTON_ADD);
		__pButtonAdd->AddActionEventListener(*this);
	}

	__pButtonGet = static_cast<Button *>(GetControl(L"IDC_BUTTON_GET"));
	if (__pButtonGet != null)
	{
		__pButtonGet->SetActionId(ID_BUTTON_GET);
		__pButtonGet->AddActionEventListener(*this);
	}

	__pButtonLimpar = static_cast<Button *>(GetControl(L"IDC_BUTTON_LIMPAR"));
	if (__pButtonLimpar != null)
	{
		__pButtonLimpar->SetActionId(ID_BUTTON_LIMPAR);
		__pButtonLimpar->AddActionEventListener(*this);
	}

	__pEditFieldNome = static_cast<EditField *>(GetControl(L"IDC_EDITFIELD_NOME"));
	__pEditFieldPontos = static_cast<EditField *>(GetControl(L"IDC_EDITFIELD_PONTOS"));
	__pEditFieldVitorias = static_cast<EditField *>(GetControl(L"IDC_EDITFIELD_VITORIAS"));
	__pEditFieldPosicao = static_cast<EditField *>(GetControl(L"IDC_EDITFIELD_POSICAO"));

	__pLabelNome = static_cast<Label *>(GetControl(L"IDC_LABEL_NOME"));
	__pLabelPontos = static_cast<Label *>(GetControl(L"IDC_LABEL_PONTOS"));
	__pLabelVitorias = static_cast<Label *>(GetControl(L"IDC_LABEL_VITORIAS"));

	return r;
}

result FormRanking::OnTerminating(void) {
	result r = E_SUCCESS;

	//todo

	return r;
}

void FormRanking::Add()
{
    InfoRanking* info = new InfoRanking();

    String nome = __pEditFieldNome->GetText();

    int pontos;
    Integer::Parse(__pEditFieldPontos->GetText(), pontos);

    int vitorias;
    Integer::Parse(__pEditFieldVitorias->GetText(), vitorias);

    info->Construct(nome, pontos, vitorias);

    ranking.Inserir(info);
}

void FormRanking::Get()
{
    int posicao;
    Integer::Parse(__pEditFieldPosicao->GetText(), posicao);

    InfoRanking* info = ranking.GetInfoPorPosicaoInserir(posicao);

    __pLabelNome->SetText(info->GetNome());
    __pLabelPontos->SetText(Integer::ToString(info->GetPontos()));
    __pLabelVitorias->SetText(Integer::ToString(info->GetVitorias()));

    RequestRedraw(true);

}

void FormRanking::OnActionPerformed(const Osp::Ui::Control& source,
		int actionId) {
	switch (actionId) {

	case ID_BUTTON_ADD: {
		AppLog("ADD Button is clicked! \n");
		Add();
	}
		break;

	case ID_BUTTON_GET: {
		AppLog("GET Button is clicked! \n");
		Get();
	}
		break;

	case ID_BUTTON_LIMPAR: {
		AppLog("LIMPAR Button is clicked! \n");
		ranking.Limpar();
	}
		break;

	default:
		break;
	}
}
