/*
 * FormRanking.h
 * Created on: 21/09/2011
 * Author: Catharine
 */

#ifndef FORMRANKING_H_
#define FORMRANKING_H_

#include <FBase.h>
#include <FUi.h>

class FormRanking: public Osp::Ui::Controls::Form,
		public Osp::Ui::IActionEventListener {

public:
	FormRanking();
	virtual ~FormRanking();
	bool Initialize(void);

protected:
	/*static const int ID_BUTTON_OK = 101;
	 Osp::Ui::Controls::Button *__pButtonOK;
	 */
public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void
	OnActionPerformed(const Osp::Ui::Control& source, int actionId);
};

#endif /* FORMRANKING_H_ */
