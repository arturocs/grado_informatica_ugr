//==============================================================
// Práctica 1 - IG
// Arturo Cortés Sánchez
//==============================================================

#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"
#include "Cubo.h"
#include "Tetraedro.h"
#include "Octaedro.h"
#include "Objply.h"
#include <vector>

Escena::Escena(int argc, char *argv1, char *argv2){
	arg_c=argc;
	arg_v=argv2;
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    ejes.changeAxisSize(5000);
    
    tetra.ladoTetra(100);
	cubo.ladoCubo(50);
	oct.ladoOct(50);

	argc<3 ? peon.perfil(nvueltas) : peon.perfil(nvueltas, argv2);
	
	mediaRev=30/peon.media();
	peon.zoom(mediaRev);

	argc<2 ? oply.figply("ant.ply") : oply.figply(argv1);
	oply.zoom(30/oply.media());

	perfbar.perfilBar(4);
	perfbar.zoom(30/perfbar.media());

}

void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);

}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {

	if(fig==1){
		cubo.dibujar();
	}else if(fig==2){
		tetra.dibujar();
	}else if(fig==3){
		oct.dibujar();
	}else if(fig==4){
		oply.dibujar();
	}else if(fig==5){
		peon.dibujar();
	}else if(fig==6){
		perfbar.dibujar();
	}
}



void Escena::dibujar() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects();
}

int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {

    std::cout << "Tecla" << Tecla1<< std::endl;
	if (toupper(Tecla1)=='Q') {return 1;}
	else if(toupper(Tecla1)=='L'){ 
		cubo.modo('l');
		tetra.modo('l');
		oct.modo('l');
		oply.modo('l');
		peon.modo('l');
		perfbar.modo('l');
	}else if(toupper(Tecla1)=='P'){ 
		cubo.modo('p');
		tetra.modo('p');
		oct.modo('p');
		oply.modo('p');
		peon.modo('p');
		perfbar.modo('p');
	}else if(toupper(Tecla1)=='F'){ 
		cubo.modo('f');
		tetra.modo('f');
		oct.modo('f');
		oply.modo('f');
		peon.modo('f');
		perfbar.modo('f');
	}else if(toupper(Tecla1)=='C'){ 
		cubo.modo('c');
		tetra.modo('c');
		oct.modo('c');
		oply.modo('c');
		peon.modo('c');
		perfbar.modo('c');
	}else if(toupper(Tecla1)=='A'){ 
		cubo.modo('a');
		tetra.modo('a');
		oct.modo('a');
		oply.modo('a');
		peon.modo('a');
		perfbar.modo('a');
	}else if(toupper(Tecla1)=='T'){ 
		peon.gettapa() ? peon.settapa(false) : peon.settapa(true);
		peon.reset();
		arg_c < 3 ? peon.perfil(nvueltas) : peon.perfil(nvueltas, arg_v);
		peon.zoom(mediaRev);		

	}else if(toupper(Tecla1)=='M'){
		nvueltas++;
		peon.reset();
		arg_c < 3 ? peon.perfil(nvueltas) : peon.perfil(nvueltas, arg_v);
		peon.zoom(mediaRev);
	}
	else if(toupper(Tecla1)=='N'){
		if(nvueltas>0) nvueltas--;
		peon.reset();
		arg_c < 3 ? peon.perfil(nvueltas) : peon.perfil(nvueltas, arg_v);
		peon.zoom(mediaRev);	
	}
	else if(Tecla1=='1'){
		fig=1;
	}else if(Tecla1=='2'){
		fig=2;
	}else if(Tecla1=='3'){
		fig=3;
	}else if(Tecla1=='4'){
		fig=4;
	}else if(Tecla1=='5'){
		fig=5;
	}else if(Tecla1=='6'){
		fig=6;
	}
	else return 0;

	return 0;
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}

	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
Width=newWidth/10;
Height=newHeight/10;
glViewport(0,0,newWidth,newHeight);
}



//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
ejes.draw();
}




