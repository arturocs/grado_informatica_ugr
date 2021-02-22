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
// EJERCICIO 4
//
/*	

	Programa que lee tres enteros desde teclado y nos dice si est�n 
	ordenados (da igual si es de forma ascendente o descendente) o no.
	(la versi�n 2 informa adicionalmente sobre el tipo de ordenaci�n)
	
	Entradas: tres n�meros enteros 
	Salidas: El mensaje "Est�n ordenados" � "No est�n ordenados"


*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int numero1, numero2, numero3;

	// Entrada 	
	
	cout << "\nIntroduce tres enteros: ";
	cin >> numero1 >> numero2 >> numero3;

	// C�lculos

	/* 	Versi�n 1: 
		Estructura condicional doble que no comprueba el 
		tipo de orden creciente/decreciente	

	bool estan_ordenados; 

	if ((numero1 > numero2) && (numero2 > numero3))
		estan_ordenados = true; 
	else 
		if ((numero1 < numero2) && (numero2 < numero3))
			estan_ordenados = true; 
	 	else 
			estan_ordenados = false; 	
	*/
	 	
	/* 	Versi�n 2: 
		Se guardan los estados en variable l�gicas.
		Se inician todas a false por defecto
	*/
	
	bool orden_creciente, orden_decreciente, estan_ordenados;
	orden_creciente = orden_decreciente = estan_ordenados = false; 

	orden_creciente = ((numero1 < numero2) && (numero2 < numero3));
	orden_decreciente = ((numero1 > numero2) && (numero2 > numero3));
	estan_ordenados = orden_creciente || orden_decreciente; 
	 		 	

	// Salida 
	
	if (estan_ordenados) {
		cout << "Est�n ordenados.";
		if (orden_creciente) 
			cout << " Orden creciente.";
		else 
			cout << " Orden decreciente.";
	}	
	else 
		cout << "No est�n ordenados.";

	cout << endl << endl;

	return (0);
}
