#include "BolsaLetras.h"

BolsaLetras::BolsaLetras(){
	apariciones=map<char, int>();
}

map<char, pair<int,int> > BolsaLetras::generar_cantidad_y_puntuaciones() {
    map<char, pair<int,int>> resultado;
    multimap<int, char> apariciones2;
    int diff, i = 0, j=0;

    for (auto f : apariciones) {
      apariciones2.emplace(f.second, f.first);
    }

	auto rit = apariciones2.rbegin();
	diff = rit->first - apariciones2.begin()->first;

	while(diff>=20){
		diff>>=1;
		j++;
	}
	for (; rit != apariciones2.rend(); ++rit) {
      resultado[rit->second] =make_pair( (rit->first>>j)+1,(i - resultado[apariciones2.rbegin()->second].second)+1) ;
      if (distance(apariciones2.rbegin(), rit) % 2)
        i++;
    }
    return resultado;
}


bool BolsaLetras::leer_letras(char *archivo_letras) {
	fstream letras(archivo_letras);
	bool abrible = letras ? true : false;
	if (abrible) {
	  string s;
	  while (!letras.eof()) {
	    getline(letras, s);
	    apariciones[s[0]] = 0;
	  }
	}
	letras.close();
	return abrible;
}

bool BolsaLetras::leer_diccionario(char *archivo_diccionario) {
    fstream diccionario(archivo_diccionario);
    bool abrible = diccionario ? true : false;
    string s;
    if (abrible) {
      while (!diccionario.eof()) {
        getline(diccionario, s);
        for (auto c : s) {
          if (apariciones.end() != apariciones.find(c))
            apariciones[c]++; // solo si la letra está en el conjunto de letras
        }
      }
    }
    diccionario.close();
    return abrible;
}

bool BolsaLetras::escribir_frecuencias(char *archivo_frecuencias) {
    fstream frecuencias(archivo_frecuencias, fstream::out);
    bool abrible = frecuencias ? true : false;
    if (abrible) {
      float total = 0;
      for (auto a : apariciones) {
        total += a.second;
      }
      frecuencias << "#Letra" << '\t' << "FAbs." << '\t' << "Frel." << endl;
      for (auto a : apariciones) {
        frecuencias << a.first << "\t" << a.second << "\t" << a.second / total
                    << (a.first != apariciones.rbegin()->first ? "\n" : "");
      }
    }
    frecuencias.close();
    return abrible;
}

bool BolsaLetras::escribir_puntuaciones(char *archivo_puntuaciones) {
    fstream f_puntuaciones(archivo_puntuaciones, fstream::out);
    bool abrible = f_puntuaciones ? true : false;
    if (abrible) {
      map<char, pair<int,int> > puntuaciones = generar_cantidad_y_puntuaciones();
      f_puntuaciones << "#Letra\tCantidad\tPuntos" << endl;
      for (auto a : apariciones) {
        f_puntuaciones << a.first << '\t' << puntuaciones[a.first].first << '\t'
                       << puntuaciones[a.first].second
                       << (a.first != puntuaciones.rbegin()->first ? "\n" : "");
      }
    }
    f_puntuaciones.close();
    return abrible;
}
