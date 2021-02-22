#include "BolsaLetras.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
  BolsaLetras bolsa;
  if (argc != 5) {
    cout << "Uso: " << argv[0]
         << " fichero_diccionario letras.txt frecuencias.txt puntuaciones.txt"
         << endl;
    exit(-1);
  }

  if (!bolsa.leer_letras(argv[2])) {
    cout << "Error leyendo " << argv[2] << endl;
    exit(-1);
  }

  if (!bolsa.leer_diccionario(argv[1])) {
    cout << "Error leyendo " << argv[1] << endl;
    exit(-1);
  }

  if (!bolsa.escribir_frecuencias(argv[3])) {
    cout << "Error creando " << argv[3] << endl;
    exit(-1);
  }

  if (!bolsa.escribir_puntuaciones(argv[4])) {
    cout << "Error creando " << argv[4] << endl;
    exit(-1);
  }

  cout << endl <<  "Creados los archivos " << argv[3] << " y " << argv[4] <<endl <<endl;
}
