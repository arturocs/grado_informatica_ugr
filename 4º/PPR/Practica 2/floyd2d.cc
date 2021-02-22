#include "Graph.h"
#include "mpi.h"
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>

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

  int N = G.vertices;
  int rank;
  int P;

  MPI_Init(&argc, &argv);            // Inicializamos los procesos
  MPI_Comm_size(MPI_COMM_WORLD, &P); // Obtenemos el numero total de procesos
  MPI_Comm_rank(MPI_COMM_WORLD,
                &rank); // Obtenemos el valor del identificador

  MPI_Bcast(&N, 1, MPI_INT, 0,
            MPI_COMM_WORLD); // Broadcast del numero de vertices

  MPI_Datatype MPI_BLOQUE; // Declaramos el tipo bloque cuadrado
  int raiz_P = sqrt(P);
  int tam = N / raiz_P;

  int rank_hor, rank_vert;      // Valor del identificador vertical y horizontal
  MPI_Comm comm_hor, comm_vert; // Comunicadores vertical y horizontal

  MPI_Comm_split(MPI_COMM_WORLD, rank / raiz_P, rank, &comm_hor);
  MPI_Comm_split(MPI_COMM_WORLD, rank % raiz_P, rank, &comm_vert);

  MPI_Comm_rank(comm_hor, &rank_hor);
  MPI_Comm_rank(comm_vert, &rank_vert);

  /*Creo buffer de envío para almacenar los datos empaquetados*/

  // int buf_envio[N][N];
  int *buf_envio = new int[N * N];

  // Empaquetado de los datos
  if (rank == 0) {
    /*Defino el tipo bloque cuadrado */
    MPI_Type_vector(tam, tam, N, MPI_INT, &MPI_BLOQUE);
    /* Creo el nuevo tipo */
    MPI_Type_commit(&MPI_BLOQUE);
    for (int i = 0, posicion = 0; i < P; i++) {
      /* Calculo la posicion de comienzo de cada submatriz */
      int filaP = i / raiz_P;
      int columnaP = i % raiz_P;
      int comienzo = columnaP * tam + i / raiz_P * tam * tam * raiz_P;
      MPI_Pack(&G.getMatriz()[comienzo], 1, MPI_BLOQUE, buf_envio,
               sizeof(int) * N * N, &posicion, MPI_COMM_WORLD);
    }
    /*Destruye la matriz local*/
    MPI_Type_free(&MPI_BLOQUE);
  }

  int *fila_K = new int[tam];
  int *buf_recep = new int[tam * tam];
  int *columna_K = new int[tam];

  // Repartir la matriz matriz entre los procesos
  MPI_Scatter(buf_envio, sizeof(int) * tam * tam, MPI_PACKED, buf_recep,
              tam * tam, MPI_INT, 0, MPI_COMM_WORLD);

  int ind_local_inicio_i = rank / raiz_P * tam; // Fila de inicio del proceso
  int ind_local_inicio_j = rank % raiz_P * tam; // Columna de inicio del proceso
  int ind_local_fin_i = (rank / raiz_P + 1) * tam; // Fila de final del proceso
  int ind_local_fin_j = (rank % raiz_P + 1) * tam; // Columna final del proceso

  double t = MPI_Wtime(); // Tiempo inicial

  for (int k = 0; k < N; k++) {
    if (k >= ind_local_inicio_i &&
        k < ind_local_fin_i) { // Comprobar si fila_K pertenece al proceso
      for (int a = 0; a < tam;
           a++) // Copiar la fila k % tam del buffer de recepcion a fila_k
        fila_K[a] = buf_recep[(k % tam) * tam + a];
    }
    if (k >= ind_local_inicio_j &&
        k < ind_local_fin_j) { // Comprobar si la columna K pertenece al proceso
      for (int a = 0; a < tam; a++) {
        columna_K[a] =
            buf_recep[a * tam + k % tam]; // Copiar la columna k%tam del buffer
                                          // de recepcion a columna_K
      }
    }

    MPI_Bcast(fila_K, tam, MPI_INT, k / tam, comm_vert); //Broadcast de la fila k 
    MPI_Bcast(columna_K, tam, MPI_INT, k / tam, comm_hor); //Broadcast de la columna_K
    for (int i = 0; i < tam; i++) { //Bucle filas
      for (int j = 0; j < tam; j++) { //Bucle columnas
        if (ind_local_inicio_i + i != ind_local_inicio_j + j &&
            ind_local_inicio_i + i != k && ind_local_inicio_j + j != k) { //Eviar la diagonal
          buf_recep[i * tam + j] =
              min(columna_K[i] + fila_K[j], buf_recep[i * tam + j]);
        }
      }
    }
  }

  t = MPI_Wtime() - t; //Calcular tiempo transcurrido

  //Recoger los resultados
  MPI_Gather(buf_recep, tam * tam, MPI_INT, buf_envio, sizeof(int) * tam * tam,
             MPI_PACKED, 0, MPI_COMM_WORLD);


  //Desempaquetar los datos recogidos
  if (rank == 0) {
    MPI_Type_vector(tam, tam, N, MPI_INT, &MPI_BLOQUE);
    MPI_Type_commit(&MPI_BLOQUE);
    for (int i = 0, posicion = 0; i < P; i++) {

      int filaP = i / raiz_P;
      int columnaP = i % raiz_P;
      int comienzo = columnaP * tam + filaP * tam * tam * raiz_P;
      MPI_Unpack(buf_envio, sizeof(int) * N * N, &posicion,
                 &G.getMatriz()[comienzo], 1, MPI_BLOQUE, MPI_COMM_WORLD);
    }
    MPI_Type_free(&MPI_BLOQUE);
  }

  MPI_Finalize();

  if (rank == 0) {
    cout << endl
         << "EL Grafo con las distancias de los caminos más cortos es:" << endl
         << endl;
    // G.imprime();
    cout << "Tiempo gastado= " << t << endl << endl;
  }

  delete[] fila_K;
  delete[] buf_recep;
  delete[] columna_K;
}
