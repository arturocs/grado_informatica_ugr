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
A�adid el m�todo EliminaMayusculas para eliminar todas las may�sculas.
Por ejemplo, despu�s de aplicar dicho m�todo al vector
   {'S','o','Y',' ','y','O'}, 
�ste debe quedarse con 
   {'o',' ','y'}.
Un primer algoritmo para resolver este problema ser�a el siguiente (en ejercicios posteriores
se ver�n m�todos m�s eficientes):

   Recorrer todas las componentes de la secuencia
      Si la componente es una may�scula, borrarla

Queremos implementarlo llamando al m�todo Elimina que se ha definido en el ejercicio
4 de esta relaci�n de problemas:

class SecuenciaCaracteres{
.........
   void EliminaMayusculas(){
      for (int i=0; i<total_utilizados; i++)
         if (isupper(vector_privado[i]))
            Elimina(i);
   }
};

El anterior c�digo tiene un fallo. �Cu�l? Probarlo con cualquier secuencia que tenga
dos may�sculas consecutivas, proponer una soluci�n e implementarla
*/

#include <iostream>
#include <chrono>
#include <cctype>
using namespace std;

class Cronometro{
private:
   typedef std::chrono::time_point<std::chrono::steady_clock> Punto_en_el_Tiempo;
   typedef chrono::duration <double, nano>  IntervaloTiempo;

   Punto_en_el_Tiempo inicio;
   Punto_en_el_Tiempo final;   // Podr�a haberse puesto como dato local a MiliSegundosTranscurridos
public:
   void Reset(){
      inicio = chrono::steady_clock::now();
   }
   double MiliSegundosTranscurridos(){
      final = chrono::steady_clock::now();
      IntervaloTiempo diferencia = final - inicio;

      return diferencia.count() / 1e+6;  // count() devuelve nanosegundos
   }
};


class  SecuenciaCaracteres{
private:
   /*
   Para poder trabajar con vectores grandes en la pila,
   hay que se�alar la siguiente opci�n, dentro 
   Herramientas -> Opciones del Compilador
      A�adir los siguientes comandos al llamar al compilador
   y en la caja de texto introduzca lo siguiente:
      -Wl,--stack,2600000
   */
   static const int TAMANIO  =  22e+5;  // casting de double a int
   char vector_privado[TAMANIO];
   int total_utilizados;

   void IntercambiaComponentesDirectamente (int izda, int dcha){
      char intermedia;

      intermedia = vector_privado[izda];
      vector_privado[izda] = vector_privado[dcha];
      vector_privado[dcha] = intermedia;
   }
public:
   SecuenciaCaracteres()
      :total_utilizados(0)        // O bien en la misma declaraci�n del dato miembro:  int  total_utilizados = 0;
   {
   }

   int TotalUtilizados(){
      return  total_utilizados;
   }

   int Capacidad(){
      return TAMANIO;
   }

   void  Aniade(char  nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados]  =  nuevo;
         total_utilizados++;
      }
   }

   char  Elemento(int  indice){
      return  vector_privado[indice];
   }

   void EliminaTodos(){
      total_utilizados = 0;
   }

   void Modifica (int indice_componente, char nuevo){
      if (indice_componente >= 0  &&  indice_componente < total_utilizados)
         vector_privado[indice_componente] = nuevo;
   }

   string ToString(){
      string cadena;

      for (int i=0; i < total_utilizados; i++)
         cadena = cadena + vector_privado[i];

      return cadena;
   }

   int NumeroMayusculas(){
      int numero_mayusculas = 0;

      for (int i = 0; i < total_utilizados; i++){
         if (isupper(vector_privado[i]))
            numero_mayusculas++;
      }

      return numero_mayusculas;
   }

   // A�ade todos los caracteres de un string
   void AniadeCadena(string nuevo){
      int tope = nuevo.size();

      for (int i = 0; i < tope; i++)
         Aniade(nuevo[i]);
   }


   // Elimina una componente, dada por su posici�n
   void Elimina (int posicion){
      /*
      Algoritmo:

         Recorremos de izquierda a derecha toda las componentes
         que hay a la derecha de la posici�n a eliminar
            Le asignamos a cada componente la que hay a su derecha
      */
      if (posicion >= 0 && posicion < total_utilizados){
         int tope = total_utilizados-1;

         for (int i = posicion ; i < tope ; i++)         // i < tope ya que la �ltima asignaci�n  ultimo <- ? no es necesaria
            vector_privado[i] = vector_privado[i+1];

         total_utilizados--;
      }
   }

   void EliminaMayusculasIneficiente(){
      /*
      Algoritmo:
         Recorrer todas las componentes que hay en el vector
            Si la componente actual es may�scula
               Elimirla (llamar al m�todo Elimina)
            en otro caso
               Pasar a la siguiente componente
      */
      // La siguiente implementaci�n de este algoritmo es incorrecta porque 
      // cuando ha borrado una may�scula, no debe avanzar i. 
      // Al estar dentro de un for, siempre se ejecuta i++, 
      // por lo que si hay dos may�sculas contiguas, 
      // no borra la segunda.
      /*
         void EliminaMayusculas(){
            for (int i=0; i<total_utilizados; i++)
               if (isupper(vector_privado[i]))
                  Elimina(i);
         }
      */
      // Soluci�n: �Decrementamos i dentro del bucle?
      /*
         for (int i=0; i<total_utilizados; i++){
            if (isupper(vector_privado[i])){
               Elimina(i);
               i--;         // :-(
            }
        }
      */
      // NO. Jam�s modificaremos la variable contadora de un for dentro del bucle.
      // Usamos un bucle while, incrementado i dentro de un else:

      int i;
      i = 0;

      while (i < total_utilizados){
         if (isupper(vector_privado[i]))
            Elimina(i);
         else
            i++;
      }
      
      /*
      
      Observad la forma de trabajar del algoritmo:
      Si el valor de i pasa la condici�n del while (est� en el rango correcto)
      procede a trabajar con dicha componente 
      (avanzando en el caso de que no la elimine 
      o elimin�ndola sin avanzar)
      y vuelve a subir para comprobar si el i (avanzado previamente o no)
      est� en el rango correcto.
      
      Podr�amos haber optado por otro planteamiento:
         
         Mientras i sea correcto
            Mientras v[i] sea may�scula
               Eliminarla
      
         while (i < total_utilizados){
            while (isupper(vector_privado[i]))
               Elimina(i);
            
            i++;
         }
      
      Pero se presenta un problema.
      En el segundo while no controlamos que el �ndice sea correcto.
      Por tanto, si los �ltimos caracteres del vector son
      todo may�sculas, entrar� en un bucle sin fin. 
      Para que funcionase correctamente tendr�amos que haber puesto lo siguiente:
         
         while (i < total_utilizados){
            while (i < total_utilizados && isupper(vector_privado[i]))
               Elimina(i);
            
            i++;
         }
      
      Y la soluci�n no queda ya tan elegante al repetir la
      expresi�n i < total_utilizados
      
      
      Para finalizar, veamos otro recorrido para eliminar correctamente las may�sculas
      y resolver el problema que se presentaba cuando hab�a varias consecutivas.
      Podr�amos haber realizado el bucle desde el final hasta el principio.
      Sigue siendo muy ineficiente pero elimina correctamente las may�sculas:
      
         for (int i = total_utilizados - 1; i >= 0; i--){
            if (isupper(vector_privado[i]))
               Elimina(i);
        }
      */
   }

   void EliminaMayusculas(){
      // El siguiente algoritmo es mucho m�s eficiente.
      // En vez de usar dos bucles anidados, 
      // resolvemos el problema con un �nico bucle.
      // Ejecutado con el Quijote, tarda unos cuantos milisegundos
      // mientras que los otros algoritmos tardan como m�nimo un minuto
      
      /*
      Usamos dos "apuntadores":
            pos_lectura: para ir leyendo las componentes
            pos_escritura: para ir colocando las componentes en el sitio correcto.
      
      Algoritmo:

         Recorrer todas las componentes que hay en el vector
            Si la componente actual no es may�scula
               ponedla donde indique pos_escritura
            Avanzar pos_lectura

         Actualizar el n�mero de componentes utilizadas
      */
      int pos_escritura, pos_lectura;

      pos_escritura = 0;

      for (pos_lectura = 0; pos_lectura < total_utilizados; pos_lectura++){
         if (! isupper(vector_privado[pos_lectura])){
            vector_privado[pos_escritura] = vector_privado[pos_lectura];
            pos_escritura++;
         }
      }

      total_utilizados = pos_escritura;
   }
};

int main(){
   /*
   Bater�a de pruebas:
      - Secuencia sin may�sculas
      - Secuencia s�lo con may�suculas
      - Secuencia vac�a
      - Secuencia con una s�la componente (may�scula o no)
   */
   SecuenciaCaracteres secuencia;
   Cronometro crono_mayusculas;
   double milisegundos_transcurridos;

   
   // Lectura

   // secuencia.AniadeCadena("AbbCDEefgTTT");

   const char TERMINADOR = '#';
   char caracter;

   caracter = cin.get();
   
   while (caracter != TERMINADOR){
      secuencia.Aniade(caracter);
      caracter = cin.get();
   }
   
   // Elimina May�sculas:
   
   cout << "\n�ltima letra: " << secuencia.Elemento(secuencia.TotalUtilizados()-1);
   cout << "\nN�mero de may�sculas antes de la llamada al m�todo: " << secuencia.NumeroMayusculas();
   
   crono_mayusculas.Reset();

   secuencia.EliminaMayusculas();
   // secuencia.EliminaMayusculasIneficiente();

   milisegundos_transcurridos = crono_mayusculas.MiliSegundosTranscurridos();

   cout << "\nTiempo de ejecuci�n del m�todo: " << milisegundos_transcurridos << " milisegundos";
   cout << "\nN�mero de may�sculas despu�s de la llamada al m�todo: " << secuencia.NumeroMayusculas();
   cout << "\n\n";
   system ("pause");
}

