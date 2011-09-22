/*
 * FormRanking.h
 * Created on: 21/09/2011
 * Author: Catharine
 */

#ifndef FORMRANKING_H_
#define FORMRANKING_H_

#include <FBase.h>
#include <FUi.h>
#include "BlackJack/Ranking.h"
#include "BlackJack/InfoRanking.h"

class FormRanking: public Osp::Ui::Controls::Form,
		public Osp::Ui::IActionEventListener {

public:
	FormRanking();
	virtual ~FormRanking();
	bool Initialize(void);

protected:
	static const int ID_BUTTON_ADD = 101;
	static const int ID_BUTTON_GET = 102;
	static const int ID_BUTTON_LIMPAR = 103;

	 Osp::Ui::Controls::Button *__pButtonAdd;
	 Osp::Ui::Controls::Button *__pButtonGet;
	 Osp::Ui::Controls::Button *__pButtonLimpar;

	 Osp::Ui::Controls::EditField *__pEditFieldNome;
	 Osp::Ui::Controls::EditField *__pEditFieldPontos;
	 Osp::Ui::Controls::EditField *__pEditFieldVitorias;
	 Osp::Ui::Controls::EditField *__pEditFieldPosicao;

	 Osp::Ui::Controls::Label *__pLabelNome;
	 Osp::Ui::Controls::Label *__pLabelPontos;
	 Osp::Ui::Controls::Label *__pLabelVitorias;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
	Ranking ranking;
private:
    void Add();
    void Get();
};

#endif /* FORMRANKING_H_ */
