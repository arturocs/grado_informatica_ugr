#include <iostream>
using namespace std;

int main(){
	int inicio, i, j, ultimo, ultimoenlafila, ultimafila, numerodefilas;
   
	cout << "Introduzca el numero inicial"<< endl;
	cin >> inicio;
   
	cout << "Introduzca el numero de filas"<< endl;
	cin >> numerodefilas;
	cout << endl;
   	
	ultimo = inicio + numerodefilas - 1;

	for (i = inicio ; i <= ultimo ; i++){
		for (j = i ; j <= ultimo ; j++){
			cout << j << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
	
	ultimafila = inicio + numerodefilas - 1;

	for (i = inicio ; i <= ultimafila ; i++){
		ultimoenlafila = i + numerodefilas - 1;

		for (j = i ; j <= ultimoenlafila ; j++){
			cout << j << " ";
			}
		cout << "\n";
	}
  
	
}
