#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <list>
#include <string>

using namespace std;

/*Tipo elemento que define el diccionario. T es el tipo de dato asociado a una
clave que no se repite (DNI p.ej.) y list<U> es una lista de datos (string p.ej)
asociados a la clave de tipo T. El diccionario está ordenado de menor a mayor
clave.
*/
template <class T, class U> struct data {
  T clave;
  list<U> info_asoci;
};

/*Comparador de datos. Ordena 2 registros de acuerdo a la clave de tipo T. Puede
usarse como un funtor.
*/
template <class T, class U>
bool operator<(const data<T, U> &d1, const data<T, U> &d2) {
  if (d1.clave < d2.clave)
    return true;
  return false;
}

/*Un diccionario es una lista de datos de los definidos anteriormente. Cuidado
porque se manejan listas de listas. Se añaden 2 funciones privadas que hacen más
facil la implementación de algunos operadores o funciones de la parte pública.
Copiar copia un diccioario en otro y borrar elimina todos los elementos de un
diccionario. La implementación de copiar puede hacerse usando iteradores o
directamente usando la función assign.
*/
template <class T, class U> class Diccionario {
private:
  list<data<T, U>> datos;

  void Copiar(const Diccionario<T, U> &D) {

    datos.assign(D.datos.begin(), D.datos.end());
  }

  void Borrar() { this->datos.erase(datos.begin(), datos.end()); }

public:
  /*
  Método para borrar una entrada a partir de su nombre
  */

  void Borrar(const T &clave) {
    typename list<data<T, U>>::iterator pos;
    if (Esta_Clave(clave, pos)) {
      this->datos.erase(pos);
    }
  }

  /*
  Método para obtener sinónimos de una palabra
  Para que haya sinónimos, las palabras tendrán que tener una misma definición
  */
  std::list<T> Sinonimos(const T &clave) {
    list<T> listaSinonimos;
    list<T> l = getInfo_Asoc(clave);

    typename list<T>::const_iterator it_s;

    for (it_s = l.begin(); it_s != l.end(); ++it_s) {

      typename list<data<T, U>>::const_iterator it;
      for (it = this->begin(); it != this->end(); ++it) {

        typename list<T>::const_iterator it_sin;

        for (it_sin = (*it).info_asoci.begin();
             it_sin != (*it).info_asoci.end(); ++it_sin) {

          if ((*it_sin) == (*it_s) && (*it).clave != clave) {
            listaSinonimos.insert(listaSinonimos.begin(), (*it).clave);
          }
        }
      }
    }
    return listaSinonimos;
  }

  /*
  Método para hacer una búsqueda de una palabra
  que contengan el string definido en sus definiciones
  */
  std::list<T> BusquedaPalabra(string contenido) {
    list<T> listaPalabras;
    typename list<T>::const_iterator it_s;

    typename list<data<T, U>>::const_iterator it;
    for (it = this->begin(); it != this->end(); ++it) {

      typename list<T>::const_iterator it_sin;

      for (it_sin = (*it).info_asoci.begin(); it_sin != (*it).info_asoci.end();
           ++it_sin) {

        if ((*it_sin).find(contenido) != std::string::npos) {
          listaPalabras.insert(listaPalabras.begin(), (*it).clave);
        }
      }
    }

    return listaPalabras;
  }

  /* Constructor por defecto*/
  Diccionario() : datos(list<data<T, U>>()) {}

  /* Constructor de copias*/
  Diccionario(const Diccionario &D) { Copiar(D); }

  /* Desstructor*/
  ~Diccionario() {}

  /* Operador de asignación*/
  Diccionario<T, U> &operator=(const Diccionario<T, U> &D) {
    if (this != &D) {
      Borrar();
      Copiar(D);
    }
    return *this;
  }

  /* Busca la clave p en el diccionario. Si está devuelve un iterador a
  dónde está clave. Si no está, devuelve end() y deja el iterador de salida
  apuntando al sitio dónde debería estar la clave
  */
  bool Esta_Clave(const T &p, typename list<data<T, U>>::iterator &it_out) {

    if (datos.size() > 0) {

      typename list<data<T, U>>::iterator it;

      for (it = datos.begin(); it != datos.end(); ++it) {
        if ((*it).clave == p) {
          it_out = it;
          return true;
        } else if ((*it).clave > p) {
          it_out = it;
          return false;
        }
      }

      it_out = it;
      return false;
    } else {
      it_out = datos.end();
      return false;
    }
  }

  /* Inserta un nuevo registro en el diccionario. Lo hace a través de la clave
  e inserta la lista con toda la información asociada a esa clave. Si el
  diccionario no estuviera ordenado habría que usar la función sort()
  */
  void Insertar(const T &clave, const list<U> &info) {

    typename list<data<T, U>>::iterator it;

    if (!Esta_Clave(clave, it)) {
      data<T, U> p;
      p.clave = clave;
      p.info_asoci = info;

      datos.insert(it, p);
    }
  }

  /*Añade una nueva informacion asocida a una clave que está en el diccionario.
  la nueva información se inserta al final de la lista de información.
   Si no esta la clave la inserta y añade la informacion asociada.
  */
  void AddSignificado_Palabra(const U &s, const T &p) {
    typename list<data<T, U>>::iterator it;

    if (!Esta_Clave(p, it)) {
      datos.insert(it, p);
    }

    // Insertamos el siginificado al final
    (*it).info_asoci.insert((*it).info_asoci.end(), s);
  }

  /* Devuelve la información (una lista) asociada a una clave p. Podrían
  haberse definido operator[] como
  data<T,U> & operator[](int pos){ return datos.at(pos);}
  const data<T,U> & operator[](int pos)const { return datos.at(pos);}
   */
  list<U> getInfo_Asoc(const T &p) {
    typename list<data<T, U>>::iterator it;

    if (!Esta_Clave(p, it)) {
      return list<U>();
    } else {
      return (*it).info_asoci;
    }
  }

  /*Devuelve el tamaño del diccionario*/
  int size() const { return datos.size(); }

  /*Funciones begin y end asociadas al diccionario*/
  typename list<data<T, U>>::iterator begin() { return datos.begin(); }
  typename list<data<T, U>>::iterator end() { return datos.end(); }

  typename list<data<T, U>>::const_iterator begin() const {
    return datos.begin();
  }

  typename list<data<T, U>>::const_iterator end() const { return datos.end(); }
};

#endif
