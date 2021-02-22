//==============================================================
// Práctica 1 - IG
// Arturo Cortés Sánchez
//==============================================================

#include "Octaedro.h"
#include "Objeto3D.h"
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

void Octaedro::ladoOct(float ladooct){
	relleno=true;

	float lado=ladooct;

	vertices={lado,lado,lado, //frontal derecha
			 lado,lado,-lado, // trasero derecha
			-lado,lado,-lado, // trasero izquierda
			-lado,lado,lado,  //frontal izquierda
			 0,2*lado,0,   // arriba
			 
			 0,0,0 	//abajo
			}; 
			
	aristas={
		0,1,4,
		1,2,4,
		2,3,4,
		1,2,3,
	//	0,3,1,
		1,0,4,
		0,3,4,

		5,3,0,
		5,0,1,
		5,1,2,
		5,2,3

	};	     

}


Octaedro::Octaedro(){
	cout << "constructor Octaedro"<< endl;
	bool puntos=false, alambre=false, relleno=true, ajedrez=false,rellenoybordes=false;

}
