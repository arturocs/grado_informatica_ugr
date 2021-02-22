#include <iostream>
#include "Letras.h"

using namespace std;
int main(int argc, char *argv[]) {

  Letras letras;
  int tamano = 0;
  bool fuera_del_diccionario=false;

  if (argc < 5) {
    cout << "Uso: "<< argv[0]<< " diccionario.txt puntuacion.txt tamaño_maximo modo_de_juego" << endl;
    exit(-1);
  }

  try {
    tamano = stoi(string(argv[3]));
  } catch (...) {
    cout << "Error en el tamaño máximo" << endl;
    exit(-1);
  }

  if (!letras.cargar_diccionario(argv[1])) {
    cout << "Error leyendo " << argv[1] << endl;
    exit(-1);
  }
  if (!letras.cargar_datos(argv[2])) {
    cout << "Error leyendo " << argv[2] << endl;
    exit(-1);
  }

  if(argc>=6 && argv[5][0]==tolower('s')){
    fuera_del_diccionario=true;
  }

  letras.jugar(fuera_del_diccionario, tolower(argv[4][0]), tamano);

}