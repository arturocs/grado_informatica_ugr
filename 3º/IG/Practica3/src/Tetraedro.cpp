//==============================================================
// Práctica 1 - IG
// Arturo Cortés Sánchez
//==============================================================

#include "Tetraedro.h"
#include "Objeto3D.h"
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;
	
void Tetraedro::ladoTetra(float ladotetra){
	relleno=true;

	float lado=ladotetra;

	vertices={
		0,lado,0, //arriba
		0,0,lado, //frente
		lado,0,-lado/2,//trasero derecha
	   -lado,0,-lado/2 // trasero izquierda
	};		
	aristas={
		0,1,2,
		0,2,3,
		0,3,1,
		1,2,3
	};	     
}


Tetraedro::Tetraedro(){
	cout << "constructor Tetraedro"<< endl;
	bool puntos=false, alambre=false, relleno=true, ajedrez=false, rellenoybordes=false;

}
