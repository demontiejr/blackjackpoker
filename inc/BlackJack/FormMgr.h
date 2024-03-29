#ifndef _FORMMGR_H_
#define _FORMMGR_H_

#include <FApp.h>
#include <FBase.h>
#include <FUi.h>

class FormMgr :
	public Osp::Ui::Controls::Form
{
public:
	FormMgr(void);
	virtual ~FormMgr(void);

public:
	bool Initialize();
	bool SetStarterForm(RequestId requestId, Osp::Base::Collection::IList* pArgs);
	static const RequestId REQUEST_FORM_JOGO = 100;
	static const RequestId REQUEST_FORM_MENU = 101;
	static const RequestId REQUEST_FORM_INSTRUCOES = 102;
	static const RequestId REQUEST_FORM_RANKING = 103;
	static const RequestId REQUEST_FORM_LOBBY = 104;

protected:
	void SwitchToForm(RequestId requestId, Osp::Base::Collection::IList* pArgs);
	Osp::Ui::Controls::Form *__pPreviousForm;

public:
	virtual void OnUserEventReceivedN(RequestId requestId, Osp::Base::Collection::IList* pArgs);
};

#endif
