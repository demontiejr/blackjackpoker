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

	// Construction
public:
	FormJogo(void);
	virtual ~FormJogo(void);
	bool Initialize(void);
	void desenharCartas();

	// Implementation
protected:
	static const int ID_BUTTON_PUXAR = 102;
	static const int ID_BUTTON_PARAR = 103;
	static const int ID_BUTTON_REINICIAR = 104;
	Osp::Ui::Controls::Button *__pButtonPuxar;
	Osp::Ui::Controls::Button *__pButtonParar;
	Osp::Ui::Controls::Button *__pButtonReiniciar;
	Osp::Ui::Controls::Label *__pLabelPontos;
	//	Osp::System::Vibrator *myVibrator;
	Controlador *controlador;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual result OnDraw(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

	virtual void OnInicioJogadaJogador();
	virtual void OnInicioJogadaMesa();
	virtual void OnFimJogadaJogador();
	virtual void OnFimJogadaMesa();
	virtual void OnInicioPartida();
	virtual void OnFimPartida();
	virtual void OnPagarVencedor();

};

#endif	//_FORMJOGO_H_
