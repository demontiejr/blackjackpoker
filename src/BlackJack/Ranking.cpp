/*
 * Ranking.cpp
 *
 *  Created on: 22/09/2011
 *      Author: Arthur Holanda
 */

#include "BlackJack/Ranking.h"

Ranking::Ranking() {}

void Ranking::Construct()
{
	result r;

	String dbLocation("/Home/Ranking");

	if(bancoRanking.Exists(dbLocation)){

		r = bancoRanking.Construct(dbLocation, false);

		if(IsFailed(r)){
			AppLog("Falhou ao carregar ranking.");
		}else{
			AppLog("Construiu baseado em anterior.");
		}

	}else{
		r = bancoRanking.Construct(dbLocation, true);
		if(IsFailed(r)){
			AppLog("Falhou ao construir ranking.");
		}else{
			String statement("CREATE TABLE IF NOT EXISTS Ranking(nome TEXT, pontuacao INTEGER, vitorias INTEGER)");

			r = bancoRanking.ExecuteSql(statement, true);
			if(IsFailed(r)){
				AppLog("Falhou ai construir tabela do ranking");
			}else{
				AppLog("Construiu nova tabela com sucesso");
			}
		}
	}
}

Ranking::~Ranking() {
	// TODO Auto-generated destructor stub
}

InfoRanking *Ranking::GetInfoPorPosicaoInserir(int posicao)
{
	DbStatement* pStatement;
	DbEnumerator* pEnum;
	String statement;
	result r = E_SUCCESS;

	String nome;
	int pontuacao, vitorias;
	InfoRanking* info = new InfoRanking();

	statement = (L"SELECT * FROM Ranking ORDER BY pontuacao DESC");

	pStatement = bancoRanking.CreateStatementN(statement);

	if(!pStatement) goto CATCH;

	pEnum = bancoRanking.ExecuteStatementN(*pStatement);
	if(!pEnum) goto CATCH;

	r = pEnum->Reset();


	for (int i = 0; i < posicao; ++i) {
		r = pEnum->MoveNext();
	}

	r = pEnum->GetStringAt(0, nome);
	r = pEnum->GetIntAt(1, pontuacao);
	r = pEnum->GetIntAt(2, vitorias);

	if(IsFailed(r))
		return info;

	info->Construct(nome, pontuacao, vitorias);

	delete pStatement;
	delete pEnum;

	return info;

	CATCH:
	result res = GetLastResult();

	if(res == E_SUCCESS){

	}else if(res == E_INVALID_STATE){

	}else if(res == E_INVALID_ARG ){

	}else if(res == E_DATABASE){

	}else if(res == E_SERVICE_BUSY){

	}else{

	}

	if(pEnum) delete pEnum;
	if(pStatement) delete pStatement;

	return info;
}



void Ranking::Inserir(InfoRanking *info)
{
	result r = E_SUCCESS;

	DbStatement* pStatement;
	String statement;

	r = bancoRanking.BeginTransaction();

	if(IsFailed(r)){
		AppLog("Falhou ao iniciar inserir.");
		return;
	}

	statement = "INSERT INTO Ranking(nome, pontuacao, vitorias) VALUES (?, ?, ?)";

	pStatement = bancoRanking.CreateStatementN(statement);
	if(IsFailed(r)){
		AppLog("Falhou ao criar statement.");
		return;
	}

	r = pStatement->BindString(0, info->GetNome());
	if(IsFailed(r)) goto CATCH;

	r = pStatement->BindInt(1, info->GetPontos());
	if(IsFailed(r)) goto CATCH;

	r = pStatement->BindInt(2, info->GetVitorias());
	if(IsFailed(r)) goto CATCH;

	bancoRanking.ExecuteStatementN(*pStatement);
	r = bancoRanking.CommitTransaction();

	delete pStatement;

	return;

	CATCH:
	if(pStatement) delete pStatement;
	return;
}

void Ranking::Limpar()
{
	result r = E_SUCCESS;

	DbStatement* pStatement;
	String statement;

	r = bancoRanking.BeginTransaction();

	if(IsFailed(r)){
		AppLog("Falhou ao iniciar inserir.");
		return;
	}

	statement = "DELETE FROM Ranking";

	pStatement = bancoRanking.CreateStatementN(statement);
	if(IsFailed(r)){
		AppLog("Falhou ao criar statement.");
		return;
	}

	bancoRanking.ExecuteStatementN(*pStatement);
	r = bancoRanking.CommitTransaction();

	delete pStatement;

	return;
}


