#include <iostream>
using namespace std;

int main(){


double gananciatotal;
double gananciadiseniador;
double gananciafabricantes;



	// Entrada de datos
	cout << "\nIntroduzca la ganancia total: ";
	cin >> gananciatotal;

	// C�mputos
	gananciafabricantes = gananciatotal/5;
	gananciadiseniador = gananciafabricantes*2;

	// Salida
	cout << "\nLa ganancia de cada fabricante es: " << gananciafabricantes << " y la ganancia del dise�ador es: " << gananciadiseniador ;

}
