//==============================================================
// Práctica 4 - IG
// Arturo Cortés Sánchez
//==============================================================

#include "Luz.h"
#include "Objeto3D.h"
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;
	
void Luz::set_pos(float x, float y, float z, float w){
	//cout <<"set pos "<< x<< " " << y << " "<< z << " "<< w << endl;
	posicion[0]=x;
	posicion[1]=y;
	posicion[2]=z;
	posicion[3]=w;
}

void Luz::set_difuso(float r, float g, float b){
	//cout<< "set difuso "<< r<< " " << g << " " <<b<<  endl;
	difuso[0]=r;
	difuso[1]=g;
	difuso[2]=b;
	difuso[3]=1.0;
}

void Luz::set_especular(float r, float g, float b){
	//cout <<"set especular "<< r<< " " << g << " " <<b<<  endl;
	especular[0]=r;
	especular[1]=g;
	especular[2]=b;
	especular[3]=1.0;
}

void Luz::set_ambiental(float r, float g, float b){
	//cout<< "set ambiental "<< r<< " " << g << " "<< b<<  endl;
	ambiental[0]=r;
	ambiental[1]=g;
	ambiental[2]=b;
	ambiental[3]=1.0;
}


void Luz::activar_luz(){
	//cout << "activar_luz"<< endl;
	switch(num){
		case 0:
			glLightfv(GL_LIGHT0, GL_AMBIENT, ambiental);
			glLightfv(GL_LIGHT0, GL_DIFFUSE, difuso);
			glLightfv(GL_LIGHT0, GL_SPECULAR, especular);
			glLightfv(GL_LIGHT0, GL_POSITION, posicion);

			glEnable(GL_LIGHT0);

			break;

		case 1:
			//cout << "luz1"<< endl;
			glLightfv(GL_LIGHT1, GL_AMBIENT, ambiental);
			glLightfv(GL_LIGHT1, GL_DIFFUSE, difuso);
			glLightfv(GL_LIGHT1, GL_SPECULAR, especular);
			glLightfv(GL_LIGHT1, GL_POSITION, posicion);

			glEnable(GL_LIGHT1);
		
			break;

		case 2:

			glLightfv(GL_LIGHT2, GL_AMBIENT, ambiental);
			glLightfv(GL_LIGHT2, GL_DIFFUSE, difuso);
			glLightfv(GL_LIGHT2, GL_SPECULAR, especular);
			glLightfv(GL_LIGHT2, GL_POSITION, posicion);

			glEnable(GL_LIGHT2);

			break;

		default:
			cout << "solo 2 luces"<< endl;
			break;	

	}

}

Luz::Luz(){
	cout << "constructor Escena_iluminada"<< endl;

}

void Luz::set_num(int i){
	num=i;
}

