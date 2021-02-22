//==============================================================
// Práctica 1 - IG
// Arturo Cortés Sánchez
//==============================================================

#ifndef _TETRAEDRO_H
#define _TETRAEDRO_H
#include "Objeto3D.h"
#include <vector>

class Tetraedro: public Objeto3D{
	public:
		Tetraedro();
		void ladoTetra(float ladotetra);

};

#endif
