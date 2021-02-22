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
   Ejercicio del inter�s acumulado usando un bucle for
*/

#include <iostream> 
using namespace std;  
   
int main(){    
   double interes, capital_inicial, capital_acumulado;
   int anios_transcurridos, numero_anios;
   
   cout << "Introduzca capital inicial --> ";
   cin >> capital_inicial;
   cout << "\nIntroduzca n�mero de a�os --> ";
   cin >> numero_anios;
   cout << "\nIntroduzca inter�s (como un %) --> ";
   cin >> interes;   
   
	capital_acumulado = capital_inicial;

	for (anios_transcurridos = 0 ; anios_transcurridos < numero_anios ; anios_transcurridos++){     
		capital_acumulado = capital_acumulado  +  capital_acumulado * interes / 100.0; 
		cout << "\nCapital en el a�o n�mero " << anios_transcurridos + 1 << " = " << capital_acumulado;    // anios_transcurridos + 1 ! ya que se incrementa al final, antes del cout.
	}

	cout << "\n\n";
	system("pause");
}