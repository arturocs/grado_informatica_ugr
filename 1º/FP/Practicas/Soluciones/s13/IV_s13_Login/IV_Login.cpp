////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

// Login autom�tico

/*
Se est� dise�ando un sistema web que recolecta datos
personales de un usuario y, en un momento dado, debe sugerirle un nombre de
usuario (login). Dicho login estar� basado en el nombre y los apellidos; en 
concreto estar� formado por los N primeros caracteres de cada nombre y apellido
(en min�sculas, unidos y sin espacios en blanco). Por ejemplo, si el nombre es

   "Antonio Francisco Molina Ortega" 
y 
   N=2, 
   
el nombre de usuario sugerido ser� 

   "anfrmoor".
   
Debe tener en cuenta que el n�mero de palabras que forman el nombre y los apellidos
puede ser cualquiera. Adem�s, si N es mayor que alguna de las palabras que
aparecen en el nombre, se incluir� la palabra completa. Por ejemplo, si el nombre
es "Ana CAMPOS de la Blanca" y N=4, entonces la sugerencia ser�
"anacampdelablan" (observe que se pueden utilizar varios espacios en blanco
para separar palabras).
Implemente la clase Login que tendr� como �nico dato miembro el tama�o N. Hay
que definir el m�todo Codifica que recibir� una cadena de caracteres (tipo string)
formada por el nombre y apellidos (separados por uno o m�s espacios en blanco) y
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
         Primera versi�n.
            Este algoritmo est� dise�ado para ir
            recorriendo el vector con varios bucles secuenciales
            que van comprobando las condiciones que se exigen.

          !
         "   Halo  Adi   "  Saltar al primer car�cter distinto de blanco

             !
         "   Halo  Adi   "  Concatena los n primeros (3 en este caso)

               !
         "   Halo  Adi   "  Avanza hasta el final de la palabra (blanco o final de la cadena)

                 !
         "   Halo  Adi   "  
         
         Cada una de las tres partes anteriores se implementar�n con bucles.
         Dentro de CADA UNO de los tres bucles habr� que controlar que
         al ir avanzando no nos salgamos del final del vector.
         
         Recorrer con un �ndice actual la cadena
            Saltar todos los espacios en blanco a partir de actual
            A�adir al login las n primeras letras de la palabra actual
               (sin salirnos de la cadena y hasta que lleguemos a un blanco)
            Saltar al final de la palabra actual y colocar ah� el �ndice actual
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
         Segunda versi�n.
            Este algoritmo est� dise�ado centr�ndose en la componente
            actual que en cada momento se est� procesando.

            Usamos un contador de n�mero de letras almacenadas
            en cada momento en el login (aniadidos)

            Recorrer con un �ndice i la cadena
               Si la componente i es un blanco, reseteamos aniadidos
               En otro caso, a�adimos la letra actual, siempre
                  y cuando no se hayan a�adido ya n letras
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
