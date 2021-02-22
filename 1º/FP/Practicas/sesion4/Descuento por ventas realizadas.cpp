#include <iostream>

using namespace std;

int main(){

int ventas;
double importe;
double importe_final;

	// Entrada de datos
	cout << "\nIntroduzca el importe: ";
	cin >> importe;
	cout << "\nIntroduzca las ventas: ";
	cin >> ventas;



if ((importe>700)&&(ventas>100)){

	importe_final=importe*0.98;

	cout << "\nEl precio con el descuento aplicado es: " << importe_final;

	
}
else
	cout << "\nDescuento no aplicable";
}
