//==============================================================
// Práctica 1 - IG
// Arturo Cortés Sánchez
//==============================================================

#ifndef _CUBO_H
#define _CUBO_H
#include "Objeto3D.h"
#include <vector>

class Cubo: public Objeto3D{
	public:
		Cubo();
		void ladoCubo(float ladocubo);
};

#endif
