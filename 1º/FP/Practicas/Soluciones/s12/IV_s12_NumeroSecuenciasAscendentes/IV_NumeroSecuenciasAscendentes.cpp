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
Defina la clase SecuenciaEnteros análoga a SecuenciaCaracteres. 
Defina lo que sea necesario para calcular el número de secuencias 
ascendentes del vector.  Por ejemplo, el vector 
   {2,4,1,1,7,2,1}
tiene 4 secuencias que son 
   {2,4}, {1,1,7}, {2}, {1}.
*/

#include <iostream>
using namespace std;

class SecuenciaEnteros{
private:
   static const int TAMANIO = 50;
   int vector_privado[TAMANIO];
   int total_utilizados;
public:
   SecuenciaEnteros()
      :total_utilizados(0)        
   {    
   }

   int TotalUtilizados(){
      return  total_utilizados;
   }

   void Aniade(int  nuevo){
      if (total_utilizados  <  TAMANIO){
         vector_privado[total_utilizados]  =  nuevo;
         total_utilizados++;
      }
   }

   int Elemento(int  indice){
      return  vector_privado[indice];
   }

   void Modifica(int indice_componente, int nuevo){
      if (indice_componente >= 0  &&  indice_componente < total_utilizados)
         vector_privado[indice_componente] = nuevo;
   }   
   
   /*
    Lo importante del ejercicio NumeroSecuencias es que debemos comparar dos elementos:
    el actual y el siguiente (o el anterior)
    Debemos tener mucho cuidado en el recorrido y no hacer cosas del tipo siguiente:
      for (i=0; i<tope; i++)
         Comprobar lo que sea con vector[i] y vector[i+1]
    En el for garantizamos que el acceso a i es correcto, PERO NO A i+1!!!
   */

   int NumeroSecuencias_vs1(){
      /*
      Idea:
         Contamos que hay una secuencia cuando la estamos recorriendo y llegamos
         al final (porque hay un elemento menor o porque hemos llegado al final del vector)
         
      Algoritmo:
         Número de secuencias: -numero_secuencias-
         
         Recorrer cada componente -actual- del vector desde la primera
            Si no hemos llegado al final y la siguiente es menor
               incrementar numero_secuencias 
            Si hemos llegado al final, hay que incrementar también
               numero_secuencias
      */
      int numero_secuencias;
      int siguiente;
      int actual;
      bool hay_componentes;
      int tope;

      numero_secuencias = 0;
      tope = total_utilizados;
      siguiente = 0;
      hay_componentes = (tope != 0);

      while (hay_componentes){
         actual = vector_privado[siguiente];
         siguiente++;
         hay_componentes = (siguiente < tope);

         if (hay_componentes){
            if (vector_privado[siguiente] < actual)
               numero_secuencias++;
         }
         else
            numero_secuencias++;     // Hay que contar la última
      }

      return numero_secuencias;
   }

   int NumeroSecuencias_vs2(){
      /*
      Idea:
         Contamos que hay una secuencia cuando la empezamos.
    
      Con este cambio de enfoque nos queda una versión bastante más compacta.
      En cualquier caso, ambas versiones son correctas.
      
      Algoritmo:
         Número de secuencias: -numero_secuencias-
         
         Si el vector no está vacío, ya hay una secuencia (al menos)
         
         Recorrer cada componente -actual- del vector DESDE LA SEGUNDA            
            Si la componente actual es menor que la ANTERIOR,
            incrementar numero_secuencias
      */
      int numero_secuencias;

      numero_secuencias = 0;

      if (total_utilizados > 0){
         numero_secuencias = 1;

         for (int actual = 1; actual < total_utilizados; actual++){
            if (vector_privado[actual-1] > vector_privado[actual])   // Si actual>=1 => actual-1>=0 :-)
               numero_secuencias++;
         }
      }

      // Nota: Si el vector tiene una única componente, el algoritmo
      //      no entra dentro del bucle for => numero_secuencias = 1.

      return numero_secuencias;
   }
};


int main(){
   SecuenciaEnteros valores;

   // Casos de prueba:
   // El vector vacío

   //// Un sólo valor:
   // valores.Aniade(2);

   //// Una única secuencia:
   valores.Aniade(4);
   valores.Aniade(4);
   valores.Aniade(4);

   // Varios valores:
   //valores.Aniade(2);
   //valores.Aniade(4);
   //valores.Aniade(1);
   //valores.Aniade(1);
   //valores.Aniade(7);
   //valores.Aniade(2);
   //valores.Aniade(1);

   cout << valores.NumeroSecuencias_vs2();
   cout << "\n\n";
}


