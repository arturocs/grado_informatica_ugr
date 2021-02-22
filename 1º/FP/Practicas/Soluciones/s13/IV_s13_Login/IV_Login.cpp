////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

// Login automático

/*
Se está diseñando un sistema web que recolecta datos
personales de un usuario y, en un momento dado, debe sugerirle un nombre de
usuario (login). Dicho login estará basado en el nombre y los apellidos; en 
concreto estará formado por los N primeros caracteres de cada nombre y apellido
(en minúsculas, unidos y sin espacios en blanco). Por ejemplo, si el nombre es

   "Antonio Francisco Molina Ortega" 
y 
   N=2, 
   
el nombre de usuario sugerido será 

   "anfrmoor".
   
Debe tener en cuenta que el número de palabras que forman el nombre y los apellidos
puede ser cualquiera. Además, si N es mayor que alguna de las palabras que
aparecen en el nombre, se incluirá la palabra completa. Por ejemplo, si el nombre
es "Ana CAMPOS de la Blanca" y N=4, entonces la sugerencia será
"anacampdelablan" (observe que se pueden utilizar varios espacios en blanco
para separar palabras).
Implemente la clase Login que tendrá como único dato miembro el tamaño N. Hay
que definir el método Codifica que recibirá una cadena de caracteres (tipo string)
formada por el nombre y apellidos (separados por uno o más espacios en blanco) y
devuelva otra cadena con la sugerencia de login.
*/

#include <iostream>
#include <string>
using namespace std;


class Login{
private:
   int num_caracteres_a_coger;
public:
   Login (int numero_caracteres_a_coger)
      :num_caracteres_a_coger(numero_caracteres_a_coger)
   {
   }
   string Codifica(string nombre_completo){
      /*
         Primera versión.
            Este algoritmo está diseñado para ir
            recorriendo el vector con varios bucles secuenciales
            que van comprobando las condiciones que se exigen.

          !
         "   Halo  Adi   "  Saltar al primer carácter distinto de blanco

             !
         "   Halo  Adi   "  Concatena los n primeros (3 en este caso)

               !
         "   Halo  Adi   "  Avanza hasta el final de la palabra (blanco o final de la cadena)

                 !
         "   Halo  Adi   "  
         
         Cada una de las tres partes anteriores se implementarán con bucles.
         Dentro de CADA UNO de los tres bucles habrá que controlar que
         al ir avanzando no nos salgamos del final del vector.
         
         Recorrer con un índice actual la cadena
            Saltar todos los espacios en blanco a partir de actual
            Añadir al login las n primeras letras de la palabra actual
               (sin salirnos de la cadena y hasta que lleguemos a un blanco)
            Saltar al final de la palabra actual y colocar ahí el índice actual
      */
      
      /*
      int actual;
      int cogidos;
      int utilizados = nombre_completo.size();
      string login;
      actual = 0;

      while (actual < utilizados){
         while (actual < utilizados && nombre_completo[actual] == ' ')
            actual++;

         cogidos = 0;

         while (actual < utilizados
                && cogidos < num_caracteres_a_coger
                && nombre_completo[actual] != ' '){

            login.push_back(tolower(nombre_completo[actual]));
            actual++;
            cogidos++;
         }

         while (actual < utilizados && nombre_completo[actual] != ' ')
            actual++;
      }
      */


      /*
         Segunda versión.
            Este algoritmo está diseñado centrándose en la componente
            actual que en cada momento se está procesando.

            Usamos un contador de número de letras almacenadas
            en cada momento en el login (aniadidos)

            Recorrer con un índice i la cadena
               Si la componente i es un blanco, reseteamos aniadidos
               En otro caso, añadimos la letra actual, siempre
                  y cuando no se hayan añadido ya n letras
      */


      int utilizados = nombre_completo.size();
      string login;
      int aniadidos = 0;

      for(int actual = 0; actual < utilizados; actual++){
         if (nombre_completo[actual] == ' ')
            aniadidos = 0;
         else if (aniadidos < num_caracteres_a_coger){
            login.push_back(tolower(nombre_completo[actual]));
            aniadidos++;
         }
      }

      return login;
   }
};



int main(){
   const char TERMINADOR = '#';
   char caracter;
   Login login_automatico(3);
   string a_codificar, codificada;
   
   cout << "\nIntroduzca la secuencia de caracteres a codificar. ";
   cout << TERMINADOR << " para terminar.";
   
   caracter = cin.get();
   
   while (caracter != TERMINADOR){
      a_codificar.push_back(caracter);
      caracter = cin.get();
   }
   
   codificada = login_automatico.Codifica(a_codificar);
   
   cout << "\n\nCadena codificada: " << codificada;

   cout << "\n\n";
   
   // abcd    ef  ghij  k ppp#
}
