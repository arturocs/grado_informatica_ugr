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
// EJERCICIO 4
//
/*	

	Programa que lee tres enteros desde teclado y nos dice si están 
	ordenados (da igual si es de forma ascendente o descendente) o no.
	(la versión 2 informa adicionalmente sobre el tipo de ordenación)
	
	Entradas: tres números enteros 
	Salidas: El mensaje "Están ordenados" ó "No están ordenados"


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

	// Cálculos

	/* 	Versión 1: 
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
	 	
	/* 	Versión 2: 
		Se guardan los estados en variable lógicas.
		Se inician todas a false por defecto
	*/
	
	bool orden_creciente, orden_decreciente, estan_ordenados;
	orden_creciente = orden_decreciente = estan_ordenados = false; 

	orden_creciente = ((numero1 < numero2) && (numero2 < numero3));
	orden_decreciente = ((numero1 > numero2) && (numero2 > numero3));
	estan_ordenados = orden_creciente || orden_decreciente; 
	 		 	

	// Salida 
	
	if (estan_ordenados) {
		cout << "Están ordenados.";
		if (orden_creciente) 
			cout << " Orden creciente.";
		else 
			cout << " Orden decreciente.";
	}	
	else 
		cout << "No están ordenados.";

	cout << endl << endl;

	return (0);
}
