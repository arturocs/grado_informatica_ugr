#include <iostream> 
using namespace std;  
   
int main(){    
   long long factorial;
	int n;
	double base;
	int exponente;
	double potencia;
	
	cout << "Introduzca un entero : " << endl;
	cin >> n;

	factorial = 1;
	for (int i = 2; i <= n ; i++)    
		factorial = factorial * i;

	cout << "El factorial de " << n << " es " << factorial<< endl;
	cout << "Introduce la base: "<< endl;
	cin >> base;
	cout << "Introduce el exponente: "<< endl;
	cin >> exponente;

	potencia = 1;
	for (int i = 1; i <= exponente; i++)    
		potencia = potencia * base;

	cout << "El resultado es: " << potencia << enld;

}
