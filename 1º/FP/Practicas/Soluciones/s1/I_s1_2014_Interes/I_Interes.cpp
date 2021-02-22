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
   Programa que calcula el dinero que se obtiene al realizar una
   inversi�n a plazo fijo (en un a�o).
   Entradas: capital a invertir (capital) e inter�s a aplicar (interes).
   Salidas:  dinero total (capital + ganancia obtenida) calculado por:
				total = capital + (capital * interes/100)
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main(){
	double interes;		// Entrada: inter�s a aplicar
	double capital;		// Entrada: capital solicitado
	double total;			// Salida: cantidad ganada en un a�o

	cout << "Introduzca capital inicial --> ";
	cin >> capital;
	cout << "\nIntroduzca inter�s --> ";
	cin >> interes;

    // Observad que la misma variable capital se puede usar en varios sitios de la expresi�n:

	total = capital + capital * interes/100;

	cout << "\nCapital + Ganancia obtenida = " << total;
	cout << "\n\n";

   /*
      �Hubiese sido mejor "ahorrarnos" la variable total?
      
         capital = capital + capital * interes/100;
         cout << "\nCapital + Ganancia obtenida = " << capital;
         
      El programa tambi�n funcionar�a correctamente, pero �y si quisi�ramos imprimir
      tambi�n el capital inicial? No lo podr�amos hacer porque modificamos el valor
      original del capital en la asignaci�n capital = capital + capital * interes/100;

      Principio de Programaci�n:
         No debemos modificar los valores de los datos "importantes" de nuestro programa
         ya que es muy posible que los necesitemos en distintos sitios del programa.

      Por lo tanto, nunca debemos pensar que es bueno utilizar cuantas menos variables mejor.
      Al rev�s, en numerosas ocasiones, introducir variables aumenta la legibilidad del c�digo.
   */

	system("pause");
}

