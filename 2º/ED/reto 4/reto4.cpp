/*************************************************************/
/* Reto 4 - Por Rubén Mogica Garrido y Arturo Cortés Sánchez */
/*************************************************************/

#include "ArbolBinario.h"
#include <bitset>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

template <class Tbase>
void preorden(const ArbolBinario<Tbase> &a,
              const typename ArbolBinario<Tbase>::Nodo n) {
  if (n != 0) {
    cout << a.etiqueta(n) << ' ';
    preorden(a, a.izquierda(n));
    preorden(a, a.derecha(n));
  }
}

template <class Tbase>
void inorden(const ArbolBinario<Tbase> &a,
             const typename ArbolBinario<Tbase>::Nodo n) {
  if (n != 0) {
    inorden(a, a.izquierda(n));
    cout << a.etiqueta(n) << ' ';
    inorden(a, a.derecha(n));
  }
}

template <class Tbase>
void postorden(const ArbolBinario<Tbase> &a,
               const typename ArbolBinario<Tbase>::Nodo n) {
  if (n != 0) {
    postorden(a, a.izquierda(n));
    postorden(a, a.derecha(n));
    cout << a.etiqueta(n) << ' ';
  }
}

template <class Tbase>
int Altura(const ArbolBinario<Tbase> &a,
           const typename ArbolBinario<Tbase>::Nodo n) {
  int iz, de;
  if (n == 0)
    return -1;
  else {
    iz = Altura(a, a.izquierda(n));
    de = Altura(a, a.derecha(n));
    return 1 + (iz > de ? iz : de);
  }
}

template <class Tbase> void refleja(ArbolBinario<Tbase> &a) {
  ArbolBinario<Tbase> ai, ad;

  if (!a.empty()) {
    a.podar_izquierda(a.raiz(), ai);
    a.podar_derecha(a.raiz(), ad);
    refleja(ai);
    refleja(ad);
    a.insertar_izquierda(a.raiz(), ad);
    a.insertar_derecha(a.raiz(), ai);
  }
}

template <class Tbase>
void Esquema(const ArbolBinario<Tbase> &a,
             const typename ArbolBinario<Tbase>::Nodo n, string &pre) {
  int i;

  if (n == 0)
    cout << pre << "-- x" << endl;
  else {
    cout << pre << "-- " << a.etiqueta(n) << endl;
    if (a.derecha(n) != 0 || a.izquierda(n) != 0) { // Si no es una hoja
      pre += "   |";
      Esquema(a, a.derecha(n), pre);
      pre.replace(pre.size() - 4, 4, "    ");
      Esquema(a, a.izquierda(n), pre);
      pre.erase(pre.size() - 4, 4);
    }
  }
}

template <class Tbase> void Niveles(const ArbolBinario<Tbase> &a) {
  queue<typename ArbolBinario<Tbase>::Nodo> c;
  typename ArbolBinario<Tbase>::Nodo n;

  if (!a.empty()) {
    c.push(a.raiz());
    while (!c.empty()) {
      n = c.front();
      c.pop();
      cout << a.etiqueta(n) << ' ';
      if (a.izquierda(n) != 0)
        c.push(a.izquierda(n));
      if (a.derecha(n) != 0)
        c.push(a.derecha(n));
    }
  }
  cout << endl;
}

string descomprimir(string nodos, string centinelas) {
  string resultado = "", bitstring = "";

  for (auto c : centinelas) { //Convertir caracteres centinelas a un string de bits
    bitstring += bitset<8>(c).to_string();
  }
  for (int i = 0, j = 0; i < nodos.size(); i++, j++) {
    if (bitstring[j] == '0') { // 2 hijos
      resultado += string("n ") + nodos[i] + ' ';
    } else if (bitstring[j] == '1') {
      j++;
      if (bitstring[j] == '1') { // ningun hijo
        resultado += string("n ") + nodos[i] + " x x ";
      } else if (bitstring[j] == '0') { // 1 hijo
        resultado += string("n ") + nodos[i] + " x ";
      }
    }
  }
  return resultado;
}

string comprimir(string s) {
  string nodos = "", bitstring = "", resultado = "";

  for (int i = 0; i < s.size(); i++) {
    if (((s[i] >= '0') && (s[i] <= '9'))) { // Detectar nodos
      nodos += s[i];
      if (s[i + 2] == 'x') { // ver el numero de hijos
        if (s[i + 4] == 'x') {
          bitstring += "11"; // ningun hijo
        } else {
          bitstring += "10"; // 1 hijo
        }
      } else {
        bitstring += '0'; // 2 hijos
      }
    }
  }

  resultado += nodos + '\n';
  
  for (int i = 0; i < bitstring.size(); i += 8) { //Convertimos el string de bits a caracteres
    if (i + 8 <= bitstring.size()) {
      resultado += char(bitset<8>(bitstring.substr(i, i + 8)).to_ulong());
    } else {
      resultado += char((bitset<8>(bitstring.substr(i, bitstring.size()))
                         << (i + 8 - bitstring.size())).to_ulong());
    }
  }
  return resultado;
}

void cin_inverso(string s) { //introducir el string en el istream
  s.insert(0, "\n");
  for(int i=s.size();i>0;i--){
    cin.putback(s[i]);
  }
}

// Formato de entrada: n 1 n 2 n 4 x x n 5 x n 8 x x n 3 n 6 x x n 7 x x
//          El �rbol: n 1 n 2 n 4 n x x n 5 x n 8 x x n 3 n 6 x x n 7 x x
//          tiene el esquema:
//          -- 1
//             |-- 3
//             |   |-- 7
//             |    -- 6
//              -- 2
//                 |-- 5
//                 |   |-- 8
//                 |    -- x
//                  -- 4
//

int main(int argc, char *argv[]) {

  if (argc != 2 || (atoi(argv[1]) != 2 && atoi(argv[1]) != 1)) {
    cout << "Modo de uso: " << argv[0] << " [1 o 2]" << endl
         << "1 para leer un archivo de arbol (se recomienda usar " << argv[0]
         << " < archivo_arbol)" << endl
         << "2 para generar un archivo de arbol llamado 'archivo_arbol' a "
            "partir de uno introducido manualmente"
         << endl;
    exit(1);
  }

  string pre, nodos, string_arbol, centinelas = "";
  ArbolBinario<float> a;
  ofstream f;

  if (atoi(argv[1]) == 1) {
    cin >> nodos;
    cin >> centinelas;

    string_arbol = descomprimir(nodos, centinelas);
    cout << "Descomprimido: " << string_arbol << endl;
    cin_inverso(string_arbol);
  } else if (atoi(argv[1]) == 2) {

    cout << "Introduce el arbol en el formato:" << endl;
    cout << "n 1 n 2 n 4 x x n 5 x n 8 x x n 3 n 6 x x n 7 x x" << endl;
    getline(cin, string_arbol);

    f.open("archivo_arbol");
    f << comprimir(string_arbol);
    f.close();
    cin_inverso(string_arbol);
  } else {
    exit(1);
  }

  cin >> a;

  cout << "El arbol: " << a << " tiene recorridos:" << endl;

  cout << "Preorden: ";
  preorden(a, a.raiz());
  cout << endl;

  cout << "Inorden: ";
  inorden(a, a.raiz());
  cout << endl;

  cout << "Postorden: ";
  postorden(a, a.raiz());
  cout << endl;

  cout << "y la altura es: " << Altura(a, a.raiz()) << endl;
  cout << "Listado por niveles del arbol" << endl;
  Niveles(a);

  cout << "El arbol: " << a << " tiene el esquema:" << endl;
  pre = "";
  Esquema(a, a.raiz(), pre);

  refleja(a);

  cout << "Listado por niveles del arbol reflejado" << endl;
  Niveles(a);

  cout << "El arbol reflejado tiene el esquema:" << endl;
  pre = "";
  Esquema(a, a.raiz(), pre);
  return 0;
}
