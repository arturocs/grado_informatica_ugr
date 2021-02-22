//==============================================================
// Práctica 3 - IG
// Arturo Cortés Sánchez
//==============================================================

#include "Objeto3D.h"
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;


void Objeto3D::push_back_3(vector<float> & v, float a, float b, float c){
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
}

void Objeto3D::push_back_3(vector<int> & v, int a, int b, int c){
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
}

float Objeto3D::media(){
	float sum=0;
	for(int i=0;i<vertices.size();i++){
		sum+=abs(vertices[i]);
	}
	return sum/vertices.size();
}

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

vector<float> Objeto3D::vectorcolorrainbow(){
	vector<float> color1;
	//n*0.1+
	for(int i=0; i<vertices.size()/3;i++){
		push_back_3(color1,0.3,0.9,0.9);
		push_back_3(color1,0.4,0.95,0.3);
		push_back_3(color1,1,0.3,0.3);

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
	glPointSize(5);
	glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
	glColorPointer(3, GL_FLOAT,0, &color2[0]);
	glDrawElements( GL_POINTS, aristas.size(), GL_UNSIGNED_INT, &aristas[0]);
	disablecl();
}

void Objeto3D::dibujar_alambre(){

	vector<float> color2 =vectorcolor(0,0,0);

	enablecl();
	//glCullFace(GL_FRONT);
	glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
	glColorPointer(3, GL_FLOAT,0, &color2[0]);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	//for (int i = 0; i < aristas.size(); i=i+3){	
			glDrawElements(GL_TRIANGLES, aristas.size(), GL_UNSIGNED_INT, &aristas[0]);
	//}
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	disablecl();
}
void Objeto3D::dibujar_relleno(){
	
	//vector<float> color2 =vectorcolor(0,255,0);
	vector<float> color2 =vectorcolorrainbow();
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
}

void Objeto3D::zoom(float zm){
	for(int i=0;i<vertices.size();i++){
		vertices[i]=vertices[i]*zm;
	}
};
