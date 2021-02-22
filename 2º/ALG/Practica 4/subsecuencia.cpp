#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<vector<int>> matriz;

template <class T> inline ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto &i : v)
    os << " " << i;
  os << endl;
  return os;
}

string subsecuencia_comun(string s1, string s2) {
  // Matriz s1.size()+1 x s2.size()+1
  matriz M(s1.size() + 1, vector<int>(s2.size() + 1));
  // Subsecuencia de caraceteres a encontrar
  string subsecuencia;

  // Rellenamos la matriz de forma que  M[i][j] contiene el tamaño de tamaño de
  // la subsecuencia comun de s1 hasta i y s2 hasta j
  for (int i = 0; i <= s1.size(); i++) {
    for (int j = 0; j <= s2.size(); j++) {
      if (i == 0 || j == 0) {
        M[i][j] = 0;
      } else if (s1[i - 1] == s2[j - 1]) {
        M[i][j] = M[i - 1][j - 1] + 1;
      } else {
        M[i][j] = max(M[i - 1][j], M[i][j - 1]);
      }
    }
  }

  // Imprimimos la matriz de tamaños
  cout << endl << M << endl;

  // Empezamos a recorrer la matriz desde la esquina inferior derecha
  for (int i = s1.size(), j = s2.size(); i > 0 && j > 0;) {
    // Si el caracter i-1 y el j-1 son iguales, entonces forman parte de la
    // subsecuencia
    if (s1[i - 1] == s2[j - 1]) {
      subsecuencia.insert(subsecuencia.begin(), s1[i - 1]);
      i--;
      j--;
    }
    // Si no son iguales entonces buscamos la subsecuencia
    // mayor en la matriz y avanzamos en esa direccion
    else {
      M[i - 1][j] > M[i][j - 1] ? i-- : j--;
    }
  }

  return subsecuencia;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cerr << "Uso: " << argv[0] << " <secuencia 1> <secuencia 2>" << endl;
    return 1;
  }
  string s1 = argv[1];
  string s2 = argv[2];
  string subsecuencia = subsecuencia_comun(s1, s2);

  cout << "La subsecuencia comun de \"" << s1 << "\" y \"" << s2 << "\" es \""
       << subsecuencia << "\"" << endl
       << endl;
}
