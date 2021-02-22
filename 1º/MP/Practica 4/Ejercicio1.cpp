//lee imagenes/gio.txt y la convierte en ascii con los caracteres "@%#*+=-:. "
#include<iostream>
#include<imagen.h>
#include <fstream> 

using namespace std;


const int MAXLONG = 1000000;

void leelinea(char *s){
	do{
		cin.getline(s, MAXLONG);
	} while (s[0]=='\0');
}

int main(){
//	char grises[MAXLONG];
	char arteASCII[MAXLONG]; 
	char nombreImagen[MAXLONG];
	char s[1000];
	int cuantos;
//	int aux;
	ifstream fe;
	
	Imagen origen;

	cout << "Introduzca nombre de la imagen: ";
	leelinea(nombreImagen);

    // Leer la imagen gio.txt
	if (!origen.leerImagen(nombreImagen)){
		cerr << "error al ler imagen" << nombreImagen << endl;
		return 1;
 	}
	

	fe.open("grises.txt");	
	if(fe) {
	fe.getline(s, 999, '\n');
	fe >> cuantos;
		for(int i=0; i<cuantos; i++) {
			fe >> s;
			cout << "\nLa cadena" << i << " es: " << s << endl;
                                         
    			cout << "\nLa imagen en arte ASCII es:  ";
    			if(origen.aArteASCII(s, arteASCII, MAXLONG-1))
       			cout << arteASCII << endl;
   		 	else
      	 		cout << "La trasformacion no ha sido posible" << endl;  
		}
		fe.close();
	}
	else 
		cerr << "El fichero grises.txt ha dado un error de acceso " << endl;  
	
}
