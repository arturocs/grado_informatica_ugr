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
// EJERCICIO 19 (Apartado c)
/*
	Este programa ampl�a la funcionalidad descrita en los ejercicios 
	5 y 12 de la Relaci�n de Problemas I acerca del reparto de ganancias 
	entre los fabricantes y el dise�ador de un producto. 

	1) Gestiona varias sucursales y cada una tiene su propia n�mina. 
	2) Cada sucursal tiene un �nico dise�ador. Se lleva una parte del total. 
	3) El n�mero de fabricantes puede ser distinto entre diferentes sucursales.
	   Se reparte equitativamente el resto de descontar la parte del dise�ador. 
	4) El n�mero de fabricantes en una sucursal NO cambia. 
	5) Los salarios brutos se obtienen al repartir los ingresos de la 
	   empresa
	6) Se aplica una retenci�n fiscal a los salarios brutos, DIFERENTE 
	   para para los fabricantes y el dise�ador. 
	7) Una vez que se establezcan las retenciones fiscales, NO cambian.
	
	El programa leer� los siguientes datos desde un fichero externo:
	* El n�mero de sucursales.
	* Los siguientes valores por cada una de las sucursales:
		� Ingresos totales a repartir
		� N�mero de fabricantes
		� Parte que se lleva el dise�ador
		� Retenci�n fiscal del dise�ador
		� Retenci�n fiscal de los fabricantes
	
	Por ejemplo, el siguiente fichero indica que hay dos sucursales. 
	La primera tiene unos ingresos de 300 euros, 3 fabricantes, el dise�ador 
	se lleva 1/6, la retenci�n del dise�ador es del 20% y la de cada 
	fabricante un 18 %. 
	Los datos para la segunda son 400 euros, 5 fabricantes, 1/4, 22% y 19 %.
	
		2
		300 3 6 20 18
		400 5 4 22 19

	El programa tendr� que imprimir el salario neto del dise�ador y de los fabricantes
	por cada una de las sucursales, llamando a los m�todos oportunos de la clase
	Nomina.
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
	
	Igual ocurre con el n�mero de fabricantes. 
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

   	// PRE: NUM_FABRICANTES >= 1
   const int NUM_FABRICANTES;

   	// PRE: PARTE_DISENIADOR >= 1
   const int PARTE_DISENIADOR;
   
public:   

	/*****************************************************************/
	// Constructor con argumentos
	// Constructor con argumentos
	// Se encarga de inicar adecuadamente los campos privados de la clase
	// 
	// Recibe: "ingresos_totales_nomina", los ingresos brutos totales de 
	//			la empresa.
	// PRE: ingresos_totales_nomina >= 0
	// PRE: num_fabricantes > 0
	// PRE: parte_diseniador > 0	
	// PRE: 0 <= porc_retencion_diseniador <= 100
	// PRE: 0 <= porc_retencion_fabricante <= 100
	
	Nomina (double ingresos_totales_nomina, 
			int num_fabricantes, 
			int parte_diseniador, 
			double porc_retencion_diseniador, 
			double porc_retencion_fabricante) : 
			NUM_FABRICANTES (num_fabricantes),
			PARTE_DISENIADOR (parte_diseniador),
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
		salario_bruto_diseniador = ingresos_totales / PARTE_DISENIADOR;
		
		// Lo que queda, descontada la parte del dise�ador, se reparte 
		// equitativamente entre los fabricantes
		double resto = ingresos_totales - salario_bruto_diseniador;		
		salario_bruto_fabricante = resto / NUM_FABRICANTES;
	}

   	/*****************************************************************/
	// M�todos Get 
 
	int GetPorcRetencionFiscalFabricante()
	{
      return (PORC_RETENCION_FISCAL_FABRICANTE);
	}

	int GetPorcRetencionFiscalDiseniador()
	{
      return (PORC_RETENCION_FISCAL_DISENIADOR);
	}

	int GetNumFabricantes(void)
	{
      return (NUM_FABRICANTES);
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

		return ((NUM_FABRICANTES*imp_fabricante) + imp_diseniador);
	}

   	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/
/*
	NOTA DE DISE�O: EL programa lee los datos por redirecci�n de la entrada.
	Asumimos que los datos son correctos, por lo que:
		1) NO se etiquetan las entradas, y 
		2) NO se implmentan filtros para la lectura de datos
*/

int main (void)
{
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	// Lectura del n�mero de sucursales 
	
	int num_sucursales; 
	cin >> num_sucursales;
	
	
	// Como desconocemos a priori el n�mero de sucursales, usaremos una �nica 
	// variable "Nomina" llamada "nomina_empresa"
	// El objeto "nomina_empresa" se crea, iniciliza y procesa en cada 
	// iteraci�n del ciclo for siguiente (no sabemos c�mo guardar TODAS las 
	// n�minas en memoria) de ah� que se declare DENTRO del ciclo. 
	
	for (int sucursal = 1; sucursal <= num_sucursales; sucursal++) {

		double	ingresos_una_empresa;
		int 	num_fabricantes;
		int 	parte_diseniador; 
		double	porc_retencion_diseniador;
		double	porc_retencion_fabricante;

		// Lectura de los datos de una sucursal
		
		cin >> ingresos_una_empresa;
		cin >> num_fabricantes;
		cin >> parte_diseniador;
		cin >> porc_retencion_diseniador;
		cin >> porc_retencion_fabricante;

		
		// Durante la ejecuci�n del programa, el objeto "una_nomina" mantendr� 
		// constantes los valores de las retenciones y del n�mero de fabricantes. 
	
		// Creaci�n de un objeto "Nomina" --> constructor
	  	
		Nomina nomina_empresa (ingresos_una_empresa, 
							   num_fabricantes, 
							   parte_diseniador, 
							   porc_retencion_diseniador, 
							   porc_retencion_fabricante);
	
	
		// Presentaci�n de resultados
		
		cout << endl << endl; 
		cout << "*************" << endl;		
		cout << "SUCURSAL "<< sucursal << endl;
		cout << "*************" << endl;		
		cout << endl << endl; 
		
		// Sueldos brutos
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
			 << " (x " << nomina_empresa.GetNumFabricantes() << ") -> " 
			 << setw(10) << setprecision(2) 
			 << (nomina_empresa.GetNumFabricantes() * 
			     nomina_empresa.SalarioNetoFabricante()) << endl;
		cout << "\nImpuestos totales =                       " 
			 << setw(10) << setprecision(2) 
			 << nomina_empresa.CalculaImpuestosTotales();
		cout << "\n                                           ---------";
		cout << "\n                                          "
			 << setw(10) << setprecision(2) 
			 << (nomina_empresa.SalarioNetoDiseniador() + 
			    (nomina_empresa.GetNumFabricantes() * 
				 nomina_empresa.SalarioNetoFabricante()) + 
			    nomina_empresa.CalculaImpuestosTotales());
		cout << endl << endl;

	} // for sucursales
		 
	return (0);
}

