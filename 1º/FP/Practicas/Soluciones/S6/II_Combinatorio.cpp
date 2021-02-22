////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

// Combinatorio

/*
	Este ejercicio pone de manifiesto que antes de implementar una fórmula,
	debemos intentar re-escribirla para optimizar el rendimiento en su implementación
	en un lenguaje de programación.
*/

#include <iostream> 
using namespace std;  
   
int main(){    
	int total_a_elegir, elegidos;
	long long factorial_total_a_elegir, factorial_elegidos, factorial_diferencia, combinatorio;

	cout << "\n\nIntroduzca total de elementos: ";
	cin >> total_a_elegir;
	cout << "\nIntroduzca cuántos va a elegir del total: ";
	cin >> elegidos;

	/*
		El combinatorio de n sobre m nos da las formas posibles de elegir m elementos
		de un total de n, sin repetición y sin importar el orden.
		El ejemplo típico es la lotería primitiva.

		La siguiente solución aplica la fórmula del combinatorio directamente,
		es decir, calculando n! / (m! (n-m)!)
	*/

	/*
	factorial_total_a_elegir = 1;

	for (i = 2; i <= total_a_elegir; i++)
		factorial_total_a_elegir = factorial_total_a_elegir * i;

	factorial_elegidos = 1;

	for (i = 2; i <= elegidos; i++)
		factorial_elegidos = factorial_elegidos * i;

	factorial_diferencia = 1;

	for (i = 2; i <= total_a_elegir - elegidos; i++)
		factorial_diferencia = factorial_diferencia * i;

	combinatorio = factorial_total_a_elegir / (factorial_elegidos * factorial_diferencia);

	cout << "\nCombinaciones de " << total_a_elegir << " elementos ";
	cout << "tomados de " << elegidos << " en " << elegidos;
	cout << " = " << combinatorio;
	*/

	/*
		La anterior aproximación puede producir desbordamiento incluso utilizando
		un tipo entero tan grande como long long.
		Comprobadlo con 49 y 6 (combinaciones posibles en la lotería primitiva)
		http://www.nitrxgen.net/factorialcalc.php

		49! -> Tiene 63 cifras = 608281864034267560872252163321295376887552831379210240000000000
		60415263063373835637355132068513997507264512000000000

		De hecho, el máximo factorial representable en un long long es el de 20.

		Con un double tampoco valdría ya que, aunque le cupiese y no hubiese desbordamiento,
		sólo habría 16 cifras de precisión.

		Sin embargo, podemos optimizar la fórmula y simplificar la expresión del cálculo del combinatorio:
		n! / (m! (n-m)!)  =   n(n-1)...(n-m+1) / m!

		¡Hemos pasado a tener únicamente m multiplicaciones en el numerador y denominador!

		total_a_elegir (total_a_elegir-1) ... (total_a_elegir - elegidos + 1) / elegidos!

		Ahora sí podemos calcular, al menos, la probabilidad de ganar en la primitiva
		(que, por cierto, no son muchas = 1 / combinaciones de 49 tomados de 6 en 6) = 1 entre 13.983.816
	*/

	/*
		En la siguiente solución calculamos el numerador recorriendo todos
		los factores que hay entre total_a_elegir y total_a_elegir - elegidos + 1
	*/
	/*
	long long numerador;

	factorial_elegidos = 1;
	numerador = 1;

	for (i = 2; i <= elegidos; i++)
		factorial_elegidos = factorial_elegidos * i;

	for (i = total_a_elegir - elegidos + 1 ; i <= total_a_elegir ; i++)
		numerador = numerador * i;
	*/

	/*
		En la siguiente solución realizamos el recorrido de los factores
		del numerador y denominador dentro del mismo bucle.
	*/

	long long numerador;

	factorial_elegidos = 1;
	numerador = 1;

	for (int i = 1 ; i <= elegidos ; i++){    
       factorial_elegidos = factorial_elegidos * i;
       numerador = numerador * (total_a_elegir - elegidos + i);
   }

	combinatorio = numerador/factorial_elegidos;

	cout << "\nCombinaciones de " << total_a_elegir << " elementos ";
	cout << "tomados de " << elegidos << " en " << elegidos;
	cout << " = " << combinatorio;

   cout << "\n\n";
	system("pause");
}
