#include <iostream>
#include "bloqueLed.h"

using namespace std;


void on(bloqueLed &b, int pos){
      bloqueLed a=0x1;
      a= a << pos;
       b= b|a;
}

void off(bloqueLed &b, int pos)
{
      bloqueLed a=0x1; 
      a= a << pos;
       a=~a;
       b= b & a;
}

bool get(bloqueLed b, int pos){
	bloqueLed am = 0x1, resultado;
	am = am << pos;
	resultado = b & am;
	resultado = resultado >> pos;
	if (resultado == 0)
		return false;
	else 
		return true; 
}

void print(bloqueLed b)
{  
  int aux;
 
      for(int i=0; i <8;i++)
      {
        aux=get(b, i);
        cout<<aux;
      }
  cout<<endl;
}

void encender(bloqueLed &b)
{
   b=255;
}

void apagar(bloqueLed &b){
	b=0x0;

}

void asignar(bloqueLed &b, const bool v[]){
	for(int i=0;i<8;i++){
		if (v[i])
			on(b, i);
		else
			off(b, i);
	}
}
void volcar(bloqueLed b, bool v[]){
	for(int i=0;i>=7;i++){
		v[i]=get(b, i);
	}
}
void encendidos(bloqueLed b, int posic[], int &cuantos){
	cuantos=0;
	for (int i=0; i<8; i++){
		if (get(b, i)){
			posic[cuantos]=i;
			cuantos++;
		}
	}
}
