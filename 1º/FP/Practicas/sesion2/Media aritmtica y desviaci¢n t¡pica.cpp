#include <iostream>
#include <cmath>
using namespace std;

int main(){

double altura1;
double altura2;
double altura3;
double media;
double desviacion;

	// Entrada de datos
	cout << "\nIntroduzca la altura 1: ";
	cin >> altura1;
	cout << "\nIntroduzca la altura 2: ";
	cin >> altura2;
	cout << "\nIntroduzca la altura 3: ";
	cin >> altura3;


	// Cómputos
	media = (altura1+altura2+altura3)/3;
	desviacion = sqrt((pow((altura1-media),2)+pow((altura2-media),2)+pow((altura3-media),2))/3);
	
	// Salida
	cout << "\nLa media aritmetica muestral es: " << media ;
	cout << "\nLa desviacion tipica es: " << desviacion ;

}
