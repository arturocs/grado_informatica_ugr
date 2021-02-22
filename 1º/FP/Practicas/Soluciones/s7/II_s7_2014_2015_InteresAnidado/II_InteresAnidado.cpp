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
   Sobre la solución del ejercicio 11 de esta relación de problemas, se pide lo siguiente.
   Supondremos que sólo pueden introducirse intereses enteros (1, 2, 3, etc). Se pide
   calcular el capital obtenido al término de cada año, pero realizando los cálculos para
   todos los tipos de interés enteros menores o iguales que el introducido (en pasos de
   1). Por ejemplo, si el usuario introduce un interés de 5, y un número de años igual a 3,
   hay que mostrar el capital ganado al término de cada uno de los tres años a un interés
   del 1 %; a continuación, lo mismo para un interés del 2 %, y así sucesivamente hasta
   llegar al 5 %. El programa debe mostrar una salida del tipo:

   Cálculos realizados al 1%:
   Dinero obtenido en el año número 1 = 2020
   Dinero obtenido en el año número 2 = 2040.2
   Dinero obtenido en el año número 3 = 2060.6

   Cálculos realizados al 2%:
   Dinero obtenido en el año número 1 = 2040
   Dinero obtenido en el año número 2 = 2080.8
   Dinero obtenido en el año número 3 = 2122.42
*/

#include <iostream>
using namespace std;

int main(){
	double interes, interes_actual, capital_inicial, capital_acumulado;
	int anios_transcurridos, numero_anios;

	cout << "Introduzca capital inicial --> ";
	cin >> capital_inicial;
	cout << "\nIntroduzca número de años --> ";
	cin >> numero_anios;
	cout << "\nIntroduzca interés (como un %) --> ";
	cin >> interes; 

	/*
      Algoritmo:

         Recorrer los distintos valores de interés
            Reiniciar capital_acumulado al capital original
            Recorrer todos los años
               Acumular en capital_acumulado el total del año anterior 
               junto con los intereses.
   */

	for (interes_actual = 1 ; interes_actual <= interes ; interes_actual++){     
		cout << "\n\nResultados calculados para un interés del " << interes_actual << "% =\n";
		cout << "Capital inicial: " << capital_inicial;

		capital_acumulado = capital_inicial; 

		for (anios_transcurridos = 0 ; anios_transcurridos < numero_anios; anios_transcurridos++){     
			capital_acumulado = capital_acumulado + capital_acumulado * interes_actual / 100.0;
			cout << "\nCapital obtenido transcurrido el año número " << anios_transcurridos + 1 << " = " << capital_acumulado;   
		}
	}

   /*
		Importante: Observad la asignación
			capital_acumulado = capital_inicial; 
		Es necesario hacerlo, cada vez, antes de entrar al bucle for (anio ....
	*/
   
   cout << "\n\n";
   system("pause");
}
