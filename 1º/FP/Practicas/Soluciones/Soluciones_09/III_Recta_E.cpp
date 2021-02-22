/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 3
// EJERCICIO 14 (Apartado E)
//
/* 	Implementaci�n de la clase "Recta" para representar una recta en el plano.
	Una recta viene determinada por tres coeficientes A, B, C, de forma que 
	todos los puntos (x,y) que pertenecen a la recta verifican lo siguiente 
	(ecuaci�n general de la recta):

		Ax + By + C = 0

	Apartado e) Constructor
	
	Definici�n de la clase Recta (b�sica) con datos miembro privados 
	e implementaci�n de los m�todos p�blicos para:
		* Calcular la pendiente.
		* Obtener la ordenada (y) dado un valor de abscisa (x)
		* Obtener la abscisa (x) dado un valor de ordenada (y).
		
	El programa define dos objetos de la clase "Recta", 
	lee seis reales desde teclado y los asigna, por orden, a los coeficientes 
	de los  dos objetos "Recta". 
	Emplea un �nico constructor. 
	Calcula e imprime la pendiente de cada recta usando el m�todo implementado.
	A continuaci�n, se lee un valor de abscisa y se imprime la ordenada y 
	finalmente se lee un valor de ordenada y se imprime la abscisa que le 
	corresponde (s�lo con la primera recta).
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
	(ecuaci�n general de la recta):

		Ax + By + C = 0
*/

class Recta {
	
private: 
	
	double A, B, C; // Coeficientes

	// Los m�todos de la clase acceden SIEMPRE libremente a los datos 
	// (campos) del objeto impl�cito.
	// Por estar declarados private, NO podr� accederse a �stos desde 
	// cualquier funci�n que est� en el �mbito de la clase. 
	// Se proporcionan m�todos p�blicos de acceso para lectura o escritura.
	
public:
	
	/*****************************************************************/
	// Constructor

	Recta (double valor_A, double valor_B, double valor_C) 
	{
		SetCoeficientes (valor_A, valor_B, valor_C);
	}

	/* El constructor podr�a haberse escrito inicializando los campos 
	   con la lista de inicializaci�n:
	
	Recta (double valor_A, double valor_B, double valor_C) : 
		A (valor_A), B (valor_B), C(valor_C) 
	{}
		   
	*/ 
	

	
	/*****************************************************************/
	// M�todos de acceso para lectura

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
	// M�todo de c�lculo: Devuelve la pendiente de la recta
	// 
	// PRE: B != 0
	
	double Pendiente (void) 
	{
		return (-A / B);	
	}
	
	/*****************************************************************/
	// M�todo de c�lculo: Devuelve la ordenada (y) dada la abscisa (x) 
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
	// M�todo de c�lculo: Devuelve la abscisa (x) dada la ordenada (y) 
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
	// M�todo de acceso para escritura 
	
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
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
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

	// Declaraci�n e inicializaci�n (CONSTRUCTOR) de los objetos "Recta"
	
	Recta recta1 (A1, B1, C1);	
	Recta recta2 (A2, B2, C2);	
	
		
	// C�lculo y presentaci�n de la pendiente de cada recta
	// IMPORTANTE: Hay que asegurarse que se cumplen las precondiciones 
	// antes de llamar al m�todo "Pendiente"
		
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
	
	// M�todos "Ordenada" y "Abscisa" 
	// IMPORTANTE: Hay que asegurarse que se cumplen las precondiciones 
	// antes de llamar a los m�todos 

	double x, y; 
	
	// Lectura de la abscisa y c�lculo de la ordenada 
		
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
	
	// Lectura de la ordenada y c�lculo de la abscisa 

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
