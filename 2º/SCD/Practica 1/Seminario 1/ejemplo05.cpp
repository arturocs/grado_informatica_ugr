// -----------------------------------------------------------------------------
// Sistemas concurrentes y Distribuidos.
// Seminario 1. Programación Multihebra y Semáforos.
//
// Ejemplo 5 (ejemplo5.cpp)
// Obtención de resultados mediante 'return' y la llamada a 'async'
//
// Historial:
// Creado en Abril de 2017
// -----------------------------------------------------------------------------

#include <iostream>
#include <future>     // declaracion de {\bf std::thread}, {\bf std::async}, {\bf std::future}
using namespace std ; // permite acortar la notación (abc en lugar de std::abc)

// declaración de la función {\bf factorial} (parámetro {\bf int}, resultado {\bf long})

void hanoi (int M, int i, int j)
{
  if (M>0) {
	hanoi(M-1,i, 6-i-j);
    hanoi(M-1,6-i-j, j);     
  }
}
 

long factorial( int n ) { return n > 0 ? n*factorial(n-1) : 1 ; }

int main()
{
  // iniciar las hebras y obtener los objetos {\bf future} (conteniendo un {\bf long})
  // (el valor {\bf launch:async} indica que se debe usar una hebra concurrente
  // para evaluar la función):
  future<void> futuro1 = async( launch::async, hanoi, 32, 1,2  );
    future<long> futuro2 = async( launch::async, factorial, 10 );


while (futuro1.valid()){
	cout << "futuro 1 waiting" << endl;
}

  // esperar a que terminen las hebras, obtener resultado e imprimirlos
  cout << "factorial(5)  == " << futuro1.valid() << endl
       << "factorial(10) == " << futuro2.get() << endl ;
}
