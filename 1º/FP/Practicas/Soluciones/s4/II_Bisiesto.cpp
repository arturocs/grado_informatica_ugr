/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2014-2015
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
// EJERCICIO 7
/*	
	Programa que acepta el número de un año e indique si es bisiesto o no.
	Un año es bisiesto si es múltiplo de cuatro, pero no de cien. 
	Excepción a la regla anterior son los múltiplos de cuatrocientos que 
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

	cout << "\nIntroduzca un año --> ";
	cin >> anio;

	es_bisiesto = ( (anio % 4 == 0) && (anio % 100 != 0) )   ||  (anio % 400 == 0) ;
	
	if (es_bisiesto)
		cout << "El año " << anio << " es bisiesto" << endl;
	else	
		cout << "El año " << anio << " no es bisiesto" << endl;		
	cout << "\n\n";

	return (0);
}
