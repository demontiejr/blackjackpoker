/*
 * SmartTimer.cpp
 *
 *  Created on: 06/10/2011
 *      Author: Arthur Holanda
 */

#include "BlackJack/SmartTimer.h"

SmartTimer::SmartTimer() {
}

SmartTimer::~SmartTimer() {
}

void SmartTimer::Iniciar(int acionId, int milisegundos) {
	this->actionId = acionId;

	result r = E_SUCCESS;
	r = this->Start(milisegundos);

	if (IsFailed(r)) {
		goto CATCH;
	}

	return;

	CATCH: return;
}

void SmartTimer::Construir(Osp::Base::Runtime::ITimerEventListener & listener)
{
	this->Construct(listener);
}

void SmartTimer::Cancelar() {
	this->Cancel();
}

