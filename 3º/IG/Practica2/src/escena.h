//==============================================================
// Práctica 1 - IG
// Arturo Cortés Sánchez
//==============================================================
#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "Objeto3D.h"
#include "Cubo.h"
#include "Tetraedro.h"
#include "Octaedro.h"
#include "Objply.h"
#include "Figrev.h"
#include "Barrido.h"


class Escena {
private:
// tamaño de los ejes
#define AXIS_SIZE 5000
Ejes ejes;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;

private:
	void clear_window(); //borrar ventana
	void draw_axis(); // pintar ejes
	void draw_objects(); // visualizar escena
	//Objeto3D objetos[2]; //objetos a pintar, dos o mas si hago la extension


//Transformación de cámara
	void change_projection(); //ya implementado
	void change_observer();	//""
	int arg_c;
	char *arg_v;
	int nvueltas=12;


public:
     Escena(int argc, char *argv1, char *argv2); // el constructor de escena será un objeto (tetraedro o cubo)
     //cada vez que le das a 1 o 2 se invoca la visualizacion del nuevo objeto y se elimina el anerior, 
     //añadir atributo a la clase escena para ver que objeto esta siendo renderizado
	void inicializar(int UI_window_width,int UI_window_height); 
	void redimensionar(int newWidth,int newHeight) ; //readaptar imagen
	//void redimensionar(int newWidth,int newHeight, int denominador) ;
	Cubo cubo;
	Tetraedro tetra;
	Octaedro oct;
	Objply oply;
	Figrev peon, plyon;
	Barrido perfbar;
	float mediaRev=0;

	int fig=1;
	// Dibujar
	void dibujar() ; //invoca la funcion provada draw objects

	// Interacción con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);
};
#endif
