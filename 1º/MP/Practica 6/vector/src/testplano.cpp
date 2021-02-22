#include <iostream>
#include <imagen.h>

using namespace std;

int main(){

    Imagen origen, plano;

	if (!origen.leerImagen("imagenes/giotexto.pgm")){
		cerr << "error leyendo imagenes/giotexto.pgm\n";
		return 1;
	}
	plano = origen.plano(6);
  	
	if (plano.escribirImagen("plano6.pgm", false)){

		cout << "plano6.pgm guardado correctamente \n";
		cout << "usa: display plano6.pgm para ver el resultado\n";
	}
	else { 
		cerr << "Error guardando la imagen plano6.pgm\n";
		return 1;
	}	
	
	plano = origen.plano(0);
	
	if (plano.escribirImagen("plano0.pgm", false)){
		cout << "plano0.pgm guardado correctamente \n";
		cout << "usa: display plano0.pgm para ver el resultado\n";
	} 
	else { 
		cerr << "Error guardando la imagen plano0.pgm\n";
		return 1;
	}	
	origen.destruir();
	plano.destruir();
	return 0;
}
