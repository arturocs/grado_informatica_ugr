//==============================================================
// Práctica 3 - IG
// Arturo Cortés Sánchez
//==============================================================

#ifndef _PIERNA_H
#define _PIERNA_H
#include "Objply.h"
#include <vector>

class Pierna{
	
	double rodilla, incremento;
	Objply pie;
	Objply muslo;
public:
	void rodilla_inc();
	void rodilla_dec();
	void dibujar();
	void cambio_incremento(double i);
	void rodillaacero();
	void modo(char c);
	Pierna();


};

#endif
