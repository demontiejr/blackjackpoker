/*
 * FormMenu.h
 * Created on: 21/09/2011
 * Author: Catharine
 */

#ifndef FORMMENU_H_
#define FORMMENU_H_

#include <FBase.h>
#include <FUi.h>
#include <FMedia.h>
#include <FGraphics.h>

class FormMenu:
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener
{
public:
	FormMenu();
	virtual ~FormMenu();
	bool Initialize(void);

// Implementation
protected:
	static const int ID_BUTTON_NOVO_JOGO = 101;
	static const int ID_BUTTON_RANKING = 102;
	static const int ID_BUTTON_INSTRUCOES = 103;

	Osp::Ui::Controls::Button *__pButtonNovoJogo;
	Osp::Ui::Controls::Button *__pButtonRanking;
	Osp::Ui::Controls::Button *__pButtonInstrucoes;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
	virtual result OnDraw(void);

};

#endif /* FORMMENU_H_ */
