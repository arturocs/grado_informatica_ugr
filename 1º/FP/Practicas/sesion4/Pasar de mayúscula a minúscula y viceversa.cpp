#include <iostream>

using namespace std;

int main(){

char letra_original;
char letra_convertida;


	// Entrada de datos
	cout << "\nIntroduzca un caracter: ";
	cin >> letra_original;



if ((letra_original>='A')&&(letra_original<='Z')){
	cout << "\nEl caracter original es mayuscula";
	letra_convertida=letra_original+32;
	
}

else{
	if ((letra_original>='a')&&(letra_original<='z')){
	cout << "\nEl caracter original es minuscula";
	letra_convertida=letra_original-32;

}
	else{
	
	cout << "\nEl caracter original no es alfabetico";
	letra_convertida=letra_original;
		}
}



	cout << "\nEl caracter convertido es: " << letra_convertida ;

}
