#include <algorithm>
#include <chrono>
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

inline double distancia(float x1, float y1, float x2, float y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

struct comparador {
  float x, y;
  bool operator()(const Ciudad &c1, const Ciudad &c2) {
    return distancia(x, y, c1.x, c1.y) < distancia(x, y, c2.x, c2.y);
  }
};

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

vector<Ciudad> parsear_datos(fstream &archivo) {
  vector<Ciudad> ret;
  regex letra("[A-Z]");
  vector<float> numeros_linea;
  string linea;

  do { // Eliminar las lineas que no son numeros
    getline(archivo, linea);
  } while (regex_search(linea, letra));

  while (!archivo.eof()) {
    if (linea != "EOF" && linea != " EOF") {
      numeros_linea = parsear_linea(linea);
      ret.push_back({numeros_linea[0], numeros_linea[1], numeros_linea[2]});
      getline(archivo, linea);
    } else {
      break;
    }
  }
  return ret;
}

int main(int argc, char *argv[]) {

  if (argc != 2) {
    cerr << "Uso: " << argv[0] << " <archivo>" << endl;
    return 1;
  }

  vector<float> solucion;
  fstream archivo(argv[1]);
  vector<Ciudad> ciudades = parsear_datos(archivo);
  archivo.close();

  comparador comp = {ciudades[0].x, ciudades[0].y};

  sort(ciudades.begin(), ciudades.end(),comp);

  //O también podemos usar este bucle while que es una aproximación más greedy al problema pero menos eficiente
  //while (ciudades.size() > 0) {
    //auto min = min_element(ciudades.begin(), ciudades.end(), comp);
    //Ciudad tmp = *min;
    //ciudades.erase(min);
    //solucion.push_back(tmp.nciudad);
  //}

  for (auto i : ciudades)
    cout << i.nciudad << endl;
  //En caso de usar la aproximación mas greedy entonces este seria el bucle de imprimir los resultados
  //  for (auto i : solucion)
  //  cout << i << endl;
}
