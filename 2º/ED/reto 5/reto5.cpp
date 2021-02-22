#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> d(int a, int c, int m) { // Version iterativa de la funcion del reto
  vector<int> out;
  int di = 0;
  for (int i = 0; i < m; i++) {
    di = (a * di + c) % m;
    out.push_back(di);
  }
  return out;
}

void comprobar(int m) {
  vector<int> seq;
  cout << "Comprobando parejas (a,c) para M = " << m << endl;
  for (int a = 0; a < m; a++) {
    for (int c = 0; c < m; c++) {
      seq = d(a, c, m);
      if (all_of(seq.begin(), seq.end(), [&](int i) {return count(seq.begin(), seq.end(), i) == 1;})) { // Verificar que no hay repetidos
        cout << "a: " << a << ", c: " << c << endl;
      }
    }
  }
  cout << endl;
}

int main() {
  int primos[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                  43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
  for (auto i : primos) {
    comprobar(i);
  }
}