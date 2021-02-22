#include <iostream>
#include <cmath>
using namespace std;

int main(){

int valordeentrada;
int digitodesalida;
int i=0;
int aux;
int suma=0;
int exponente;

	cout << "\nIntroduzca un entero : ";
	cin >> valordeentrada;

	aux=valordeentrada;
	
	while (aux!=0){	
		aux = aux/10;
		i++;	
	}
	exponente=i;

		
	for(i;i>0;i--){
		digitodesalida=(valordeentrada/pow(10,(i-1)));
		suma=suma+pow(digitodesalida%10,exponente);
			
	}
	
	if (valordeentrada==suma)
	cout << "El numero es narcisista";
	else
	cout << "El numero no es narcisista";
	
}
