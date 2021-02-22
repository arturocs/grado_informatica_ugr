#include<iostream>
#include <cstring>
#include "imagen.h"
#include "pgm.h"
#include "byte.h"

using namespace std;

Imagen::Imagen()
{
    nfilas=0;
    ncolumnas=0;
};

 Imagen::Imagen(int filas, int columnas)
{ 
    nfilas=filas;
    ncolumnas=columnas;
    for(int i=0; i < filas*columnas;i++)
     {
        datos[i]=0;
     };
   
};

void Imagen::crear(int filas, int columnas)
{
     nfilas=filas;
     ncolumnas=columnas;
     
      for(int i=0; i < filas*columnas;i++)
     {
        datos[i]=0;
     }
};


int Imagen::filas()
{
    return nfilas;

}; 

int Imagen::columnas()
{
     return ncolumnas;

}; 


 void Imagen::set(int y, int x, byte v)
{
       
        datos[(y*ncolumnas)+x]=v;

}; 

   byte Imagen::get(int y, int x)
{
      byte aux;
      aux=datos[(y * ncolumnas)+x];

return aux;

}; 

   void Imagen::setPos(int i, byte v)
{

   datos[i]=v;


}; 
   
   byte Imagen::getPos(int i)
{
	byte aux;
      aux=datos[i];

return aux;
	
};

bool Imagen::leerImagen(const char nombreFichero[]){

	if (infoPGM(nombreFichero, nfilas, ncolumnas)==IMG_PGM_BINARIO){
		if (nfilas*ncolumnas<=MAXPIXELS)
			return leerPGMBinario (nombreFichero,datos,nfilas,ncolumnas);
                else return false;
	}
	else{
		if (infoPGM(nombreFichero, nfilas, ncolumnas)==IMG_PGM_TEXTO){
			if (nfilas*ncolumnas<=MAXPIXELS){
				return leerPGMTexto (nombreFichero,datos,nfilas,ncolumnas);
			}
		} else return false;
	}	
		
};

bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario)
{
	if (esBinario){
		return escribirPGMBinario(nombreFichero,datos,nfilas, ncolumnas);
	}
	else{
		return escribirPGMTexto(nombreFichero,datos,nfilas, ncolumnas);
	}

};

Imagen Imagen::plano(int k)
{
	Imagen imagenplano(nfilas, ncolumnas);
	for (int i=0; i<=(nfilas*ncolumnas); i++)
              {
		apagar(imagenplano.datos[i]);
		if (getbit(datos[i], k))
			on(imagenplano.datos[i], 7);
               }
       return imagenplano;
};

bool Imagen::aArteASCII ( const char grises [] , char arteASCII[], int maxlong ){
	int valor;        
	if(nfilas*ncolumnas<=maxlong)
	{
		for(int i=0; i< nfilas* ncolumnas; i++){
			if (i%ncolumnas==0)
			{
				arteASCII[i]= '\n'  ;
			}
			else{
			valor=(datos[i]*strlen(grises))/256;
			arteASCII[i]=grises[valor];
         		}
			
		}       
		return true;	
	} 
	else 
	return false;
};




