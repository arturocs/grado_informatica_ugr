/* ******************************************************************** */
/*               Algoritmo Branch-And-Bound Paralelo                    */
/* ******************************************************************** */
#include "libbb.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <mpi.h>

using namespace std;

unsigned int NCIUDADES;
int id, P;

/* ******************************************************************** */

// Tipos de mensajes que se envían los procesos
const int PETICION = 0;
const int NODOS = 1;
const int MENSAJE_TOKEN = 2;
const int FIN = 3;

// Estados en los que se puede encontrar un proceso
const int ACTIVO = 0;
const int PASIVO = 1;

// Colores que pueden tener tanto los procesos como el token
const int BLANCO = 0;
const int NEGRO = 1;

int estado;          // Estado del proceso {ACTIVO, PASIVO}
int mi_color;        // Color del proceso {BLANCO, NEGRO}
int color_token;     // Color del token la última vez que estaba en poder del
                     // proceso
bool token_presente; // Indica si el proceso posee el token
int anterior;        // Identificador del anterior proceso
int siguiente;       // Identificador del siguiente proceso

MPI_Comm comunicadorCarga;
MPI_Comm comunicadorCota;
/* ********************************************************************* */

void Difusion_Cota_Superior(int &U, bool &nueva_U) {
  bool difundir_cs_local=nueva_U; // Indica si el proceso puede difundir su cota
                          // inferior local
  bool pendiente_retorno_cs; // Indica si el proceso est� esperando a recibir la
                             // cota inferior de otro proceso
  int hay_mensajes, cotatmp;
  MPI_Status status; // Datos del mensaje
  if (difundir_cs_local && !pendiente_retorno_cs) {
    // Enviar valor local de cs al proceso(id + 1) % P;
    MPI_Send(&U, 1, MPI_INT, siguiente, id, comunicadorCota);
    pendiente_retorno_cs = true;
    difundir_cs_local = false;
  }
  // Sondear si hay mensajes de cota superior pendientes;
  MPI_Iprobe(anterior, MPI_ANY_TAG, comunicadorCota, &hay_mensajes, &status);
  while (hay_mensajes) {
    // Recibir mensaje con valor de cota superior desde el proceso(id - 1 + P) %
    // P;
    MPI_Recv(&cotatmp, 1, MPI_INT, anterior, MPI_ANY_TAG, comunicadorCota,
             &status);

    // Actualizar valor local de cota superior;
    if (cotatmp < U) {
      U = cotatmp;
      nueva_U = true;
    }

    // origen mensaje == el mismo
    if (status.MPI_TAG == id && difundir_cs_local) {
      // Enviar valor local de cs al proceso(id + 1) % P;
      MPI_Send(&U, 1, MPI_INT, siguiente, id, comunicadorCota);
      pendiente_retorno_cs = true;
      difundir_cs_local = false;
    } else if (status.MPI_TAG == id && !difundir_cs_local)
      pendiente_retorno_cs = false;
    else { // origen mensaje == otro proceso
      // Reenviar mensaje al proceso(id + 1) % P;
      MPI_Send(&U, 1, MPI_INT, siguiente, status.MPI_TAG, comunicadorCota);
    }
    // Sondear si hay mensajes de cota superior pendientes;
    MPI_Iprobe(anterior, MPI_ANY_TAG, comunicadorCota, &hay_mensajes, &status);
  }
}

void Equilibrado_Carga(tPila &pila, bool &fin, tNodo &solucion) {

  MPI_Status status; // Datos del mensaje
  int solicitante;   // Id del proceso que solicita trabajo
  int hay_mensajes;  // Hay o no mensajes pendientes
  int tam_pila;      // Tamaño de pila que se envía
  tNodo soltmp;      // Solución auxiliar

  mi_color = BLANCO;
  if (pila.vacia()) { // el proceso no tiene trabajo, pide a otros procesos
    // Enviar peticion de trabajo al proceso (id+1)%P (siguiente);
    MPI_Send(&id, 1, MPI_INT, siguiente, PETICION, comunicadorCarga);
    while (pila.vacia() && !fin) {
      // Esperar mensaje de otro proceso;
      MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, comunicadorCarga, &status);
      switch (status.MPI_TAG) {
      // case TRABAJO_AGOTADO:
      case PETICION: // Peticion de trabajo
        // Recibir mensaje de peticion de trabajo;
        MPI_Recv(&solicitante, 1, MPI_INT, anterior, PETICION, comunicadorCarga,
                 &status);
        // Reenviar peticion de trabajo al proceso(id + 1) % P (siguiente);
        MPI_Send(&solicitante, 1, MPI_INT, siguiente, PETICION,
                 comunicadorCarga);
        // Peticion devuelta
        if (solicitante == id) { // El mensaje ha dado la vuelta al anillo y ha
                                 // vuelto al solicitante original
          // Iniciar deteccion de posible situacion de fin;

          estado = PASIVO;
          // Cuando un proceso ademas tiene el token, se reinicia la deteccion
          // de fin
          if (token_presente) {
            if (id == 0) {
              color_token = BLANCO;
            } else if (mi_color == NEGRO)
              color_token = NEGRO;
            // Enviar MENSAJE_TOKEN a P(id - 1);
            MPI_Send(NULL, 0, MPI_INT, anterior, MENSAJE_TOKEN,
                     comunicadorCarga);
            mi_color = BLANCO;
            token_presente = false;
          }
        }
        break;
      case MENSAJE_TOKEN:
        // Recibir Mensajes de Petición pendientes
        MPI_Recv(NULL, 0, MPI_INT, siguiente, MENSAJE_TOKEN, comunicadorCarga,
                 &status);
        token_presente = true;
        if (estado == PASIVO) {

          if (id == 0 && mi_color == BLANCO && color_token == BLANCO) {
            // TERMINACION DETECTADA;
            fin = true;
            // Enviamos el mensaje de finalizacion al proceso siguiente
            MPI_Send(solucion.datos, 2 * NCIUDADES, MPI_INT, siguiente, FIN,
                     comunicadorCarga);
            // Recibir mensaje de finalizacion del anterior
            MPI_Recv(soltmp.datos, 2 * NCIUDADES, MPI_INT, anterior, FIN,
                     comunicadorCarga, &status);

            // Si la solucion local que tiene el proceso es mejor que la
            // solucion final la reemplazamos
            if (soltmp.ci() < solucion.ci())
              CopiaNodo(&soltmp, &solucion);

          } else {
            if (id == 0)
              color_token = BLANCO;
            else if (mi_color == NEGRO)
              color_token = NEGRO;

            // Enviar MENSAJE_TOKEN a P(id - 1);
            MPI_Send(NULL, 0, MPI_INT, anterior, MENSAJE_TOKEN,
                     comunicadorCarga);
            mi_color = BLANCO;
            token_presente = false;
          }
        }
        break;
      // Trabajo agotado en todos los procesos
      case FIN:
        fin = true;
        // Recibir mensaje final del proceso anterior
        MPI_Recv(soltmp.datos, 2 * NCIUDADES, MPI_INT, anterior, FIN,
                 comunicadorCarga, &status);
        // Enviamos la mejor solucion
        MPI_Send(soltmp.ci() < solucion.ci() ? soltmp.datos : solucion.datos,
                 2 * NCIUDADES, MPI_INT, siguiente, FIN, comunicadorCarga);
        break;

      case NODOS: // Resultado de una peticion de trabajo
        // Recibir nodos del proceso donante
        int nelem;
        MPI_Get_count(&status, MPI_INT, &nelem);
        int tmp[nelem];
        MPI_Recv(tmp, nelem, MPI_INT, status.MPI_SOURCE, NODOS,
                 comunicadorCarga, &status);

        // Almacenar nodos recibidos en la pila;
        for (int i = 0; i < nelem; i++)
          pila.nodos[i] = tmp[i];
        pila.tope = nelem;
        estado = ACTIVO;
        break;
      }
    }
  }

  if (!fin) { // el proceso tiene nodos para trabajar
    // Sondear si hay mensajes pendientes de otros procesos;
    MPI_Iprobe(MPI_ANY_SOURCE, MPI_ANY_TAG, comunicadorCarga, &hay_mensajes,
               &status);
    while (hay_mensajes > 0) { // atiende peticiones mientras haya mensajes
      // Recibir mensaje de peticion de trabajo;
      if (status.MPI_TAG == PETICION) { // Le han pedido nodos al proceso

        MPI_Recv(&solicitante, 1, MPI_INT, anterior, PETICION, comunicadorCarga,
                 &status);
        if (pila.tamanio() >= 2) {
          // Si tenemos dos o mas nodos, podemos enviar la mitad
          // Enviar nodos al proceso solicitante;
          tPila pilatmp;
          pila.divide(pilatmp);
          MPI_Send(pilatmp.nodos, pilatmp.tope, MPI_INT, solicitante, NODOS,
                   comunicadorCarga);

          if (id < solicitante) {
            mi_color = NEGRO;
          }
        } else { // no tenemos suficientes nodos como para ceder
          // Reenviar peticion de trabajo al proceso(id + 1) % P;
          MPI_Send(&solicitante, 1, MPI_INT, siguiente, PETICION,
                   comunicadorCarga);
        }
      } else if (status.MPI_TAG == MENSAJE_TOKEN) {

        // Recibir MENSAJE_TOKEN de siguiente
        MPI_Recv(NULL, 0, MPI_INT, siguiente, MENSAJE_TOKEN, comunicadorCarga,
                 &status);
        token_presente = true;
      }

      // Sondear si hay mensajes pendientes de otros procesos;
      MPI_Iprobe(MPI_ANY_SOURCE, MPI_ANY_TAG, comunicadorCarga, &hay_mensajes,
                 &status);
    }
  }
}

int main(int argc, char **argv) {

  MPI::Init(argc, argv);
  MPI_Comm_size(MPI_COMM_WORLD, &P);
  MPI_Comm_rank(MPI_COMM_WORLD, &id);
  MPI_Comm_dup(MPI_COMM_WORLD, &comunicadorCarga);
  MPI_Comm_dup(MPI_COMM_WORLD, &comunicadorCota);
  switch (argc) {
  case 3:
    NCIUDADES = atoi(argv[1]);
    break;
  default:
    if (id == 0)
      cerr << "La sintaxis es: bbseq <tamaño> <archivo>" << endl;
    exit(-1);
    break;
  }

  int **tsp0 = reservarMatrizCuadrada(NCIUDADES);
  tNodo nodo,   // nodo a explorar
      lnodo,    // hijo izquierdo
      rnodo,    // hijo derecho
      solucion; // mejor solucion
  bool fin,     // condicion de fin
      nueva_U;  // hay nuevo valor de cota superior
  int U;        // valor de cota superior
  int iteraciones = 0;
  tPila pila; // pila de nodos a explorar

  U = INFINITO;                // inicializa cota superior
  InicNodo(&nodo);             // inicializa estructura nodo
  anterior = (id - 1 + P) % P; // inicializa proceso anterior
  siguiente = (id + 1) % P;    // inicializa proceso siguiente

  if (id == 0) {
    token_presente = true;
    LeerMatriz(argv[2], tsp0);
    MPI_Bcast(&tsp0[0][0], NCIUDADES * NCIUDADES, MPI_INT, 0, MPI_COMM_WORLD);

  } else {
    token_presente = false;
    MPI_Bcast(&tsp0[0][0], NCIUDADES * NCIUDADES, MPI_INT, 0, MPI_COMM_WORLD);
    Equilibrado_Carga(pila, fin, solucion);
    if (!fin)
      pila.pop(nodo);
  }
  fin = Inconsistente(tsp0);
  double t = MPI_Wtime();
  while (!fin) { // ciclo de Branch&Bound
    Ramifica(&nodo, &lnodo, &rnodo, tsp0);
    nueva_U = false;

    if (Solucion(&rnodo)) {
      if (rnodo.ci() < U) { // se ha encontrado una solucion mejor
        U = rnodo.ci();     // actualiza cota superior
        nueva_U = true;
        CopiaNodo(&rnodo, &solucion);
      }
    } else {                //  no es un nodo solucion
      if (rnodo.ci() < U) { //  cota inferior menor que cota superior
        if (!pila.push(rnodo)) {
          printf("Error: pila agotada\n");
          liberarMatriz(tsp0);
          exit(1);
        }
      }
    }

    if (Solucion(&lnodo)) {
      if (lnodo.ci() < U) { // se ha encontrado una solucion mejor
        U = lnodo.ci();     // actualiza cota superior
        nueva_U = true;
        CopiaNodo(&lnodo, &solucion);
      }
    } else {                // no es nodo solucion
      if (lnodo.ci() < U) { // cota inferior menor que cota superior
        if (!pila.push(lnodo)) {
          printf("Error: pila agotada\n");
          liberarMatriz(tsp0);
          exit(1);
        }
      }
    }
    
//    Difusion_Cota_Superior(U, nueva_U);

    if (nueva_U)
      pila.acotar(U);

    Equilibrado_Carga(pila, fin, solucion);

    if (!fin)
      pila.pop(nodo);

    iteraciones++;
  }
  t = MPI_Wtime() - t;
  MPI::Finalize();
  if (id == 0) {
    printf("Solucion: \n");
    EscribeNodo(&solucion);
  }
  cout << fixed << id << " Tiempo gastado= " << t << endl;
  cout << id << " Numero de iteraciones = " << iteraciones << endl << endl;
  cout << id << " Tiempo por nodo explotado = " << t / iteraciones << endl
       << endl;
  liberarMatriz(tsp0);

  exit(0);
}
