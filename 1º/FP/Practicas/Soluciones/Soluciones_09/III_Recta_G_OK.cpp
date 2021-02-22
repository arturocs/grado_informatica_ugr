/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 3
// EJERCICIO 14 (Apartado G)
//
/* 	Implementaci�n de la clase "Recta" para representar una recta en el plano.
	Una recta viene determinada por tres coeficientes A, B, C, de forma que 
	todos los puntos (x,y) que pertenecen a la recta verifican lo siguiente 
	(ecuaci�n general de la recta):

		Ax + By + C = 0

	Apartado g) M�todos privados
		Se a�ade un m�todo privado que nos indica si los coeficientes son 
		correctos, es decir, A y B no pueden ser simult�neamente nulos. 
		Llaman a este m�todo: el constructor y el m�todo "SetCoeficientes".
		
	Definici�n de la clase Recta (b�sica) con datos miembro privados 
	e implementaci�n de los m�todos p�blicos para:
		* Calcular la pendiente.
		* Obtener la ordenada (y) dado un valor de abscisa (x)
		* Obtener la abscisa (x) dado un valor de ordenada (y).
		
	El programa define dos objetos de la clase "Recta", 
	lee seis reales desde teclado y los asigna, por orden, a los coeficientes 
	de los  dos objetos "Recta". 
	Emplea un �nico constructor que comprueba la validez de los datos. 
	Se vuelve a usar "SetCoeficientes", que tambi�n comprueba la validez de 
	los datos. 
	Calcula con el m�todo implementado la pendiente de cada recta y la imprime.
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
	
	// En esta versi�n se fija una precondici�n para los par�metros: que los 
	// coeficientes A y B no pueden ser simultaneamente nulos.  
	// PRE: A != 0
	// PRE: B != 0
	
	double A, B, C; // Coeficientes

	// Los m�todos de la clase acceden SIEMPRE libremente a los datos 
	// (campos) del objeto impl�cito.
	// Por estar declarados private, NO podr� accederse a �stos desde 
	// cualquier funci�n que est� en el �mbito de la clase. 
	// Se proporcionan m�todos p�blicos de acceso para lectura o escritura.
	
public:
	
	//*********************************************************************/
	// Constructor
	//
	// PRE: A != 0
	// PRE: B != 0
	
	Recta (double valor_A, double valor_B, double valor_C) : 
		A (valor_A), B (valor_B), C(valor_C) 
	{
	}
 
	//*********************************************************************/
	// M�todo de acceso para escritura 
	//
	// PRE: A != 0
	// PRE: B != 0
	
	void SetCoeficientes (double valor_A, double valor_B, double valor_C) 
	{
		A = valor_A;
		B = valor_B;	
		C = valor_C;		
	}
	
	//*********************************************************************/
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
	
	//*********************************************************************/
	// M�todo de c�lculo: Devuelve la pendiente de la recta
	// 
	// PRE: B != 0
	
	double Pendiente (void) 
	{
		return (-A / B);	
	}
	
	//*********************************************************************/
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
	
	//*********************************************************************/
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
	
	//*********************************************************************/
	// M�todo PRIVADO de c�lculo: Calcula si se cumplen las precondiciones 
	// sobre los coeficientes A y B
	//
	// Recibe: 	A, Coeficiente de x
	// 			B, Coeficiente de y
	// Devuelve: true, si A=0 y B=0
	
	bool Hay_Error_en_coeficientes (double A, double B) 
	{
		return ((A == 0) && (B == 0));	
	}
	
};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
int main (void)
{
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 
	
	double A, B, C; // Coeficientes 

	
	// Leer coeficientes
	
	bool error_coeficientes;
	
	cout << "Coeficientes de la primera recta (Ax + By + C = 0): " << endl;
	
	// Aseguramos las precondiciones para la primera recta con este filtro

	do {
		cout << "\tA: ";
		cin >> A;
	
		cout << "\tB: ";
		cin >> B;
		
		// Recta imposible si A=0 y B=0
		error_coeficientes = ((A == 0) && (B == 0));
		
		if (error_coeficientes)
			cout << "\tError: A y B no pueden ser, a la vez, cero." << endl;
			
	} while (error_coeficientes);
		
	cout << "\tC: ";
	cin >> C;

	// Declaraci�n e inicializaci�n (CONSTRUCTOR) de del objeto "recta1"
	// Hemos asegurado el cumplimiento de las precondiciones
	
	Recta recta1 (A, B, C);	



	cout << "Coeficientes de la segunda recta (Ax + By + C = 0): " << endl;
	
	// Aseguramos las precondiciones para la segunda recta con este filtro

	do {
		cout << "\tA: ";
		cin >> A;
	
		cout << "\tB: ";
		cin >> B;
		
		// Recta imposible si A=0 y B=0
		error_coeficientes = ((A == 0) && (B == 0));
		
		if (error_coeficientes)
			cout << "\tError: A y B no pueden ser, a la vez, cero." << endl;
			
	} while (error_coeficientes);
		
	cout << "\tC: ";
	cin >> C;

	// Declaraci�n e inicializaci�n (CONSTRUCTOR) de del objeto "recta2"
	// Hemos asegurado el cumplimiento de las precondiciones
	
	Recta recta2 (A, B, C);	
	
		
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
