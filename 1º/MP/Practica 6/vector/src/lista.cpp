#include <string>
#include <fstream>
#include "lista.h"

using namespace std;

Lista::Lista(){
	cabecera=NULL;
}
   
Lista::Lista(string valor){
	cabecera = new Celda;
	cabecera->datos = valor; 
	cabecera->siguiente=NULL;
}
void Lista::destruir(){
	Celda *borra;
	while(cabecera != NULL){
	borra= cabecera;
	cabecera=cabecera->siguiente; 
	delete borra;
	}
}  

void Lista::insertar(string valor){
	Celda* nueva= new Celda;
	nueva->datos= valor;
	nueva->siguiente=NULL;

	if(cabecera == NULL){
		cabecera= nueva;
	}
	else{
		Celda *aux= cabecera;
		while( aux->siguiente != NULL ){
			aux= aux->siguiente;
		}
		aux->siguiente= nueva; 
	}	
}

string Lista::getCelda(int pos) const{
	string valor;
	int contador=0;
	Celda *aux=cabecera;
	while(contador < pos && aux){
		aux=aux->siguiente;
		contador++;	
	}	
	if( aux != NULL){
		valor= aux->datos;
	}
	return valor;
}

int Lista::longitud() const{
	int contador=0;
	Celda* aux;
	aux=cabecera;
	while( aux != NULL){
		aux=aux->siguiente;
		contador++;	
	}
	return contador;
}

bool Lista::leerLista(const char nombrefichero[]){
	ifstream fin;
	fin.open(nombrefichero);
	if(!fin){
		return false;
	}
	else{
		string grises;
		int lineas;
		getline(fin,grises);
		fin >> lineas;
		getline(fin,grises);
		if (!fin){
			return false;
		}
		else {
			int i = 0;
			getline(fin,grises); 
			while ((i < lineas)&&(fin)){
				if (grises != ""){
					insertar(grises);
					i++;
				}
				getline(fin,grises);
			}
		}
		fin.close();
	}
	return true;
}


//Destructor

Lista::~Lista()
{
	destruir();


}

//Funcion auxiliar para copiar dos listas con la ventaja que podemos usarlo cuando queramos en vez del constructor de copia que no se puede

void Lista::Copiar(const Lista &orig)
{
	if(orig.cabecera!=NULL)
	{
		cabecera=new Celda;
		cabecera->datos=orig.cabecera->datos;
		Celda *aux_orig=orig.cabecera->siguiente;
		Celda *aux_this=cabecera;
		while(aux_orig != NULL)
		{
			aux_this->siguiente=new Celda;
			aux_this=aux_this->siguiente;
			aux_this->datos=aux_orig->datos;
			aux_orig=aux_orig->siguiente;
			
		}
		aux_this->siguiente=NULL;

	}
	else
	cabecera=NULL;
}




//Por copia

Lista::Lista(const Lista &orig)
{
	Copiar(orig);	
}

//Operador asignacion

Lista & Lista::operator=(const Lista &orig)
{
	if(this!=&orig)
	{
		destruir();  //SI tiene datos nuestro this
		Copiar(orig);
	}	
			

	return *this;



}




//Operator +

Lista Lista::operator+(const string &orig) const
{
	Lista nueva(*this);              //Creamos una nueva lista con los datos de la misma anterior
	nueva.insertar(orig);		 //Insertamos el elemento
	
	return nueva;
	
}


















