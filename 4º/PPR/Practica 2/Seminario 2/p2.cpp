#include <cmath>
#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char *argv[]) {
  int rank, size, n;
  double PI25DT = 3.141592653589793238462643;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (rank == 0) {
    cout << "introduce la precision del calculo (n > 0): ";
    cin >> n;
  }

  MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

  double h = 1.0 / n, final = 0.0, sum = 0.0;

  for (int i = rank * ceil(n / size); i < (rank + 1) * ceil(n / size); i++) {
    double x = h * (i + 1.0 - 0.5);
    sum += (4.0 / (1.0 + x * x));
  }
  
  sum *= h;

  MPI_Reduce(&sum, &final, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  MPI_Bcast(&final, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  cout << fixed << "El valor aproximado de PI es: " << final
       << ", con un error de " << fabs(final - PI25DT) << endl;

  MPI_Finalize();
  return 0;
}
