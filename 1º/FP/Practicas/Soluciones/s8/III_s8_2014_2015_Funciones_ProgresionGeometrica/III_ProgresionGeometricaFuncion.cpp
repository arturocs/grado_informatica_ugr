////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
	Progresión geométrica
*/

#include <iostream>
#include <cmath>
using namespace std;

//	Potencia de un real elevado a un entero cualquiera
double Potencia(double la_base, int el_exponente){
	/*
		Observad que si exponente fuese cero, la variable potencia se quedaría con 1,
		lo que es correcto ya que base elevado a 0 es siempre 1	
		
		Y observad que este comentario va dentro de la función ya que
		es una descripción de la implementación
	*/
	double provoca_indeterminacion = 0.0;
	double NaN = provoca_indeterminacion/provoca_indeterminacion;
	double potencia;
	int exponente_positivo;

	if (la_base == 0 && el_exponente == 0)
		potencia = NaN;				// Devuelve NaN (Indeterminación)
	else{
		exponente_positivo = abs(el_exponente);
		potencia = 1;								   					

		for (int i = 1; i <= exponente_positivo; i++)
			potencia = potencia * la_base;
	}

	if (el_exponente < 0)
		potencia = 1/potencia;

	return potencia;
}




// Suma  de los términos de la progresión hasta el término k. Versión 1.
/*
double SumaProgresionGeometrica (double primer_termino, double razon, double k){
	double suma_total, termino_n;
	int n;

	termino_n = primer_termino;
	suma_total = termino_n; 

	for (n=2; n <= k ; n++){
		termino_n = termino_n * razon;
		suma_total = suma_total +  termino_n;		
	}

	return suma_total;
}
*/

/*
	Suma  de los términos de la progresión hasta el término k. Versión 2. 
   Igual de válida que la versión 1. 
   Habría que comprobar empíricamente si es más rápido realizar la llamada a la función pow -versión 2-
   que realizar el bucle que va sumando los términos -versión 1-.
*/
double SumaProgresionGeometrica (double primer_termino, double razon, int k){
	return primer_termino * (pow(razon, k) - 1) / (razon - 1);
	// return primer_termino * (Potencia(razon, k) - 1) / (razon - 1);
}

// Suma  de los términos de la progresión hasta infinito. 
double SumaHastaInfinitoProgresionGeometrica (double primer_termino, double razon){
	double suma;
	double denominador = 0.0;

	if (abs(razon) < 1)
		suma = primer_termino /(1 - razon);
	else
		suma = 1.0/denominador;    // <- Devuelve infinito

	return suma;
}


/*
	La fórmula del producto de los términos de la progresión hasta el k-ésimo término es:
		raiz_cuadrada_de ( (a1 * ak) elevado a k)
		
	¿Definiríamos la siguiente función?
	
	ProductoHastaProgresionGeometrica (double primer_termino, double ultimo_termino, int k){
	  return sqrt( pow(primer_termino * ultimo_termino, k));
	}
		
	No sería una función bien diseñada ya que, para que realice su cometido,
	debe recibir el cómputo correcto de ultimo_termino (que depende de los otros dos parámetros)
	¿Y si le pasamos un valor incorrectamente calculado?
	La función no funcionaría correctamente.
	
	Estaríamos creando una dependencia entre los parámetros.
	Si bien primer_termino y k pueden variar "libremente", el otro parámetro ultimo_termino
	no puede variar. Sólo es correcto un valor específico para cada combinación
	de los otros dos parámetros.


	MUY IMPORTANTE:
	
		La función debe ocuparse de realizar los cómputos que ella necesite
		y no delegar la realización de dichos cómputos en la llamada.
	
	
	La cabecera de la función debe ser:
	
		double ProductoHastaProgresionGeometrica (double primer_termino, double razon, int k)
*/


double TerminoProgresionGeometrica(double primer_termino, double razon, int k){
	double termino;

	termino = primer_termino * pow(razon, k-1);

	return termino;
}
	
// Producto de los términos de la progresión hasta el término tope
double ProductoHastaProgresionGeometrica (double primer_termino, double razon, int k){
	double ultimo_termino;

	ultimo_termino = TerminoProgresionGeometrica(primer_termino, razon, k);

	return sqrt( pow(primer_termino * ultimo_termino , k));
}


int main(){
	double primer_termino, razon;   
	int tope;
	double suma, producto, suma_infinito;

	cout << "\nIntroduzca el primer término de la progresión ";
	cin >> primer_termino;
	cout << "\nIntroduzca la razón de la progresión ";
	cin >> razon;
	cout << "\nIntroduzca el tope hasta el que quiere sumar ";
	cin >> tope;

	suma =			 SumaProgresionGeometrica(primer_termino, razon, tope);
	producto =		 ProductoHastaProgresionGeometrica(primer_termino, razon, tope);
	suma_infinito = SumaHastaInfinitoProgresionGeometrica(primer_termino, razon);

	cout << "\nSuma hasta " << tope << " = " << suma;
	cout << "\nProducto hasta " << tope << " = " << producto;
	cout << "\nSuma hasta infinito: " << suma_infinito;

	cout << "\n\n";
	system("pause");
}
