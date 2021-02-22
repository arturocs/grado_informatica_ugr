#include <iostream>
using namespace std;

int main(){

short valordeentrada;
short digitodesalida;

	cout << "\nIntroduzca un entero de tres cifras: ";
	cin >> valordeentrada;
	
	cout << "\nLa secuencia de numeros correspondiente es: \n";
	digitodesalida = valordeentrada/100;
	cout << digitodesalida << " ";
	digitodesalida = (valordeentrada/10)-(10*digitodesalida);
	cout << digitodesalida << " ";
	digitodesalida = (valordeentrada%10);
	cout << digitodesalida ;
}
