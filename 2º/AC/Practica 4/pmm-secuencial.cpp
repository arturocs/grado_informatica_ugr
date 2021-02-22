#include <chrono>
#include <cstdio>

using namespace std;

#define N 100

double A[N][N], B[N][N], Res[N][N];
int main(int argc, char **argv) {

  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      A[i][j] = 2;
      B[i][j] = 3;
      Res[i][j] = 0;
    }
  }

  auto t0 = chrono::high_resolution_clock::now();

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++)
        Res[i][j] += A[i][k] * B[k][j];

  auto tej = (chrono::high_resolution_clock::now() - t0).count();
  printf("Tiempo: %ld\nPrimer componente: %f\nUltimo componente: %f\n", tej,
         Res[0][0], Res[N - 1][N - 1]);

  return 0;
}