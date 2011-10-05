#ifndef _FORMJOGO_H_
#define _FORMJOGO_H_

#include <FBase.h>
#include <FUi.h>
#include "BlackJack/Controlador.h"
#include "BlackJack/IListenerControlador.h"

class FormJogo:
public Osp::Ui::Controls::Form,
public Osp::Ui::IActionEventListener,
public IListenerControlador
{
public:
    FormJogo(void);
    virtual ~FormJogo(void);
    bool Initialize(void);
    void desenharCartas();
protected:
    static const int ID_BUTTON_PUXAR = 101;
    static const int ID_BUTTON_DOBRAR = 102;
    static const int ID_BUTTON_PARAR = 103;
    static const int ID_BUTTON_APOSTA1 = 104;
    static const int ID_BUTTON_APOSTA2 = 105;
    static const int ID_BUTTON_APOSTA3 = 106;
    static const int ID_BUTTON_APOSTA4 = 107;
    static const int ID_BUTTON_APOSTA5 = 108;
    static const int ID_BUTTON_APOSTAR = 109;
    static const int ID_BUTTON_LOBBY = 110;

    Osp::Ui::Controls::Button *__pButtonPuxar;
    Osp::Ui::Controls::Button *__pButtonParar;
    Osp::Ui::Controls::Button *__pButtonDobrar;

    Osp::Ui::Controls::Button *__pButtonLobby;
    Osp::Ui::Controls::Button *__pButtonApostar;

    Osp::Ui::Controls::Button *__pButtonAposta1;
    Osp::Ui::Controls::Button *__pButtonAposta2;
    Osp::Ui::Controls::Button *__pButtonAposta3;
    Osp::Ui::Controls::Button *__pButtonAposta4;
    Osp::Ui::Controls::Button *__pButtonAposta5;

    Osp::Ui::Controls::Button *__pButtonReiniciar;

    Osp::Ui::Controls::Label *__pLabelNome;
    Osp::Ui::Controls::Label *__pLabelPontos;
    Osp::Ui::Controls::Label *__pLabelPontosMao;
    Osp::Ui::Controls::Label *__pLabelPontosMesa;
    Osp::Ui::Controls::Label *__pLabelAposta;
    Controlador *controlador;
private:
    void MostrarBotoesAposta(bool mostrar);
    void MostrarBotoesAcoes(bool mostrar);
    void IrParaLobby();
    void InicializaBotoes();
    void Apostar(int valor);
    void AtualizarInfoJogador();
    void AtualizarInfoControlador();
    void AtualizaBotoesAcoes();
    void InicializaLabels();
    void AtualizaInfoMesa();

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual result OnDraw(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

	virtual void OnInicioJogadaJogador();
	virtual void OnInicioJogadaMesa();
	virtual void OnJogadorPuxaCarta();
	virtual void OnJogadorDobra();
	virtual void OnMesaPuxaCarta();
	virtual void OnFimJogadaJogador();
	virtual void OnFimJogadaMesa();
	virtual void OnInicioPartida();
	virtual void OnFimPartida();
	virtual void OnPagarVencedor();

};

#endif	//_FORMJOGO_H_
