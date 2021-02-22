#include <climits>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef vector<vector<int>> matriz;

vector<int> parsear_linea(string s) {
  vector<int> ret;
  regex numero("[0-9]+");
  auto inicio_linea = sregex_iterator(s.begin(), s.end(), numero);
  auto fin_linea = sregex_iterator();
  for (auto i = inicio_linea; i != fin_linea; i++) {
    ret.push_back(stoi((*i).str()));
  }
  return ret;
}

int indice_min(const vector<int> &distancia, const vector<bool> &visitado) {
  int min = INT_MAX, min_index;

  for (int v = 0; v < distancia.size(); v++)
    if (visitado[v] == false && distancia[v] <= min) {
      min = distancia[v];
      min_index = v;
    }

  return min_index;
}

vector<int> camino(const vector<int> &previo, int destino) {
  vector<int> ret;
  while (destino < previo.size()) {
    ret.insert(ret.begin(), destino);
    destino = previo[destino];
  }
  return ret;
}

pair<int, vector<int>> dijkstra(const matriz &adyacencia, int origen,
                                int destino) {

  vector<int> distancia(adyacencia.size(), INT_MAX);
  vector<bool> visitado(adyacencia.size(), false);
  vector<int> previo(adyacencia.size(), -1);

  distancia[origen] = 0;

  for (int count = 0; count < adyacencia.size() - 1; count++) {

    int u = indice_min(distancia, visitado);
    visitado[u] = true;

    for (int v = 0; v < adyacencia.size(); v++)
      if (!visitado[v] && adyacencia[u][v] &&
          distancia[u] + adyacencia[u][v] < distancia[v]) {
        previo[v] = u;
        distancia[v] = distancia[u] + adyacencia[u][v];
      }
  }

  return make_pair(distancia[destino], camino(previo, destino));
}

int main(int argc, char *argv[]) {

  if (argc != 5) {
    cerr << "Uso: " << argv[0] << " <M> <O> <D> <K>" << endl;
    cerr << "\tT: Archivo que contiene la matriz de adyacencia" << endl;
    cerr << "\tO: Numero de la ciudad de origen" << endl;
    cerr << "\tP: Numero de la ciudad de destino" << endl;
    cerr << "\tK: Kilometros que puede recorrer sin repostar" << endl;
    return 1;
  }

  fstream f(argv[1]);
  int origen = stoi(argv[2]);
  int destino = stoi(argv[3]);
  int deposito = stoi(argv[4]);
  int km_recorridos = 0;
  int km_local = 0;
  string s;
  matriz adyacencia;

  while (!f.eof()) {
    getline(f, s);
    if (s != "")
      adyacencia.push_back(parsear_linea(s));
  }
  f.close();

  if (origen < 0 || destino < 0 || deposito <= 0 ||
      origen >= adyacencia.size() || destino >= adyacencia.size()) {
    cerr << "Parametros de entrada erroneos" << endl;
    return 1;
  }

  auto camino_y_dist = dijkstra(adyacencia, origen, destino);

  cout << "Saliendo de ciudad " << origen << endl;
  for (int i = 0; i < camino_y_dist.second.size() - 1; i++) {
    km_local = adyacencia[camino_y_dist.second[i + 1]][camino_y_dist.second[i]];
    if (km_local + km_recorridos >= deposito) {
      cout << "\tRepostando" << endl;
      km_recorridos = 0;
      i--;
    } else {
      cout << "Viajando a " << camino_y_dist.second[i + 1] << endl;
      km_recorridos += km_local;
      cout << "\tRecorridos " << km_local
           << "km.    Deposito: " << km_recorridos << " \\ " << deposito
           << endl;
    }
  }
  cout << "Viaje finalizado. " << camino_y_dist.first
       << "km recorridos en total" << endl;
}
