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
   Cómputo del factorial y potencia de un número.
   Factorial:
      n! = 1 si n=0
      n! = n(n-1)(n-2)...1 si n>=1
   Potencia:
      x^n = x x ... x  (n veces)
*/

/*
	Como el factorial de n es un número mucho más grande que n,
	usamos un long long para almacenar el resultado.
	¡¡Aún así, el máximo factorial que podemos almacenar en un long long es el factorial de 20!!
	Factorial(20) = 2432902008176640000 

	Consultad esta web para realizar cómputos de factoriales con números grandes:
	http://www.nitrxgen.net/factorialcalc.php
*/

#include <iostream> 
using namespace std;  
   
int main(){    
   long long factorial;
	int n;
	int multiplicando;

	cout << "\nIntroduzca un entero entre 0 y 20: ";
	cin >> n;

	/*
	Algoritmo:

		Inicializar factorial a 1

		Recorrer los enteros entre 2 y n
			Acumular el producto de cada entero en factorial
	*/

	factorial = 1;

	for (multiplicando = 2; multiplicando <= n ; multiplicando++)    
		factorial = factorial * multiplicando;

	cout << "\nEl factorial de " << n << " es " << factorial;

	/////////////////////////////////////////////////////////////

	double base;
	int exponente, i;
	double potencia;

	cout << "\n\nIntroduzca la base: ";
	cin >> base;
	cout << "\nIntroduzca el exponente: ";
	cin >> exponente;

	/*
	Algoritmo:

		Inicializar potencia a 1 (base ^ 0 = 1)

		Repetir tantas veces como diga el exponente
			Acumular el producto de base en potencia 
	*/

	potencia = 1.0;

	for (i = 1; i <= exponente; i++)    
		potencia = potencia * base;

	cout << "\n" << base << " elevado a " << exponente << " es igual a " << potencia;

	// Observad que si exponente fuese cero, la variable potencia se quedaría con 1,
	// lo que es correcto ya que base elevado a 0 es siempre 1

   cout << "\n\n";
	system("pause");
}
