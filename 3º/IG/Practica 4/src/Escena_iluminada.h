//==============================================================
// Práctica 1 - IG
// Arturo Cortés Sánchez
//==============================================================

#ifndef _ESCENA_ILUMINADA_H
#define _ESCENA_ILUMINADA_H
#include "Objeto3D.h"
#include "Luz.h"
#include "Objply.h"
#include <vector>

class Escena_iluminada{

	Objply cilindro_ply, cono_ply, esfera_ply ;
	float color[4]={0.3, 0.3, 0.3, 1.0};
	float brillo=10;
	Luz luz1, luz2;

	public:
		int material = 0;
		int pos_luz1=0;
		bool flat=false, iluminacion=true;
		int x_luz2=0;
		Escena_iluminada();
		void dibujar();

};

#endif
