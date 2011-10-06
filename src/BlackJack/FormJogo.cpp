#include "BlackJack/FormJogo.h"
#include "BlackJack/FormMgr.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Base::Utility;
using namespace Osp::App;
using namespace Osp::Media;
using namespace Osp::Graphics;

FormJogo::FormJogo(void) {

}

FormJogo::~FormJogo(void) {
	//	delete myVibrator;
}

bool FormJogo::Initialize() {
	// Construct an XML form
	Construct(L"IDF_FORM_JOGO");


	return true;
}

void FormJogo::InicializaBotoes()
{
	__pButtonPuxar = static_cast<Button*>(GetControl(L"IDC_BUTTON_PUXAR"));
	if (__pButtonPuxar != null)
	{
		__pButtonPuxar->SetActionId(ID_BUTTON_PUXAR);
		__pButtonPuxar->AddActionEventListener(*this);
	}
	__pButtonDobrar = static_cast<Button*>(GetControl(L"IDC_BUTTON_DOBRAR"));
	if (__pButtonDobrar != null)
	{
		__pButtonDobrar->SetActionId(ID_BUTTON_DOBRAR);
		__pButtonDobrar->AddActionEventListener(*this);
	}
	__pButtonParar = static_cast<Button*>(GetControl(L"IDC_BUTTON_PARAR"));
	if (__pButtonParar != null)
	{
		__pButtonParar->SetActionId(ID_BUTTON_PARAR);
		__pButtonParar->AddActionEventListener(*this);
	}
	__pButtonAposta1 = static_cast<Button*>(GetControl(L"IDC_BUTTON_APOSTA1"));
	if (__pButtonAposta1 != null)
	{
		__pButtonAposta1->SetActionId(ID_BUTTON_APOSTA1);
		__pButtonAposta1->AddActionEventListener(*this);
	}
	__pButtonAposta2 = static_cast<Button*>(GetControl(L"IDC_BUTTON_APOSTA2"));
	if (__pButtonAposta2 != null)
	{
		__pButtonAposta2->SetActionId(ID_BUTTON_APOSTA2);
		__pButtonAposta2->AddActionEventListener(*this);
	}
	__pButtonAposta3 = static_cast<Button*>(GetControl(L"IDC_BUTTON_APOSTA3"));
	if (__pButtonAposta3 != null)
	{
		__pButtonAposta3->SetActionId(ID_BUTTON_APOSTA3);
		__pButtonAposta3->AddActionEventListener(*this);
	}
	__pButtonAposta4 = static_cast<Button*>(GetControl(L"IDC_BUTTON_APOSTA4"));
	if (__pButtonAposta4 != null)
	{
		__pButtonAposta4->SetActionId(ID_BUTTON_APOSTA4);
		__pButtonAposta4->AddActionEventListener(*this);
	}
	__pButtonAposta5 = static_cast<Button*>(GetControl(L"IDC_BUTTON_APOSTA5"));
	if (__pButtonAposta5 != null)
	{
		__pButtonAposta5->SetActionId(ID_BUTTON_APOSTA5);
		__pButtonAposta5->AddActionEventListener(*this);
	}
	__pButtonApostar = static_cast<Button*>(GetControl(L"IDC_BUTTON_APOSTAR"));
	if (__pButtonApostar != null)
	{
		__pButtonApostar->SetActionId(ID_BUTTON_APOSTAR);
		__pButtonApostar->AddActionEventListener(*this);
	}
	__pButtonLobby = static_cast<Button*>(GetControl(L"IDC_BUTTON_LOBBY"));
	if (__pButtonLobby != null)
	{
		__pButtonLobby->SetActionId(ID_BUTTON_LOBBY);
		__pButtonLobby->AddActionEventListener(*this);
	}
}

void FormJogo::AtualizarInfoJogador()
{
    this->__pLabelNome->SetText(controlador->GetJogador()->GetNome());
    this->__pLabelPontos->SetText("Money: $" + Integer::ToString(controlador->GetJogador()->GetPontos()));
    this->__pLabelPontosMao->SetText("Points: " + Integer::ToString(controlador->GetJogador()->GetMao()->GetValor()));
}

void FormJogo::AtualizarInfoControlador()
{
    __pLabelAposta->SetText("Pot: $" + Integer::ToString(controlador->GetValorPote()));
}

void FormJogo::InicializaLabels()
{
    __pLabelNome = static_cast<Label*>(GetControl(L"IDC_LABEL_NOME"));
    __pLabelPontos = static_cast<Label*>(GetControl(L"IDC_LABEL_PONTOS"));
    __pLabelAposta = static_cast<Label*>(GetControl(L"IDC_LABEL_APOSTA"));
    __pLabelPontosMao = static_cast<Label*>(GetControl(L"IDC_LABEL_PONTOS_MAO"));
    __pLabelPontosMesa = static_cast<Label*>(GetControl(L"IDC_LABEL_PONTOS_MESA"));
}

result FormJogo::OnInitializing(void) {
	result r = E_SUCCESS;

	InicializaBotoes();
    InicializaLabels();

    controlador = Controlador::GetInstance();
	//controlador = new Controlador();
	controlador->Construct();
	controlador->SetListener(this);

	Jogador* j = new Jogador();
	j->Construct("Arthur");
	j->Receber(100);
	j->SetControlador(controlador);
	controlador->SetJogador(j);


    AtualizarInfoJogador();
    AtualizarInfoControlador();

    controlador->IniciarPartida();

	return r;
}

result FormJogo::OnTerminating(void) {
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void FormJogo::IrParaLobby()
{
	Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
	FormMgr *pFormMgr = static_cast<FormMgr *> (pFrame->GetControl(
			"FormMgr"));
	if (pFormMgr != null)
		pFormMgr->SendUserEvent(FormMgr::REQUEST_FORM_LOBBY, null);
}

void FormJogo::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {

	switch (actionId) {
	case ID_BUTTON_PUXAR: {
		AppLog("Puxar");
		controlador->JogadorPuxaCarta();
	}
	break;

	case ID_BUTTON_DOBRAR: {
		controlador->JogadorDobra();
		AppLog("Dobrar");
	}
	break;

	case ID_BUTTON_PARAR: {
		AppLog("Parar");
		controlador->FimJogadaJogador();
	}
	break;

	case ID_BUTTON_LOBBY: {
		IrParaLobby();
	}
	break;

	case ID_BUTTON_APOSTAR: {
		AppLog("Apostar");
	}
	break;

	case ID_BUTTON_APOSTA1: {
		AppLog("Aposta 1");
		Apostar(1);
	}
	break;

	case ID_BUTTON_APOSTA2: {
		AppLog("Aposta 2");
	}
	break;

	case ID_BUTTON_APOSTA3: {
		AppLog("Aposta 3");
	}
	break;

	case ID_BUTTON_APOSTA4: {
		AppLog("Aposta 4");
	}
	break;

	case ID_BUTTON_APOSTA5: {
		AppLog("Aposta 5");
	}
	break;

	default:
		break;
	}

	RequestRedraw(true);
}

void FormJogo::desenharCartas() {

}

result FormJogo::OnDraw(void) {
	/*
	 Image *pImage = new Image();

	 result r = pImage->Construct();

	 if (IsFailed(r))
	 return r;

	 Bitmap *pBitmap = pImage->DecodeN("/Home/background.png",
	 BITMAP_PIXEL_FORMAT_ARGB8888);

	 Canvas* pCanvas = GetCanvasN();
	 if(pCanvas){
	 pCanvas->Clear();

	 pCanvas->DrawBitmap(Point(0, 0), *pBitmap);
	 controlador->desenharCartas(pCanvas);

	 pCanvas->Show();

	 delete pCanvas;
	 }

	 delete pImage;
	 delete pBitmap;

	 return r;
	 */

	return E_SUCCESS;
}

//TODO - implementar os metodos da interface

void FormJogo::AtualizaInfoMesa()
{
    __pLabelPontosMesa->SetText("Points: " + Integer::ToString(controlador->GetMesa()->GetMao()->GetValor()));
}

void FormJogo::OnFimJogadaMesa() {
    AtualizaInfoMesa();
    RequestRedraw(true);
	controlador->FimPartida();
}

void FormJogo::OnInicioPartida() {
	MostrarBotoesAcoes(false);
	MostrarBotoesAposta(true);
	RequestRedraw(true);
}

void FormJogo::OnInicioJogadaMesa() {
	//TODO - adicionar acao
	controlador->JogadaMesa();
}

void FormJogo::OnFimJogadaJogador() {
	//TODO - adicionar acao
	controlador->InicioJogadaMesa();
}

void FormJogo::OnMesaPuxaCarta() {
	//TODO - adicionar acao
	controlador->JogadaMesa();
}

void FormJogo::AtualizaBotoesAcoes()
{
    bool cond = (controlador->GetJogador()->GetMao()->GetValor() >= 21);
    __pButtonPuxar->SetEnabled(!cond);
    __pButtonDobrar->SetEnabled(!cond);
}

void FormJogo::OnJogadorPuxaCarta() {
    AtualizaBotoesAcoes();
	AtualizarInfoJogador();
	RequestRedraw(true);
}

void FormJogo::MostrarBotoesAposta(bool mostrar)
{
	__pButtonAposta1->SetShowState(mostrar);
	__pButtonAposta2->SetShowState(mostrar);
	__pButtonAposta3->SetShowState(mostrar);
	__pButtonAposta4->SetShowState(mostrar);
	__pButtonAposta5->SetShowState(mostrar);
	__pButtonApostar->SetShowState(mostrar);
	__pButtonLobby->SetShowState(mostrar);
}

void FormJogo::MostrarBotoesAcoes(bool mostrar)
{
	AtualizaBotoesAcoes();
	__pButtonPuxar->SetShowState(mostrar);
	__pButtonDobrar->SetShowState(mostrar);
	__pButtonParar->SetShowState(mostrar);
}

void FormJogo::Apostar(int valor)
{
	//TODO - debitar quantia do jogador
	//TODO - colocar quantia em dobro no valor da aposta do controlador
	controlador->GetJogador()->Apostar(valor);
	controlador->SetValorPote(valor*2);

	AtualizarInfoControlador();
	AtualizarInfoJogador();

	RequestRedraw(true);

	controlador->InicioJogadaJogador();
}

void FormJogo::OnPagarVencedor() {
	//TODO - adicionar acao

	AtualizaInfoMesa();
	AtualizarInfoControlador();
	AtualizarInfoJogador();

	RequestRedraw(true);

	controlador->IniciarPartida();
}

void FormJogo::OnInicioJogadaJogador() {
	MostrarBotoesAposta(false);
	MostrarBotoesAcoes(true);
	RequestRedraw(true);
}

void FormJogo::OnFimPartida() {
	//TODO - adicionar acao
	controlador->PagarVencedor();
}

void FormJogo::OnJogadorDobra() {
	AtualizarInfoJogador();
	AtualizarInfoControlador();
	RequestRedraw(true);

	controlador->FimJogadaJogador();
}
