#include <chrono>
#include <cstdio>

using namespace std;

#define a 3.3

int main(int argc, char **argv) {
  double maxr = 0;
  long long maxn = 0;
  for (long long N = 100; N < 1000000; N += 100) {
    double *y = new double[N + 1];
    double *x = new double[N + 1];
    for (int i = 0; i <= N; i++) {
      y[i] = 2.1 * i;
      x[i] = 3.2 * i;
    }

    auto t0 = chrono::high_resolution_clock::now();

    for (int i = 1; i <= N; i++)
      y[i] = a * x[i] + y[i];

    long tej = (chrono::high_resolution_clock::now() - t0).count();

    double r = 2*N / double(tej);
    if (r > maxr) {
      maxr = r;
      maxn = N;
    }

   /* printf(
        "Tiempo: %ld\tPc: %f\tUc: %f\t N: %lld \t R: %f\t maxr: %lf \t maxn: "
        "%lld\n",
        tej, y[0], y[N - 1], N, r, maxr, maxn);*/
        printf("%lld\t%lf\n", N, r);
    delete[] x;
    delete[] y;
  }
  printf("maxn: %lld maxr: %lf", maxn, maxr);
}
