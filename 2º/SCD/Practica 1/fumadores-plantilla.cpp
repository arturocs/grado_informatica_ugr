#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "Semaphore.h"

using namespace std ;
using namespace SEM ;


//**********************************************************************
// plantilla de función para generar un entero aleatorio uniformemente
// distribuido entre dos valores enteros, ambos incluidos
// (ambos tienen que ser dos constantes, conocidas en tiempo de compilación)
//----------------------------------------------------------------------

Semaphore mostr_vacio=1, ingr_disp[]={0,0,0};

template< int min, int max > int aleatorio(){
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

int Producir(){
  int ingrediente=aleatorio<0,2>();
  cout << "Produciendo ingrediente " << ingrediente << endl;
  chrono::milliseconds duracion_producir( aleatorio<20,100>() );
  this_thread::sleep_for( duracion_producir );
  return ingrediente;
}

//----------------------------------------------------------------------
// función que ejecuta la hebra del estanquero

void funcion_hebra_estanquero(){
  int ingrediente;
  while(true){
    ingrediente= Producir();
    sem_wait(mostr_vacio);
    cout << "El estanquero coloca el ingrediente: "<< ingrediente << endl;
    sem_signal(ingr_disp[ingrediente]);
  }
}

//-------------------------------------------------------------------------
// Función que simula la acción de fumar, como un retardo aleatoria de la hebra

void Fumar(int num_fumador){

   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_fumar( aleatorio<20,200>() );

   // informa de que comienza a fumar

    cout << "Fumador " << num_fumador << " :" << " empieza a fumar (" << duracion_fumar.count() << " ms)" << endl;

   // espera bloqueada un tiempo igual a ''duracion_fumar' milisegundos
   this_thread::sleep_for( duracion_fumar );

   // informa de que ha terminado de fumar

    cout << "Fumador " << num_fumador << " : termina de fumar, comienza espera de ingrediente" << endl;
}

//----------------------------------------------------------------------
// función que ejecuta la hebra del fumador
void  funcion_hebra_fumador(int num_fumador){
  while(true){
    sem_wait(ingr_disp[num_fumador]);
    cout << "El fumador " << num_fumador << " retira su ingrediente" << endl;
    sem_signal(mostr_vacio);
    Fumar(num_fumador);
  }
}

//----------------------------------------------------------------------

int main(){
  thread fumador[3];
  thread estanquero(funcion_hebra_estanquero);
  for(int i=0;i<3;i++) 
    fumador[i]= thread(funcion_hebra_fumador, i);

  estanquero.join();
  for(int i=0;i<3;i++) 
    fumador[i].join();

}
