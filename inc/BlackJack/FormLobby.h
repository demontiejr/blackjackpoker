
#ifndef _FORMLOBBY_H_
#define _FORMLOBBY_H_

#include <FBase.h>
#include <FUi.h>
#include <FApp.h>
#include <FMedia.h>
#include <FGraphics.h>


class FormLobby :
public Osp::Ui::Controls::Form,
public Osp::Ui::IActionEventListener
{

	// Construction
public:
	FormLobby();
	virtual ~FormLobby(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
	result OnDraw(void);

	// Implementation
protected:
	static const int ID_BUTTON_MESA1 = 101;
	static const int ID_BUTTON_MESA2 = 102;
	static const int ID_BUTTON_MESA3 = 103;
	static const int ID_BUTTON_VOLTAR = 104;

	Osp::Ui::Controls::Button* __pButtonMesa1;
	Osp::Ui::Controls::Button* __pButtonMesa2;
	Osp::Ui::Controls::Button* __pButtonMesa3;
	Osp::Ui::Controls::Button* __pButtonVoltar;

	Osp::Ui::Controls::Label *__pLabelNome;
	Osp::Ui::Controls::Label *__pLabelDinheiro;

	// Generated call-back functions
public:
private:
    void IrParaMenu();
    void IrParaMesa3();
    void IrParaMesa2();
    void IrParaMesa1();
};

#endif
