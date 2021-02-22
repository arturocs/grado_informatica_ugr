#include "stdio.h"
#include "stdlib.h"
#include <omp.h>

#define dynamic

#ifndef dynamic
#define n 10
float matriz[n][n];
float v1[n], v2[n];
#endif

float **GenerarMatriz(float **M, int N) {
  M = (float **)malloc(N * sizeof(float *));
  for (int i = 0; i < N; i++)
    M[i] = (float *)malloc(N * sizeof(float));

  return M;
}

void BorrarMatriz(float **M, int N) {
  for (int i = 0; i < N; i++)
    free(M[i]);
  free(M);
}

int main(int argc, char *argv[]) {

#ifdef dynamic
  int n = argc > 1 ? atoi(argv[1]) : 10;
  float **matriz = NULL;
  float *v1, *v2;
  matriz = GenerarMatriz(matriz, n);
  v1 = (float *)malloc(n * sizeof(float));
  v2 = (float *)malloc(n * sizeof(float));
#endif
  for (int k = 1; k <= 4; k++) {
    omp_set_num_threads(k);
#pragma omp parallel for
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        matriz[i][j] = i * j;
      }
    }

    for (int i = 0; i < n; i++) {
      v1[i] = i % 2 ? i * 3 : i * 4;
      v2[i] = 0;
    }
    float start_time = omp_get_wtime();

    for (int i = 0; i < n; i++) {
#pragma omp parallel for reduction(+ : v2[i])
      for (int j = 0; j < n; j++) {
        v2[i] += matriz[i][j] * v1[j];
      }
    }
    float ncgt = omp_get_wtime() - start_time;

    printf("%d\t%f\n", k, ncgt);
  }
#ifdef dynamic
  BorrarMatriz(matriz, n);
  free(v1);
  free(v2);
#endif
}