#include <iostream>
using namespace std;

int main(){
	short x=10;
	short y=20;
	short z=30;
	short aux;
	
	aux=z;
	z=y;
	y=x;
	x=aux;
	
	
	cout << x << "\n";
	cout << y << "\n";
	cout << z << "\n";

	system("pause");
}
