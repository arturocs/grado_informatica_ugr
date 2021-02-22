#include "Graph.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <sys/time.h>

// CUDA runtime
//#include <cuda_runtime.h>
// helper functions and utilities to work with CUDA
//#include <helper_functions.h>
//#include <helper_cuda.h>


#define blocksize2d 32
#define blocksize blocksize2d * blocksize2d

using namespace std;

//**************************************************************************

double cpuSecond() {
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return ((double)tp.tv_sec + (double)tp.tv_usec * 1e-6);
}

//**************************************************************************

__global__ void floyd_kernel(int *M, const int nverts, const int k) {
  int ij = threadIdx.x + blockDim.x * blockIdx.x;
  if (ij < nverts * nverts) {
    int Mij = M[ij];
    int i = ij / nverts;
    int j = ij - i * nverts;
    if (i != j && i != k && j != k) {
      int Mikj = M[i * nverts + k] + M[k * nverts + j];
      Mij = (Mij > Mikj) ? Mikj : Mij;
      M[ij] = Mij;
    }
  }
}

__global__ void reduction(int *M, int *out, int n_elem) {

  extern __shared__ int sdata[];
  int ij = blockIdx.x * blockDim.x + threadIdx.x;
  if (ij < n_elem) {
    int n, m, tid = threadIdx.x;
    sdata[tid] = M[ij];
    __syncthreads();

    for (int s = blockDim.x / 2; s > 0; s >>= 1) {
      if (tid < s) {
        n = sdata[tid];
        m = sdata[tid + s];
        sdata[tid] = max(n, m);
      }
      __syncthreads();
    }
  }

  if (threadIdx.x == 0)
    out[blockIdx.x] = sdata[0];
}

__global__ void floyd_kernel_2d(int *M, const int nverts, const int k) {
  int j = threadIdx.x + blockDim.x * blockIdx.x;
  int i = threadIdx.y + blockDim.y * blockIdx.y;
  int index = i * nverts + j;
  if (i < nverts && j < nverts) {
    int Mij = M[index];
    if (i != j && i != k && j != k) {
      int Mikj = M[i * nverts + k] + M[k * nverts + j];
      Mij = (Mij > Mikj) ? Mikj : Mij;
      M[index] = Mij;
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cerr << "Sintaxis: " << argv[0] << " <archivo de grafo>" << endl;
    return (-1);
  }

  // This will pick the best possible CUDA capable device
  // int devID = findCudaDevice(argc, (const char **)argv);
  // Get GPU information

  int devID;
  cudaDeviceProp props;
  cudaError_t err;

  err = cudaGetDevice(&devID);

  if (err != cudaSuccess) {
    cout << "ERRORRR" << endl;
  }

  cudaGetDeviceProperties(&props, devID);

  printf("Device %d: \"%s\" with Compute %d.%d capability\n", devID, props.name,
         props.major, props.minor);

  Graph G;

  G.lee(argv[1]); // Read the Graph

  // cout << "EL Grafo de entrada es:"<<endl;

  const int nverts = G.vertices;
  const int niters = nverts;
  const int nverts2 = nverts * nverts;

  int *c_Out_M = new int[nverts2];
  int *c_Out_M_2d = new int[nverts2];
  int size = nverts2 * sizeof(int);
  int *d_In_M = NULL;
  int *d_In_M_2d = NULL;
  int *A = G.Get_Matrix();
  int *v;
  int *v_d;

  err = cudaMalloc((void **)&d_In_M, size);
  err = cudaMalloc((void **)&d_In_M_2d, size);

  if (err != cudaSuccess) {
    cout << "ERROR RESERVA" << endl;
  }

  // GPU phase

  err = cudaMemcpy(d_In_M, A, size, cudaMemcpyHostToDevice);
  if (err != cudaSuccess) {
    cout << "ERROR COPIA A GPU" << endl;
  }

  double t1 = cpuSecond();

  // kernel 1d

  for (int k = 0; k < niters; k++) {
    // printf("CUDA kernel launch \n");
    int threadsPerBlock = blocksize;
    int blocksPerGrid = (nverts2 + threadsPerBlock - 1) / threadsPerBlock;

    floyd_kernel<<<blocksPerGrid, threadsPerBlock>>>(d_In_M, nverts, k);
    err = cudaGetLastError();

    if (err != cudaSuccess) {
      fprintf(stderr, "Failed to launch kernel 1d!\n");
      exit(EXIT_FAILURE);
    }
  }

  cudaDeviceSynchronize();
  double Tgpu = cpuSecond() - t1;
  cudaMemcpy(c_Out_M, d_In_M, size, cudaMemcpyDeviceToHost);

  cout << "Tiempo gastado GPU 1D= " << Tgpu << endl << endl;

  // kernel 2d

  err = cudaMemcpy(d_In_M_2d, A, size, cudaMemcpyHostToDevice);
  if (err != cudaSuccess) {
    cout << "ERROR COPIA A GPU" << endl;
  }
  t1 = cpuSecond();
  for (int k = 0; k < niters; k++) {
    // printf("CUDA kernel launch \n");
    dim3 threadsPerBlock(blocksize2d, blocksize2d);
    dim3 blocksPerGrid(ceil((float)(nverts) / threadsPerBlock.x),
                       ceil((float)(nverts) / threadsPerBlock.y));

    floyd_kernel_2d<<<blocksPerGrid, threadsPerBlock>>>(d_In_M_2d, nverts, k);

    err = cudaGetLastError();
    if (err != cudaSuccess) {
      fprintf(stderr, "Failed to launch kernel 2d!\n");
      exit(EXIT_FAILURE);
    }
  }

  cudaDeviceSynchronize();
  double Tgpu2d = cpuSecond() - t1;

  cudaMemcpy(c_Out_M_2d, d_In_M_2d, size, cudaMemcpyDeviceToHost);

  cout << "Tiempo gastado GPU 2D= " << Tgpu2d << endl << endl;

  // CPU phase

  t1 = cpuSecond();
  // BUCLE PPAL DEL ALGORITMO
  int inj, in, kn;
  for (int k = 0; k < niters; k++) {
    kn = k * nverts;
    for (int i = 0; i < nverts; i++) {
      in = i * nverts;
      for (int j = 0; j < nverts; j++)
        if (i != j && i != k && j != k) {
          inj = in + j;
          A[inj] = min(A[in + k] + A[kn + j], A[inj]);
        }
    }
  }

  double t2 = cpuSecond() - t1;
  cout << "Tiempo gastado CPU= " << t2 << endl << endl;
  cout << "Ganancia= " << t2 / Tgpu << endl;
  cout << "Ganancia 2d= " << t2 / Tgpu2d << endl;
  for (int i = 0; i < nverts; i++)
    for (int j = 0; j < nverts; j++)
      if (abs(c_Out_M[i * nverts + j] - G.arista(i, j)) > 0)
        cout << "Error (" << i << "," << j << ")   " << c_Out_M[i * nverts + j]
             << "..." << G.arista(i, j) << endl;

  for (int i = 0; i < nverts; i++)
    for (int j = 0; j < nverts; j++)
      if (abs(c_Out_M_2d[i * nverts + j] - G.arista(i, j)) > 0)
        cout << "Error 2d (" << i << "," << j << ")   "
             << c_Out_M_2d[i * nverts + j] << "..." << G.arista(i, j) << endl;

  // Minimum vector  to be computed on GPU

  dim3 threadsPerBlock(blocksize2d, blocksize2d);
  dim3 blocksPerGrid(ceil((int)(nverts) / threadsPerBlock.x),
                     ceil((int)(nverts) / threadsPerBlock.y));

  v = (int *)malloc(blocksPerGrid.x * sizeof(int));
  cudaMalloc((void **)&v_d, sizeof(int) * blocksPerGrid.x);

  int smemSize = threadsPerBlock.x * sizeof(int);

  // Kernel launch to compute Minimum Vector

  err = cudaMemcpy(d_In_M_2d, c_Out_M_2d, size, cudaMemcpyHostToDevice);
  if (err != cudaSuccess) {
    cout << "ERROR COPIA A GPU" << endl;
  }

  reduction<<<blocksPerGrid, threadsPerBlock, smemSize>>>(d_In_M_2d, v_d,
                                                          nverts * nverts);

  cudaMemcpy(v, v_d, blocksPerGrid.x * sizeof(int), cudaMemcpyDeviceToHost);

  int max_gpu = 0;
  for (int i = 1; i < blocksPerGrid.x; i++) {
    max_gpu = max(max_gpu, v[i]);
  }

  cout << " Max on GPU =" << max_gpu << endl;

  cout << t2 << "\t"<< Tgpu << "\t" << t2 / Tgpu << "\t"  << Tgpu2d << "\t" << t2 / Tgpu2d << endl;
}
