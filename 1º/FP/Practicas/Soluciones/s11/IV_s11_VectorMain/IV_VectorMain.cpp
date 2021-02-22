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
Declare un vector de caracteres de tamaño 100. Lea las componentes consideran-
do como terminador el carácter # (éste no forma parte de la secuencia) y que no se
introduzcan más de 100 caracteres. Las componentes leídas ocuparán las primeras
posiciones contiguas del vector. El resto de las posiciones se quedarán con el valor
indeterminado (basura) que el compilador le asignase al principio. Para conocer cuán-
tas componentes se están utilizando, utilice una variable total_utilizados (que,
obviamente, deberá ser menor de 100 en todo momento)

Implemente algoritmos para realizar las siguientes tareas:

a) Comprobar si el vector es un palíndromo, es decir, que se lee igual de izquierda a
derecha que de derecha a izquierda. Por ejemplo, {'a','b','b','a'} sería
un palíndromo, pero {'a','c','b','a'} no lo sería. Si la secuencia tiene un
número impar de componentes, la que ocupa la posición central es descartada,
por lo que {'a','b','j','b','a'} sería un palíndromo.

b) Invertir el vector. Si éste contenía, por ejemplo, los caracteres
{'m','u','n','d','o'} , después de llamar al método se quedará con
{'o','d','n','u','m'} .

c) Contar el número de mayúsculas que contiene.
*/

#include <cctype>
#include <iostream>
using namespace std;


int main(){
   const int  TAMANIO    =  100;
   const char TERMINADOR = '#';
   char vector[TAMANIO];
   char caracter;
   int  total_introducidos;
   int  numero_mayusculas;
   
   bool es_palindromo;
   int  izda, dcha;

   //////////////////////////////////////////////////////////////////
   // Lectura de los datos:
   
   total_introducidos = 0;
   caracter = cin.get();
   
   while (caracter != TERMINADOR && total_introducidos < TAMANIO){
      vector[total_introducidos] = caracter;
      total_introducidos++;
      caracter = cin.get();
   }

   
   //////////////////////////////////////////////////////////////////
   // Número de mayúsculas:
   
   numero_mayusculas = 0;
   
   for (int i = 0; i < total_introducidos; i++)
      if (isupper(vector[i]))
         numero_mayusculas++;  
         
   cout << "\n\nHay un total de " << numero_mayusculas << " mayúsculas";
            
   
   //////////////////////////////////////////////////////////////////
   // Palíndromo:

   es_palindromo = true;
   izda = 0;
   dcha = total_introducidos - 1;

   while (izda < dcha && es_palindromo){
      if (vector[izda] != vector[dcha])
         es_palindromo = false;
      else{
         izda++;
         dcha--;
      }
   }

	/*
   El siguiente bucle no funciona correctamente:
     
	for (int i = 0; i < total_introducidos; i++){
		es_palindromo = 
         vector_privado[i] == vector_privado[total_introducidos- 1 - i];


   1. No hay que llegar hasta total_utilizados sino hasta total_introducidos/2
   2. Al no salirse del bucle cuando ha encontrado dos componentes distintas,
      al final la variable es_palindromo se queda con el resultado de comparar
      las dos últimas posiciones centrales
   
   Lo siguiente sí sería correcto:
   
   tope = total_introducidos / 2;
   
   for (int i = 0; i < tope && es_palindromo; i++){
		 es_palindromo = 
         vector_privado[i] == vector_privado[total_introducidos - 1 - i];
   */
   
   if (es_palindromo)
      cout << "\nEs un palíndromo";
   else
      cout <<"\nNo es un palíndromo";
  
   
   //////////////////////////////////////////////////////////////////
   // Invierte:
   
   char copia;
   
	izda = 0;
	dcha = total_introducidos - 1;

	while (izda < dcha){
		copia = vector[izda];
      vector[izda]  = vector[dcha];
      vector[dcha]  = copia;
		izda++;
		dcha--;
	}
	
	/*
	// ¿Qué haría el siguiente código?
	
	int su_simetrico;
	
   for (int i=0; i < total_utilizados; i++){
      su_simetrico = total_utilizados - i - 1;
      copia = vector[i];
      vector[i]  = vector[su_simetrico]; 
      vector[su_simetrico]  = copia;   
   }	
   
   // Dejaría la cadena igual que estaba!!  
	*/
	
   cout << "\nComponentes del vector después de invertirlo: < ";
   
   for (int i = 0; i < total_introducidos; i++)
      cout  << vector[i] << " ";
   
   cout << ">\n";      
}

