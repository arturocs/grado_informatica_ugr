#include <iostream>
#include "byte.h"

using namespace std;


void on(byte &b, int pos){
      byte a=0x1;
      a= a << pos;
       b= b|a;
}

void off(byte &b, int pos)
{
      byte a=0x1; 
      a= a << pos;
       a=~a;
       b= b & a;
}

bool getbit(byte b, int pos){
	byte am = 0x1, resultado;
	am = am << pos;
	resultado = b & am;
	resultado = resultado >> pos;
	if (resultado == 0)
		return false;
	else 
		return true; 
}

void print(byte b)
{ 
      for(int i=7; i >=0;i--)
        cout<<getbit(b, i);

  cout<<endl;
}

void encender(byte &b)
{
   b=255;
}

void apagar(byte &b){
	b=0x0;

}

void asignar(byte &b, const bool v[]){
	for(int i=0;i<8;i++){
		if (v[i])
			on(b, i);
		else
			off(b, i);
	}
}
void volcar(byte b, bool v[]){
	for(int i=0;i>=7;i++){
		v[i]=getbit(b, i);
	}
}
void encendidos(byte b, int posic[], int &cuantos){
	cuantos=0;
	for (int i=0; i<8; i++){
		if (getbit(b, i)){
			posic[cuantos]=i;
			cuantos++;
		}
	}
}
