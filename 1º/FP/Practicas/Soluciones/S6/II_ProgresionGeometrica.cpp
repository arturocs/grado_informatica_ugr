//////////////////////////////////////////////////////////////////////////// 
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////  

/*
   Progresi�n Geom�trica
*/


#include <iostream> 
#include <cmath>  
using namespace std;   
    
int main(){     
	double termino_primero, razon;
	int  tope;
	double suma_total;
	int termino;

	cout << "\nIntroduzca el primer t�rmino de la progresi�n: ";
	cin >> termino_primero;
	cout << "\nIntroduzca la raz�n de la progresi�n: ";
	cin >> razon;
	cout << "\nIntroduzca el �ndice >= 1 del �ltimo t�rmino que quiere sumar: ";
	cin >> tope;

	suma_total = termino_primero;

	for (int i = 2; i <= tope; i++)     
		suma_total = suma_total + termino_primero * pow(razon, i-1);		
	
	/*
	En vez de hacer la operaci�n pow, que es costosa, bastar�a multiplicar
	en cada iteraci�n, el valor de a_{i-1} por la raz�n, y ya tengo a_i

	Observad que en Matem�ticas decimos:
		a_i = a_(i-1) * r
	Mientras que en un algoritmo debemos poner:
		termino = termino * r
	*/

	termino = termino_primero;
	suma_total = termino; 

	for (int i = 2; i <= tope ; i++){     
		termino = termino * razon;
		suma_total = suma_total +  termino;
	}
	
	cout << "\nSuma hasta " << tope << " = " << suma_total;
   cout << "\n\n";
	system("pause");
}
