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

if (altura1>=media)
	cout << "\nEl valor de la altura1 es mayor o igual que la media" ; 
else
	cout << "\nEl valor de la altura1 es menor que la media" ; 



if (altura2>=media)
	cout << "\nEl valor de la altura2 es mayor o igual que la media" ; 
else
	cout << "\nEl valor de la altura2 es menor que la media" ; 


if (altura3>=media)
	cout << "\nEl valor de la altura3 es mayor o igual que la media" ; 
else
	cout << "\nEl valor de la altura3 es menor que la media" ; 

}
