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
	static const int ID_BUTTON_SAIR = 104;
	//botoes do panel
	static const int ID_BUTTON_PLAY = 201;
	static const int ID_BUTTON_CANCEL = 202;

	Osp::Ui::Controls::Button *__pButtonNovoJogo;
	Osp::Ui::Controls::Button *__pButtonRanking;
	Osp::Ui::Controls::Button *__pButtonInstrucoes;
	Osp::Ui::Controls::Button *__pButtonSair;

	Osp::Ui::Controls::Panel *__pPanelNome;
	Osp::Ui::Controls::EditField *__pEditFieldNome;
	Osp::Ui::Controls::Button *__pButtonPlay;
	Osp::Ui::Controls::Button *__pButtonCancel;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
	virtual result OnDraw(void);

private:
	void CriaJogador(Osp::Base::String nomeJogador);
    void MostraPanel();
    void EscondePanel();

};

#endif /* FORMMENU_H_ */
