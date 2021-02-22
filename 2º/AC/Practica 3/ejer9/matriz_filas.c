#include "stdio.h"
#include "stdlib.h"
#include <omp.h>

#define dynamic

#ifndef dynamic
#define n 10
double matriz[n][n];
double v1[n], v2[n];
#endif

double **GenerarMatriz(double **M, int N) {
  M = (double **)malloc(N * sizeof(double *));
  for (int i = 0; i < N; i++)
    M[i] = (double *)malloc(N * sizeof(double));

  return M;
}

void BorrarMatriz(double **M, int N) {
  for (int i = 0; i < N; i++)
    free(M[i]);
  free(M);
}

int main(int argc, char *argv[]) {

#ifdef dynamic
  int n = argc > 1 ? atoi(argv[1]) : 10;
  double **matriz = NULL;
  double *v1, *v2;
  matriz = GenerarMatriz(matriz, n);
  v1 = (double *)malloc(n * sizeof(double));
  v2 = (double *)malloc(n * sizeof(double));
#endif

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
  double start_time = omp_get_wtime();
#pragma omp parallel for
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
#pragma omp atomic
      v2[i] += matriz[i][j] * v1[j];
    }
  }
  double ncgt = omp_get_wtime() - start_time;

  if (n <= 11) {
    printf("[ ");
    for (int i = 0; i < n; i++)
      printf("%f ", v2[i]);
    puts("]");
  } else {
    printf("[ %f ... %f ]\n", v2[0], v2[n - 1]);
  }

  printf("tiempo: %f\n", ncgt);

#ifdef dynamic
  BorrarMatriz(matriz, n);
  free(v1);
  free(v2);
#endif
}