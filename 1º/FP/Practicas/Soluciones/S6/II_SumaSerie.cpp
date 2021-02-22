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
   Sumar los valores de la serie:
      a_i = ( (-1)^i (i^2 - 1) ) / 2i
   sin usar la funci�n pow.
*/


#include <iostream> 
#include <cmath>  
using namespace std;   
    
/*
   Una primera soluci�n pasar�a por hacer  lo siguiente:
   Para calcular en cada iteraci�n -1 elevado a i, lo hago
   con un bucle similar al usado para calcular una base
   cualquiera elevado a un exponente entero, sustituyendo
   la base por -1 y el exponente por i, es decir:
      
   for (int recorre = 1; recorre <= i; recorre++)
       potencia_de_menos_1 = potencia_de_menos_1 * (-1); 
   
   Por tanto, el recorrido de los t�rminos de la serie quedar�a as�:
      
   suma=0;

   for (i = 1 ; i <= n ; i++){
      potencia_de_menos_1 = 1;
   
      for (int recorre = 1; recorre <= i; recorre++)
         potencia_de_menos_1 = potencia_de_menos_1 * (-1);
   
      termino = (i*i-1)/(2.0*i);
      suma = suma + potencia_de_menos_1*termino;
   }
   
   Pero SIEMPRE nos debemos preguntar si en cada iteraci�n de un bucle,
   podemos aprovechar los c�lculos realizados en la iteraci�n anterior.
   En este caso es as�. Si en la iteraci�n i-1 he calculado la potencia
   de -1 elevado a i-1, y lo he almacenado en una variable potencia_de_menos_1, 
   entonces, para calcular la potencia de -1 elevado a i, basta multiplicar
   (en la siguiente iteraci�n) potencia_de_menos_1 por -1, o lo que es lo mismo, cambiarlo 
   de signo.
   De esa forma sustituimos todo el bucle for j por una �nica l�nea:
      potencia_de_menos_1 = -potencia_de_menos_1;
*/


int main(){     
   int i, tope, potencia_de_menos_1;
   double suma_serie, termino;   
   
   cout << "\nIntroduzca el l�mite de la serie ";
   cin >> tope;

   suma_serie = 0;
   potencia_de_menos_1 = 1;

   for (i = 1 ; i <= tope ; i++){     
      potencia_de_menos_1 = - potencia_de_menos_1;
      termino = potencia_de_menos_1 * (i * i - 1) / (2.0 * i);
      suma_serie = suma_serie + termino;
   }
   
   cout << "\nSuma de la serie = " << suma_serie;      
   cout << "\n";
   system("pause");
}
