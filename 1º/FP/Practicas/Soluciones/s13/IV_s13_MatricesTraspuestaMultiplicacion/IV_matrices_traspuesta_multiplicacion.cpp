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
En este ejercicio, no hay que construir ninguna clase ni
función. Es un ejercicio sobre recorridos de una matriz.
Leed desde teclado dos variables util_filas y util_columnas y leed los datos
de una matriz de enteros de tamaño util_filas x util_columnas. Sobre dicha
matriz, se pide lo siguiente:

a) Calcular la traspuesta de la matriz, almacenando el resultado en otra matriz.

d) Leer los datos de otra matriz y multiplicar ambas matrices (las dimensiones de la
segunda matriz han de ser compatibles con las de la primera para poder hacer la
multiplicación)
*/

#include <iostream>
using namespace std;

int main(){
   const int MAX_FIL = 10, MAX_COL = 10;
   double matriz[MAX_FIL][MAX_COL];
   double traspuesta[MAX_COL][MAX_FIL];
   int util_filas, util_columnas;


   // No etiquetamos las entradas porque suponemos que leemos de un fichero
   // Supondremos que util_filas y util_columnas son > 0

   cin >> util_filas;
   cin >> util_columnas;

   for (int i=0; i<util_filas; i++)
      for (int j=0; j<util_columnas; j++)
         cin >> matriz[i][j];

   ///////////////////////////////////////////////////////////////////////////
   // Traspuesta
   
   int util_fil_traspuesta, util_col_traspuesta;
   
   util_fil_traspuesta = util_columnas;
   util_col_traspuesta = util_filas;
   
   for (int i=0; i<util_fil_traspuesta; i++)
      for (int j=0; j<util_col_traspuesta; j++)
         traspuesta[i][j] = matriz[j][i];
   
   cout << "\n\n";
   cout << "Matriz original:\n";

   for (int i=0; i<util_filas; i++){
      cout << "\n";

      for (int j=0; j<util_columnas; j++)
         cout << matriz[i][j] << '\t';
   }
   
   cout << "\n\n";
   cout << "Matriz traspuesta:\n";   
    
   for (int i=0; i<util_fil_traspuesta; i++){
      cout << "\n";
      
      for (int j=0; j<util_col_traspuesta; j++)
         cout << traspuesta[i][j] << '\t';
   }  

   ///////////////////////////////////////////////////////////////////////////
   // Multiplicación
   
   const int MAX_FIL_DCHA = MAX_COL, MAX_COL_DCHA = 30;
   double matriz_dcha[MAX_FIL_DCHA][MAX_COL_DCHA];
   double matriz_producto[MAX_FIL][MAX_COL_DCHA];

   int util_filas_dcha, util_columnas_dcha;
   int util_filas_producto, util_columnas_producto;

   util_filas_dcha = util_columnas;
   cin >> util_columnas_dcha;
      
   for (int i=0; i<util_filas_dcha; i++)
      for (int j=0; j<util_columnas_dcha; j++)
         cin >> matriz_dcha[i][j];
   
   util_filas_producto = util_filas;
   util_columnas_producto = util_columnas_dcha;
   
   for (int i=0; i<util_filas_producto; i++)
      for (int j=0; j<util_columnas_producto; j++){
         matriz_producto[i][j] = 0;
         
         for (int k=0; k<util_columnas_producto; k++)
            matriz_producto[i][j] = matriz_producto[i][j] +
                                    matriz[i][k] * matriz_dcha[k][j];
   }
   
   /*
   Nota:
      // suma += b es la forma abreviada de:
      // suma = suma + b.
      // En este ejemplo, podríamos poner lo siguiente:
      // matriz_producto[i][j] = matriz_producto[i][j]  + matriz[i][k] * matriz_dcha[k][j];
   */
   
   cout << "\n\n";
   cout << "Matriz producto:\n";
   
   for (int i=0; i<util_filas_producto; i++){
      cout << "\n";
      
      for (int j=0; j<util_columnas_producto; j++)
         cout << matriz_producto[i][j] << '\t';
   }  
  
   
   cout << "\n\n";

   // 3 4    9 7 4 5    2 18 2 12    7 9 1 5      2      1 2   3 4   5 6   7 8
}
