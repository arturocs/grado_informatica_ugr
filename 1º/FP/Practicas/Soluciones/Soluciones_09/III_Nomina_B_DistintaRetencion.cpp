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
// EJERCICIO 19 (Apartado b - variante)
/*
	Este programa ampl�a la funcionalidad descrita en los ejercicios 
	5 y 12 de la Relaci�n de Problemas I acerca del reparto de ganancias 
	entre los 3 fabricantes y el dise�ador de un producto sabiendo que 
	el dise�ador cobra el doble que cada uno de los fabricantes. 

	1) S�lo gestionamos la n�mina de una empresa. 
	2) Hay un fabricante y tres dise�adores. 
	3) Los salarios brutos se obtienen al repartir los ingresos de la 
	   empresa, de forma que el dise�ador cobra el doble de cada fabricante.
	4) NOVEDAD DE ESTA VARIANTE: Se aplica una retenci�n fiscal a los 
	   salarios brutos, DIFERENTE para para los fabricantes y el dise�ador. 
	5) Una vez que se establezcan las retenciones fiscales, no cambian.

	El programa lee el valor de los ingresos totales y las retenciones 
	a aplicar y calcula los salarios brutos y netos de los fabricantes 
	y dise�ador, llamando a los m�todos oportunos de la clase Nomina.
*/
/*********************************************************************/


#include <iostream>
#include <iomanip>
using namespace std;


//	Como norma general no debemos usar funciones globales.
//	Sin embargo, hay casos en los que s� puede justificarse su uso.
//	Por ejemplo, cuando trabajamos con datos simples (int, double, etc) 
//	y son funciones muy gen�ricas que se usar�n en muchos otros programas.
//	Tal es el caso de la funci�n AplicaRetencion() y CalculaPorcentaje()


/*********************************************************************/
// Decrementa "valor_bruto" en el porcentaje indicado por 
// "retencion_porcentual" y devuelve el valor disminuido 

double AplicaRetencion (double valor_bruto, double retencion_porcentual)
{
	return (valor_bruto * (1 - (retencion_porcentual/100.0)));
}

/*********************************************************************/
// Calcula el "porcentaje" de "total" y lo devuelve

double CalculaPorcentaje (double total, double porcentaje)
{
	return ((total*porcentaje) /100.0);
}

///////////////////////////////////////////////////////////////////////
//	Notas de dise�o sobre la clase "Nomina": 
/*
	Todos los objetos de la clase "Nomina" tienen la misma retenci�n. 
	Podr�a emplearse una constante est�tica (constante a nivel de clase) 
	con el valor de retenci�n fiscal a aplicar si �sta fuera conocida en 
	tiempo de compilaci�n.
	
	Como el programa pide que el usuario introduzca la retenci�n a aplicar, 
	debe usarse una constante a nivel de objeto, que se inicia mediante 
	el constructor. 
	
	En este caso la clase "Nomina" s�lo sirve para la retenci�n fijada. 
	Habr�a que cambiar la definici�n de la clase si se quisiese aplicar 
	otra retenci�n.
*/

class Nomina
{

private:
	
	// PRE: salario_bruto_diseniador >= 0
	double salario_bruto_diseniador;
	
	// PRE: salario_bruto_fabricante >= 0
	double salario_bruto_fabricante;

	// Constantes a nivel de objeto
	// PRE: 0 <= PORC_RETENCION_FISCAL_DISENIADOR <= 100
	// PRE: 0 <= PORC_RETENCION_FISCAL_FABRICANTE <= 100	
   const double PORC_RETENCION_FISCAL_DISENIADOR; 
   const double PORC_RETENCION_FISCAL_FABRICANTE;
   
   
public:   

	/*****************************************************************/
	// Constructor con argumentos
	// Constructor con argumentos
	// Se encarga de inicar adecuadamente los campos privados de la clase
	// 
	// Recibe: "ingresos_totales_nomina", los ingresos brutos totales de 
	//			la empresa.
	// PRE: ingresos_totales_nomina >= 0
	// PRE: 0 <= porc_retencion_diseniador <= 100
	// PRE: 0 <= porc_retencion_fabricante <= 100
	
	Nomina (double ingresos_totales_nomina, 
			double porc_retencion_diseniador, 
			double porc_retencion_fabricante) : 
			PORC_RETENCION_FISCAL_DISENIADOR (porc_retencion_diseniador), 
			PORC_RETENCION_FISCAL_FABRICANTE (porc_retencion_fabricante)
	{
		SetIngresosTotales (ingresos_totales_nomina);
	}

	/*****************************************************************/
	// M�todo Set para los dos campos privados. 
	// Reparte los beneficios entre entre los fabricantes (3) y el 
	// dise�ador (1) de un producto sabiendo que el dise�ador cobra el 
	// doble que cada uno de los fabricantes. 
	// 
	// Recibe: "ingresos_totales", los ingresos brutos totales de 
	//			la empresa.
	// PRE: ingresos_totales >= 0
	
	void SetIngresosTotales (double ingresos_totales)
	{
		salario_bruto_fabricante = ingresos_totales / 5.0;
		salario_bruto_diseniador = 2.0 * salario_bruto_fabricante;
	}

   	/*****************************************************************/
	// M�todos Get para los porcentajes de retenci�n

	int GetPorcRetencionFiscalFabricante()
	{
      return (PORC_RETENCION_FISCAL_FABRICANTE);
	}

	int GetPorcRetencionFiscalDiseniador()
	{
      return (PORC_RETENCION_FISCAL_DISENIADOR);
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
	
	// Los m�todos "SalarioNetoDiseniador" y "SalarioNetoFabricante" 
	// calculan los salarios netos despu�s de reducir la retenci�n 
	// correspondiente.

	double SalarioNetoDiseniador(void)
	{
		return (AplicaRetencion (salario_bruto_diseniador, 
							    PORC_RETENCION_FISCAL_DISENIADOR));
	}

	double SalarioNetoFabricante(void)
	{
		return (AplicaRetencion (salario_bruto_fabricante, 
							    PORC_RETENCION_FISCAL_FABRICANTE));
	}

	/*****************************************************************/
	// M�todo de c�lculo. 
	// Calcula el dinero a pagar por impuestos

	double CalculaImpuestosTotales (void)
	{
		double imp_fabricante, imp_diseniador;

		imp_fabricante = salario_bruto_fabricante - SalarioNetoFabricante();
		imp_diseniador = salario_bruto_diseniador - SalarioNetoDiseniador();

		return (3.0*imp_fabricante + imp_diseniador);
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

	double	porc_retencion_diseniador;
	double	porc_retencion_fabricante;

	do {
		cout << "Introduzca porcentaje de retenci�n del dise�ador: ";
		cin >> porc_retencion_diseniador;
	} while ((porc_retencion_diseniador<0) || (porc_retencion_diseniador>100));

	do {
		cout << "Introduzca porcentaje de retenci�n de los fabricantes: ";
		cin >> porc_retencion_fabricante;
	} while ((porc_retencion_fabricante<0) || (porc_retencion_fabricante>100));
	
	// Durante la ejecuci�n del programa, el objeto "una_nomina" mantendr� 
	// constantes los valores de las retenciones. Adem�s, todos los objetos 
	// de la clase "nomina" tendr�n los mismos valores para las constantes, 
	// cuyos valores se leen en tiempo de ejecuci�n. 

	// Creaci�n de un objeto "Nomina" --> constructor
  	
	Nomina nomina_empresa (ingresos_una_empresa, 
						   porc_retencion_diseniador, 
						   porc_retencion_fabricante);


	// Presentaci�n de resultados
	
	// Sueldos brutos
	cout << endl << endl; 
	cout << "N�mina (sueldo bruto):" << endl;
	cout << "\tDise�ador =  " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioBrutoDiseniador() << endl; 
	cout << "\tFabricante = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioBrutoFabricante() << endl; 
	cout << endl << endl; 
	
	// Sueldo neto del dise�ador indicando la retenci�n aplicada
	cout << "Sueldo neto (dise�ador):" << endl;
	cout << "\tSueldo bruto =        " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioBrutoDiseniador() << endl;
	cout << "\tRetencion (" << setw(5) << setprecision(2) 
		 << nomina_empresa.GetPorcRetencionFiscalDiseniador() << " %) = " 
		 << setw(10) << setprecision(2) 		 	
		 << CalculaPorcentaje (nomina_empresa.SalarioBrutoDiseniador(), 
		 				nomina_empresa.GetPorcRetencionFiscalDiseniador());  
	cout << endl; 		 
	cout << "\t                      ----------" << endl;
	cout << "\t                      " 
		 << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoDiseniador() << endl;
	
	// Sueldo neto de cada fabricante indicando la retenci�n aplicada		   
	cout << endl; 		 
	cout << "Sueldo neto (fabricante):" << endl;
	cout << "\tSueldo bruto =        " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioBrutoFabricante() << endl; 
	cout << "\tRetencion (" << setw(5) << setprecision(2) 
		 << nomina_empresa.GetPorcRetencionFiscalFabricante() << " %) = "
		 << setw(10) << setprecision(2) 		 	
		 << CalculaPorcentaje (nomina_empresa.SalarioBrutoFabricante(), 
		 				nomina_empresa.GetPorcRetencionFiscalFabricante());  
	cout << endl; 		 
	cout << "\t                      ----------" << endl;
	cout << "\t                      " 
		 << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoFabricante() << endl;		 

	// N�mina final detallada
	cout << endl << endl; 
	cout << "N�mina (sueldo neto):" << endl;
	cout << "\tDise�ador   = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoDiseniador()
		 << " -------> " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoDiseniador() << endl;
	cout << "\tFabricantes = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoFabricante()
		 << " (x 3) -> " << setw(10) << setprecision(2) 
		 << 3.0 * nomina_empresa.SalarioNetoFabricante() << endl;
	cout << "\nImpuestos totales =                       " 
		 << setw(10) << setprecision(2) 
		 << nomina_empresa.CalculaImpuestosTotales();
	cout << "\n                                           ---------";
	cout << "\n                                          "
		 << setw(10) << setprecision(2) 
		 << (nomina_empresa.SalarioNetoDiseniador() + 
		    (3 * nomina_empresa.SalarioNetoFabricante()) + 
		    nomina_empresa.CalculaImpuestosTotales());
	cout << endl << endl;
	
	return (0);
}

