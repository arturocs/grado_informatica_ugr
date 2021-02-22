
#include <iostream>
#include <fstream>
#include <cstring>
#include "imagen.h"
#include "lista.h"

using namespace std;

int main(int np, char * argumentos[]){

    Imagen origen;
    Lista celdas;

	if (np==3){
    	if (!origen.leerImagen(argumentos[1])){
			cerr << endl;
			cerr << "Error leyendo imagen " << argumentos[1] << endl;
			cerr << endl;
			return 1;
    	}
    	
		if (celdas.leerLista(argumentos[2])){	
			if (origen.listaAArteASCII(celdas)){
				cout << endl;
				cout << "Exito en la conversion." << endl;
				cout << "Chequee los ficheros asciiX.txt" << endl;
				cout << endl;
			}
			else{
				cerr << endl;
				cerr << "La conversion no ha sido posible" << endl;
				cerr << endl;
			}
			celdas.destruir(); 
		}
		else{
			cerr << endl;
			cerr << "Error lista de grises " << argumentos[2] << endl;
			cerr << endl;
		}
		origen.destruir();
	}
	else{
		cout << endl;
		cout << "Numero de argumentos erroneo, ejecute el programa con la sintaxis: " << endl;
		cout << argumentos[0] << " 'imagen a convertir' 'fichero de caracteres' " << endl;
		cout << endl;
	}

}