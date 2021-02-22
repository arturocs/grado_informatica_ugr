#include <iostream> 
using namespace std;  
   
int main(){    

	double interes, capitalinicial, capital;	
	int anios, numeroanios;
   
	cout << "Introduzca el capital inicial " << endl;
	cin >> capitalinicial;
	cout << "Introduzca numero de años "<< endl;
	cin >> numeroanios;
	cout << "Introduzca interes "<< endl;
	cin >> interes;   	

for(int interesincremento = 1; interesincremento <= interes ; interesincremento++){
	capital = capitalinicial;
	cout << " Calculos realizados al " << interesincremento << "%:" << endl; 

	for (anios = 0 ; anios < numeroanios ; anios++){     
		capital = capital  +  capital * interesincremento / 100.0; 
		cout << "Capital en el año " << anios + 1 << " = " << capital << endl;  
	}
}
}
