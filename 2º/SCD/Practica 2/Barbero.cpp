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

class Mon_Barbero : public HoareMonitor {
private:
  CondVar silla, barbero, clientes;

public:
  Mon_Barbero();
  void cortarPelo(int i);
  void siguienteCliente();
  void finCliente();
};

Mon_Barbero::Mon_Barbero() {
  barbero = newCondVar();
  clientes = newCondVar();
  silla = newCondVar();
}

void Mon_Barbero::cortarPelo(int i) {
  cout << "El cliente " << i << ": llega" << endl;
  if (clientes.empty()) {
    if (!barbero.empty()) {
      cout << "El cliente " << i << " despierta al barbero" << endl;
      barbero.signal();
    } 
    else {
      cout << "El cliente " << i << " espera" << endl;
      clientes.wait();
    }
  } 
  else {
    cout << "El cliente " << i << "en cola" << endl;
    clientes.wait();
  }
  cout << "El cliente " << i << " está siendo pelado." << endl;
  silla.wait();
}

void Mon_Barbero::siguienteCliente(){
  if(clientes.empty()){
    cout << "El barbero se duerme" << endl;
    barbero.wait();
  }else{
    cout << "Pasa el siguiente cliente" << endl;
    clientes.signal();
  }
}
void Mon_Barbero::finCliente(){
  cout << "El barbero termina" << endl;
  silla.signal();
}

void funcion_hebra_barbero(MRef<Mon_Barbero> monitor) {
  int ingrediente;
  for (;;) {
    monitor->siguienteCliente();
    this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));
    monitor->finCliente();
  }
}

void funcion_hebra_cliente(int cliente, MRef<Mon_Barbero> monitor) {
  for (;;) {
    monitor->cortarPelo(cliente);
    this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));
  }
}
int main() {

  const int num_hebras = 3;

  cout << "Problema del barbero durmiente"<< endl;
  MRef<Mon_Barbero> monitor = Create<Mon_Barbero>();

  thread clientes[5];
  thread barbero(funcion_hebra_barbero, monitor);

  for (int i = 0; i < 5; i++) {
    clientes[i] = thread(funcion_hebra_cliente, i, monitor);
  }

  for (int i = 0; i < 5; i++) {
    clientes[i].join();
  }

  barbero.join();
}
