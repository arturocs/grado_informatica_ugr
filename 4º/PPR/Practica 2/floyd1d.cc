#include "Graph.h"
#include "mpi.h"
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>

using namespace std;

//**************************************************************************

int main(int argc, char *argv[]) {

  if (argc != 2) {
    cerr << "Sintaxis: " << argv[0] << " <archivo de grafo>" << endl;
    return (-1);
  }

  Graph G;
  G.lee(argv[1]); // Read the Graph
  // cout << "EL Grafo de entrada es:"<<endl;
  // G.imprime();

  int nverts = G.vertices;
  int rank;
  int size;

  MPI_Init(&argc, &argv);               // Inicializamos los procesos
  MPI_Comm_size(MPI_COMM_WORLD, &size); // Obtenemos el numero total de procesos
  MPI_Comm_rank(MPI_COMM_WORLD,
                &rank); // Obtenemos el valor de nuestro identificador

  MPI_Bcast(&nverts, 1, MPI_INT, 0,
            MPI_COMM_WORLD); // Broadcast del numero de vertices

  int tam_mat =
      nverts * nverts / size; // Tamaño de la matriz a procesar por cada proceso
  int vpproc = nverts / size; // Vertices por proceso

  int *submatriz =
      new int[tam_mat]; // Reservar memoria para la submatriz de cada proceso
  int *fila_K = new int[nverts]; // Reservar memoria para la fila k

  // Repartir grafo
  MPI_Scatter(G.getMatriz(), tam_mat, MPI_INT, submatriz, tam_mat, MPI_INT, 0,
              MPI_COMM_WORLD);

  int inicio = rank * vpproc;    // Fila de inicio del proceso
  int fin = (rank + 1) * vpproc; // Fila final del proceso

  double t = MPI_Wtime(); // Tomar tiempo de inicio

  for (int k = 0; k < nverts; k++) {
    if (k >= inicio && k < fin) { // Comprobar si fila_K pertenece al proceso
      for (int a = 0; a < nverts;
           a++) // Copiar la fila k % vpproc de la matriz a fila_k
        fila_K[a] = submatriz[(k % vpproc) * nverts + a];
    }
    MPI_Bcast(fila_K, nverts, MPI_INT, k / vpproc,
              MPI_COMM_WORLD); // Broadcast de la fila K
    for (int i = 0; i < vpproc; i++) { //Bucle filas
      for (int j = 0; j < nverts; j++) { //Bucle columnas
        if ((inicio + i) != j && (inicio + i) != k &&
            j != k) { // Evitar diagonal
          submatriz[i * nverts + j] = min(submatriz[i * nverts + k] + fila_K[j],
                                          submatriz[i * nverts + j]);
        }
      }
    }
  }

  t = MPI_Wtime() - t; // Calcular el tiempo transcurrido

  // Recoger resultados
  MPI_Gather(submatriz, tam_mat, MPI_INT, G.getMatriz(), tam_mat, MPI_INT, 0,
             MPI_COMM_WORLD);

  MPI_Finalize();

  if (rank == 0) {
    cout << endl
         << "EL Grafo con las distancias de los caminos más cortos es:" << endl
         << endl;
    G.imprime();
    cout << "Tiempo gastado= " << t << endl << endl;
  }

  delete[] fila_K;
  delete[] submatriz;
}
