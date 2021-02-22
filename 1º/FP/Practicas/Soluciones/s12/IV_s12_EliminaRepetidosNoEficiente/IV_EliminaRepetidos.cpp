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
   Eliminar los elementos repetidos de un vector de caracteres
*/

/*
Sobre la clase SecuenciaCaracteres, añadir un método EliminaRepetidos que
quite los elementos repetidos, de forma que cada componente sólo aparezca una
única vez. Por ejemplo, si el vector contiene
   {'b','a','a','h','a','a','a','a','c','a','a','a','g'}
después de quitar los repetidos, se quedaría como sigue:
   {'b','a','h','c','g'}
Implementad los siguientes algoritmos para resolver este problema:

a) Usar un vector local sin_repetidos en el que almacenamos una única aparición de cada componente:

   Recorrer todas las componentes del vector original
      Si la componente NO está en el vector sin_repetidos, añadirla (al vector sin_repetidos)
      Asignar las componentes de sin_repetidos al vector original

b) El problema del algoritmo anterior es que usa un vector local, lo que podría suponer una 
carga importante de memoria si trabajásemos con vectores grandes.
Por lo tanto, vamos a resolver el problema sin usar vectores locales.
Si una componente está repetida, se borrará del vector. Para borrar una componente, 
podríamos desplazar una posición a la izquierda, todas las componentes
que estén a su derecha. El algoritmo quedaría:

   Recorrer todas las componentes del vector original
      Si la componente se encuentra en alguna posición anterior, 
      la eliminamos desplazando hacia la izquierda 
         todas las componentes que hay a su derecha.
*/

#include <iostream>
using namespace std;

class  SecuenciaCaracteres{
private:
   static  const  int  TAMANIO  =  50;
   char vector_privado[TAMANIO];
   int  total_utilizados;
public:
   SecuenciaCaracteres()
      :total_utilizados(0)        
   {    
   }

   int  TotalUtilizados(){
      return  total_utilizados;
   }

   void  Aniade(char  nuevo){
      if (total_utilizados  <  TAMANIO){
         vector_privado[total_utilizados]  =  nuevo;
         total_utilizados++;
      }
   }

   void AniadeCadena(string nuevo){
      int tope = nuevo.size();

      for (int i = 0; i < tope; i++)
         Aniade(nuevo[i]);
   }

   char Elemento(int  indice){
      return  vector_privado[indice];
   }

   void Modifica(int indice_componente, char nuevo){
      if (indice_componente >= 0  &&  indice_componente < total_utilizados)
         vector_privado[indice_componente] = nuevo;
   }   
   
   string ToString(){
      string cadena;

      for (int i=0; i < total_utilizados; i++)
         cadena = cadena + vector_privado[i];

      return cadena;
   }

   // Elimina una componente, dada por su posición
   void Elimina(int posicion){
      if (posicion >= 0 && posicion < total_utilizados){
         int tope = total_utilizados-1;

         for (int i=posicion ; i<tope ; i++)
            vector_privado[i] = vector_privado[i+1];

         total_utilizados--;    
      }
   }

   int PrimeraOcurrenciaEntre(int pos_izda, int pos_dcha, char buscado){
      int i = pos_izda; 
      bool encontrado = false;

      while (i <= pos_dcha  &&  !encontrado)
         if (vector_privado[i] == buscado)
            encontrado = true;
         else
            i++;

      if (encontrado)
         return i;
      else
         return -1;
   }

   int PrimeraOcurrencia (char buscado){
      return PrimeraOcurrenciaEntre(0, total_utilizados - 1, buscado);
   }

   void EliminaRepetidos_con_VectorLocal(){
      /*
      Algoritmo:
      
      Recorrer todas las componentes del vector original
         Si la componente NO está en el vector sin_repetidos,
         añadirla (al vector sin_repetidos)

      Asignar las componentes de sin_repetidos al vector original
      */
      
      /*
      IMPORTANTE: 
         El vector sin_repetidos lo declaramos local, dentro del método EliminaRepetidos
         No lo declaramos como dato miembro ya que no va a ser utilizado por ningún otro método.
      */
      
      char sin_repetidos[TAMANIO];     
      bool encontrado_en_repetidos;
      int utilizados_en_repetidos;

      if (total_utilizados > 0){
         sin_repetidos[0] = vector_privado[0];
         utilizados_en_repetidos = 1;

         for (int actual = 1; actual < total_utilizados; actual++){
            encontrado_en_repetidos = false;

            for (int j = 0; j < utilizados_en_repetidos 
                            && !encontrado_en_repetidos; j++){
                               
               if (vector_privado[actual] == sin_repetidos[j])
                  encontrado_en_repetidos = true;
            }

            if (!encontrado_en_repetidos){
               sin_repetidos[utilizados_en_repetidos] = vector_privado[actual];
               utilizados_en_repetidos++;
            }
         }

         for (int i=0; i<utilizados_en_repetidos; i++)
            vector_privado[i] = sin_repetidos[i];

         total_utilizados = utilizados_en_repetidos;
      }
   }

   void EliminaRepetidosIneficiente(){
      /*
       Algoritmo:
       
       Recorrer todas las componentes del vector original
          Si la componente es igual a alguna de las componentes que
          hay a su izquierda, eliminarla
      */ 
      int actual = 1, pos_encontrado;

      while (actual < total_utilizados){
         pos_encontrado =
            PrimeraOcurrenciaEntre (0, actual-1, vector_privado[actual]);

         if (pos_encontrado != -1)
            Elimina(actual);
         else                           
            actual++;
      }
      
      /*
      Importante: actual++ debe ir dentro de else. En caso contrario, no funcionaría
      correctamente si hubiese dos repetidos consecutivos que hubiese que eliminar
      Es lo mismo que ocurría en el problema de ELiminar Mayúsculas.
      
      Este algoritmo es muy ineficiente ya que por cada valor que esté repetido
      hay que desplazar una a una todas las componentes que hay a su derecha.      
      La versión eficiente de EliminaRepetidos se ve posteriormente.
      */
   }
};

int main(){
   SecuenciaCaracteres frase;
   int tope;

   frase.Aniade('H');
   frase.Aniade('H');
   frase.Aniade('o');
   frase.Aniade('l');
   frase.Aniade('a');
   frase.Aniade('a');
   frase.Aniade('a');
   frase.Aniade('H');
   
   tope = frase.TotalUtilizados();

   for (int i = 0; i < tope; i++)
      cout  << frase.Elemento(i) << " ";

   frase.EliminaRepetidosIneficiente();
   
   
   // Mostramos resultados:
   
   // Hay que recalcular tope ya que 
   // el número de componentes utilizadas ha cambiado
   
   tope = frase.TotalUtilizados();          
   
   cout << "\n";
   
   cout  << frase.ToString() << " ";

   cout << "\n\n";
}

