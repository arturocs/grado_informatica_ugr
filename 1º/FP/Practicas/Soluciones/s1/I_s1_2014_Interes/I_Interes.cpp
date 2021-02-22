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
   Programa que calcula el dinero que se obtiene al realizar una
   inversión a plazo fijo (en un año).
   Entradas: capital a invertir (capital) e interés a aplicar (interes).
   Salidas:  dinero total (capital + ganancia obtenida) calculado por:
				total = capital + (capital * interes/100)
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main(){
	double interes;		// Entrada: interés a aplicar
	double capital;		// Entrada: capital solicitado
	double total;			// Salida: cantidad ganada en un año

	cout << "Introduzca capital inicial --> ";
	cin >> capital;
	cout << "\nIntroduzca interés --> ";
	cin >> interes;

    // Observad que la misma variable capital se puede usar en varios sitios de la expresión:

	total = capital + capital * interes/100;

	cout << "\nCapital + Ganancia obtenida = " << total;
	cout << "\n\n";

   /*
      ¿Hubiese sido mejor "ahorrarnos" la variable total?
      
         capital = capital + capital * interes/100;
         cout << "\nCapital + Ganancia obtenida = " << capital;
         
      El programa también funcionaría correctamente, pero ¿y si quisiéramos imprimir
      también el capital inicial? No lo podríamos hacer porque modificamos el valor
      original del capital en la asignación capital = capital + capital * interes/100;

      Principio de Programación:
         No debemos modificar los valores de los datos "importantes" de nuestro programa
         ya que es muy posible que los necesitemos en distintos sitios del programa.

      Por lo tanto, nunca debemos pensar que es bueno utilizar cuantas menos variables mejor.
      Al revés, en numerosas ocasiones, introducir variables aumenta la legibilidad del código.
   */

	system("pause");
}

