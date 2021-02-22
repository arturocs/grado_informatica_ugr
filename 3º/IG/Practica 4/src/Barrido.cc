//==============================================================
// Práctica 2 - IG
// Arturo Cortés Sánchez
//==============================================================
#include "Barrido.h"
#include "Objeto3D.h"
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

void Barrido::perfilBar(int n){
	relleno=true;
	vertices={
		 1,0,1,
		 0,0,0.5,
		-1,0,1,
		-0.5,0,0,
		-1,0,-1,
		 0,0,-0.5,
		 1,0,-1,
	     0.5,0,0

	}; 
	aristas={};

	push_back_3(vertices, vertices[0], vertices[1], vertices[2]); // Se solapa el primer punto con el ultimo para que al generar las caras no haya problemas
	int lim=vertices.size();
	vertices.insert(vertices.end(),vertices.begin(),vertices.end());// Se duplica el vector
	for(int i=vertices.size()/2 + 1;i< vertices.size(); i=i+3){
		vertices[i]=n;
	}
	for(int i=0;i< lim/3 -1 ; i++){
		push_back_3(aristas, i, i+1, i + lim/3);
		push_back_3(aristas, i+1, i+lim/3, 1+i+lim/3);
		push_back_3(aristas, i, i, i+lim/3);
	}

}

Barrido::Barrido(){
	cout << "constructor Barrido"<< endl;
	bool puntos=false, alambre=false, relleno=true, ajedrez=false,rellenoybordes=false;
	vertices={};
	aristas={};
}

