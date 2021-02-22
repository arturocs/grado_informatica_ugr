#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char *argv[]) {
  int rank, contador, size;
  MPI_Status estado;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if (rank == 0 || rank == 1) {
    MPI_Send(&rank, 1, MPI_INT, rank + 2, 0, MPI_COMM_WORLD);
  } else if (rank == size - 1 || rank == size - 2) {
    MPI_Recv(&contador, 1, MPI_INT, rank - 2, 0, MPI_COMM_WORLD, &estado);
    cout << "Soy el proceso " << rank << " y he recibido " << contador << endl;
  } else {
    MPI_Send(&rank, 1, MPI_INT, rank + 2, 0, MPI_COMM_WORLD);

    MPI_Recv(&contador, 1, MPI_INT, rank - 2, 0, MPI_COMM_WORLD, &estado);
    cout << "Soy el proceso " << rank << " y he recibido " << contador << endl;
  }

  MPI_Finalize();
  return 0;
}