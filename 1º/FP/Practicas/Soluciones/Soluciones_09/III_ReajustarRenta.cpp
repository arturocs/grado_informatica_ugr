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
// EJERCICIO 17
//
/* 
	Otra soluci�n para el ejercicio 8 de la Relaci�n de Problemas II. 
	
	En esta versi�n se usa la clase "LectorOpcion" para la lectura de 
	las propiedades (variables l�gicas) "es_autonomo", "es_soltero" 
	y "es_pensionista"		
*/
/*********************************************************************/

#include <iostream>
#include <cctype>
#include <iomanip> // Recursos para dar formato a la presentaci�n de datos 
#include <string>
using namespace std;

/////////////////////////////////////////////////////////////////////////////

/* 
	Un objeto de la clase "LectorOpcion" es �til para leer valores de 
	variables l�gicas. 
	Permite etiquetar las lecturas y realiza un filtrado de la lectura. 
*/

class LectorOpcion 
{
private: 

	string mensaje; // Mensaje que se mostrar� en cada lectura

public: 
		
	/************************************************************************/
	// M�todo de escritura del campo privado "mensaje". 
	// 
	// Recibe:	 "el_mensaje", cadena de caracteres que se copiar� 
	//			 en el campo privado "mensaje".
	// Devuelve: Nada. 
	
	void SetMensaje (string el_mensaje) 
	{
		mensaje = el_mensaje;
	}
	
	/************************************************************************/
	// Muestra un mensaje (campo privado) y pide que el usuario introduzca 
	// una 's' � una 'n' (may�scula o min�scula, es indiferente). 
	// La lectura se filtra adecuadamente. 
	// 
	// Recibe:	 Nada.
	// Devuelve: true, si el usuario escibi� 's' � 'S'
	//			 false, en otro caso. 

	bool LeeOpcion (void) 
	{
   		char opcionSN;

		do{
	        cout << "�" << mensaje << "(S/N)? : ";
	        cin >> opcionSN;
	        opcionSN = toupper(opcionSN);
	    } while (opcionSN != 'S' && opcionSN != 'N');
	
		return (toupper(opcionSN) == 'S');
	}

	/************************************************************************/	
};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/

int main (void)
{
	const double INCR_AUTONOMO = 0.97; 	
	const double INCR_PENSIONISTA = 1.01;
	const double INCR_LINEAL = 1.02;	
	const double INCR_SALARIO_BAJO = 1.06;
	const double INCR_SALARIO_NORMAL_SOLTERO = 1.1;
	const double INCR_SALARIO_NORMAL_CASADO = 1.08;
	const double LIMITE_SALARIO_NORMAL = 20000;

	double	renta_bruta, renta_neta, 
			retencion_inicial, retencion_final, 
			porc_modificacion;

	bool es_autonomo, es_soltero, es_pensionista;	

	// Lectura
	
	// Lectura de las propiedades binarias es_autonomo, 
	// es_pensionista y es_soltero. Observe c�mo se asigna 
	// el valor bool adecuado de manera indirecta
	
	LectorOpcion lector;

	lector.SetMensaje ("Aut�nomo");
	es_autonomo = lector.LeeOpcion();

	lector.SetMensaje ("Pensionista");
	es_pensionista = lector.LeeOpcion();

	lector.SetMensaje ("Soltero");
	es_soltero = lector.LeeOpcion();

	
	// Lectura de valores num�ricos
	
	cout << "Retenci�n inicial : "; 
	cin >> retencion_inicial;
	
	cout << "Renta bruta : "; 
	cin >> renta_bruta;	
	

	// C�lculos
	
	if (es_autonomo)   
		porc_modificacion = INCR_AUTONOMO;   

	else 
	
		if (es_pensionista)
			porc_modificacion = INCR_PENSIONISTA;

		else { // Ni aut�nomo ni pensionista

      		porc_modificacion = INCR_LINEAL;

      		if (renta_bruta < LIMITE_SALARIO_NORMAL)
         		porc_modificacion = porc_modificacion * INCR_SALARIO_BAJO;
								   
      		else // renta_bruta >= LIMITE_SALARIO_NORMAL
      		
				if (es_soltero)
         			porc_modificacion = porc_modificacion * 
					 					INCR_SALARIO_NORMAL_SOLTERO;
      			else  
         			porc_modificacion = porc_modificacion * 
					 					INCR_SALARIO_NORMAL_CASADO;
   }

	retencion_final = retencion_inicial * porc_modificacion;
	renta_neta = renta_bruta * (1 - retencion_final /100.0);


	// Salida
	
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	cout << endl << endl;

	cout << "Autonomo = ";
	if (es_autonomo) 
		cout << "SI";
	else  
		cout << "NO";
	cout << endl;

	cout << "Pensionista = ";
	if (es_pensionista) 
		cout << "SI";
	else  
		cout << "NO";
	cout << endl;

	cout << "Soltero = ";
	if (es_soltero) 
		cout << "SI";
	else  
		cout << "NO";
	cout << endl << endl;

	cout << "Retenci�n inicial = " << setw(6) << setprecision(2) 
						           << retencion_inicial << endl;
	cout << "Retenci�n final =   " << setw(6) << setprecision(2) 
						           << retencion_final << endl;
	cout << "Renta bruta = " << setw(10) << setprecision(2) 
		                     << renta_bruta << endl;
	cout << "Renta final = " << setw(10) << setprecision(2) 
						     << renta_neta;
	cout << "\n\n";

	return (0);
}

