//==============================================================
// Práctica 1 - IG
// Arturo Cortés Sánchez
//==============================================================

#include "Cubo.h"
#include "Objeto3D.h"
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;
	
void Cubo::ladoCubo(float ladocubo){
	relleno=true;

	float lado=ladocubo;

	vertices={-lado,0,lado, 
			lado,0,lado,
			-lado,2*lado,lado, 
			lado,2*lado,lado, 
			-lado,0,-lado,  
			lado,0,-lado,  
			-lado,2*lado,-lado, 
			lado,2*lado,-lado}; 			

	aristas={0,1,2,  
			 1,3,2, 
			 2,3,7, 
			 2,7,6, 
			 1,7,3, 
			 1,5,7, 
			 6,7,4, 
			 7,5,4, 
			 0,4,1, 
			 1,4,5,  
			 2,6,4,
			 0,2,4};

}


Cubo::Cubo(){
	cout << "constructor cubo"<< endl;
	bool puntos=false, alambre=false, relleno=true, ajedrez=false, rellenoybordes=false;

}
