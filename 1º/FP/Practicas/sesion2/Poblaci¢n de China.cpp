#include <iostream>
using namespace std;

int main(){

const double INCREMENTOANUAL = 6781525.246331089 ;
int poblacioninicial;
long poblacionfinal;
short numeroanios;

	// Entrada de datos
	cout << "\nIntroduzca la poblacion inicial: ";
	cin >> poblacioninicial;
	cout << "\nIntroduzca el numero de años: ";
	cin >> numeroanios;

	// Cómputos
	poblacionfinal = poblacioninicial + INCREMENTOANUAL*numeroanios;

	// Salida
	cout << "\nLa poblacion final es: " << poblacionfinal ;

}
