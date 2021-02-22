/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOSÉ CORTIJO BON
// (C) JUAN CARLOS CUBERO TALAVERA
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 3
// EJERCICIO 25 
//
/*	
	Un paso más en la resolución de este problema, planteado en: 
	* ejercicio 4 de la Relación de Problemas 1
	* ejercicio 13 de la Relación de Problemas 3 
	* ejercicio 22 de la Relación de Problemas 3 
	No describiremos los detalles, ya que deben ser conocidos. 

	Se construye la clase "Gausssiana" que incorpore la 
	funcionalidad necesaria para resolver los problemas planteados.

	Un objeto de la clase "Gaussiana" queda completamente 
	determinado por la esperanza y la desviación típica. 

	Los métodos ofertados por la clase serán los conocidos: 
	- Calcular el valor de una gaussiana para un valor x dado.
	- el valor aproximado de la CDF(x)

	En el diseño de esta clase se ha decidido que, una vez creado el  
	objeto no se pueda cambiar ni la esperanza ni la desviación típica. 
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Por el momento tendremos que aceptar el uso de una constante global
// No obstante, observe que no pueden producirse efectos colaterales 
// al no poder modificar este valor (es una constante)
// No obstante, avanzamos que podría emplearse una constante a nivel 
// de clase para PI (compartida por todos los objetos de la clase): 
// constante estatica


///////////////////////////////////////////////////////////////////////

class Gaussiana
{

private:

	double esperanza;	// Esperanza
	
	// PRE: desviacion >= 0
	double desviacion;	// Desviación típica

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
	// Métodos de lectura (Get) de los datos individuales 
	
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
	//		x: valor de la abscisa o término independiente
	// Devuelve: 
	//		g(x), ordenada o término dependiente

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
	//		x: valor de la abscisa o término independiente
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

	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	// Peticion de los parámetros de la gaussiana

	double esperanza, desviacion;

	cout << "Parámetros de la gaussiana." << endl;
	cout << "\tEsperanza = ";
	cin >> esperanza;
	
	// Filtro para asegurar que se cumple la precondición sobre "desviacion" 
	do {
		cout << "\tDesviación típica = ";
		cin >> desviacion;
	} while (desviacion < 0);

	// Creación de la gaussiana (constructor)

	Gaussiana g (esperanza, -3);

	
	cout << endl;
	cout << "Cálculos sobre la gausssiana:" << endl;
	cout << "\tEsperanza =   " << setw(10) << setprecision (6) 
		 << g.GetEsperanza() << endl;
	cout << "\tDesv.Típica = " << setw(10) << setprecision (6) 
		<< g.GetDesviacion() << endl;
	cout << endl;


	// Cálculos 
	
	double x;	// Entrada
	double y; 	// Salida, y=Evalua(x)
	double cdf;	// Salida, cdf=CDF(x)
	
	// Petición del valor de abscisa, x, para calcular:  
	// y=Evalua(x) y cdf=CDF(x)

	cout << endl;
	cout << "Valor de la abscisa: ";
	cin >> x;
   
	y = g.Evalua(x);	// Se llama a los métodos de 
	cdf = g.CDF(x);		// cálculo ofrecidos por la clase


	// Presentación de resultados
	
	cout << endl << endl;
	cout << "El valor de la función gaussiana en " 
		 << setw(10) << setprecision(7) << x << " es " 
		 << setw(10) << setprecision(7) << y << endl;
	cout << "El valor de CDF(" << setw(10) << setprecision(7) << x << ") es " 
		 << setw(10) << setprecision(7) << cdf;
	cout << endl << endl;
	
	return(0);
}
