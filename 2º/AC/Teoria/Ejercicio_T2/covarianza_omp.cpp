#include <algorithm>
#include <chrono>
#include <iostream>
#include <omp.h>
#include <vector>
#include <fstream>

using namespace std;

template <class T> double covarianza(vector<T> a, vector<T> b) {
  T sum_a = 0, sum_b = 0, sum_ab = 0;
  double tam = min(a.size(), b.size());

  #pragma omp parallel for reduction(+ : sum_ab)
  for (int i = 0; i < (int)tam; i++)
    sum_ab += a[i] * b[i];

  #pragma omp parallel for reduction(+ : sum_b)
  for (int i = 0; i < (int)tam; i++)
    sum_b += b[i];

  #pragma omp parallel for reduction(+ : sum_a)
  for (int i = 0; i < (int)tam; i++)
    sum_a += a[i];

  return (sum_ab / tam) - (sum_a / tam) * (sum_b / tam);
}

int main(int argc, char* argv[]) {
  vector<int> vec1, vec2;
  int nthreads = argc == 2 ? atoi(argv[1]) : 8;
  #ifdef _OPENMP
  	omp_set_num_threads(nthreads);
  	string filename = string("covarianza_omp_") + to_string(nthreads)+".dat";
  #else
  	string filename = "covarianza.dat";
  #endif

  ofstream f(filename,fstream::out);
  cout << "Guardando datos en "<< filename << endl;
  for (int j = 1; j < 500; j++) {
    for (int i = 0; i < 500; i++) {
      vec1.push_back(i);
      vec2.push_back(i);
    }
    random_shuffle(vec1.begin(), vec1.end());
    random_shuffle(vec2.begin(), vec2.end());
    auto t0 = chrono::high_resolution_clock::now();
    covarianza(vec1, vec2);
    auto tej = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - t0).count();
    f << fixed << vec1.size() << "\t" << tej << endl;
  }
}
