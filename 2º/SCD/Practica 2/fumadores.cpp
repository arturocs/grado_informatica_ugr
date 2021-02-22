#include "HoareMonitor.h"
#include <cassert>
#include <condition_variable>
#include <iomanip>
#include <iostream>
#include <random>
#include <thread>

using namespace std;
using namespace HM;

template <int min, int max> int aleatorio() {
  static default_random_engine generador((random_device())());
  static uniform_int_distribution<int> distribucion_uniforme(min, max);
  return distribucion_uniforme(generador);
}

class Estanco : public HoareMonitor {
private:
  int ingrediente;
  CondVar estanquero, fumadores[3];

public:
  Estanco();
  void obtenerIngrediente(int ing);
  void ponerIngrediente(int ing);
  void esperarRecogidaIngrediente();
};

Estanco::Estanco() {
  ingrediente = -1;
  for (int i = 0; i < 3; i++)
    fumadores[i] = newCondVar();
  estanquero = newCondVar();
}

void Estanco::ponerIngrediente(int ing) {
  ingrediente = ing;
  fumadores[ing].signal();
}

void Estanco::obtenerIngrediente(int fumador) {
  if (ingrediente != fumador)
    fumadores[fumador].wait();
  ingrediente = -1;
  estanquero.signal();
}

void Estanco::esperarRecogidaIngrediente() {
  if (ingrediente != -1)
    estanquero.wait();
}

int ProducirIngrediente() {
  this_thread::sleep_for(chrono::milliseconds(aleatorio<20, 100>()));
  int i = aleatorio<0, 2>();
  cout << "producido ingrediente " << i << endl;
  return i; // Produce entero aleatorio
}

void Fumar(int num_fumador) {
  // calcular milisegundos aleatorios de duración de la acción de fumar)
  chrono::milliseconds duracion_fumar(aleatorio<20, 200>());
  // informa de que comienza a fumar
  cout << "Fumador " << num_fumador << " :"
       << " empieza a fumar (" << duracion_fumar.count() << " ms)" << endl;
  // espera bloqueada un tiempo igual a ''duracion_fumar' milisegundos
  this_thread::sleep_for(duracion_fumar);
  // informa de que ha terminado de fumar
  cout << "Fumador " << num_fumador
       << " : termina de fumar, comienza espera de ingrediente" << endl;
}

void funcion_hebra_estanquero(MRef<Estanco> monitor) {
  int ingrediente;
  for (;;) {
    ingrediente = ProducirIngrediente();
    monitor->ponerIngrediente(ingrediente);
    monitor->esperarRecogidaIngrediente();
  }
}

void funcion_hebra_fumador(int fumador, MRef<Estanco> estanco) {
  for (;;) {
    estanco->obtenerIngrediente(fumador);
    cout << "El fumador " << fumador << " retira su ingrediente" << endl;
    Fumar(fumador);
  }
}
int main() {


	const int num_hebras = 3;

  //Crear Monitor
  MRef<Estanco> monitor = Create<Estanco>();

	thread hebra_fumador[num_hebras];

	thread hebra_estanquero(funcion_hebra_estanquero, monitor);

	for (int i=0; i<num_hebras; i++){
		hebra_fumador[i] = thread (funcion_hebra_fumador,i, monitor);
	}

   for(int i=0; i<num_hebras; i++){
   		hebra_fumador[i].join();
   }

   hebra_estanquero.join();
   
}
