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
   Programa que pide la intensidad de la corriente y la resistencia para 
			calcular e imprimir en pantalla el voltaje
   Entradas: Intensidad de la corriente (intensidad) y 
			 la resistencia (resistencia)
   Salidas:  El voltaje, calculado mediante la ley de Ohm: 
				voltaje = intensidad * resistencia
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main(){
	double intensidad;   // Entrada: intensidad de corriente
	double resistencia;	// Entrada: resistencia 
	double voltaje;		// Salida: voltaje 

	// Entrada de datos
	cout << "\nIntroduzca el valor de intensidad: ";
	cin >> intensidad;
	cout << "\nIntroduzca el valor de resistencia: ";
	cin >> resistencia;

	// C�mputos
	voltaje = intensidad * resistencia;

	// Salida
	cout << "\nEl valor de voltaje es: " << voltaje << "\n\n";

	system("pause");
}