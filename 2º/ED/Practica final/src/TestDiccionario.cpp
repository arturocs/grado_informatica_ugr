#include "Diccionario.h"
#include <fstream>
#include <iostream>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {
  string palabra;
  int tam=0;
  vector<string> vt;

  if (argc != 2) {
    cout << "Dime el nombre del diccionario" << endl;
    return 0;
  }
  ifstream f(argv[1]);
  if (!f) {
    cout << "No puedo abrir el diccionario" << endl;
  }
  Diccionario D;
  cout << "Cargando diccionario" << endl;
  f >> D;
  cout << "Diccionario leído:" << endl;
  cout << D << endl;
  cout << "Tamaño del diccionario: " << D.size() << endl;
  cout << "Dime una palabra" << endl;
  cin >> palabra;
  if (D.esta(palabra)) {
    cout << "La palabra existe en el diccionario" << endl;
  } else {
    cout << "La palabra no existe en el diccionario" << endl;
  }
  cout << "Introduce un tamaño de palabra"<< endl;
  cin >> tam;
  cout << "Palabras de tamaño "<< tam << endl;
  vt=D.palabra_longitud(tam);
  for (auto s:vt){ cout << s << endl; }
}
