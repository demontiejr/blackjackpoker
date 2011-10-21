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

	Osp::Ui::Controls::Label *__pLabelRanking;
	Osp::Ui::Controls::Label *__pLabelNomes;

	Osp::Ui::Controls::Label *__pLabelPosicao1;
	Osp::Ui::Controls::Label *__pLabelPosicao2;
	Osp::Ui::Controls::Label *__pLabelPosicao3;
	Osp::Ui::Controls::Label *__pLabelPosicao4;
	Osp::Ui::Controls::Label *__pLabelPosicao5;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
	Ranking ranking;
	virtual result OnDraw(void);

private:
	void RetrieveData();
	void RedesenhaLabels();
};

#endif /* FORMRANKING_H_ */

