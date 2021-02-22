#include <iostream>
#include <fstream>
using namespace std;

int main(){

short sucursal;
char producto;
int unidades;
int sumasucursal_1=0;
int sumasucursal_2=0;
int sumasucursal_3=0;

do{

cout << "introduzca la sucursal" << endl;
cin >> sucursal;
cout << "introduzca el producto" << endl;
cin >> producto;
cout << "introduzca las unidades" << endl;
cin >> unidades;

if(sucursal==1)
	sumasucursal_1=sumasucursal_1+unidades;
if(sucursal==2)
	sumasucursal_2=sumasucursal_2+unidades;
if(sucursal==3)
	sumasucursal_3=sumasucursal_3+unidades;

}while(sucursal!=-1);

if (sumasucursal_1>=sumasucursal_2){

	if (sumasucursal_1>=sumasucursal_3)
		cout << "La sucursal 1 es la que mas ventas ha tenido con " << sumasucursal_1 << endl;
	else 
		cout << "La sucursal 3 es la que mas ventas ha tenido con " << sumasucursal_3 << endl;
	}
	else{
	
	if (sumasucursal_2>=sumasucursal_3)
		cout << "La sucursal 2 es la que mas ventas ha tenido con " << sumasucursal_2 << endl;
	else
		cout << "La sucursal 3 es la que mas ventas ha tenido con " << sumasucursal_3 << endl;
}
}

