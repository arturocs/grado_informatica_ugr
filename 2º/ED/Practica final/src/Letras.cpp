#include "Letras.h"
#include <algorithm>
Letras::Letras() {
  bolsa_letras = "";
  letras_admitidas = "";
  tamano = 0;
}

bool Letras::formable(string palabra) {
  bool resultado = false;
  string letras = letras_admitidas;
  size_t busqueda;
  int i = 0;
  do {
    if (palabra[i] == 0)
      break;

    busqueda = letras.find(palabra[i]);
    resultado = string::npos != busqueda;
    if (resultado) {
      letras.erase(busqueda, 1);
      i++;
    }
  } while (resultado);
  return resultado;
}

int Letras::puntuacion_palabra(string palabra) {
  int pt = 0;
  try {
    for (auto c : palabra) {
      pt += puntuaciones.at(c);
    }
  } catch (...) {
    return -1;
  }
  return pt;
}

bool Letras::cargar_datos(const char *fichero) {
  fstream puntos(fichero);
  bool abrible = puntos ? true : false;
  string linea;
  int veces = 0;
  if (abrible) {
    getline(puntos, linea); // quitar la primera linea
    if(linea.compare("#Letra	Cantidad	Puntos")==0){
        while (!puntos.eof()) {
            getline(puntos, linea);
            try {
                puntuaciones[linea[0]] = stoi(linea.substr(linea.rfind('\t')));
                veces = stoi(linea.substr(linea.find('\t'), linea.rfind('\t')));
                for (int i = 0; i < veces; i++) {
                    bolsa_letras += linea[0];
                }
            } catch (...) {
                return false;
            }
        }
    }
    else{
        return false;
    }
  }
  puntos.close();
  return abrible;
}

bool Letras::cargar_diccionario(const char *archivo_dicconario) {
  fstream f_diccionario(archivo_dicconario);
  string palabra;
  bool abrible = f_diccionario ? true : false;
  if (abrible)
    f_diccionario >> diccionario;
  f_diccionario.close();
  return abrible;
}

string Letras::mejor_palabra_tamano() {
  string mejor_palabra = "";
  vector<string> palabras_tam = diccionario.palabra_longitud(tamano);
  for (auto palabra : palabras_tam) {
    if (palabra.size() > mejor_palabra.size()) {
      if (formable(palabra))
        mejor_palabra = palabra;
    }
  }
  return mejor_palabra;
}

string Letras::mejor_palabra_puntos() {
  string mejor_palabra = "";
  int puntuacion = 0, mejor_puntuacion = 0;
  vector<string> palabras_tam = diccionario.palabra_longitud(tamano);
  for (auto palabra : palabras_tam) {
    if (formable(palabra)) {
      puntuacion = puntuacion_palabra(palabra);
      if (puntuacion > mejor_puntuacion) {
        mejor_palabra = palabra;
        mejor_puntuacion = puntuacion;
      }
    }
  }
  return mejor_palabra;
}


bool Letras::inicializar_letras(unsigned int n) {
  tamano = n;
  letras_admitidas="";
  string bolsa_letras_copia = bolsa_letras;
  if(bolsa_letras.size()>=n){
    srand(time(NULL));
    for (unsigned int i = 0; i < n; i++) {
        letras_admitidas += bolsa_letras_copia[rand() % (bolsa_letras_copia.size()-1)];
    }
    sort(letras_admitidas.begin(),letras_admitidas.end());
    return true;
  }else{
    return false;
  }
}

void Letras::de_nuevo(bool fuera, char modo, int tamano) {
  char c;
  cout << "¿Jugar de nuevo? [s/n]" << endl;
  cin >> c;
  if (c == 's') {
    jugar(fuera, modo, tamano);
  }
  else{
    cout << "Fin del juego"<< endl;
    exit(0);
  }
}

void Letras::mensajes_tamano(string palabra_introducida){
  string mejor_palabra;
  cout << "Tamaño de " << palabra_introducida << ": " << palabra_introducida.size() << endl << endl;
  mejor_palabra = mejor_palabra_tamano();
  cout << "Mi solución es: " << mejor_palabra << endl << "Tamaño: " << mejor_palabra.size() << endl;

  if (palabra_introducida.size() > mejor_palabra.size()) {
    cout << "Has ganado" << endl << endl;
  } else {
    if (palabra_introducida.size() == mejor_palabra.size())
      cout << "Empate" << endl << endl;
    else
      cout << "Has perdido" << endl << endl;
  }
}

void Letras::mensajes_puntuacion(string palabra_introducida){
  string mejor_palabra;
  int punt_1, punt_2;
  punt_1=puntuacion_palabra(palabra_introducida);
  cout << "Puntuación de " << palabra_introducida << ": " <<  punt_1 << endl<< endl;
  mejor_palabra = mejor_palabra_puntos();
  punt_2 = puntuacion_palabra(mejor_palabra);
  cout << "Mi solución es: " << mejor_palabra << endl << "Puntuación: " << punt_2 << endl;
  if (punt_1 > punt_2) {
    cout << "Has ganado" << endl << endl;
  } else {
    if (punt_1 == punt_2)
      cout << "Empate" << endl << endl;
    else
      cout << "Has perdido" << endl << endl;
  }
}

void Letras::jugar(bool fuera_diccionario, char modo,  int tamano) {
  string palabra_introducida;
  if(!inicializar_letras(tamano)){
      cout << "Tamaño superior al de la bolsa de letras, introduce un tamaño menor"<< endl;
      exit(-1);
  }

  cout << endl << "Letras seleccionadas: " << getLetras_admitidas() << endl << endl;

  if(modo=='p'){
    cout << endl << "Puntuaciones:" << getPuntuacion() << endl << endl;
  }

  cout << endl << "Dime tu palabra" << endl;
  cin >> palabra_introducida;

  if (formable(palabra_introducida)) {
    if (fuera_diccionario || diccionario.esta(palabra_introducida)) {
      if (modo == 'l') {
        mensajes_tamano(palabra_introducida);
      } else if (modo == 'p') {
        mensajes_puntuacion(palabra_introducida);
      } else {
          cout << "Modo de juego no válido" << endl;
      }
        de_nuevo(fuera_diccionario, modo, tamano);
      } else {
        cout << palabra_introducida << " no está en el diccionario" << endl;
        de_nuevo(fuera_diccionario, modo, tamano);
      }
    } else {
      cout << palabra_introducida << " no se puede generar con las letras dadas"
           << endl;
      de_nuevo(fuera_diccionario, modo, tamano);
    }
  }

string Letras::getLetras_admitidas(){
    string l_admitidas_mostrar="";
    for(auto s:letras_admitidas){
        l_admitidas_mostrar+=toupper(s);
        l_admitidas_mostrar+=" ";
    }
    return l_admitidas_mostrar;
}

string Letras::getPuntuacion(){
    string out="";

    for (auto a : puntuaciones){
        if(letras_admitidas.find(a.first)!=string::npos){
            out +=toupper(a.first);
            out +=": ";
            out +=to_string(a.second);
            out += a.first != letras_admitidas.back() ? ", " : "";
        }
    }
    return out;
}

string Letras::getBolsa_letras(){
    return bolsa_letras;
}

bool Letras::enDiccionario(string s){
    return diccionario.esta(s);
}
