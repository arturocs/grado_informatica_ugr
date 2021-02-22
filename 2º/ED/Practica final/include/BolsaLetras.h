#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <iostream>

using namespace std;

/**
 * @brief T.D.A. BolsaLetras
 *
 * Clase destinada a almacenar la información de las letras
 *
 *
 * Un ejemplo de su uso:
 * @include UsoBolsaLetras.cpp
 *
 * @author Arturo Cortés Sánchez
 * @author Rubén Mogica Garrido
 * @date Diciembre 2018
 */

class BolsaLetras {

private:
  map<char, int> apariciones;   /**< Map que almacena las letras junto a su número de apariciones*/
  
    /**
   * @brief Método para asignar una puntuación y una cantidad cada carácter, la puntuación se genera de 
   * forma inversamente proporcional al numero de apariciones del caracter, mientras que la cantidad se genera de forma proporcional
   * @return map con un par (cantidad, puntuación) asociado a cada letra
   */
  map<char, pair<int,int> > generar_cantidad_y_puntuaciones();

public:

  /**
   * @brief Constructor por defecto de la clase.
   */
	BolsaLetras();

  /**
   * @brief Método para leer letras de un archivo
   * @param archivo_letras nombre del archivo a leer
   * @return Devuelve true si se pudo leer el archivo, false en caso contrario
   */
  bool leer_letras(char *archivo_letras);

  /**
   * @brief Método para leer letras de un archivo diccionario
   * @param archivo_diccionario nombre del archivo a leer
   * @return Devuelve true si se pudo leer el archivo, false en caso contrario
   */  
  bool leer_diccionario(char *archivo_diccionario);
  /**
   * @brief Método para escribir las frecuencias en un archivo
   * @param archivo_frecuencias nombre del archivo a escribir
   * @return Devuelve true si se pudo escribir el archivo, false en caso contrario
   */   
  bool escribir_frecuencias(char *archivo_frecuencias);

  /**
   * @brief Método para escribir las puntuaciones en un archivo
   * @param archivo_puntuaciones nombre del archivo a escribir
   * @return Devuelve true si se pudo escribir el archivo, false en caso contrario
   */   
  bool escribir_puntuaciones(char *archivo_puntuaciones);
};