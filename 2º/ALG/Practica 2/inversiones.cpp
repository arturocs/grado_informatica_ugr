#include <algorithm>
#include <chrono>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

double uniforme() {
  int t = rand();
  double f = ((double)RAND_MAX + 1.0);
  return (double)t / f;
}

vector<int> generador(int n) {
  vector<int> T;
  for (int j = 0; j < n; j++)
    T.push_back(j);
  for (int j = n - 1; j > 0; j--) {
    double u = uniforme();
    int k = (int)(j * u);
    int tmp = T[j];
    T[j] = T[k];
    T[k] = tmp;
  }
  return T;
}

int inversiones(const vector<int> &v) {
  int inv = 0;
  for (int i = 0; i < v.size() - 1; i++)
    for (int j = i + 1; j < v.size(); j++)
      if (v[i] > v[j])
        inv++;

  return inv;
}

int fusion(vector<int> &vec, int iz, int der) {
  vector<int> aux(der - iz + 1);
  int centro = (iz + der) / 2, inv = 0, i = iz, j = centro + 1, k;

  for (k = 0; i <= centro && j <= der; k++) {
    if (vec[i] <= vec[j]) {
      aux[k] = vec[i];
      i++;
    } else {
      aux[k] = vec[j];
      j++;
      inv += centro - i + 1;
    }
  }

  for (; i <= centro; k++, i++)
    aux[k] = vec[i];

  for (; j <= der; k++, j++)
    aux[k] = vec[j];

  copy(aux.begin(), aux.begin() + der - iz + 1, vec.begin() + iz);

  return inv;
}

int inversiones_dyv(vector<int> &vec, int iz, int der) {
  int centro = (iz + der) / 2;
  if (iz >= der) {
    return 0;
  } else {
    return inversiones_dyv(vec, iz, centro) +
           inversiones_dyv(vec, centro + 1, der) + fusion(vec, iz, der);
  }
}

int main() {
  srand(time(0));
  for (int n = 2; n< 150; n++) {

    auto a = generador(n);
    auto t0 = chrono::high_resolution_clock::now();
    //int inv = inversiones_dyv(a, 0, a.size() - 1);
    int inv = inversiones(a);
    auto tej = chrono::duration_cast<chrono::nanoseconds>(
                   chrono::high_resolution_clock::now() - t0)
                   .count();
    cout << n << '\t' << tej << endl;
    // cout << inv << endl;
  }
}
