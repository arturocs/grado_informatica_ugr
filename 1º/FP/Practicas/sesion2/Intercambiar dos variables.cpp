#include <iostream>
using namespace std;

int main(){

int edad_Pedro;
int edad_Juan;
int variabledecambio;

	// Entrada de datos
	cout << "\nIntroduzca el valor de la variable edad_Pedro : ";
	cin >> edad_Pedro;
	cout << "\nIntroduzca el valor de la variable edad_Juan: ";
	cin >> edad_Juan;

	// Cómputos
	variabledecambio = edad_Pedro;
	edad_Pedro = edad_Juan;
	edad_Juan = variabledecambio;
	

	// Salida
	cout << "\nEl valor de la variable edad_Pedro es: " << edad_Pedro << " y el de la variable edad_Juan es: " << edad_Juan ;

}
