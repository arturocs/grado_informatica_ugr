#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> matriz; //Es una matriz de chars para ahorrar memoria

matriz traspuesta(const matriz &m) {
  matriz m2(m[0].size(), vector<char>(m.size()));

  for (int i = 0; i < m.size(); i++)
    for (int j = 0; j < m[0].size(); j++)
      m2[j][i] = m[i][j];

  return m2;
}

void traspuesta_dyv(const matriz &entrada, matriz &salida, int x0, int x1,
                    int y0, int y1) {

  if (abs(y0 - y1) == 0) {
    salida[x1][y1] = entrada[y1][x1];
    salida[x0][y0] = entrada[y0][x0];
  } else {
    int x_mid = (x1 + x0) / 2;
    int y_mid = (y1 + y0) / 2;
    traspuesta_dyv(entrada, salida, x0, x_mid + 1, y0, y_mid);
    traspuesta_dyv(entrada, salida, x0, x_mid + 1, y_mid + 1, y1);
    traspuesta_dyv(entrada, salida, x_mid, x1, y0, y_mid);
    traspuesta_dyv(entrada, salida, x_mid, x1, y_mid + 1, y1);
  }
}

matriz traspuesta_dyv(matriz m) {
  matriz m2(m[0].size(), vector<char>(m.size()));
  traspuesta_dyv(m, m2, 0, m[0].size() - 1, 0, m.size() - 1);
  return m2;
}

int main() {
  for (int N = 1; N < 17; N++) {
    int n = pow(2, N);
    matriz mat(n);

    for (int i = 0; i < n; i++)
      for (int k = 0; k < n; k++) {
        mat[i].push_back(i);
      }

    auto t0 = chrono::high_resolution_clock::now();
    // traspuesta(mat);
    traspuesta_dyv(mat);
    auto tej = chrono::duration_cast<chrono::nanoseconds>(
                   chrono::high_resolution_clock::now() - t0)
                   .count();
    cout << n << "\t" << tej << endl;
  }
}
