#include <chrono>
#include <cstdio>

using namespace std;

#define N 40000

struct {
  int a;
  int b;
} s[5000];

int main() {

  double R[N];
  auto t0 = chrono::high_resolution_clock::now();

  for (int ii = 0; ii < N; ii++) {
    double X1 = 0, X2 = 0;

    for (int i = 0; i < 5000; i+=4) {
      X1 += 2 * s[i].a + ii;
      X2 += 3 * s[i].b - ii;

      X1 += 2 * s[i+1].a + ii;
      X2 += 3 * s[i+1].b - ii;

      X1 += 2 * s[i+2].a + ii;
      X2 += 3 * s[i+2].b - ii;

      X1 += 2 * s[i+3].a + ii;
      X2 += 3 * s[i+3].b - ii;
    }

    R[ii] = X1 < X2 ? X1 : X2;
  }

  auto tej = (chrono::high_resolution_clock::now() - t0).count();
  printf("Tiempo: %ld\nPrimer componente: %f\nUltimo componente: %f\n", tej,
         R[0], R[N - 1]);
}