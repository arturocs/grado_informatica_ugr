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
Construya la función con cabecera:
   string Digitos (int n)
para que extraiga en un string los dígitos del número n tal y como se indica en el
ejercicio 27 de la relación de problemas II.
*/


#include <iostream>
#include <cmath>
using namespace std;

string ExtraeDigitos(int numero){
   int numero_positivo, num_digitos, potencia, digito;
   int i;
   bool es_negativo;  
   
   /*
   Idea:

      n = 375
      potencia = 100
      /potencia -> Imprime 3
      %potencia -> 75
      
      n = 75
      potencia = 10
      /potencia -> Imprime 7
      %potencia -> 5
      
      n = 5 
      potencia = 1
      /potencia  -> Imprime 5
      %potencia  -> 0
   */
   
   /*
   Algoritmo (Pintar dígitos de un entero):
      
      Contar el número de dígitos del número -> num_dig      
      Inicializar potencia a 10^(num_dig - 1) 
      
      Repetir lo siguiente tantas veces como cifras haya:         
         Imprimir la primera difra de n -> n / potencia 
         Remplazar n por n % potencia
         potencia = 10 ^ (i-1)      
   */
   
   /*
   En cada iteración tenemos que dividir por 10^k
   ¿Cómo calculamos 10^k?
         
      ¿Hacemos lo siguiente EN CADA iteración?
         potencia = pow(10,k);
         k--;
      El uso de pow es costoso y podemos evitarlo.

      En vez de calcular la potencia, nos preguntamos si podemos aprovechar
      los cómputos que hemos realizados en una iteración, para la siguiente.

      Efectivamente:
         Dado un valor de potencia (10000 por ejemplo) basta hacer lo siguiente:
             potencia = potencia / 10;     (de 10000 pasamos a 1000, de 1000 a 100 ...)
   
   Por último, antes de entrar al bucle, debemos inicializar potencia a 10^(num_dig - 1)
      Podemos hacerlo con
        potencia = pow(10,num_digitos-1);
      Pero siguiendo el mismo consejo de antes, también podríamos hacerlo en el mismo bucle
      que hemos usado para realizar el cómputo del número de dígitos.
   */
   
   es_negativo = numero < 0;   
   numero_positivo = abs(numero);      
   num_digitos = 1;
   potencia = 1;    
   string cadena;  
   
   while (numero_positivo > 9){
      numero_positivo = numero_positivo / 10;
      num_digitos++;
      potencia = potencia * 10;
   }

   numero_positivo = abs(numero);  
   
   if (es_negativo)           
     cadena = "- ";
      
   for (i = 1; i <= num_digitos; i++){
      digito = numero_positivo / potencia;
      cadena = cadena + to_string(digito) + " "; 
      numero_positivo = numero_positivo % potencia;
      potencia = potencia / 10;
   }
   
   return cadena;
   
}

int main()
{
   int numero;
   
   cout << "Introduce un entero cualquiera: ";
   cin >> numero;

   cout << "\n\nDígitos separados por blanco: ";
   cout << ExtraeDigitos(numero);  
         
   cout << "\n\n";
   system ("pause");
}
