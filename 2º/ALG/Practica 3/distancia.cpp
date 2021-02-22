#include <cmath>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

struct Ciudad {
  float nciudad, x, y;
};

double distancia(Ciudad c1, Ciudad c2) {
  return sqrt((c2.x - c1.x) * (c2.x - c1.x) + (c2.y - c1.y) * (c2.y - c1.y));
}

vector<float> parsear_linea(string s) {
  vector<float> ret;
  regex numero("-?[0-9]+\\.?[0-9]*");
  auto inicio_linea = sregex_iterator(s.begin(), s.end(), numero);
  auto fin_linea = sregex_iterator();
  for (auto i = inicio_linea; i != fin_linea; i++) {
    ret.push_back(stof((*i).str()));
  }
  return ret;
}

vector<float> parsear_solucion(fstream &archivo) {
  vector<float> ret;
  string linea;

  do { // Eliminar las lineas que no son numeros
    getline(archivo, linea);
  } while (regex_search(linea, regex("[A-Z]")));

  while (!archivo.eof()) {
    if (linea != "EOF" && linea != " EOF" && linea != "-1") {
      vector<float> numeros_linea = parsear_linea(linea);
      for (auto i : numeros_linea) {
        ret.push_back(i);
      }
      getline(archivo, linea);
    } else {
      break;
    }
  }
  return ret;
}

vector<Ciudad> parsear_ciudades(fstream &archivo) {
  vector<Ciudad> ret;
  string linea;
  do { // Eliminar las lineas que no son numeros
    getline(archivo, linea);
  } while (regex_search(linea, regex("[A-Z]")));

  while (!archivo.eof()) {
    if (linea != "EOF" && linea != " EOF") {
      vector<float> numeros_linea = parsear_linea(linea);
      ret.push_back({numeros_linea[0], numeros_linea[1], numeros_linea[2]});
      getline(archivo, linea);
    } else {
      break;
    }
  }
  return ret;
}

int main(int argc, char *argv[]) {

  if (argc != 3) {
    cerr << "Uso: " << argv[0] << "<archivo solucion> <archivo ciudades>\n";
    return 1;
  }
  fstream archivo_solucion(argv[1]);
  fstream archivo_ciudades(argv[2]);

  auto solucion = parsear_solucion(archivo_solucion);
  auto ciudades = parsear_ciudades(archivo_ciudades);
  ciudades.insert(ciudades.begin(), {0, 0, 0});

  float dis = 0.0;

  for (int i = 0; i < solucion.size(); i++) {
    dis += distancia(ciudades[solucion[i]], ciudades[solucion[i - 1]]);
  }
  dis += distancia(ciudades.front(), ciudades.back());
  cout << "Distancia total: " << dis << endl;
}