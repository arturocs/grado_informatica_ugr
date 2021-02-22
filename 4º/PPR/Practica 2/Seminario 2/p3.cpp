#include "mpi.h"
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  int tama, rank, size;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (argc < 2) {
    if (rank == 0) {
      cout << "No se ha especificado numero de elementos, multiplo de la "
              "cantidad de entrada, por defecto sera "
           << size * 100;
      cout << "\nUso: <eiecutable> <cantidad>" << endl;
    }
    tama = size * 100;
  } else {
    tama = atoi(argv[1]);
    if (tama < size)
      tama = size;
    else {
      int i = 1, num = size;
      while (tama > num) {
        ++i;
        num = size * i;
      }
      if (tama != num) {
        if (rank == 0)
          cout << "Cantidad cambiada a " << num << endl;
        tama = num;
      }
    }
  }

  // Creacion y relleno de los vectores
  vector<long> VectorA, VectorB, VectorALocal, VectorBLocal;
  VectorA.resize(tama, 0);
  VectorB.resize(tama, 0);
  VectorALocal.resize(tama / size, 0);

  if (rank == 0) {
    for (long i = 0; i < tama; ++i) {
      VectorA[i] = i + 1;
    }
  }

  // Repartimos los valores del vector A
  MPI_Scatter(&VectorA[0], tama / size, MPI_LONG, &VectorALocal[0], tama / size,
              MPI_LONG, 0, MPI_COMM_WORLD);

  for (int i = tama / size * rank; VectorBLocal.size() < tama / size; i++) {
    VectorBLocal.push_back((i + 1) * 10);
  }

  // Calculo de la multiplicacion escalar entre vectores
  long producto = 0;
  for (long i = 0; i < tama / size; ++i) {
    producto += VectorALocal[i] * VectorBLocal[i];
  }
  long total;

  MPI_Reduce(&producto, &total, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

  if (rank == 0)
    cout << "Total = " << total << endl;

  MPI_Finalize();
  return 0;
}