/*
 * SmartTimer.h
 *
 *  Created on: 06/10/2011
 *      Author: Arthur Holanda
 */

#ifndef SMARTTIMER_H_
#define SMARTTIMER_H_

#include <FBase.h>

class SmartTimer :
	public Osp::Base::Runtime::Timer{
public:
	SmartTimer();
	virtual ~SmartTimer();
	int actionId;
	void Construir(Osp::Base::Runtime::ITimerEventListener& listener);
	void Iniciar(int acionId, int milisegundos);
	void Cancelar();
};

#endif /* SMARTTIMER_H_ */
