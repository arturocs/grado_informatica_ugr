/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOS� CORTIJO BON
// (C) JUAN CARLOS CUBERO TALAVERA
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 3
// EJERCICIO 25 
//
/*	
	Un paso m�s en la resoluci�n de este problema, planteado en: 
	* ejercicio 4 de la Relaci�n de Problemas 1
	* ejercicio 13 de la Relaci�n de Problemas 3 
	* ejercicio 22 de la Relaci�n de Problemas 3 
	No describiremos los detalles, ya que deben ser conocidos. 

	Se construye la clase "Gausssiana" que incorpore la 
	funcionalidad necesaria para resolver los problemas planteados.

	Un objeto de la clase "Gaussiana" queda completamente 
	determinado por la esperanza y la desviaci�n t�pica. 

	Los m�todos ofertados por la clase ser�n los conocidos: 
	- Calcular el valor de una gaussiana para un valor x dado.
	- el valor aproximado de la CDF(x)

	En el dise�o de esta clase se ha decidido que, una vez creado el  
	objeto no se pueda cambiar ni la esperanza ni la desviaci�n t�pica. 
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Por el momento tendremos que aceptar el uso de una constante global
// No obstante, observe que no pueden producirse efectos colaterales 
// al no poder modificar este valor (es una constante)
// No obstante, avanzamos que podr�a emplearse una constante a nivel 
// de clase para PI (compartida por todos los objetos de la clase): 
// constante estatica


///////////////////////////////////////////////////////////////////////

class Gaussiana
{

private:

	double esperanza;	// Esperanza
	
	// PRE: desviacion >= 0
	double desviacion;	// Desviaci�n t�pica

	static const double PI = 3.1415927;

public:

	// Para este problema no permitimos el constructor sin argumentos, 
	// porque no tiene sentido la existencia de un objeto de la clase 
	// con valores por defecto. 

	/*****************************************************************/
	// Constructor con argumentos
	// PRE: desv >= 0
	
	Gaussiana (double esp, double desv)
	{
		esperanza = esp;
		desviacion = desv;
	}

	/*****************************************************************/
	// M�todos de lectura (Get) de los datos individuales 
	
	double GetEsperanza (void)
	{
		return (esperanza);
	}

	double GetDesviacion (void)
	{
		return (desviacion);
	}

	/*********************************************************************/
	// Calcula el valor de g(x) donde g -> N (esperanza, desviacion)
	//
	// Entradas: 
	//		x: valor de la abscisa o t�rmino independiente
	// Devuelve: 
	//		g(x), ordenada o t�rmino dependiente

	double Evalua (double x)
	{
		return (exp (-0.5 * pow ((x - esperanza)/desviacion, 2)) / 
		                        (desviacion * sqrt(2*PI)));
	}

	/*********************************************************************/
	// Calcula CDF (x) = Integral_{-infty}^{x} {g(x) d(x)}
	// donde g -> N (esperanza, desviacion)
	//
	// Entradas: 
	//		x: valor de la abscisa o t�rmino independiente
	// Devuelve: 
	//		CDF (x) = Integral_{-infty}^{x} {g(x) d(x)}

	double CDF (double x)
	{
		const double b0 =  0.231641900;
		const double b1 =  0.319381530;
		const double b2 = -0.356563782;
		const double b3 =  1.781477937;
		const double b4 = -1.821255978;
		const double b5 =  1.330274429;
	
		double t = 1.0 / (1 + b0*x);
		double t2 = t*t;
		double t3 = t2*t; // t*t*t
		double t4 = t3*t; // t*t*t*t
		double t5 = t4*t; // t*t*t*t*t

		return (1 - Evalua (x) * (b1*t + b2*t2 + b3*t3 + b4*t4 + b5*t5));
	}

	/*********************************************************************/
};

///////////////////////////////////////////////////////////////////////////

/*************************************************************************/


int main (void)
{

	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	// Peticion de los par�metros de la gaussiana

	double esperanza, desviacion;

	cout << "Par�metros de la gaussiana." << endl;
	cout << "\tEsperanza = ";
	cin >> esperanza;
	
	// Filtro para asegurar que se cumple la precondici�n sobre "desviacion" 
	do {
		cout << "\tDesviaci�n t�pica = ";
		cin >> desviacion;
	} while (desviacion < 0);

	// Creaci�n de la gaussiana (constructor)

	Gaussiana g (esperanza, desviacion);

	
	cout << endl;
	cout << "C�lculos sobre la gausssiana:" << endl;
	cout << "\tEsperanza =   " << setw(10) << setprecision (6) 
		 << g.GetEsperanza() << endl;
	cout << "\tDesv.T�pica = " << setw(10) << setprecision (6) 
		<< g.GetDesviacion() << endl;
	cout << endl;


	// C�lculos 
	
	double x_init;	// Entrada. Valor inicial de abscisa.
	double x_end;	// Entrada. Valor final de abscisa.
	double x_incr;	// Entrada. Salto entre dos valores de abscisa.
	
	double y; 	// Salida, y=Evalua(x)
	double cdf;	// Salida, cdf=CDF(x)
	
	cout << endl;

	double valor1, valor2;
		
	cout << "Valor inicial de la abscisa: ";
	cin >> valor1;
   
	cout << "Valor final de la abscisa: ";
	cin >> valor2;

	do {
		cout << "Diferencia entre dos valores de abscisa: ";
		cin >> x_incr;
	} while (x_incr <= 0);
	
	cout << endl << endl;
	
	// Reajustar extremos del inetrvalo 
	
	if (valor1 <= valor2) {	
		x_init = valor1;
		x_end  = valor2;
	}
	else {
		x_init = valor1;
		x_end  = valor2;
	}

	// Calcular y mostrar resultados
	
	for (double x=x_init; x <= x_end; x += x_incr) {
		
		// C�lculo
		y = g.Evalua(x);	
		cdf = g.CDF(x);	
		
		// Presentaci�n de resultados
		cout << "x = " << setw(5) << setprecision(2) << x;
		cout << " g(x) = " << setw(8) << setprecision(4) << y;
		cout << " CDF(x) = " << setw(8) << setprecision(4) << cdf;
		cout << endl;	
			
	} // for x
	
	cout << endl << endl;	
		
	return(0);
}
