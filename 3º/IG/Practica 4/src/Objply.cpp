//==============================================================
// Práctica 2 - IG
// Arturo Cortés Sánchez
//==============================================================

#include "Objply.h"
#include "Objeto3D.h"
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <file_ply_stl.h>
using namespace std;

void Objply::figply(string s){
	//cout << "figply"<< endl;
	relleno=true;
	
	if(File_ply.open(s)){
		File_ply.read(vertices_h,triangles_h);
		for(int i=0;i<vertices_h.size();i++)
			push_back_3(vertices, vertices_h[i].x, vertices_h[i].y, vertices_h[i].z);

		for(int i=0;i<triangles_h.size();i++)
			push_back_3(aristas, triangles_h[i]._0, triangles_h[i]._1, triangles_h[i]._2);
	}
	else{
		cout << "error leyendo " << s << endl;
	}
};

void Objply::dibujar_luz(){

	glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
	glNormalPointer( GL_FLOAT, 0, &normales_vertices[0] );

	glEnableClientState( GL_VERTEX_ARRAY );
	glEnableClientState( GL_NORMAL_ARRAY );
	glDrawElements( GL_TRIANGLES, aristas.size(), GL_UNSIGNED_INT, &aristas[0]);
	glDisableClientState( GL_VERTEX_ARRAY );
	glDisableClientState( GL_NORMAL_ARRAY );
}

Objply::Objply(){
	cout << "constructor Objply"<< endl;
	bool puntos=false, alambre=false, relleno=true, ajedrez=false, rellenoybordes=false;
}
