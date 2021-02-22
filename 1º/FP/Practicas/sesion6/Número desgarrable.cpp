#include <iostream>
#include <cmath>
using namespace std;

int main(){

int valordeentrada;
int numero;
int i=0;
int aux;
int x;
bool desgarrable=false;

	cout << "\nIntroduzca un entero : ";
	cin >> valordeentrada;
	
	aux=valordeentrada;
	
	while (aux!=0){	
		aux = aux/10;
		i++;	
	}	
	for(i;i>0;i--){
	
	x=pow(10,i-1);
	numero=pow((valordeentrada/x)+(valordeentrada%x),2);

	if (valordeentrada==numero)
		desgarrable=true;

	}
	
	if (desgarrable)
	cout << "El " << valordeentrada <<" numero es desgarrable";
	else
	cout << "El " << valordeentrada <<" numero no es desgarrable";
	
}
