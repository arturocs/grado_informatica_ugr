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
// EJERCICIO 19 (Apartado b - variante)
/*
	Este programa amplía la funcionalidad descrita en los ejercicios 
	5 y 12 de la Relación de Problemas I acerca del reparto de ganancias 
	entre los 3 fabricantes y el diseñador de un producto sabiendo que 
	el diseñador cobra el doble que cada uno de los fabricantes. 

	1) Sólo gestionamos la nómina de una empresa. 
	2) Hay un fabricante y tres diseñadores. 
	3) Los salarios brutos se obtienen al repartir los ingresos de la 
	   empresa, de forma que el diseñador cobra el doble de cada fabricante.
	4) NOVEDAD DE ESTA VARIANTE: Se aplica una retención fiscal a los 
	   salarios brutos, DIFERENTE para para los fabricantes y el diseñador. 
	5) Una vez que se establezcan las retenciones fiscales, no cambian.

	El programa lee el valor de los ingresos totales y las retenciones 
	a aplicar y calcula los salarios brutos y netos de los fabricantes 
	y diseñador, llamando a los métodos oportunos de la clase Nomina.
*/
/*********************************************************************/


#include <iostream>
#include <iomanip>
using namespace std;


//	Como norma general no debemos usar funciones globales.
//	Sin embargo, hay casos en los que sí puede justificarse su uso.
//	Por ejemplo, cuando trabajamos con datos simples (int, double, etc) 
//	y son funciones muy genéricas que se usarán en muchos otros programas.
//	Tal es el caso de la función AplicaRetencion() y CalculaPorcentaje()


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
//	Notas de diseño sobre la clase "Nomina": 
/*
	Todos los objetos de la clase "Nomina" tienen la misma retención. 
	Podría emplearse una constante estática (constante a nivel de clase) 
	con el valor de retención fiscal a aplicar si ésta fuera conocida en 
	tiempo de compilación.
	
	Como el programa pide que el usuario introduzca la retención a aplicar, 
	debe usarse una constante a nivel de objeto, que se inicia mediante 
	el constructor. 
	
	En este caso la clase "Nomina" sólo sirve para la retención fijada. 
	Habría que cambiar la definición de la clase si se quisiese aplicar 
	otra retención.
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
	// Método Set para los dos campos privados. 
	// Reparte los beneficios entre entre los fabricantes (3) y el 
	// diseñador (1) de un producto sabiendo que el diseñador cobra el 
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
	// Métodos Get para los porcentajes de retención

	int GetPorcRetencionFiscalFabricante()
	{
      return (PORC_RETENCION_FISCAL_FABRICANTE);
	}

	int GetPorcRetencionFiscalDiseniador()
	{
      return (PORC_RETENCION_FISCAL_DISENIADOR);
	}

	/*****************************************************************/
	// Métodos de cálculo. 
	
	// Los métodos "SalarioBrutoDiseniador" y "SalarioBrutoFabricante" 
	// devuelven los salarios brutos de diseñador y fabricantes, resp.

	double SalarioBrutoDiseniador (void)
	{
		return (salario_bruto_diseniador);
	}

	double SalarioBrutoFabricante (void)
	{
		return (salario_bruto_fabricante);
	}
	
	// Los métodos "SalarioNetoDiseniador" y "SalarioNetoFabricante" 
	// calculan los salarios netos después de reducir la retención 
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
	// Método de cálculo. 
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
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
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
		cout << "Introduzca porcentaje de retención del diseñador: ";
		cin >> porc_retencion_diseniador;
	} while ((porc_retencion_diseniador<0) || (porc_retencion_diseniador>100));

	do {
		cout << "Introduzca porcentaje de retención de los fabricantes: ";
		cin >> porc_retencion_fabricante;
	} while ((porc_retencion_fabricante<0) || (porc_retencion_fabricante>100));
	
	// Durante la ejecución del programa, el objeto "una_nomina" mantendrá 
	// constantes los valores de las retenciones. Además, todos los objetos 
	// de la clase "nomina" tendrán los mismos valores para las constantes, 
	// cuyos valores se leen en tiempo de ejecución. 

	// Creación de un objeto "Nomina" --> constructor
  	
	Nomina nomina_empresa (ingresos_una_empresa, 
						   porc_retencion_diseniador, 
						   porc_retencion_fabricante);


	// Presentación de resultados
	
	// Sueldos brutos
	cout << endl << endl; 
	cout << "Nómina (sueldo bruto):" << endl;
	cout << "\tDiseñador =  " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioBrutoDiseniador() << endl; 
	cout << "\tFabricante = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioBrutoFabricante() << endl; 
	cout << endl << endl; 
	
	// Sueldo neto del diseñador indicando la retención aplicada
	cout << "Sueldo neto (diseñador):" << endl;
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
	
	// Sueldo neto de cada fabricante indicando la retención aplicada		   
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

	// Nómina final detallada
	cout << endl << endl; 
	cout << "Nómina (sueldo neto):" << endl;
	cout << "\tDiseñador   = " << setw(10) << setprecision(2) 
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

