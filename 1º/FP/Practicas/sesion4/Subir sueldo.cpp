#include <iostream>

using namespace std;

int main(){

int edad;
double salario_inicial;
double salario_final;


	// Entrada de datos
	cout << "\nIntroduzca la edad: ";
	cin >> edad;
	cout << "\nIntroduzca el salario: ";
	cin >> salario_inicial;

if (salario_inicial<300&&edad>65){
	
	salario_final=salario_inicial*1.05;
	
	cout << "\nEl salario subido a: " << salario_final; 
}
else
	cout << "\nNo es aplicable la subida" ; 


}
