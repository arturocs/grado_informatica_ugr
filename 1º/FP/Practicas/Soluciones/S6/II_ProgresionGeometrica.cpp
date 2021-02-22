//////////////////////////////////////////////////////////////////////////// 
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////  

/*
   Progresión Geométrica
*/


#include <iostream> 
#include <cmath>  
using namespace std;   
    
int main(){     
	double termino_primero, razon;
	int  tope;
	double suma_total;
	int termino;

	cout << "\nIntroduzca el primer término de la progresión: ";
	cin >> termino_primero;
	cout << "\nIntroduzca la razón de la progresión: ";
	cin >> razon;
	cout << "\nIntroduzca el índice >= 1 del último término que quiere sumar: ";
	cin >> tope;

	suma_total = termino_primero;

	for (int i = 2; i <= tope; i++)     
		suma_total = suma_total + termino_primero * pow(razon, i-1);		
	
	/*
	En vez de hacer la operación pow, que es costosa, bastaría multiplicar
	en cada iteración, el valor de a_{i-1} por la razón, y ya tengo a_i

	Observad que en Matemáticas decimos:
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
