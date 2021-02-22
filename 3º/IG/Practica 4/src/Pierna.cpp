//==============================================================
// Práctica 3 - IG
// Arturo Cortés Sánchez
//==============================================================

#include "Pierna.h"

#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;
	
Pierna::Pierna(){
	cout << "cargo ply pie"<< endl;
	pie.figply("pie.ply");
	cout << "cargo ply muslo" << endl;
	muslo.figply("muslo.ply");
	rodilla=0;
	incremento=5;
}
void Pierna::dibujar(){
	glPushMatrix();
		glRotatef(rodilla,1,0,0);
		glScalef(50,50,50);
		glTranslatef(0,-0.5,0.1);
		pie.dibujar();
	glPopMatrix();

	glPushMatrix();
		glScalef(50,50,50);
		glTranslatef(0,0.7,0);
		muslo.dibujar();
	glPopMatrix();

}
void Pierna::rodilla_inc(){
	//cout << "rodilla_inc: "<< rodilla<< endl;
	if(rodilla<90)
		rodilla+=incremento;
}
void Pierna::rodilla_dec(){
	//cout << "rodilla_dec: "<< rodilla<< endl;
	if(rodilla>0)
		rodilla-=incremento;
}
void Pierna::cambio_incremento(double i){
	incremento=i;
}
void Pierna::rodillaacero(){
	rodilla=0;
}

void Pierna::modo(char c){
	pie.modo(c);
	muslo.modo(c);
}