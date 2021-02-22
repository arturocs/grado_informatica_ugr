//==============================================================
// Práctica 4 - IG
// Arturo Cortés Sánchez
//==============================================================

#include "Escena_iluminada.h"
#include "Objeto3D.h"
#include "Luz.h"
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;
	

void Escena_iluminada::dibujar(){

	
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);   //Activa el buffer de profundidad.
	
	flat ? glShadeModel(GL_FLAT) : glShadeModel(GL_SMOOTH);

	iluminacion ? glEnable(GL_LIGHTING) : glDisable(GL_LIGHTING);

	switch (material%3){
		case 0:
			color[0]=0.3;
			color[1]=0.3;
			color[2]=0.3;
			brillo=50;
			break;
		case 1:
			color[0]=0.3;
			color[1]=0.7;
			color[2]=0.3;
			brillo=100;
			break;
		case 2:
			color[0]=1.0;
			color[1]=0.3;
			color[2]=0.9;
			brillo=20;
			break;	
		default:	
			cout << "material erroneo"<<endl;
			break;	
	}
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, color);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, brillo);

	switch(pos_luz1%3){
		case 0:
			luz1.set_pos( 1, 0, 0, 0 );
			break;

		case 1:
			luz1.set_pos( 0, 1, 0, 0 );
			break;

		case 2:
			luz1.set_pos( 0, 0, 1, 0 );
			break;	
		default:
			cout << "posicion erronea luz 1"<< endl;
			break;	
	}

	
	luz1.set_num(1);
	//luz1.set_pos( 1, 0, 0, 0 );
	luz1.set_difuso(1, 1, 0.6);
	luz1.set_ambiental(0.5, 0.5, 0.25);
	luz1.set_especular(1, 1, 0.65);
	luz1.activar_luz();

	luz2.set_num(2);
	luz2.set_pos( 0, 0, 0, 1 );
	luz2.set_difuso(0.2, 0.9, 0.9);
	luz2.set_ambiental(0.2, 0.5, 0.5);
	luz2.set_especular(0.5, 1, 1);

	glPushMatrix();
		glRotatef(x_luz2,0,1,0);
		glTranslatef(200,300,0);
		luz2.activar_luz();
		glScalef(30,30,30);
		esfera_ply.dibujar_luz();

	glPopMatrix();

	glPushMatrix(); // cilindro
		glScalef(100,100,100);
		glTranslatef(2.5,0,2.5);
		//cilindro_ply.modo('l');
		cilindro_ply.dibujar_luz();
		//cilindro_ply.visualizar_normales(0.15);
	glPopMatrix();	

	glPushMatrix(); // cono
		glScalef(30,30,30);
		glTranslatef(0,0,-2.5);
		//cono_ply.modo('l');
		cono_ply.dibujar_luz();
		//cono_ply.visualizar_normales(0.15);
	glPopMatrix();	

	glPushMatrix(); // esfera
		glScalef(80,80,80);
		glTranslatef(-2.5,0,2.5);
		//glTranslatef(-1,0,1);
		//esfera_ply.modo('l');
		esfera_ply.dibujar_luz();
		//esfera_ply.visualizar_normales(0.15);
	glPopMatrix();	

	glDisable(GL_LIGHTING);

}

Escena_iluminada::Escena_iluminada(){
	
	cout << "constructor Escena_iluminada"<< endl;
	cout << "GL_MAX_LIGHTS "<< GL_MAX_LIGHTS << endl;
	cilindro_ply.figply("cilindro.ply");
	cono_ply.figply("beethoven.ply");
	esfera_ply.figply("esfera2.ply");

	cilindro_ply.calcular_normales();
	cono_ply.calcular_normales();
	esfera_ply.calcular_normales();

}
