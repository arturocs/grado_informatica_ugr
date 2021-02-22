#include <omp.h>
#include <stdio.h>
int main(void) {
#pragma omp parallel
  printf("Hello %d\n", omp_get_thread_num());
  printf("world %d\n", omp_get_thread_num());
  return (0);
}