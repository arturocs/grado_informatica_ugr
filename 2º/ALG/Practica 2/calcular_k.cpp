#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>


using namespace std;

template <class T> double media_vector(vector<T> v) {
 double k = 0;
 for (auto i : v)
   k += i;
 return k / v.size();
}


double orden(double f) {
 return f*f; // Orden del algoritmo
}


int main(int argc, char *argv[]) {
  fstream file;
 for (int i = 1; i <= argc; i++) {
   vector<double> vec;
   double fx, tx;
   file.open(argv[i]);
   while (file) {
     file >> fx >> tx;
     vec.push_back(tx / orden(fx));
   }
   cout << fixed << argv[i] <<" K: " << media_vector(vec) << endl;
   file.close();
 }
}
