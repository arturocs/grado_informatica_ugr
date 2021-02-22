#include <iostream>
#include <fstream>
#include <cstring>
#include "imagen.h"

using namespace std;

int main(int np, char * argumentos[]){

    Imagen im1, im2, imsalida;
 
	if (np==5){
    	if (!im1.leerImagen(argumentos[1])){
			cerr << endl;
			cerr << "Error leyendo imagen " << argumentos[1] << endl;
			cerr << endl;
			return 1;
    	}
    	
		if (!im2.leerImagen(argumentos[2])){
			cerr << endl;
			cerr << "Error leyendo imagen " << argumentos[1] << endl;
			cerr << endl;
			return 1;
    	}

    		imsalida = im1 + im2;

    	if ( argumentos[4]=="b"){	
    		imsalida.escribirImagen(argumentos[3], true);
    	}
    	else{
			if ( argumentos[4]=="t"){	
    			imsalida.escribirImagen(argumentos[3], false);
    		}
    		else{

    			cerr << endl;
				cerr << "Error en el ultimo argumento" << endl;
				cerr << endl;

    		}	
    	}
 }
	else{
		cout << endl;
		cout << "Numero de argumentos erroneo" << endl;
		cout << endl;
	}

}