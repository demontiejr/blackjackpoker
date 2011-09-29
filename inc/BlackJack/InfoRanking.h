			/*
 * InfoRanking.h
 * Created on: 22/09/2011
 * Author: Arthur Holanda
 */

#ifndef INFORANKING_H_
#define INFORANKING_H_

#include<FBase.h>

using namespace Osp::Base;

class InfoRanking {
public:
	InfoRanking();
	InfoRanking(String nome, int pontuacao, int vitorias);
	void Construct(String nome, int pontuacao, int vitorias);
	String GetNome();
	int GetPontos();
	int GetVitorias();

	virtual ~InfoRanking();

protected:
	String nome;
	int pontuacao;
	int vitorias;
};

#endif /* INFORANKING_H_ */
