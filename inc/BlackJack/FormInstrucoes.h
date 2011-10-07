/*
 * FormInstrucoes.h
 * Created on: 21/09/2011
 * Author: Catharine
 */

#ifndef FORMINSTRUCOES_H_
#define FORMINSTRUCOES_H_

#include <FBase.h>
#include <FUi.h>
#include <FMedia.h>
#include <FGraphics.h>

class FormInstrucoes: public Osp::Ui::Controls::Form,
		public Osp::Ui::IActionEventListener {

public:
	FormInstrucoes();
	virtual ~FormInstrucoes();
	bool Initialize(void);

protected:
	static const int ID_BUTTON_VOLTAR = 101;
	Osp::Ui::Controls::Button *__pButtonVoltar;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void
	OnActionPerformed(const Osp::Ui::Control& source, int actionId);
	virtual result OnDraw(void);
};

#endif /* FORMINSTRUCOES_H_ */
