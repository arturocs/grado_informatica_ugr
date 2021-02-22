//==============================================================
// Práctica 3 - IG
// Arturo Cortés Sánchez
//==============================================================

#ifndef _BRAZO_H
#define _BRAZO_H
#include "Objply.h"
#include <vector>

class Brazo{
	private:
		Objply mano, posbrazo;
		double codo, incremento;


	public:
		Brazo();
		void dibujar();
		void codo_inc();
		void codo_dec();
		void codoacero();
		void modo(char c);
		void cambio_incremento(double i);

};

#endif
