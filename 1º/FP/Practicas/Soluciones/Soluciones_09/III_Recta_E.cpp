/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 3
// EJERCICIO 14 (Apartado E)
//
/* 	Implementación de la clase "Recta" para representar una recta en el plano.
	Una recta viene determinada por tres coeficientes A, B, C, de forma que 
	todos los puntos (x,y) que pertenecen a la recta verifican lo siguiente 
	(ecuación general de la recta):

		Ax + By + C = 0

	Apartado e) Constructor
	
	Definición de la clase Recta (básica) con datos miembro privados 
	e implementación de los métodos públicos para:
		* Calcular la pendiente.
		* Obtener la ordenada (y) dado un valor de abscisa (x)
		* Obtener la abscisa (x) dado un valor de ordenada (y).
		
	El programa define dos objetos de la clase "Recta", 
	lee seis reales desde teclado y los asigna, por orden, a los coeficientes 
	de los  dos objetos "Recta". 
	Emplea un único constructor. 
	Calcula e imprime la pendiente de cada recta usando el método implementado.
	A continuación, se lee un valor de abscisa y se imprime la ordenada y 
	finalmente se lee un valor de ordenada y se imprime la abscisa que le 
	corresponde (sólo con la primera recta).
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/////////////////////////////////////////////////////////////////////////////

/* 
	La clase "Recta" representa una recta en el plano.
	Una recta viene determinada por tres coeficientes A, B, C, de forma que 
	todos los puntos (x,y) que pertenecen a la recta verifican lo siguiente 
	(ecuación general de la recta):

		Ax + By + C = 0
*/

class Recta {
	
private: 
	
	double A, B, C; // Coeficientes

	// Los métodos de la clase acceden SIEMPRE libremente a los datos 
	// (campos) del objeto implícito.
	// Por estar declarados private, NO podrá accederse a éstos desde 
	// cualquier función que esté en el ámbito de la clase. 
	// Se proporcionan métodos públicos de acceso para lectura o escritura.
	
public:
	
	/*****************************************************************/
	// Constructor

	Recta (double valor_A, double valor_B, double valor_C) 
	{
		SetCoeficientes (valor_A, valor_B, valor_C);
	}

	/* El constructor podría haberse escrito inicializando los campos 
	   con la lista de inicialización:
	
	Recta (double valor_A, double valor_B, double valor_C) : 
		A (valor_A), B (valor_B), C(valor_C) 
	{}
		   
	*/ 
	

	
	/*****************************************************************/
	// Métodos de acceso para lectura

	double GetA (void) 
	{
		return (A);	
	}
	
	double GetB (void) 
	{
		return (B);	
	}

	double GetC (void) 
	{
		return (C);	
	}
	
	/*****************************************************************/
	// Método de cálculo: Devuelve la pendiente de la recta
	// 
	// PRE: B != 0
	
	double Pendiente (void) 
	{
		return (-A / B);	
	}
	
	/*****************************************************************/
	// Método de cálculo: Devuelve la ordenada (y) dada la abscisa (x) 
	// 
	// Recibe: x, valor de la abscisa
	// Devuelve: el valor de la ordenada que le corresponde a "x"
	//
	// PRE: B != 0
	
	double Ordenada (double x) 
	{
		return ((-C - A*x) / B);	
	}
	
	/*****************************************************************/
	// Método de cálculo: Devuelve la abscisa (x) dada la ordenada (y) 
	//
	// Recibe: y, valor de la ordenada
	// Devuelve: el valor de la abscisa que le corresponde a "y"
	//
	// PRE: A != 0
	
	double Abscisa (double y) 
	{
		return ((-C - B*y) / A);	
	}
	
private:
	
	/*****************************************************************/
	// Método de acceso para escritura 
	
	void SetCoeficientes (double valor_A, double valor_B, double valor_C) 
	{
		A = valor_A;
		B = valor_B;	
		C = valor_C;		
	}
};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
int main (void)
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 
	
	double A1, B1, C1; // Coeficientes de la primera recta 
	double A2, B2, C2; // Coeficientes de la segunda recta 

	// Lectura de los coeficientes 

	cout << "Coeficientes de la primera recta (Ax + By + C = 0): " << endl;
	cout << "\tA: ";
	cin >> A1;
	cout << "\tB: ";
	cin >> B1;
	cout << "\tC: ";
	cin >> C1;

	cout << "Coeficientes de la segunda recta (Ax + By + C = 0): " << endl;
	cout << "\tA: ";
	cin >> A2;
	cout << "\tB: ";
	cin >> B2;
	cout << "\tC: ";
	cin >> C2;

	// Declaración e inicialización (CONSTRUCTOR) de los objetos "Recta"
	
	Recta recta1 (A1, B1, C1);	
	Recta recta2 (A2, B2, C2);	
	
		
	// Cálculo y presentación de la pendiente de cada recta
	// IMPORTANTE: Hay que asegurarse que se cumplen las precondiciones 
	// antes de llamar al método "Pendiente"
		
	cout << endl;

	if (recta1.GetB() != 0) 
		cout << "Recta 1. Pendiente = " << setw(5) 
			 << setprecision (2) << recta1.Pendiente() << endl;
	else 
		cout << "Recta 1. Pendiente = infinito " 
			 << "(paralela al eje de ordenadas)." << endl; 
	
	if (recta2.GetB() != 0) 
		cout << "Recta 2. Pendiente = " << setw(5) 
			 << setprecision (2) << recta2.Pendiente() << endl;
	else 
		cout << "Recta 2. Pendiente = infinito " 
			 << "(paralela al eje de ordenadas)." << endl; 
	
	// Métodos "Ordenada" y "Abscisa" 
	// IMPORTANTE: Hay que asegurarse que se cumplen las precondiciones 
	// antes de llamar a los métodos 

	double x, y; 
	
	// Lectura de la abscisa y cálculo de la ordenada 
		
	cout << endl;
	cout << "Valor de la abscisa (x) = " ;
	cin >> x;
	
	if (recta1.GetB() != 0) 
		cout << "Recta 1. abscisa = " << setw(5) << setprecision (2) 
			 << x << " ordenada = " << setw(5) << setprecision (2) 
			 << recta1.Ordenada(x) << endl;
	else 
		cout << "Recta 1 paralela al eje de ordenadas --> " 
			 << " infinitos valores para la ordenada." << endl; 
	
	// Lectura de la ordenada y cálculo de la abscisa 

	cout << endl;
	cout << "Valor de la ordenada (y) = " ;
	cin >> y;
	
	if (recta1.GetA() != 0) 
		cout << "Recta 1. ordenada = " << setw(5) << setprecision (2) 
			 << y << " abscisa = " << setw(5) << setprecision (2) 
			 << recta1.Abscisa(y) << endl;
	else 
		cout << "Recta 1 paralela al eje de abscisas --> " 
			 << " infinitos valores para la abscisa." << endl; 
	
	cout << endl << endl;
	return (0);
}
