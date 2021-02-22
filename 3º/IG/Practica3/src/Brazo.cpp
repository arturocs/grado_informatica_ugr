//==============================================================
// Práctica 3 - IG
// Arturo Cortés Sánchez
//==============================================================

#include "Brazo.h"

#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;
	
Brazo::Brazo(){
	mano.figply("mano.ply");
	posbrazo.figply("posbrazo.ply");
	codo=0;
	incremento=5;

}
void Brazo::dibujar(){
	//cout << "Brazo dibujar"<< endl;
	glPushMatrix();
		glRotatef(-40,0,0,1);
		glTranslatef(35,0,0);
		glPushMatrix();
			glRotatef(codo,0,1,0);
			glScalef(50,50,50);
			glTranslatef(0.65,-0.1,0.05);
			mano.dibujar();
		glPopMatrix();

		glPushMatrix();
			glScalef(50,50,50);
			glTranslatef(-0.35,0,0);
			posbrazo.dibujar();
		glPopMatrix();
	glPopMatrix();	

}
void Brazo::codo_inc(){
	cout <<"codo_inc: "<< codo<< endl;
	if(codo<0)
		codo+=incremento;
}
void Brazo::codo_dec(){
	cout <<"codo_dec: "<< codo<< endl;
	if(codo>-70)
		codo-=incremento;
}
void Brazo::cambio_incremento(double i){
	incremento=i;
}
void Brazo::codoacero(){
	codo=0;
}
void Brazo::modo(char c){
	mano.modo(c);
	posbrazo.modo(c);
}