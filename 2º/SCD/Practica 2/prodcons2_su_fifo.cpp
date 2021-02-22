// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Seminario 2. Introducción a los monitores en C++11.
//
// archivo: prodcons_1.cpp
// Ejemplo de un monitor en C++11 con semántica SC, para el problema
// del productor/consumidor, con un único productor y un único consumidor.
// Opcion LIFO (stack)
//
// Historial:
// Creado en Julio de 2017
// -----------------------------------------------------------------------------
#include "HoareMonitor.h"
#include <cassert>
#include <condition_variable>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>

using namespace std;
using namespace HM;

constexpr int num_items = 40; // número de items a producir/consumir

mutex mtx;                     // mutex de escritura en pantalla
unsigned cont_prod[num_items], // contadores de verificación: producidos
    cont_cons[num_items];      // contadores de verificación: consumidos

const int nprods = 5;
const int ncons = 5;
int lista_prods[nprods];

//**********************************************************************
// plantilla de función para generar un entero aleatorio uniformemente
// distribuido entre dos valores enteros, ambos incluidos
// (ambos tienen que ser dos constantes, conocidas en tiempo de compilación)
//----------------------------------------------------------------------

template <int min, int max> int aleatorio() {
  static default_random_engine generador((random_device())());
  static uniform_int_distribution<int> distribucion_uniforme(min, max);
  return distribucion_uniforme(generador);
}

//**********************************************************************
// funciones comunes a las dos soluciones (fifo y lifo)
//----------------------------------------------------------------------

int producir_dato(int nhebra) {
  static int contador = 0;
  this_thread::sleep_for(chrono::milliseconds(aleatorio<20, 100>()));
  mtx.lock();
  cout << "producido: " << contador << endl << flush;
  mtx.unlock();
  cont_prod[contador]++;
  lista_prods[nhebra]++;
  contador++;
  return (nhebra * num_items) / nprods + lista_prods[nhebra] - 1;
}
//----------------------------------------------------------------------

void consumir_dato(unsigned dato) {
  if (num_items <= dato) {
    cout << " dato === " << dato << ", num_items == " << num_items << endl;
    assert(dato < num_items);
  }
  cont_cons[dato]++;
  this_thread::sleep_for(chrono::milliseconds(aleatorio<20, 100>()));
  mtx.lock();
  cout << "                  consumido: " << dato << endl;
  mtx.unlock();
}
//----------------------------------------------------------------------

void ini_contadores() {
  for (unsigned i = 0; i < num_items; i++) {
    cont_prod[i] = 0;
    cont_cons[i] = 0;
  }
}

//----------------------------------------------------------------------

void test_contadores() {
  bool ok = true;
  cout << "comprobando contadores ...." << flush;

  for (unsigned i = 0; i < num_items; i++) {
    if (cont_prod[i] != 1) {
      cout << "error: valor " << i << " producido " << cont_prod[i] << " veces."
           << endl;
      ok = false;
    }
    if (cont_cons[i] != 1) {
      cout << "error: valor " << i << " consumido " << cont_cons[i] << " veces"
           << endl;
      ok = false;
    }
  }
  if (ok)
    cout << endl
         << flush << "solución (aparentemente) correcta." << endl
         << flush;
}

// *****************************************************************************
// clase para monitor buffer, version LIFO, semántica SC, un prod. y un cons.
class ProdCons1SC : public HoareMonitor
{
 private:
 static const int           // constantes:
   num_celdas_total = 10;   //  núm. de entradas del buffer
 int                        // variables permanentes
   buffer[num_celdas_total],//  buffer de tamaño fijo, con los datos
   primera_libre,
   primera_ocupada,n;
 CondVar         // colas condicion:
   ocupadas,                //  cola donde espera el consumidor (n>0)
   libres ;                 //  cola donde espera el productor  (n<num_celdas_total)

 public:                    // constructor y métodos públicos
   ProdCons1SC() ;           // constructor
   int  leer();                // extraer un valor (sentencia L) (consumidor)
   void escribir( int valor ); // insertar un valor (sentencia E) (productor)
} ;
// -----------------------------------------------------------------------------

ProdCons1SC::ProdCons1SC(  )
{
   primera_ocupada =0;
   primera_libre = 0;
   n=0;
   ocupadas = newCondVar();
   libres = newCondVar();
}
// -----------------------------------------------------------------------------
// función llamada por el consumidor para extraer un dato

int ProdCons1SC::leer(  )
{
   // esperar bloqueado hasta que 0 < num_celdas_ocupadas
   while ( primera_ocupada >= primera_libre )
      ocupadas.wait();

   // hacer la operación de lectura, actualizando estado del monitor
   assert(primera_ocupada < primera_libre);
   const int valor = buffer[primera_ocupada % num_celdas_total] ;
   primera_ocupada++;
   n--;

   // señalar al productor que hay un hueco libre, por si está esperando
   libres.signal();

   // devolver valor
   return valor ;
}
// -----------------------------------------------------------------------------

void ProdCons1SC::escribir( int valor )
{
   while ( primera_libre - primera_ocupada > num_celdas_total )
      libres.wait();

   //cout << "escribir: ocup == " << num_celdas_ocupadas << ", total == " << num_celdas_total << endl ;
   assert( n < num_celdas_total );

   // hacer la operación de inserción, actualizando estado del monitor
   buffer[primera_libre % num_celdas_total] = valor ;
   primera_libre++ ;
   n++;

   // señalar al consumidor que ya hay una celda ocupada (por si esta esperando)
   ocupadas.signal();
}
// *****************************************************************************
// funciones de hebras

void funcion_hebra_productora(int a, MRef<ProdCons1SC> monitor) {
  for (unsigned i = 0; i < num_items / nprods; i++) {
    int valor = producir_dato(a);
    monitor->escribir(valor);
  }
}
// -----------------------------------------------------------------------------

void funcion_hebra_consumidora(MRef<ProdCons1SC> monitor) {
  for (unsigned i = 0; i < num_items / ncons; i++) {
    int valor = monitor->leer();
    consumir_dato(valor);
  }
}
// -----------------------------------------------------------------------------

int main() {
  cout << "--------------------------------------------------------------------"
          "-----------"
       << endl
       << "Problema de los productores-consumidores (1 prod/cons, Monitor SC, "
          "buffer FIFO). "
       << endl
       << "--------------------------------------------------------------------"
          "-----------"
       << endl
       << flush;

  MRef<ProdCons1SC> monitor = Create<ProdCons1SC>();

  thread hebras_productoras[nprods], hebras_consumidoras[ncons];

  for (int i = 0; i < ncons; i++)
    hebras_productoras[i] = thread(funcion_hebra_productora, i, monitor);

  for (int i = 0; i < ncons; i++)
    hebras_consumidoras[i] = thread(funcion_hebra_consumidora, monitor);

  for (int i = 0; i < ncons; i++)
    hebras_productoras[i].join();

  for (int i = 0; i < ncons; i++)
    hebras_consumidoras[i].join();

  // comprobar que cada item se ha producido y consumido exactamente una vez
  test_contadores();
}
