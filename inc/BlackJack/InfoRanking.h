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
	InfoRanking(String nome, int pontuacao);
	void Construct(String nome, int pontuacao);
	String GetNome();
	int GetPontos();
	String ToString();

	virtual ~InfoRanking();

protected:
	String nome;
	int pontuacao;
};

#endif /* INFORANKING_H_ */
