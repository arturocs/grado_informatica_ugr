#ifndef LETRAS_H
#define LETRAS_H

#include "Diccionario.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <map>

using namespace std;

/**
 *  @brief T.D.A. Letras
 *
 * Clase destinada a la ejecución del juego de las letras
 *
 * Un ejemplo de su uso:
 * @include Juego.cpp
 *
 * @author Arturo Cortés Sánchez
 * @author Rubén Mogica Garrido
 * @date Diciembre 2018
 */

class Letras {
private:
  int tamano; /**< Tamaño máximo de las palabras */
  map<char, int> puntuaciones;        /**< Puntuaciones asociadas a cada letra */
  string bolsa_letras;     /**< Lista de las letras disponibles */
  string letras_admitidas; /**< Lista de letras admitidas */
  Diccionario diccionario; /**< Diccionario de palabras de la clase @c Diccionario */

public:
  /**
   * @brief Constructor por defecto de la clase.
   */
  Letras();

  /**
   * @brief Método para cargar puntuaciones, cantidades y letras de un fichero
   * @param fichero nombre del fichero a leer
   * @return Devuelve true si se pudo cargar correctamente, false en caso de
   * error
   */

  bool cargar_datos(const char *fichero);

  /**
  * @brief Método para cargar un diccionario de un archivo
  * @param archivo_dicconario nombre del fichero a leer
  * @return Devuelve true si se pudo cargar correctamente, false en caso de
  error
  */
  bool cargar_diccionario(const char *archivo_dicconario);


  /**
  * @brief Método que contiene la lógica del juego
  * @param fuera_diccionario booleano para permitir o no permitir palabras
  * @param modo modo de juego a iniciar
  * @param tamano Tamaño de letras con las que jugar
  */
  void jugar(bool fuera_diccionario, char modo, int tamano);

  /**
   * @brief Método para comprobar si se puede formar una palabra
   * @param palabra palabra a formar
   * @return Devuelve true si se puede formar, false en caso contrario
   */
  bool formable(string palabra);

  /**
   * @brief Método para comprobar puntuacion de una palabra
   * @param palabra palabra a comprobar
   * @return Devuelve un entero con el valor total de la palabra
   */
  int puntuacion_palabra(string palabra);

  /**
  * @brief Método que se encarga de mostrar la mayoria de mensajes en el juego por tamaños
  * @param palabra_introducida palabra introducida por el usuario
  */
  void mensajes_tamano(string palabra_introducida);

  /**
  * @brief Método que se encarga de mostrar la mayoria de mensajes en el juego por puntuaciones
  * @param palabra_introducida palabra introducida por el usuario
  */
  void mensajes_puntuacion(string palabra_introducida);

  /**
  * @brief Método que reinicia el juego
  * @param fuera booleano para permitir o no permitir palabras de fuera del diccionario
  * @param modo modo de juego
  * @param tamano Tamaño de letras con las que jugar
  */
  void de_nuevo(bool fuera, char modo, int tamano);

  /**
   * @brief Inicializa las letras de forma aleatoria
   * @param n numero de letras a incluir
   * @return String con las letras seleccionadas
   */
  bool inicializar_letras(unsigned int n);

  /**
   * @brief Método para jugar con limite de tamaño por palabra
   * @return Devuelve un string con la mejor palabra encontrada
   */
  string mejor_palabra_tamano();

  /**
   * @brief Método para jugar buscando la palabra con más puntos
   * @return Devuelve un string con la mejor palabra encontrada en base a los
   * puntos
   */
  string mejor_palabra_puntos();

  /**
   * @brief Método para devolver las letras admitidas en mayúscula
   * @return Devuelve un string con las letras admitidas en mayúsculas
   */  

  string getLetras_admitidas();

  /**
   * @brief Getter de la bolsa de letras
   * @return Devuelve un string con la bolsa de letras
   */  

  string getBolsa_letras();


  /**
   * @brief Método para obtener cada letra con su puntuación
   * @return Devuelve un string con cada letra acompañada de su puntuación
   */  

  string getPuntuacion();

  /**
   * @brief Método para comprobar si existe una palabra en un diccionario
   * @param s palabra a comprobar
   * @return Devuelve true en caso de estar en el diccionario, false en caso contrario
   */  


  bool enDiccionario(string s);
};
#endif // LETRAS_H
