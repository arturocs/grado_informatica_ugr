#include <iostream>

using namespace std;

int main(){

int entero1;
int entero2;
int entero3;


	// Entrada de datos
	cout << "\nIntroduzca un entero1: ";
	cin >> entero1;
	cout << "\nIntroduzca un entero2: ";
	cin >> entero2;
	cout << "\nIntroduzca un entero3: ";
	cin >> entero3;

if (entero1<entero2&&entero2<entero3)
	cout << "\nLos enteros estan ordenados" ; 
else
	cout << "\nLos enteros no estan ordenados" ; 

}
