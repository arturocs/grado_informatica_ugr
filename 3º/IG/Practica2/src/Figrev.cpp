//==============================================================
// Práctica 1 - IG
// Arturo Cortés Sánchez
//==============================================================

#include "Figrev.h"
#include "Objeto3D.h"
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

using namespace std;

void Figrev::perfil(int n){
	rellenoybordes=true;

	vertices={
		1,0,0,
		1,2,0
	}; 
	aristas={};

	if (tapa)
		ponertapas(vertices);

	revolucion(n, vertices, aristas);
}

void Figrev::perfil(int n, string s){
	rellenoybordes=true;

	if(vertices_orig.size()==0){
		figply(s);
		vertices_orig=vertices;
	}else{
		vertices=vertices_orig;
	}

	aristas={};

	if (tapa)
		ponertapas(vertices);

	revolucion(n, vertices, aristas);
}

Figrev::Figrev(){
	cout << "constructor Figrev"<< endl;
	bool puntos=false, alambre=false, relleno=true, ajedrez=false,rellenoybordes=false;
	vertices={};
	aristas={};

}
void Figrev::rotar(float x, float y, float z, float & x_out, float & y_out, float & z_out, float angulo){
	x_out = cos(angulo) * x + sin(angulo) * z;
	y_out = y;
	z_out = -sin(angulo) * x + cos(angulo) * z;
}

bool Figrev::gettapa(){
	return tapa;
}
void Figrev::settapa(bool t){
	tapa=t;
}

void Figrev::reset(){
	vertices={};
	aristas={};
}

void Figrev::ponertapas(vector<float> & v){
	v.insert(vertices.begin(),0);
	v.insert(vertices.begin(),vertices[2]);
	v.insert(vertices.begin(),0);

	push_back_3(v, 0, vertices[vertices.size()-2], 0);
}

vector<int> Figrev::unirPerfil(int i, int tope){
	vector<int> aristas;

	for(int k=i*tope; k< tope-1 + i*tope ;k++){
		push_back_3(aristas, k, k+tope, k+1);
		push_back_3(aristas, k+1, k+tope, k+tope+1);
	}
	push_back_3(aristas, tope-1 + tope*i, tope-1 + tope*i , tope-1 + tope*(i+1) );
	return aristas;
}	

void Figrev::revolucion(int n, vector<float> & vertices, vector<int> & aristas){

	float  x_out,y_out,z_out, alfa= 2* M_PI /n;
	int lim = vertices.size();
	vector<int> temp;

	for(int i=0;i<=n;i++){
		for (int j=0;j<lim;j=j+3){
			rotar(vertices[j],vertices[j+1], vertices[j+2], x_out, y_out, z_out, i*alfa);
			push_back_3(vertices, x_out, y_out, z_out);
		}
		temp=unirPerfil(i, lim/3); //generar nueva cara
		aristas.insert(aristas.end(),temp.begin(),temp.end());//unir la nueva cara al vector de aristas
	}

}
/*
void Figrev::rotar(float x, float y, float z, float & x_out, float & y_out, float & z_out, float angulo){
	x_out = x;
	y_out = cos(angulo) * y - sin(angulo) * z;
	z_out = sin(angulo) * y + cos(angulo) * z;
}
void Figrev::rotar(float x, float y, float z, float & x_out, float & y_out, float & z_out, float angulo){
	x_out = cos(angulo) * x - sin(angulo) * y;
	y_out = sin(angulo) * x + cos(angulo) * y;
	z_out = z;
}*/