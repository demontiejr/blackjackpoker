/*
 * IListenerControlador.h
 * Created on: 25/09/2011
 * Author: Arthur Holanda
 */

#ifndef ILISTENERCONTROLADOR_H_
#define ILISTENERCONTROLADOR_H_

class IListenerControlador {
public:
	IListenerControlador();
	virtual ~IListenerControlador();
	virtual void OnInicioJogadaJogador()=0;
	virtual void OnJogadorPuxaCarta()=0;
	virtual void OnFimJogadaJogador()=0;
	virtual void OnInicioJogadaMesa()=0;
	virtual void OnMesaPuxaCarta()=0;
	virtual void OnFimJogadaMesa()=0;
	virtual void OnInicioPartida()=0;
	virtual void OnFimPartida()=0;
	virtual void OnPagarVencedor()=0;
};

#endif /* ILISTENERCONTROLADOR_H_ */
