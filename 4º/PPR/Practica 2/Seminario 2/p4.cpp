#include "mpi.h"
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  int rank, size;

  MPI_Init(&argc, &argv);               // iniciamos el entorno MPI
  MPI_Comm_rank(MPI_COMM_WORLD, &rank); // obtenemos el identificador del
                                        // proceso
  MPI_Comm_size(MPI_COMM_WORLD, &size); // obtenemos el numero de procesos

  MPI_Comm comm,    // nuevo comunicador para pares o impares
      comm_inverso; // nuevo para todos los procesos pero con rank inverso.
  int rank_inverso, size_inverso;
  int rank_nuevo, size_nuevo;
  int a;
  int b;
  
  vector<int> vec(size_nuevo, 0);
  int num = 0;

  if (rank == 0) {
    a = 2000;
    b = 1;
  } else {
    a = 0;
    b = 0;
  }

  int color = rank % 2;
  // creamos un nuevo cominicador
  MPI_Comm_split(MPI_COMM_WORLD, color, rank, &comm);

  MPI_Comm_split(MPI_COMM_WORLD, 0, -rank, &comm_inverso);

  MPI_Comm_rank(comm, &rank_nuevo);
  MPI_Comm_size(comm, &size_nuevo);

  MPI_Comm_rank(comm_inverso, &rank_inverso);
  MPI_Comm_size(comm_inverso, &size_inverso);

  MPI_Bcast(&b, 1, MPI_INT, size - 1, comm_inverso);
  MPI_Bcast(&a, 1, MPI_INT, 0, comm);

  
  // El proceso 1 (0 en el impar) inicializa el vector
  if (rank == 1) {
    for (int i = 0; i < size_nuevo; i++) {
      vec.push_back(i);
    }
  }

  // Repartir vector
  MPI_Scatter(vec.data(), 1, MPI_INT, &num, 1, MPI_INT, 0, comm);

  cout << "Soy el proceso " << rank << " de " << size
       << " dentro de MPI_COMM_WORLD,"
          "\n\t mi rango en COMM_nuevo es "
       << rank_nuevo << ", de " << size_nuevo << ", aqui he recibido el valor "
       << a << ",\n\ten COMM_inverso mi rango es " << rank_inverso << " de "
       << size_inverso << " aqui he recibido el valor " << b << "\n"
       << endl;
  if (color == 1) {
    cout << "Rango global: " << rank << ", num: " << num << endl;
  }

  MPI_Finalize();
  return 0;
}