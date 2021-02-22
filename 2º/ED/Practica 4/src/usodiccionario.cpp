#include "diccionario.h"
#include <iostream>

/*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre
listas de listas y otro sobre listas
*/
ostream &operator<<(ostream &os, const Diccionario<string, string> &D) {

  list<data<string, string>>::const_iterator it;

  for (it = D.begin(); it != D.end(); ++it) {

    list<string>::const_iterator it_s;

    os << endl << (*it).clave << endl << " informacion asociada:" << endl;
    for (it_s = (*it).info_asoci.begin(); it_s != (*it).info_asoci.end();
         ++it_s) {
      os << (*it_s) << endl;
    }
    os << "**************************************" << endl;
  }

  return os;
}

/*Operator >>. El formato de la entrada es:
     numero de claves en la primera linea
     clave-iésima retorno de carro
     numero de informaciones asociadas en la siguiente linea
     y en cada linea obviamente la informacion asociada
*/

istream &operator>>(istream &is, Diccionario<string, string> &D) {
  int np;
  is >> np;
  is.ignore(); // quitamos \n
  Diccionario<string, string> Daux;
  for (int i = 0; i < np; i++) {
    string clave;

    getline(is, clave);

    int ns;
    is >> ns;
    is.ignore(); // quitamos \n
    list<string> laux;
    for (int j = 0; j < ns; j++) {
      string s;
      getline(is, s);

      // cout<<"Significado leido "<<s<<endl;
      laux.insert(laux.end(), s);
    }
    Daux.Insertar(clave, laux);
  }
  D = Daux;
  return is;
}

/*Recorre la lista de información asociada a una clave y la imprime*/
void EscribeSigni(const list<string> &l) {
  list<string>::const_iterator it_s;

  for (it_s = l.begin(); it_s != l.end(); ++it_s) {
    cout << *it_s << endl;
  }
}

/*Lee un diccioario e imprime datos asociados a una clave.
Hay un fichero ejemplo de prueba: data.txt.Para lanzar el programa con ese
fichero se escribe:
                  ./usodiccionario < data.txt
*/
int main() {

  Diccionario<string, string> D;

  cout << "Introduce un diccionario" << endl;
  cin >> D;
  cout << D;

  string a;

  cout << "Introduce una palabra" << endl;
  cin >> a;

  list<string> l = D.getInfo_Asoc(a);

  if (l.size() > 0)
    EscribeSigni(l);

  cout << "Introduce una palabra a borrar" << endl;
  cin >> a;
  D.Borrar(a);

  cout << "Diccionario modificado:" << endl;
  cout << D;

  cout << "Sinonimos" << endl;
  l = D.Sinonimos("Programa");
  cout << "Sinonimos de Programa:" << endl;
  if (l.size() > 0)
    EscribeSigni(l);
  l = D.BusquedaPalabra("Plan");
  cout << "Palabras que contienen la cadena 'plan':" << endl;
  if (l.size() > 0)
    EscribeSigni(l);
}
