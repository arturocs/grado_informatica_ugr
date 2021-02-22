/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//  
// CURSO 2014-2015
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS V
// EJERCICIO 21
//
/*	 
	Programa que crear una matriz dentada de valores reales leyendo sus 
	valores de la entrada estándar y realizar cálculos con ella.
	En concreto, este programa calcula la suma de los valores de cada grupo.
	
	Todos los valores necesarios (número de secuencias, número de datos de 
	cada secuencia y los valores de cada secuencia) se introducen en una 
	sola línea.
	
	.........................................................................
	Representación: matriz "clásica".
	.........................................................................
	
	Por ejemplo, una línea de entrada podría ser la siguiente:
	
		3 2 3.1 0.4 5 1.0 1.0 1.0 1.0 1.0 2 5.2 4.7
	
		--> Se distinguen tres grupos o secuencias de datos (lo indica el
			primer número (int) de la línea). 
		-->	Cada grupo empieza por un valor (int) que indica el tamaño de la
			secuencia (en el ejemplo, las secuencias tienen dos, cinco y dos
			elementos, respectivamente). 
		-->	A continuación de este valor se encentran tantos valores (double)
			como indique el valor entero que encabeza cada grupo.
	
		En el ejemplo, la primera secuencia contendrá los valores 3.1 y 0.4, 
		la segunda 1.0, 1.0, 1.0, 1.0 y 1.0 y la tercera 5.2 y 4.7.
	
		El programa escribe como resultado: 3.5, 5.0 y 9.9
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

/////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////

class SecuenciaReales  
{

	// ......
	
};

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// Tabla dentada de datos double
//
// Representación: matriz "clásica"

class TablaDentadaReales 
{
private:

  	static const int MAX_FIL = 50;  // Filas disponibles
    static const int MAX_COL = 40;  // Columnas disponibles

    double matriz_privada[MAX_FIL][MAX_COL];

    // PRE: 0 <= filas_utilizadas < MAX_FIL

    int filas_utilizadas;

    // PRE: 0 <= num_cols_utilizadas[i] < MAX_COL
    //      para i=0,1,...,filas_utilizadas-1
    // Número de columnas ocupadas en cada fila

    int num_cols_utilizadas[MAX_FIL];
	
public:
	
	/***********************************************************************/
	// Constructor sin argumentos

	TablaDentadaReales (void) 	
	{
		filas_utilizadas = 0;
	}

	/***********************************************************************/
	// Devuelve el número de casillas disponibles
	
	int CapacidadFilas (void)
	{
		return (MAX_FIL);
	}
	
	/*****************************************************************/
	// Método de lectura: número máximo de columnas

	int CapacidadColumnas (void)
	{
		return (MAX_COL);
	}
	
	/*****************************************************************/
	// Método de lectura: número real de filas usadas

	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}
			
	/*****************************************************************/
	// Método de lectura: número real de columnas usadas en la fila "fila"
	// 
	// PRE: 0 <= fila < filas_utilizadas
	
	int ColumnasUtilizadas (int fila)
	{
		return (num_cols_utilizadas[fila]);
	}
	
	/*****************************************************************/
	// Método de lectura: devuelve el dato que ocupa la casilla 
	// de coordenadas (fila, columna)
	//
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < num_cols_utilizadas[fila]	
	
	double Elemento (int fila, int columna)
	{
		return (matriz_privada[fila][columna]);
	}
	
	/*****************************************************************/
	// Devuelve una fila completa, como un objeto de la clase 
	// "SecuenciaReales"
	//
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaReales Fila (int indice_fila)
	{
		SecuenciaReales la_fila;
					
		if ((0 <= indice_fila) && (indice_fila < filas_utilizadas)) {
					
			int num_columnas = num_cols_utilizadas[indice_fila];
			
			for (int c=0; c<num_columnas; c++) 
				la_fila.Aniade (matriz_privada[indice_fila][c]);
		}
		return (la_fila);
	}
	
	/***********************************************************************/
	// Añade una fila completa. La fila se porporciona en un objeto de 
	// la clase "SecuenciaReales".
	// 
	// PRE:  fila_nueva.TotalUtilizados() <= MAX_COL
	// PRE:  filas_utilizadas < MAX_FIL
	//
	// 		La adición se realiza si hay espacio para el nuevo elemento. 
	// 		El nuevo elemento se coloca al final del vector. 
	// 		Si no hay espacio, no se hace nada.	
	
	void Aniade (SecuenciaReales fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		if ((filas_utilizadas < MAX_FIL) && 
			(numero_columnas_fila_nueva <= MAX_COL)) {

			for (int c=0; c<numero_columnas_fila_nueva; c++) 
				matriz_privada[filas_utilizadas][c] = fila_nueva.Elemento(c);

			num_cols_utilizadas[filas_utilizadas]=numero_columnas_fila_nueva;
			
			filas_utilizadas++;

		}
	}

	/*****************************************************************/
	// Inserta una fila completa en una posición dada. 
	// La fila se porporciona en un objeto "SecuenciaReales".
	// 
	// Recibe: num_fila, la posición que ocupará "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase SecuenciaReales. 
	//
	// PRE:  fila_nueva.TotalUtilizados() <= MAX_COL
	// PRE:  filas_utilizadas < MAX_FIL
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" será la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" será la nueva 
	//		 última fila (el resultado será equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaReales fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		// Comprobar precondiciones
		
		if ((filas_utilizadas < MAX_FIL) && 
			(numero_columnas_fila_nueva <= MAX_COL) && 
			(0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La última fila se copia en una NUEVA FILA que ocupa la 
			// posición "filas_utilizadas", la penúltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todavía) "filas_utilizadas" 
			
			for (int fil=filas_utilizadas; fil>num_fila; fil--) {	
			
				int num_columnas = num_cols_utilizadas[fil-1];
					
				for (int c=0; c<num_columnas; c++) 
					matriz_privada[fil][c] = matriz_privada[fil-1][c]; 
					
				num_cols_utilizadas[fil] = num_cols_utilizadas[fil-1];
			}
					
			// Copiar en el "hueco" (fila "num_fila") el contenido de 
			// la secuencia "fila_nueva"
			
			for (int c=0; c<numero_columnas_fila_nueva; c++) 
				matriz_privada[num_fila][c] = fila_nueva.Elemento(c);
			
			num_cols_utilizadas[num_fila] = numero_columnas_fila_nueva;
			
			filas_utilizadas++; // Actualización del tamaño de la tabla.
		}
	}

	/*****************************************************************/
	// Elimina una fila completa, dada una posición. 
	// 
	// Recibe: num_fila, la posición de la fila a eliminar.
	//
	// PRE:  0 <= num_fila < TotalUtilizados()
	
	void Elimina (int num_fila)
	{		
		// Comprobar precondiciones
		
		if ((0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones bajas. 
			// En la posición "num_fila" se copia la que está en la posición
			// siguiente ("num_fila"+1), en su lugar se copia que está en 
			// "num_fila"+2, ... y en la posición "total_utilizados"-2 se 
			// copia la de "total_utilizados"-1. 
			
			for (int fil=num_fila; fil<filas_utilizadas-1; fil++) {
			
				int num_columnas = num_cols_utilizadas[fil+1];
					
				for (int c=0; c<num_columnas; c++) 
					matriz_privada[fil][c]=matriz_privada[fil+1][c];
					
				num_cols_utilizadas[fil] = num_cols_utilizadas[fil+1];
			}
			
			filas_utilizadas--; // Actualización del tamaño de la tabla.
		}
	}
		
	/***********************************************************************/
	// "Vacía" una tabla
	
	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}
	
	/***********************************************************************/
	// Devuelve true si la tabla está vacía

	bool EstaVacia (void) 
	{
		return (filas_utilizadas == 0);
	}
	
	/*****************************************************************/
	// Calcula si dos matrices dentadas son iguales

	bool EsIgual (TablaDentadaReales otra_tabla)
	{
		bool son_iguales = true; 
		
		if (filas_utilizadas != otra_tabla.FilasUtilizadas())
			
			son_iguales = false;
		
		else {
			
			int f=0; 
			
			while (f<filas_utilizadas && son_iguales) {
				
				if (num_cols_utilizadas[f] != otra_tabla.ColumnasUtilizadas(f)) 
				
					son_iguales = false;	
				
				else {
					
					int c=0; 
					
					while (c<num_cols_utilizadas[f] && son_iguales) {
				
						if (matriz_privada[f][c] != otra_tabla.Elemento(f,c)) 
							son_iguales = false;
							
						c++;
						
					} // while c
		
					f++;
					
				} // else 
					
			} // while f
					
		} // else 
	
		return (son_iguales);
	}
	
	/***********************************************************************/
			
};

/////////////////////////////////////////////////////////////////////////////



/***************************************************************************/
// Mostrar el contenido de "tabla".  
// Se muestra el encabezamiento indicado en "titulo".

void MuestraTablaDentada (TablaDentadaReales tabla, string titulo)
{
	cout << endl;
	cout <<  titulo << endl; 	
	cout << endl;
	cout << "------------------------------------------------------" << endl; 
	
	int num_filas = tabla.FilasUtilizadas();
	
	for (int fila=0; fila<num_filas; fila++) {

		
		SecuenciaReales la_secuencia = tabla.Fila(fila);
		
		int num_datos = la_secuencia.TotalUtilizados();

		cout << "Secuencia " << setw(2) << fila+1; 
		cout << " (" << setw(2) << num_datos << " datos): "; 
			
		for (int num_dato=0; num_dato<num_datos; num_dato++) {
			double dato = la_secuencia.Elemento(num_dato);
			cout << setw(6) << setprecision(2) << dato;
		}
		cout << endl;
	}
	cout << "------------------------------------------------------" << endl; 	
	cout << endl << endl;	
	
}

/***************************************************************************/

int main (void)
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	// La "TablaDentadaReales" que se va a formar. 
	// Inicialmente, vacía. 
	
	TablaDentadaReales tabla; 


	// Leer los datos y formar la tabla
		
	cout << endl;
	cout << "Introduzca los valores: ";

	int num_secuencias;		// Primer valor: número de secuencias
	cin >> num_secuencias;
	
	for (int num_sec=0; num_sec<num_secuencias; num_sec++) {

		// Para cada secuencia
		
		SecuenciaReales una_secuencia; // Inicialmente vacía
		
		int num_datos;		// Número de datos que forman la secuencia
		cin >> num_datos;
		
		for (int num_dato=0; num_dato<num_datos; num_dato++) {
			
			// Para cada dato 
			
			double dato;	// Dato "num_dato" de la secuencia "num_sec"
			cin >> dato;
			
			una_secuencia.Aniade(dato); // Añadir dato a "una_secuencia"
		}
		
		tabla.Aniade(una_secuencia); // Añadir secuencia a "tabla"
	}
	

	// Mostrar los datos leidos
	
	MuestraTablaDentada (tabla, "Tabla leida."); 	
	
	
	// Calcular la suma de cada secuencia, guardando los resultados en 
	// una nueva secuencia de reales llamada "sumas"
	
	SecuenciaReales sumas; // Secuencia de sumas
		
	// Para cada secuencia, calcular la suma y añadirla a "sumas"

	// Número de secuencias en "tabla" 
	int num_secuencias_en_tabla = tabla.FilasUtilizadas();
	
	for (int num_sec=0; num_sec<num_secuencias_en_tabla; num_sec++) {

		// Extraer una copia de la secuencia número "num_sec" desde "tabla"
		SecuenciaReales una_secuencia = tabla.Fila(num_sec);
		
		double suma = 0.0; // Iniciar el acumulador 

		// Número de elementos de la secuencia actual
		int num_datos = una_secuencia.TotalUtilizados();

		// Sumar los elementos de la secuencia
		for (int num_dato=0; num_dato<num_datos; num_dato++) 
			suma += una_secuencia.Elemento(num_dato);
		
		// Añadir la suma a la secuencia de sumas
		sumas.Aniade(suma);
	}
	
	// Mostrar los valores de la secuencia "sumas"
	
	int num_sumas = sumas.TotalUtilizados();
	
	for (int n=0; n<num_sumas; n++) {
		
		double suma_secuencia_n = sumas.Elemento(n); 
		
		cout << "Suma de secuencia " << setw(2) << n+1; 
		cout << " = " << setw(6)<<setprecision(2) << suma_secuencia_n << endl;
	}		
	cout << endl;
	
	return (0);
}
