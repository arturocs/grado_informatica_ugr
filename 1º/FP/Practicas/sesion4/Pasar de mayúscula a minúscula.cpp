#include <iostream>

using namespace std;

int main(){

char letra_original;
char letra_convertida;
int DIFERENCIA = ('A'-'a');

	// Entrada de datos
	cout << "\nIntroduzca un caracter: ";
	cin >> letra_original;
	
		cout << DIFERENCIA;

if ((letra_original>='A')&&(letra_original<='Z'))
		letra_convertida=letra_original-DIFERENCIA;
else
letra_convertida=letra_original;


if ((letra_original>='a')&&(letra_original<='z'))
		letra_convertida=letra_original+DIFERENCIA;



 cout << "\nEl caracter convertido es: " << letra_convertida ;

}
