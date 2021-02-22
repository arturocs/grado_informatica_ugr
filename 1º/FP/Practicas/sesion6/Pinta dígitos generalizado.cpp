#include <iostream>
#include <cmath>
using namespace std;

int main(){

int valordeentrada;
int digitodesalida;
int i=0;
int aux;



	cout << "\nIntroduzca un entero : ";
	cin >> valordeentrada;
	cout << "\nLa secuencia de numeros correspondiente es: \n";
	
	aux=valordeentrada;
	
	while (aux!=0){	
		aux = aux/10;
		i++;	
	}
		
	for(i;i>0;i--){
		digitodesalida=(valordeentrada/pow(10,(i-1)));
		cout << digitodesalida%10 << " ";
		
	}
	
}
