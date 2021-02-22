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
// EJERCICIO 19 (Apartado a)
/*
	Este programa ampl�a la funcionalidad descrita en los ejercicios 
	5 y 12 de la Relaci�n de Problemas I acerca del reparto de ganancias 
	entre los 3 fabricantes y el dise�ador de un producto sabiendo que 
	el dise�ador cobra el doble que cada uno de los fabricantes. 

	S�lo gestionamos la n�mina de una empresa en la que hay un fabricante
	y tres dise�adores. Los salarios brutos se obtienen al repartir los 
	ingresos de la empresa, de forma que el dise�ador cobra el doble 
	de cada fabricante.

	El programa lee el valor de los ingresos totales y calcula los 
	salarios brutos de los fabricantes y dise�ador, llamando a los 
	m�todos oportunos de la clase Nomina.
*/
/*********************************************************************/


#include <iostream>
#include <iomanip>
using namespace std;


///////////////////////////////////////////////////////////////////////
//	Notas de dise�o sobre la clase "Nomina": 
/*
	Hemos decidido permitir asignar a un mismo objeto "Nomina" distintos 
	ingresos totales, es decir, que podemos calcular y cambiar los salarios 
	de fabricante y dise�ador en tiempo de ejecuci�n. Para realizar esta 
	tarea incorporamos el m�todo SetIngresosTotales().
	Si no fuera as�, suprimir�amos el m�todo y pasar�amos el valor de los 
	ingresos totales �nicamente en el constructor. 
*/

class Nomina
{

private:
	
	// PRE: salario_bruto_diseniador >= 0
	double salario_bruto_diseniador;
	
	// PRE: salario_bruto_fabricante >= 0
	double salario_bruto_fabricante;

public:   

	/*****************************************************************/
	// Constructor con argumentos
	// Se encarga de inicar adecuadamente los campos privados de la clase
	// 
	// Recibe: "ingresos_totales_nomina", los ingresos brutos totales de 
	//			la empresa.
	// PRE: ingresos_totales_nomina >= 0
	
	Nomina (double ingresos_totales_nomina)
	{
		// El m�todo "SetIngresosTotales" se encarga de iniciar 
		// adecuadamente los campos privados de la clase
		
		SetSalarios (ingresos_totales_nomina);
	}

	/*****************************************************************/
	// M�todo Set para los dos campos privados. 
	// Reparte los beneficios brutos totales entre entre los 
	// (3) fabricantes y el (1) dise�ador de un producto, sabiendo que 
	// el dise�ador cobra el doble que cada uno de los fabricantes. 
	// 
	// Recibe: "ingresos_totales", los ingresos brutos totales de 
	//			la empresa.
	// PRE: ingresos_totales >= 0
	
	void SetSalarios (double ingresos_totales)
	{
		salario_bruto_fabricante = ingresos_totales / 5.0;
		salario_bruto_diseniador = 2.0 * salario_bruto_fabricante;
	}
	
   	/*****************************************************************/
	// M�todos de c�lculo. 
	// Los m�todos "SalarioBrutoDiseniador" y "SalarioBrutoFabricante" 
	// devuelven los salarios brutos de dise�ador y fabricantes, resp.

	double SalarioBrutoDiseniador (void)
	{
		return (salario_bruto_diseniador);
	}

	double SalarioBrutoFabricante (void)
	{
		return (salario_bruto_fabricante);
	}
	
	/*****************************************************************/
	
};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/

int main (void)
{
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	// Lectura de datos
	
	double	ingresos_una_empresa;

	do {
		cout << "Introduzca cantidad total de ingresos: ";
		cin >> ingresos_una_empresa;
	} while (ingresos_una_empresa < 0);


	// Creaci�n de un objeto "Nomina" --> constructor
  
	Nomina nomina_empresa (ingresos_una_empresa);
	
	
	// Presentaci�n de resultados

	cout << endl << endl; 
	cout << "N�mina (sueldo bruto):" << endl;
	cout << "\tDise�ador =   " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioBrutoDiseniador() << endl; 
	cout << "\tFabricantes = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioBrutoFabricante() << endl; 
		 	 
	cout << endl << endl;  	 
	cout << "Resumen:" << endl;
	cout << "\tDise�ador =   " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioBrutoDiseniador()
		 << " ---------> " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioBrutoDiseniador() << endl;
	cout << "\tFabricantes = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioBrutoFabricante()
		 << " -- x 3 --> " << setw(10) << setprecision(2) 
		 << 3.0 * nomina_empresa.SalarioBrutoFabricante() << endl;
	cout << "                                              ---------";
	cout << endl;
	cout << "                                            "
		 << setw(10) << setprecision(2) 
		 << (nomina_empresa.SalarioBrutoDiseniador() + 
		 	3.0 * nomina_empresa.SalarioBrutoFabricante()) << endl;
	cout << endl << endl;
	
	return (0);
}
