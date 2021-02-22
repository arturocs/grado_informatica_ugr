#include <iostream>
using namespace std;

int main(){


double gananciatotal;
double gananciadiseniador;
double gananciafabricantes;



	// Entrada de datos
	cout << "\nIntroduzca la ganancia total: ";
	cin >> gananciatotal;

	// Cómputos
	gananciafabricantes = gananciatotal/5;
	gananciadiseniador = gananciafabricantes*2;

	// Salida
	cout << "\nLa ganancia de cada fabricante es: " << gananciafabricantes << " y la ganancia del diseñador es: " << gananciadiseniador ;

}
