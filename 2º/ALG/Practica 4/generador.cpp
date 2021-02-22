#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#define aleatorio(min, max) rand() % (max - min) + min

int main(int argc, char **argv) {
  if (argc != 3) {
    cerr << "Uso: " << argv[0] << "<tamaño secuencia 1> <tamaño secuencia 2>"
         << endl;
    return 1;
  }

  unsigned long tam1 = stoul(argv[1]);
  unsigned long tam2 = stoul(argv[2]);

  int ncaracteres_comunes = ceil(min(tam1, tam2) / 4.0);

  string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string caracteres_comunes, secuencia1, secuencia2;

  for (int i = 0; i < ncaracteres_comunes; i++)
    caracteres_comunes += caracteres[aleatorio(0, caracteres.size())];
  for (int i = 0; i < tam1; i++)
    secuencia1 += caracteres[aleatorio(0, caracteres.size())];
  for (int i = 0; i < tam2; i++)
    secuencia2 += caracteres[aleatorio(0, caracteres.size())];

  int step1 = tam1 / ncaracteres_comunes;
  int step2 = tam2 / ncaracteres_comunes;

  for (int i = 0, j = 0; i < tam1 && j < ncaracteres_comunes; i += step1, j++) {
    secuencia1[i] = caracteres_comunes[j];
  }

  for (int i = 0, j = 0; i < tam2 && j < ncaracteres_comunes; i += step2, j++) {
    secuencia2[i] = caracteres_comunes[j];
  }

  cout << secuencia1 << endl;
  cout << secuencia2 << endl;

  cout << endl << "Subsecuencia comun: " << caracteres_comunes << endl;
}