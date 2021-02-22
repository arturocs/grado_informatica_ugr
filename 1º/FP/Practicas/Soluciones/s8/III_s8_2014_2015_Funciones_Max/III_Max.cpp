////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////


/*
	Cread una funci�n que calcule el m�ximo entre tres double
*/

#include <iostream>
#include <string>
using namespace std;

/*
	Dentro de una funci�n que realiza c�mputos, JAM�S leeremos los datos dentro de ella.
	Si ejecutamos cin dentro de la funci�n, �sta ya no puede usarse en un entorno (Windows por ejemplo) en
	el que no funcione cin.
	Adem�s, la funci�n S�LO sirve para calcular el m�ximo de tres valores 
	que vengan de la entrada por defecto y no de otros tres valores cualesquiera.
*/

double MaxSuspenso(){   // Suspenso garantizado :-(
	double max;
	double un_valor, otro_valor, el_tercero;
	const string MENSAJE_ENTRADA = "\nIntroduzca un valor entero ";

	cout << MENSAJE_ENTRADA;
	cin >> un_valor;
	cout << MENSAJE_ENTRADA;
	cin >> otro_valor;
	cout << MENSAJE_ENTRADA;
	cin >> el_tercero;

	if (un_valor >= otro_valor)
		max = un_valor;
	else
		max = otro_valor;

	if (el_tercero >= max)
		max = el_tercero;

	return max;
}


/*
int main(){
	double maximo_de_los_tres;
	
	maximo_de_los_tres = MaxSuspenso();

	cout << "\nEl m�ximo es " << maximo_de_los_tres;

	cout << "\n\n";
	system("pause");
}
*/


double Max(double un_valor, double otro_valor, double el_tercero){   // :-)
	double max;

	if (un_valor >= otro_valor)
		max = un_valor;
	else
		max = otro_valor;

	if (el_tercero > max)
		max = el_tercero;

	return max;
}



/*
int main(){ 
	const string MENSAJE_ENTRADA = "\nIntroduzca un valor entero ";
	double uno, dos, tres;
	double maximo_de_los_tres;

	cout << MENSAJE_ENTRADA;
	cin >> uno;
	cout << MENSAJE_ENTRADA;
	cin >> dos;
	cout << MENSAJE_ENTRADA;
	cin >> tres;

	maximo_de_los_tres = Max(uno, dos, tres);

	cout << "\nEl m�ximo es " << maximo_de_los_tres;

	cout << "\n\n";
	system("pause");
}
*/

// Y si queremos, tambi�n podemos crear una funci�n para leer un entero

double LeeEntero(string mensaje){
	int entero;
	
	cout << mensaje;
	cin >> entero;
	
	return entero;
}


int main(){
	const string MENSAJE_ENTRADA = "\nIntroduzca un valor entero ";
	double uno, dos, tres;
	double maximo_de_los_tres;

	uno  = LeeEntero(MENSAJE_ENTRADA);
	dos  = LeeEntero(MENSAJE_ENTRADA);
	tres = LeeEntero(MENSAJE_ENTRADA);

	maximo_de_los_tres = Max(uno, dos, tres);

	cout << "\nEl m�ximo es " << maximo_de_los_tres;

	cout << "\n\n";
	system("pause");
}


