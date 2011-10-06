/*
 * FormRanking.h
 * Created on: 21/09/2011
 * Author: Catharine
 */

#ifndef FORMRANKING_H_
#define FORMRANKING_H_

#include <FBase.h>
#include <FUi.h>
#include <FMedia.h>
#include <FGraphics.h>
#include "BlackJack/Ranking.h"
#include "BlackJack/InfoRanking.h"


class FormRanking: public Osp::Ui::Controls::Form,
		public Osp::Ui::IActionEventListener {

public:
	FormRanking();
	virtual ~FormRanking();
	bool Initialize(void);

protected:
	static const int ID_BUTTON_LIMPAR = 103;
	static const int ID_BUTTON_VOLTAR = 104;

	 Osp::Ui::Controls::Button *__pButtonLimpar;
	 Osp::Ui::Controls::Button *__pButtonVoltar;
	 Osp::Ui::Controls::EditArea *__pEditAreaRanking;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
	Ranking ranking;
	virtual result OnDraw(void);

private:
	void RetrieveData();
//    void Add();
//    void Get();
};

#endif /* FORMRANKING_H_ */
