//==============================================================
// Práctica 1 - IG
// Arturo Cortés Sánchez
//==============================================================

#include "Objeto3D.h"
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

vector<float> Objeto3D::vectorcolor(float a, float b, float c){
	vector<float> color1;
	for(int i=0; i<vertices.size();i++){
		if(i%3==0){
			color1.push_back(a);
		}else if(i%3==1){
			color1.push_back(b);
		}else{
			color1.push_back(c);
		}
	}
	return color1;
}

void Objeto3D::enablecl(){
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
}
void Objeto3D::disablecl(){
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Objeto3D::dibujar_puntos(){
	
	vector<float> color2 =vectorcolor(0,0,255);

	enablecl();
	glPointSize(10);
	glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
	glColorPointer(3, GL_FLOAT,0, &color2[0]);
	glDrawElements( GL_POINTS, aristas.size(), GL_UNSIGNED_INT, &aristas[0]);
	disablecl();
}

void Objeto3D::dibujar_alambre(){

	vector<float> color2 =vectorcolor(0,0,0);

	enablecl();
	glLineWidth(2);
	glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
	glColorPointer(3, GL_FLOAT,0, &color2[0]);
	for (int i = 0; i < aristas.size(); i=i+3){	
			glDrawElements(GL_LINE_STRIP, 3, GL_UNSIGNED_INT, &aristas[i]);
	}
	//glDrawElements( GL_LINE_STRIP, aristas.size(), GL_UNSIGNED_INT, &aristas[0]);
	disablecl();
}
void Objeto3D::dibujar_relleno(){
	
	vector<float> color2 =vectorcolor(0,255,0);
	enablecl();
	glLineWidth(2);
	glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
	glColorPointer(3, GL_FLOAT,0, &color2[0]);
	glDrawElements( GL_TRIANGLES, aristas.size(), GL_UNSIGNED_INT, &aristas[0]);
	disablecl();
}
void Objeto3D::dibujar_ajedrez(){
	
	vector<float> color1=vectorcolor(255,0,0);
	vector<float> color2=vectorcolor(0,255,0);

	enablecl();
	glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
	
	int k=0;
	for(int i=0;i<aristas.size();i=i+3){
		if(k%2==0){
				glColorPointer(3, GL_FLOAT,0, &color1[0]);
		}
		else{
				glColorPointer(3, GL_FLOAT,0, &color2[0]);
		}
		k++;
		glDrawElements( GL_TRIANGLES, 3, GL_UNSIGNED_INT, &aristas[i]);
	}
	disablecl();
}
void Objeto3D::dibujar(){
	if(puntos){
		dibujar_puntos();
	} else if(alambre){
		dibujar_alambre();
	} else if(relleno){
		dibujar_relleno();
	} else if(ajedrez){
		dibujar_ajedrez();
	} else if (rellenoybordes){
		dibujar_puntos();
		dibujar_ajedrez();
		dibujar_alambre();
	}
}

void Objeto3D::modo(char ch){
	cout << "modo "<< ch << endl;
	switch(ch){
		case 'l':
			puntos=false; alambre=true; relleno=false; ajedrez=false; rellenoybordes=false;
			break;
		case 'p':
			puntos=true; alambre=false; relleno=false; ajedrez=false; rellenoybordes=false;
			break;
		case 'f':
			puntos=false; alambre=false; relleno=true; ajedrez=false; rellenoybordes=false;
			break;
		case 'c':
			puntos=false; alambre=false; relleno=false; ajedrez=true; rellenoybordes=false;
			break;		
		case 'a':	
			puntos=false; alambre=false; relleno=false; ajedrez=false; rellenoybordes=true;
			break;
		default:
			cout << "modo erroneo" << endl;		
			break;	
	}	
};