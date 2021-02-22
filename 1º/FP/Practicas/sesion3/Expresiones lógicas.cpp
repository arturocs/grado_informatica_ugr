#include <iostream>
using namespace std;

int main(){
	
	short edad;
	char letra;
	short anio;
	
	bool booledad = (edad>18)||(edad<65);
	bool boolletra = (letra>='a')||(letra<='z');
	bool boolanio = (anio%4==0)&&(anio!=100)||(anio%400==0);

	cout << "\nIntroduzca un caracter: ";
	cin >> letra;
	cout << "\nIntroduzca una edad: ";
	cin >> edad;
	cout << "\nIntroduzca un año: ";
	cin >> anio;
	
	
	cout << "la edad esta en el rango indicado? "<< booledad << "\n";
	cout << "la letra es minuscula? "<< boolletra << "\n";
	cout << "el año es bisiesto? " << boolanio << "\n";

}
