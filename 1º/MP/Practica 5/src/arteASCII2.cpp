
#include <iostream>
#include <fstream>
#include <cstring>
#include "imagen.h"
#include "lista.h"

using namespace std;
const int MAXLONG = 1000;

void leelinea(char *s){
	do{
		cin.getline(s, MAXLONG);
	} while (s[0]=='\0');
}

int main(){
    char ficheroGrises[MAXLONG];
    char ficheroImagen[MAXLONG];
    Imagen origen;
    Lista celdas;

	cout << "Introduzca nombre de la imagen: ";
	leelinea(ficheroImagen);

    if (!origen.leerImagen(ficheroImagen)){
		cerr << "Error leyendo imagen " << ficheroImagen << endl;
		return 1;
    }
	
	cout << "Introduzca el nombre de fichero con el conjunto de caracteres para realizar la conversion: ";
	leelinea(ficheroGrises);
	
	if (celdas.leerLista(ficheroGrises)){	
		if (origen.listaAArteASCII(celdas)){
			cout << "Exito en la conversion." << endl;
			cout << "Chequee los ficheros asciiX.txt" << endl;
			cout << endl;
		}
		else{
			cerr << "La conversion no ha sido posible" << endl;
			cerr << endl;
		}
		celdas.destruir(); 
	}
	else{
		cerr << "Error lista de grises " << ficheroGrises << endl;
	}
    origen.destruir();
}
