#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

/**
 *  @brief T.D.A. Diccionario
 *
 * Una instancia @e c del tipo de datos abstracto @c Diccionario es un objeto
 * que representa un conjunto de palabras ordenadas de forma alfabética
 *
 * Un ejemplo de su uso:
 * @include TestDiccionario.cpp
 *
 * @author Arturo Cortés Sánchez
 * @author Rubén Mogica Garrido
 * @date Diciembre 2018
 */

class Diccionario {
private:
  set<string> datos; /**< datos del diccionario */

public:
  /**
   * @brief Palabras de determinado tamaño
   * @param lon Tamaño máximo de las palabras
   * @return Devuelve un vector con las palabras de tamaño menor o igual que lon
   */
  vector<string> palabra_longitud(unsigned int lon) {
    vector<string> palabras_lon;
    for (auto d : datos)
      if (d.size() <= lon)
        palabras_lon.push_back(d);
    return palabras_lon;
  }

  /**
   * @brief Función size
   * @return Devuelve el tamaño del diccionario
   */
  int size() const { return datos.size(); }

  /**
   * @brief Busqueda de palabra en el diccionario
   * @param palabra palabra a buscar
   * @return Devuelve true si se encuentra la palabra, false en caso contrario
   */
  bool esta(string palabra) { return datos.find(palabra) != datos.end(); }

  /**
   * @brief Entrada de un Diccionario desde istream
   * @param is stream de entrada
   * @param D Diccionario que recibe los datos
   * @retval El Diccionario leído en D
   */

  friend istream &operator>>(istream &is, Diccionario &D) {
    string palabra;
    while (getline(is, palabra))
      D.datos.insert(palabra);
    return is;
  }

  /**
   * @brief Salida de un diccionario a ostream
   * @param os stream de salida
   * @param D Diccionario a escribir
   * @post Se obtiene en \a os los valores del diccionario
   */
  friend ostream &operator<<(ostream &os, const Diccionario &D) {
    for (auto i : D.datos)
      cout << i << endl;
    return os;
  }
};

typedef set<string>::iterator iterator;

#endif // DICCIONARIO_H
