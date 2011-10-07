
#ifndef _FORMLOBBY_H_
#define _FORMLOBBY_H_

#include <FBase.h>
#include <FUi.h>
#include <FApp.h>

class FormLobby :
public Osp::Ui::Controls::Form,
public Osp::Ui::IActionEventListener
{

	// Construction
public:
	FormLobby(void);
	virtual ~FormLobby(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

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


	// Generated call-back functions
public:
private:
    void IrParaMenu();
    void IrParaMesa3();
    void IrParaMesa2();
    void IrParaMesa1();
};

#endif
