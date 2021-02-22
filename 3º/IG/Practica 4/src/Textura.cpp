//==============================================================
// Práctica 4 - IG
// Arturo Cortés Sánchez
//==============================================================

#include "Textura.h"
#include "Objeto3D.h"
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;


int Textura::BMP(){
		// Lectura de información del encabezado del archivo
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Información RGB
	//unsigned char * data;

	FILE * file = fopen("./textura3.bmp","rb");
	if (!file){printf("Image could not be opened\n"); return 0;}

	if ( fread(header, 1, 54, file)!=54 ){ // If not 54 bytes read : problem
	    printf("Not a correct BMP file\n");
	    return false;
	}

	if ( header[0]!='B' || header[1]!='M' ){
    	printf("Not a correct BMP file\n");
    	return 0;
	}

	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);

	// Algunos archivos BMP tienen un mal formato, así que adivinamos la información faltante
	if (imageSize==0)    imageSize=width*height*3; // 3 : un byte por cada componente Rojo (Red), Verde (Green) y Azul(Blue)
	if (dataPos==0)      dataPos=54; // El encabezado del BMP está hecho de ésta manera          

	unsigned char data [imageSize];

	// Leemos la información del archivo y la ponemos en el buffer
	fread(data,1,imageSize,file);

	//Todo está en memoria ahora, así que podemos cerrar el archivo
	fclose(file);

	GLuint textureID;
	glGenTextures(1, &textureID);

	// Se "Ata" la nueva textura : Todas las futuras funciones de texturas van a modificar esta textura
	glBindTexture(GL_TEXTURE_2D, textureID);

	glActiveTexture(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexParameteri( GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT );

	//glEnable( GL_TEXTURE_GEN_S ); // desactivado inicialmente
	//glEnable( GL_TEXTURE_GEN_T ); // desactivado inicialmente

	// Se le pasa la imagen a OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	glEnable(GL_TEXTURE_2D);
  	glEnableClientState(GL_VERTEX_ARRAY);
  	glEnableClientState (GL_TEXTURE_COORD_ARRAY_EXT);

  	glActiveTexture(GL_TEXTURE0);

  	glBindTexture(GL_TEXTURE_2D, textureID);

  	glPushMatrix();


	  	glMatrixMode(GL_TEXTURE);
	  	glLoadIdentity();
	  	glTranslatef(offset,0.5,0.0);
	  //	glRotatef(angle,0.0,0.0,1.0);
	  	glTranslatef(-0.5,-0.5,0.0);
	  	glMatrixMode(GL_MODELVIEW);



  		glScalef(80,80,80);
  		glRotatef(angulo,0,0,1);
		glVertexPointer(2, GL_FLOAT, 0, v);
	  	glTexCoordPointer(2, GL_FLOAT, 0, tv);
		glDrawArrays(GL_QUADS, 0, 4);

	glPopMatrix();


	glDisableClientState(GL_VERTEX_ARRAY);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

}

Textura::Textura(){
	cout << "constructor Textura"<< endl;


}
