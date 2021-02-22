//==============================================================
// Práctica 3 - IG
// Arturo Cortés Sánchez
//==============================================================

#include "Objeto3D.h"
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <array>
#include "vertex.h"
using namespace std;


void Objeto3D::calcular_normales(){

	vector<_vertex3f> puntos,triangulos, nC, nV;
	_vertex3f p, p0,p1,p2, n,a,b;
	float modulo;

	for(int i=0;i<vertices.size();i+=3){
		p.x=vertices[i];
		p.y=vertices[i+1];
		p.z=vertices[i+2];
		puntos.push_back(p);
	}

	for(int i=0;i<aristas.size();i+=3){
		p.x=aristas[i];
		p.y=aristas[i+1];
		p.z=aristas[i+2];
		triangulos.push_back(p);
	}

	for(int i =0; i< triangulos.size();i++){
		p0=puntos[triangulos[i].x];
		p1=puntos[triangulos[i].y];
		p2=puntos[triangulos[i].z];

		a = p1 - p0;
		b = p2 - p0;

		n.x=(a.y*b.z - a.z*b.y);
		n.y=(a.z*b.x - a.x*b.z);
		n.z=(a.x*b.y - a.y*b.x);

		modulo = sqrt(n.x*n.x + n.y*n.y +n.z*n.z);

		n.x/=modulo;
		n.y/=modulo;
		n.z/=modulo;

		nC.push_back(n);
	}

	nV.resize(puntos.size());

	for(int i=0;i<triangulos.size();i++){

		nV[triangulos[i].x] += nC[i];
		nV[triangulos[i].y] += nC[i];
		nV[triangulos[i].z] += nC[i];
	}
	for(int i=0;i<nC.size();i++){
		push_back_3(normales_caras, nC[i].x, nC[i].y, nC[i].z);
	}

	for(int i=0;i<nV.size();i++){
		push_back_3(normales_vertices, nV[i].x, nV[i].y, nV[i].z);
	}

}

void Objeto3D::visualizar_normales(float t){
	glPointSize(1);
	float v1[3], v2[3];
	glBegin(GL_LINES);

	for(int i =0; i<vertices.size();i+=3){
		v1[0]=vertices[i];
		v1[1]=vertices[i+1];
		v1[2]=vertices[i+2];
		v2[0]=v1[0] + normales_vertices[i] * t;
		v2[1]=v1[1] + normales_vertices[i+1] * t;
		v2[2]=v1[2] + normales_vertices[i+2] * t;
		glVertex3fv((GLfloat*) &v1 );
		glVertex3fv((GLfloat*) &v2);

	}
	glEnd();
}

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
	
	vector<float> color2 =vectorcolor(0,255,0);
	//vector<float> color2 =vectorcolorrainbow();
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
