/*
 * Ranking.h
 *
 *  Created on: 22/09/2011
 *      Author: Arthur Holanda
 */

#ifndef RANKING_H_
#define RANKING_H_

#include "InfoRanking.h"
#include <FBase.h>
#include <FIo.h>

using namespace Osp::Io;
using namespace Osp::Base;

class Ranking {
public:
	Ranking();
	void Construct();
	virtual ~Ranking();

	void Inserir(InfoRanking* info);
	InfoRanking* GetInfoPorPosicaoInserir(int posicao);
	void Limpar();

protected:
	Database bancoRanking;
};

#endif /* RANKING_H_ */
