/*
 * Carta.cpp
 *
 *  Created on: 22/09/2011
 *      Author: Arthur Brasileiro
 */

#include "BlackJack/Carta.h"

Carta::Carta() {}

Carta::Carta(int numero, int naipe) {
	String numeros[13] = { "AS", "DOIS", "TRES", "QUATRO", "CINCO", "SEIS",
			"SETE", "OITO", "NOVE", "DEZ", "VALETE", "DAMA", "REI" };
	String naipes[4] = { "ESPADAS", "COPAS", "PAUS", "OUROS" };

	this->numero = numero;
	this->naipe = naipe;
	this->nome = numeros[numero] + " DE " + naipes[naipe];

	if (DOIS <= numero && numero <= DEZ) {
		this->valor = numero + 1;
	} else {
		if (numero == AS)
			this->valor = 11;
		else
			this->valor = 10;
	}
}

Carta::~Carta() {
	// TODO Auto-generated destructor stub
}

int Carta::getValor()
{
	return valor;
}

String Carta::toString()
{
	return nome;
}

int Carta::getNumero()
{
	return this->numero;
}
