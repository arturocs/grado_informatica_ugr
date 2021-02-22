#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

int probabilidad(double prob_0, int max) {
  random_device random_dev;
  mt19937 random_engine{random_dev()};
  bernoulli_distribution coin_dist{1-prob_0};
  default_random_engine generator(random_dev());
  uniform_int_distribution<int> distribution(1, max);

  return coin_dist(random_engine) * distribution(generator);
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    cerr << "Uso: " << argv[0] << " <T> <M> <P> <F>" << endl;
    cerr << "\tT: Tamaño de la matriz" << endl;
    cerr << "\tM: Maximo numero que puede aparecer" << endl;
    cerr << "\tP: Probabilidad de que aparezcan ceros" << endl;
    cerr << "\tF: Formato: 0 para compilar o 1 para cargar desde txt" << endl;
    return 1;
  }

  int tam = stoi(argv[1]);
  int max = stoi(argv[2]);
  double p = stod(argv[3]);
  int f = stoi(argv[4]);

  vector<vector<int>> mat(tam, vector<int>(tam, 0));
  int n = 0;

  for (int i = 0; i < tam; i++) {
    for (int j = i + 1; j < tam; j++) {
      n = probabilidad(p, max);
      mat[i][j] = n;
      mat[j][i] = n;
    }
  }

  if (f == 0) {
    cout << "{";
    for (int i = 0; i < tam; i++) {
      cout << "{";
      for (int j = 0; j < tam; j++)
        cout << mat[i][j] << ((j != tam - 1) ? ", " : "");
      cout << "}" << ((i != tam - 1) ? ",\n" : "");
    }
    cout << "};" << endl;
  } else if (f == 1) {
    for (int i = 0; i < tam; i++) {
      for (int j = 0; j < tam; j++)
        cout << mat[i][j] << ((j != tam - 1) ? " " : "");
      cout << ((i != tam - 1) ? "\n" : "");
    }
    cout << endl;
  }
}