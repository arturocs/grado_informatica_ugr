//==============================================================
// Práctica 4 - IG
// Arturo Cortés Sánchez
//==============================================================

#ifndef _LUZ_H
#define _LUZ_H
#include "Objeto3D.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>

class Luz{

	public:
		GLfloat posicion[4], difuso[4], especular[4], ambiental[4];
		short num;

		Luz();
		void set_num(int i);
		void activar_luz();
		void set_pos(float x, float y, float z, float w);
		void set_difuso(float r, float g, float b);
		void set_especular(float r, float g, float b);
		void set_ambiental(float r, float g, float b);

};

#endif
