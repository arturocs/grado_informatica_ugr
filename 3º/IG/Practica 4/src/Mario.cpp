//==============================================================
// Práctica 3 - IG
// Arturo Cortés Sánchez
//==============================================================

#include "Mario.h"

#include <unistd.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;
	
Mario::Mario(){
	animacion=true;
	arriba=false;
	abajo=true;

	hombro_der=0;
	hombro_iz=0;
	cadera_der=0;
	cadera_iz=0;

	mon_y=0;
	mar_y=0;

	inc_hombro_der=5;
	inc_hombro_iz=5;
	inc_cadera_der=5;
	inc_cadera_iz=5;

	inc_mon_y=5;
	inc_mar_y=5;

	cuerpo.figply("tronco.ply");
	cabeza.figply("cabeza.ply");
	bloque.figply("Bloque.ply");
	moneda.figply("cilindro.ply");

}
void Mario::dibujar(){

	glPushMatrix(); // bloque
		glScalef(40,40,40);
		glTranslatef(0,10,0);
		bloque.dibujar();
	glPopMatrix();	

	glPushMatrix(); // moneda
		glTranslatef(0,mon_y,0);
		glTranslatef(0,400,0);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		glScalef(50,10,50);
		moneda.dibujar();
	glPopMatrix();

	glPushMatrix();

		glTranslatef(0,mar_y,0);

		glPushMatrix(); // cuerpo
			glScalef(53,53,53);
			glTranslatef(0,0.6,0.2);
			cuerpo.dibujar();
		glPopMatrix();	

		glPushMatrix(); //pierna izquierda
			glRotatef(cadera_iz,1,0,0);
			glTranslatef(25,-50,0);
			izquierda.dibujar();
		glPopMatrix();

		glPushMatrix(); //pierna derecha
			glScalef(-1,1,1);
			glRotatef(cadera_der,1,0,0);
			glTranslatef(25,-50,0);
			derecha.dibujar();
		glPopMatrix();

		glPushMatrix(); //brazo izquierdo
			glTranslatef(35,55,0);
			glRotatef(hombro_iz,1,0,0);
			izquierdo.dibujar();
		glPopMatrix();

		glPushMatrix();//brazo derecho
			glScalef(-1,1,1);
			glTranslatef(35,55,0);
			glRotatef(hombro_der,1,0,0);
			derecho.dibujar();
		glPopMatrix();

		glPushMatrix(); //cabeza
			glScalef(45,45,45);
			glTranslatef(0,2.8,0.2);
			cabeza.dibujar();
		glPopMatrix();

	glPopMatrix();

	if(animacion){
		if(abajo){
			saltar();
		}
		else if(arriba){
			bajar();
		}	

		if(abajo && mar_y>=150){
			abajo=false;
			arriba=true;
		}else if(arriba && mar_y<=0){
			abajo=true;
			arriba=false;
			pose_original();
		}
	}
}


void Mario::saltar(){
	//cout << "saltar"<< endl;
		mar_y_inc();
		cadera_der_inc();
		cadera_iz_dec();
		hombro_der_inc();
		hombro_iz_dec();

		izquierdo.codo_dec();
		derecho.codo_dec();

		izquierda.rodilla_inc();
		//derecha.rodilla_inc();
}

void Mario::bajar(){
	//cout << "bajar"<< endl;
		mar_y_dec();
		mon_y_inc();
		cadera_der_dec();
		cadera_iz_inc();
		hombro_der_dec();
		hombro_iz_inc();

		izquierdo.codo_inc();
		derecho.codo_inc();

		izquierda.rodilla_dec();
		//derecha.rodilla_dec();
}

void Mario::pose_original(){
	//cout << "pose_original"<< endl;
	mar_y=0;
	mon_y=0;
	hombro_der=0;
	hombro_iz=0;
	cadera_der=0;
	cadera_iz=0;
	izquierdo.codoacero();
	derecho.codoacero();
	izquierda.rodillaacero();
	derecha.rodillaacero();

}

void Mario::hombro_der_inc(){
	if(hombro_der<90)
		hombro_der+=inc_hombro_der;
	//cout << "hombro_der: "<<hombro_der<< endl;
}

void Mario::hombro_der_dec(){
	if(hombro_der>-90)
		hombro_der-=inc_hombro_der;
	//cout << "hombro_der: "<<hombro_der<< endl;
}

void Mario::hombro_iz_inc(){
	if(hombro_iz<90)
		hombro_iz+=inc_hombro_iz;
	//cout << "hombro_iz: "<<hombro_iz<< endl;
}

void Mario::hombro_iz_dec(){
	if(hombro_iz>-90)
		hombro_iz-=inc_hombro_iz;
	//cout << "hombro_iz: "<<hombro_iz<< endl;
}


void Mario::cadera_der_inc(){
	if(cadera_der<60)
		cadera_der+=inc_cadera_der;
	//cout << "cadera_der: "<<cadera_der<< endl;
}

void Mario::cadera_der_dec(){
	if(cadera_der>-60)
		cadera_der-=inc_cadera_der;
	//cout << "cadera_der: "<<cadera_der<< endl;
}

void Mario::cadera_iz_inc(){
	if(cadera_iz<60)
		cadera_iz+=inc_cadera_iz;
	//cout << "cadera_iz: "<<cadera_iz<< endl;
}

void Mario::cadera_iz_dec(){
	if(cadera_iz>-60)
		cadera_iz-=inc_cadera_iz;
	//cout << "cadera_iz: "<<cadera_iz<< endl;
}


void Mario::cambio_inc_hombro_der(double i){
	inc_hombro_der=i;
	//cout << "inc_hombro_der: "<<inc_hombro_der<< endl;
}

void Mario::cambio_inc_hombro_iz(double i){
	inc_hombro_iz=i;	
	//cout << "inc_hombro_iz: "<<inc_hombro_iz<< endl;
}

void Mario::cambio_inc_cadera_der(double i){
	inc_cadera_der=i;
	//cout << "inc_cadera_der: "<<inc_cadera_der<< endl;
}

void Mario::cambio_inc_cadera_iz(double i){
	inc_cadera_iz=i;
	//cout << "inc_cadera_iz: "<<inc_cadera_iz<< endl;
}


void Mario::mon_y_inc(){
	if(mon_y<130)
		mon_y+=inc_mon_y;
	//cout << "mon_y: "<< mon_y << endl;
}

void Mario::mon_y_dec(){
	if(mon_y>0)
		mon_y-=inc_mon_y;
	//cout << "mon_y: "<< mon_y << endl;
}

void Mario::mar_y_inc(){
	if(mar_y<150)
		mar_y+=inc_mar_y;
	//cout << "mar_y: "<< mar_y << endl;
}

void Mario::mar_y_dec(){
	if(mar_y>0)
		mar_y-=inc_mar_y;
	//cout << "mar_y: "<< mar_y << endl;
}


void Mario::cambio_inc_mon_y(double i){
	inc_mon_y=i;
}

void Mario::cambio_inc_mar_y(double i){
	inc_mar_y=i;
}

void Mario::modo(char c){
	cuerpo.modo(c);
	cabeza.modo(c);
	bloque.modo(c);
	moneda.modo(c);

	izquierdo.modo(c);
	derecho.modo(c);
	izquierda.modo(c);
	derecha.modo(c);
}

void Mario::cambio_velocidad(double v){
	inc_hombro_der=v;
	inc_hombro_iz=v;
	inc_cadera_der=v;
	inc_cadera_iz=v;

	inc_mon_y=v;
	inc_mar_y=v;

	izquierda.cambio_incremento(v);
	derecha.cambio_incremento(v);

	izquierdo.cambio_incremento(v);
	derecho.cambio_incremento(v);
}