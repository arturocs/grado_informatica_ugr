#include<iostream>
using namespace std;
double Max(double un_valor, double otro_valor, double el_tercero){
	
	if (un_valor>otro_valor){
		if (un_valor>el_tercero)
			return un_valor;
		else 
			return el_tercero;
	}
	else{
		if (otro_valor>el_tercero)
			return otro_valor;
		else
			return el_tercero;
	}
}
int main(){
	
int entero1;
int entero2;
int entero3;
	
	cout << "\nIntroduzca un entero1: ";
	cin >> entero1;
	cout << "\nIntroduzca un entero2: ";
	cin >> entero2;
	cout << "\nIntroduzca un entero3: ";
	cin >> entero3;
	
	
cout << "El maximo de los tres valores es "	<< Max(entero1, entero2, entero3);
	
	
}
