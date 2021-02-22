#include <imagen.h>
#include <pgm.h>
#include <byte.h>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <lista.h>
#include <fstream>

using namespace std;
typedef unsigned char byte;

Imagen::Imagen ()
{
	nfilas=0;
	ncolumnas=0;
	datos=0;	
}
Imagen::Imagen ( int filas , int columnas )
{
	nfilas=filas;
	ncolumnas=columnas;

	datos= new byte [nfilas * ncolumnas];	

	for(int i=0 ; i < filas*columnas; i++)
	{ 
			datos[i]=0;
	}
}

void Imagen::crear ( int filas , int columnas )
{ 
	nfilas=filas;
	ncolumnas=columnas;

	if(datos != 0)
		delete [] datos;		
	
	datos = new byte [filas * columnas];	
		
	for(int i=0 ; i< filas*columnas; i++)	
	{  
			datos[i]=0;
	}	
}

int Imagen::filas()
{
	return nfilas;
}

int Imagen::columnas()
{
	return ncolumnas;
}

void Imagen::set ( int y , int x , byte v )
{
		assert(datos != 0);			
			datos[ y * ncolumnas + x ]=v;
}

byte Imagen::get ( int y , int x )
{
		assert(datos != 0);			  
		return datos [y * ncolumnas + x];
}

void Imagen::setPos ( int i , byte v )
{ 

	assert(datos != 0 && i<ncolumnas*nfilas);
	datos[i]=v;
}
	
byte Imagen::getPos ( int i )
{

		assert(datos != 0 && i<ncolumnas*nfilas);	
		return datos[i];
}
	
bool Imagen::leerImagen ( const char nombreFichero [ ] ){
			
			if((infoPGM(nombreFichero, nfilas, ncolumnas)==IMG_PGM_BINARIO)){	
				Imagen::crear(nfilas, ncolumnas);
				return leerPGMBinario (nombreFichero, datos, nfilas, ncolumnas);
			}else if((infoPGM(nombreFichero, nfilas, ncolumnas)==IMG_PGM_TEXTO)){	
				Imagen::crear(nfilas, ncolumnas);
				return leerPGMTexto(nombreFichero, datos, nfilas, ncolumnas);
			}else{
				
				return false;
			}
	}

	bool Imagen::escribirImagen ( const char nombreFichero [ ] , bool esBinario ){
		bool resultado = true;
			if(datos!=0){
				if(esBinario){
					resultado = escribirPGMBinario (nombreFichero, datos, nfilas, ncolumnas);
				}else{
					resultado = escribirPGMTexto (nombreFichero, datos, nfilas, ncolumnas);
				}
			}
		return resultado;					
	}

	Imagen Imagen::plano ( int k ){
		Imagen img(nfilas , ncolumnas );
		byte auxiliar;
		bool estadoled;
		if(datos != 0){
			for(int i=0 ; i< nfilas*ncolumnas; i++){
				auxiliar = datos [i];
				estadoled = getbit ( auxiliar, k );
				apagar(auxiliar); 

				if(estadoled){
					on (auxiliar,7);
				}
				img.setPos(i,auxiliar); 
			}
		}
	return img;
	}
	
	bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong){
		int pos=0;
		int tamanio=0;
		if(ncolumnas*nfilas < maxlong){
			tamanio=strlen(grises);
			for(int fil=0;fil<nfilas;fil++){
				for(int col=0;col<ncolumnas;col++){
					pos=fil*ncolumnas+col;
					arteASCII[pos]=grises[get(fil,col)*tamanio/256];
				}
				arteASCII[pos]='\n';
			}
			arteASCII[pos++]='\0';
			return true;
		}
		else{
			return false;
		}
	}

void Imagen::destruir()
{		
	if (datos != 0)
	{
		delete [] datos;
	}
		
	nfilas = 0;
	ncolumnas = 0;
	datos= 0;
	}
	
bool Imagen::listaAArteASCII(const Lista celdas)
{
	
	string gris;
	char * arteASCII;
	ofstream fichout;					
	string fichero;
	bool satisfactorio=true;

		for(int i =0; i< celdas.longitud() ; i++ ){	
			
			fichero="ascii"+to_string(i)+".txt";
			gris=celdas.getCelda (i);
			arteASCII = new char[nfilas*ncolumnas +1];
			aArteASCII(gris.c_str(),arteASCII, nfilas*ncolumnas +2);
			fichout.open(fichero);					 
			
			if(fichout){						
				fichout<< arteASCII;
			}
			else{
				satisfactorio=false;				
			}
			fichout.close();					
			delete [] arteASCII;					
		}
		return satisfactorio;
}

//Destructor
Imagen::~Imagen()
{
	destruir();

}
//Funcion auxiliar para copiar imagenes
void Imagen::Copiar(const Imagen &orig)
{
	if(orig.datos !=NULL)
	{
		nfilas=orig.nfilas;
		ncolumnas=orig.ncolumnas;
		datos=new byte[nfilas*ncolumnas];
		for(int i=0; i<nfilas*ncolumnas; i++)
		{			
		datos[i]=orig.datos[i];
		}
	}
	else
	{
		datos=NULL;
		nfilas=ncolumnas=0;
	}
}

//Copia
Imagen::Imagen(const Imagen &orig)
{
	Copiar(orig);
}
//Operator=
Imagen & Imagen::operator=(const Imagen &orig)
{
	if(this!=&orig)
	{
		destruir();
		Copiar(orig);
	}
	return *this;
}

//Operator+
Imagen Imagen::operator+(const Imagen &orig) const
{
	Imagen nueva;
	nueva.crear(nfilas,(ncolumnas+orig.ncolumnas));
	int j=0, z=0;
	
	for(int i=0; i<nueva.nfilas*nueva.ncolumnas;i++)
	{
		if( i%nueva.ncolumnas < this->ncolumnas )
		{
			if( i< this->nfilas*nueva.ncolumnas)
			{
				nueva.datos[i]=this->datos[z];
				z++;
			}
			else
				nueva.datos[i]=0;

		}
		else
		{
			if(i <orig.nfilas*nueva.ncolumnas)
			{
			nueva.datos[i]=orig.datos[j];
			j++;
			}	
			else
			nueva.datos[i]=0;
		}



	}
	




	return nueva;

}
