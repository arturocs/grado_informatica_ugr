#include <algorithm>
#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <omp.h>
#include <vector>

using namespace std;

const int UMBRAL_MS = 60;

template <class U> void insercion(vector<U> &a) {
  int i, j;
  for (i = 1; i < a.size(); i++) {
    j = i;
    while ((a[j] < a[j - 1]) && (j > 0)) {
      swap(a[j], a[j - 1]);
      j--;
    }
  }
}

template <class U> vector<U> fusion(const vector<U> &a, const vector<U> &b) {
  vector<U> ret;
  int i = 0, j = 0;
  while (i < a.size() && j < b.size()) {
    if (a[i] < b[j]) {
      ret.push_back(a[i]);
      i++;
    } else {
      ret.push_back(b[j]);
      j++;
    }
  }

  for (int k = j; k < b.size(); k++)
    ret.push_back(b[k]);
  for (int k = i; k < a.size(); k++)
    ret.push_back(a[k]);

  return ret;
}

template <class U> vector<U> mergesort_omp(const vector<U> &a) {
  int vsize = a.size() / UMBRAL_MS + 1;
  vector<U> vec[vsize];

  #pragma omp parallel for
  for (int i = 0; i < vsize - 1; i++) {
    vec[i].resize(UMBRAL_MS);
  }
  vec[vsize - 1].resize(a.size() % UMBRAL_MS);

  #pragma omp parallel for
  for (int i = 0; i < a.size(); i++)
    vec[i / UMBRAL_MS][i % UMBRAL_MS] = a[i];

  #pragma omp parallel for
  for (int i = 0; i < vsize; i++)
    insercion(vec[i]);

  while (vsize > 1) {
    int j=0, v2size = ceil(vsize / 2.0);
    vector<U> v2[v2size];
	#pragma omp parallel for
    for (int i = 0; i < vsize; i += 2) {
      auto tmp = (i != vsize - 1) ? fusion(vec[i], vec[i + 1]) : vec[i];
	#pragma omp critical
      {
        v2[j] = tmp;
        j++;
      }
    }

	#pragma omp parallel for
    for (int i = 0; i < v2size; i++)
      vec[i] = v2[i];

    vsize = v2size;
  }
  return vec[0];
}


int main(int argc, char* argv[]) {
  vector<int> vec;
  int nthreads = argc == 2 ? atoi(argv[1]) : 8;
  #ifdef _OPENMP
    omp_set_num_threads(nthreads);
	string filename = string("mergesort_omp_") + to_string(nthreads)+".dat";
  #else
  	string filename = "mergesort.dat";
  #endif

  ofstream f(filename,fstream::out);
  cout << "Guardando datos en "<< filename << endl;
  
  for (int j = 1; j < 500; j++) {
    for (int i = 0; i < 500; i++)
      vec.push_back(i);
    random_shuffle(vec.begin(), vec.end());
    auto t0 = chrono::high_resolution_clock::now();
    auto v = mergesort_omp(vec);
    auto tej = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - t0).count();
	if (!is_sorted(v.begin(), v.end()) || v.size() != vec.size())
      cerr << "Error de ordenacion" << endl;
    f << fixed << vec.size() << "\t" << tej << endl;
  }
  f.close();
}
