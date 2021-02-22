#include <iostream>
using namespace std;

int main(){
	int suma, tope, sumando, entero;
	bool triangular;
	
	cout << "Introduzca un tope ";
	cin >> tope;

	for (entero = 1; entero <= tope; entero++){
		triangular = false;
		suma = 0;
		sumando = 1;
		
		while(suma < entero && !triangular){		
			suma = suma + sumando;
			triangular = suma == entero;
			sumando++;
		}
		
		if (triangular)
			cout << entero << " es triangular" << endl;;
	}
		
}

