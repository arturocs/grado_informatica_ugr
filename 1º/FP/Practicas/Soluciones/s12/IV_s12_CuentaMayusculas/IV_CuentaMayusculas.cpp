////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

// Cuenta mayúsculas

/*
Realizar un programa que vaya leyendo caracteres hasta que se encuentre un punto '.'. 
Queremos contar el número de veces que aparece cada una de las letras mayúsculas.
Una posibilidad sería leer el carácter, y después de comprobar si es una mayúscula,
ejecutar un conjunto de sentencias del tipo:

   if (letra == 'A')
      contador_mayusculas[0] = contador_mayusculas[0] + 1;
   else if (letra == 'B')
      contador_mayusculas[1] = contador_mayusculas[1] + 1;
   else if (letra == 'C')
      contador_mayusculas[2] = contador_mayusculas[2] + 1;
   else ....

Sin embargo, este código es muy redundante. Proponed una solución e implementarla.
Para resolver este ejercicio puede usarse o bien un vector clásico -array- de enteros,
o bien un objeto de la clase SecuenciaEnteros. La idea es que todos los if-else
anteriores los podamos resumir en una única sentencia del tipo:

   contador_mayusculas[indice] = contador_mayusculas[indice]+1;

si empleamos un vector clásico -array- o bien

   contador_mayusculas.Modifica(indice, contador_mayusculas.Elemento(indice)+1);

si empleamos un objeto de la clase SecuenciaEnteros.
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;
/*
   Vamos a ver tres versiones:
   1. Todo en el main con un vector clásico
   2. Todo en el main con un objeto de la clase SecuenciaEnteros
   3. Definiendo una clase específica que lleve el contador de mayúsculas
*/

////////////////////////////////////////////////////////////////////////////////////
/*
int main(){
   const int numero_mayusculas = 'Z' -'A' + 1;
   const char TERMINADOR = '.';
   int conteo_mayusculas[numero_mayusculas] = {0};  // Todas se inicializan a cero
   char letra;

   cin >> letra;

   while (letra != TERMINADOR){
      if (isupper(letra)){
         int indice_letra = letra - 'A';
         conteo_mayusculas[indice_letra] = conteo_mayusculas[indice_letra]  + 1;
      }

      cin >> letra;
   }

   cout << "\n\n";
   cout << "Número de apariciones de cada letra:\n\n";

   for (char mayuscula = 'A'; mayuscula <= 'Z' ; mayuscula++){
      int indice_letra = mayuscula - 'A';
      int conteo = conteo_mayusculas[indice_letra];
      
      cout << mayuscula << " --> " << conteo << "\n" ;
   }

   cout << "\n";
   system ("pause");
}
*/

////////////////////////////////////////////////////////////////////////////////////

// Versión con una SecuenciaEnteros en vez de un vector clásico

/*
class  SecuenciaEnteros{
private:
   static  const  int  TAMANIO  =  50;
   int  vector_privado[TAMANIO];
   int  total_utilizados;
public:
   SecuenciaEnteros()
      :total_utilizados(0)        
   {    
   }
   int  TotalUtilizados(){
      return  total_utilizados;
   }
   void  Aniade(int  nuevo){
      if (total_utilizados  <  TAMANIO){
         vector_privado[total_utilizados]  =  nuevo;
         total_utilizados++;
      }
   }
   int  Elemento(int  indice){
      return  vector_privado[indice];
   }

   void Modifica (int indice_componente, int nuevo){
      if (indice_componente >= 0  &&  indice_componente < total_utilizados)
         vector_privado[indice_componente] = nuevo;
   }
};

int main(){
   SecuenciaEnteros conteo_mayusculas;   
   char letra;
   const int numero_mayusculas = 'Z' -'A' + 1;
   const char TERMINADOR = '.';

   for (int i=0; i<numero_mayusculas; i++)
      conteo_mayusculas.Aniade(0);

   cin >> letra;

   while (letra != TERMINADOR){
      if (isupper(letra)){
         int indice_letra = letra - 'A';
         int cuantos_habia =  conteo_mayusculas.Elemento(indice_letra);
         conteo_mayusculas.Modifica(indice_letra, cuantos_habia + 1);
      }

      cin >> letra;
   }

   cout << "\n\n";
   cout << "Número de apariciones de cada letra:\n\n";

   for (char mayuscula = 'A'; mayuscula <= 'Z' ; mayuscula++){
      int indice_letra = mayuscula - 'A';
      int conteo = conteo_mayusculas.Elemento(indice_letra);
      
      cout << mayuscula << " --> " << conteo << "\n" ;
   }
}
*/

/*
   En la siguiente versión se utiliza una clase específica ContadorMayusculas.

   Un objeto de la clase ContadosMayusculas realizará la tarea de gestionar
   el conteo de las mayúsculas introducidas. No almacenará los caracteres
   introducidos, ni siquiera las mayúsculas introducidas, sino únicamente
   almacenará los conteos de éstas.

   El programa principal queda mucho más "limpio" y sencillo de entender.
*/
class  ContadorMayusculas{
private:
   static  const  int  NUMERO_MAYUSCULAS = 'Z' -'A' + 1;
   int  conteo[NUMERO_MAYUSCULAS];

   int IndiceLetra(char letra){
      return letra - 'A';
   }

public:
   ContadorMayusculas()
   {    
      for (int i=0; i<NUMERO_MAYUSCULAS; i++)
         conteo[i] = 0;
   }

   int  NumeroMayusculas(){
      return  NUMERO_MAYUSCULAS;
   }

   void IncrementaConteo(char mayuscula){
      int indice_mayuscula;

      if (isupper(mayuscula)){
         indice_mayuscula = IndiceLetra(mayuscula);
         conteo[indice_mayuscula] = conteo[indice_mayuscula] + 1; 
      }
   }

   int CuantasHay(char mayuscula){
      return  conteo[IndiceLetra(mayuscula)];
   }   
};


int main(){
   const char TERMINADOR = '.';
   char letra;   
   ContadorMayusculas conteo_mayusculas; 

   cin >> letra;

   while (letra != TERMINADOR){
      conteo_mayusculas.IncrementaConteo(letra);   
      cin >> letra;
   }

   cout << "\n\n";
   cout << "Número de apariciones de cada letra:\n\n";
   
   for (char mayuscula = 'A'; mayuscula <= 'Z'; mayuscula++)
      cout  << mayuscula << " --> " 
            << conteo_mayusculas.CuantasHay(mayuscula) << "\n";

   cout << "\n";
}

  
