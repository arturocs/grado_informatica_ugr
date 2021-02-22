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
   El m�todo RLE (Run Length Encoding) codifica una secuencia de datos formada por
   series de valores id�nticos consecutivos como una secuencia de parejas de n�meros
   (valor de la secuencia y n�mero de veces que se repite). Esta codificaci�n es un
   mecanismo de compresi�n de datos (zip) sin p�rdidas. Se aplica, por ejemplo, para
   comprimir los ficheros de im�genes en las que hay zonas con los mismos datos (fondo
   blanco, por ejemplo). Realizar un programa que lea una secuencia de n�meros
   naturales terminada con un n�mero negativo y la codifique mediante el m�todo RLE.

   Entrada: 1 1 1 2 2 2 2 2 3 3 3 3 3 3 5 -1   
   Salida: 3 1 5 2 6 3 1 5
          (tres veces 1, cinco veces 2, seis veces 3, una vez 5)
*/

#include <iostream> 
using namespace std;  
   
int main(){    
	const int TERMINADOR = -1;	
   int actual, anterior, iguales_hasta_ahora;

   /*
      Idea:
         Llevar dos variables actual y anterior que "apunten"
         al valor le�do en un momento dado y al valor anterior, respectivamente.

      Descripci�n del algoritmo:

      Mientras que el actual no sea el terminador 
			Avanzar anterior y actual

         Si son iguales
            incrementar la longitud de la secuencia actual
         si no
            Imprimir el anterior junto con la longitud de la secuencia
            y resetear el contador de la longitud actual
            
   */

	cin >> actual;
	iguales_hasta_ahora = 1;

	while (actual != TERMINADOR){     
		anterior = actual;      
		cin >> actual;

		if (anterior == actual)
			iguales_hasta_ahora++;
		else{
			cout << iguales_hasta_ahora << " " << anterior << " ";      
			iguales_hasta_ahora = 1;
		}
	}   

	cout << "\n\n";
	system("pause");
}
