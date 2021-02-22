//==============================================================
// Práctica 4 - IG
// Arturo Cortés Sánchez
//==============================================================

#ifndef _TEXTURA_H
#define _TEXTURA_H
#include "Objeto3D.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>

class Textura{


	float tv[8] = {
        0,1,
        1,1,
        1,0,
        0,0
    };  

    float v[8] = {
    	-5, -5,
         5, -5,
         5, 5,
        -5, 5
    }; 

	public:
		float offset=0.5;
		int angulo=0;
		int BMP();
		Textura();

};

#endif
