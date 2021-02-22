/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2014-2015
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 2
// EJERCICIO 7
/*	
	Programa que acepta el n�mero de un a�o e indique si es bisiesto o no.
	Un a�o es bisiesto si es m�ltiplo de cuatro, pero no de cien. 
	Excepci�n a la regla anterior son los m�ltiplos de cuatrocientos que 
	siempre son bisiestos. Son bisiestos: 1600,1996, 2000, 2004. 
	No son bisiestos: 1700, 1800, 1900, 1998, 2002.
*/
/*********************************************************************/


#include <iostream>
using namespace std;

int main()
{
   	int	anio;
	bool es_bisiesto;

	cout << "\nIntroduzca un a�o --> ";
	cin >> anio;

	es_bisiesto = ( (anio % 4 == 0) && (anio % 100 != 0) )   ||  (anio % 400 == 0) ;
	
	if (es_bisiesto)
		cout << "El a�o " << anio << " es bisiesto" << endl;
	else	
		cout << "El a�o " << anio << " no es bisiesto" << endl;		
	cout << "\n\n";

	return (0);
}
