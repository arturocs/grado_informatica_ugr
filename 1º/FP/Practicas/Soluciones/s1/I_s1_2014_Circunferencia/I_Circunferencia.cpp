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
   Programa que pide el radio y calcula e imprime
   en pantalla el �rea correspondiente y la longitud de la circunferencia.
   Entradas: El radio de la circunferencia
   Salidas:  El �rea del c�rculo calculada mediante:
				      area = PI * radio * radio
             La longitud de la circunferencia calculada mediante:
				      longitud = 2 * PI * radio
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main(){
   /*
      Si en vez de usar el dato PI hubi�semos utilizado el literal 3.1416
      
         area = 3.1416 * radio * radio;
	      longitud = 2 * 3.1416  * radio;
	      
      el c�digo fuente es "propenso a errores" ya que la actualizaci�n del programa
      puede ser problem�tica. Para cambiar 3.1416 por un valor m�s preciso como 3.1415927
      debemos marcar con el rat�n el texto y reemplazar 16 por 15927
      �Y si en el texto marcado hubiese alguna aparici�n de 16 que no correspondiese a Pi?
      Lo resolvemos usando el dato PI y actualizamos su valor modificando �nicamente
      la l�nea en la que se define dicho dato.

      Principio de Programaci�n:
         Las actualizaciones futuras de nuestro c�digo deben afectar al menor n�mero
         posible de instrucciones.

      Por otra parte, ser�a deseable que el compilador diese un error
        si el programador incluyese una sentencia para modificar el valor de PI.
        �sto se consigue con el cualificador const:
        
        const double PI = 3.1415927
   */

	const double PI = 3.1415927;

	double radio;				// Dato de entrada
	double area, longitud;	// Datos de salida

	cout << "Introduzca el valor del radio: ";
	cin >> radio;

	area = PI * radio * radio;
	longitud = 2 * PI  * radio;

	cout << "\n\nEl �rea del c�rculo vale " << area;
	cout << "\n\nLa longitud de la circunferencia vale " << longitud;
	cout << "\n\n";

	system("pause");
}
