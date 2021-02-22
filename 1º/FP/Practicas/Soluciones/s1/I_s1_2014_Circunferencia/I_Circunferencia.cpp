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
   Programa que pide el radio y calcula e imprime
   en pantalla el área correspondiente y la longitud de la circunferencia.
   Entradas: El radio de la circunferencia
   Salidas:  El área del círculo calculada mediante:
				      area = PI * radio * radio
             La longitud de la circunferencia calculada mediante:
				      longitud = 2 * PI * radio
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main(){
   /*
      Si en vez de usar el dato PI hubiésemos utilizado el literal 3.1416
      
         area = 3.1416 * radio * radio;
	      longitud = 2 * 3.1416  * radio;
	      
      el código fuente es "propenso a errores" ya que la actualización del programa
      puede ser problemática. Para cambiar 3.1416 por un valor más preciso como 3.1415927
      debemos marcar con el ratón el texto y reemplazar 16 por 15927
      ¿Y si en el texto marcado hubiese alguna aparición de 16 que no correspondiese a Pi?
      Lo resolvemos usando el dato PI y actualizamos su valor modificando únicamente
      la línea en la que se define dicho dato.

      Principio de Programación:
         Las actualizaciones futuras de nuestro código deben afectar al menor número
         posible de instrucciones.

      Por otra parte, sería deseable que el compilador diese un error
        si el programador incluyese una sentencia para modificar el valor de PI.
        Ésto se consigue con el cualificador const:
        
        const double PI = 3.1415927
   */

	const double PI = 3.1415927;

	double radio;				// Dato de entrada
	double area, longitud;	// Datos de salida

	cout << "Introduzca el valor del radio: ";
	cin >> radio;

	area = PI * radio * radio;
	longitud = 2 * PI  * radio;

	cout << "\n\nEl área del círculo vale " << area;
	cout << "\n\nLa longitud de la circunferencia vale " << longitud;
	cout << "\n\n";

	system("pause");
}
