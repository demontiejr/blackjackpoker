/**
 * Name        : blackjackpoker
 * Version     : 
 * Vendor      : 
 * Description : 
 */

#include "BlackJack/blackjackpoker.h"
#include "BlackJack/FormMgr.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::System;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

blackjackpoker::blackjackpoker()
{
}

blackjackpoker::~blackjackpoker()
{
}

Application*
blackjackpoker::CreateInstance(void)
{
	return new blackjackpoker();
}

bool
blackjackpoker::OnAppInitializing(AppRegistry& appRegistry)
{
	FormMgr *pFormMgr = new FormMgr();
	pFormMgr->Initialize();

	GetAppFrame()->GetFrame()->AddControl(*pFormMgr);

	pFormMgr->SetStarterForm(FormMgr::REQUEST_FORM_MENU, null);

	return true;
}

bool
blackjackpoker::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	return true;
}

void
blackjackpoker::OnForeground(void)
{
}

void
blackjackpoker::OnBackground(void)
{
}

void
blackjackpoker::OnLowMemory(void)
{
}

void
blackjackpoker::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
}

void
blackjackpoker::OnScreenOn (void)
{
}

void
blackjackpoker::OnScreenOff (void)
{
}
