/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS V
// EJERCICIO 15
//
/*	
	Este programa amplia la clase "TablaRectangularCaracteres", clase 
	sobre la que se ha trabajado en los ejercicios 13 y 14.  

	Se emplea como dato miembro privado una matriz "clásica".

	En este programa se incorporan dos métodos a la clase:
	
	1)  Inserta(), que permite insertar una fila completa en una 
		posición (de fila) determinada:
	
			void Inserta (int num_fila, SecuenciaCaracteres fila_nueva);
		
		Tras la inserción, la tabla tiene una fila más, la fila de la 
		posición "num_fila" contiene una copia de "fila_nueva", la fila que 
		ocupaba la posición  "num_fila" está en la posición "num_fila"+1, 
		la de "num_fila"+1 en "num_fila"+2, y así sucesivamente.
		
	2) Elimina(), que borra una fila completa de la matriz, 
	
			void Elimina (int num_fila);
		
		Tras la eliminación, la tabla tiene una fila menos: la que ocupaba 
		la posición "num_fila".
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////

class SecuenciaCaracteres  
{

private:

	static const int TAMANIO = 50; // Número de casillas disponibles
	char vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas

public:
	
	/*
		Métodos de la clase "SecuenciaCaracteres"
	*/
};

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// La clase "PosicionEnMatriz" es útil para representar posiciones 
// (coordenadas) en una tabla bidimensional.

class PosicionEnMatriz
{
private:
	int fila;
	int columna;

public: 
	
	/*
		Métodos de la clase "PosicionEnMatriz"
	*/
};

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////

class TablaRectangularCaracteres
{

private:
	
	static const int MAX_FIL = 50; // Filas disponibles
    static const int MAX_COL = 40; // Columnas disponibles
    
    char matriz_privada[MAX_FIL][MAX_COL];

    // PRE: 0 <= filas_utilizadas < MAX_FIL
    // PRE: 0 <= col_utilizadas < MAX_COL
    
    int filas_utilizadas;
    int cols_utilizadas;

public:

	/*
		Otros métodos de la clase "TablaRectangularCaracteres"
	*/

	/*****************************************************************/
	// Añade una fila completa. La fila se porporciona en un objeto de 
	// la clase "SecuenciaCaracteres".
	// 
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	
	void Aniade (SecuenciaCaracteres fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		if ((filas_utilizadas < MAX_FIL) && 
			(numero_columnas_fila_nueva == cols_utilizadas)) {

			for (int col = 0; col < numero_columnas_fila_nueva; col++)
				matriz_privada[filas_utilizadas][col]=fila_nueva.Elemento(col);

			filas_utilizadas++;
		}
	}

	/*****************************************************************/
	// Inserta una fila completa en una posición dada. 
	// La fila se porporciona en un objeto "SecuenciaCaracteres".
	// 
	// Recibe: num_fila, la posición que ocupará "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase Secuenciacaracteres. 
	//
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" será la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" será la nueva 
	//		 última fila (el resultado será equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaCaracteres fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		// Comprobar precondiciones
		
		if ((filas_utilizadas < MAX_FIL) && 
			(numero_columnas_fila_nueva == cols_utilizadas) && 
			(0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La última fila se copia en una NUEVA FILA que ocupa la 
			// posición "filas_utilizadas", la penúltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todavía) "filas_utilizadas" 
			
			for (int fil=filas_utilizadas; fil>num_fila; fil--) {
				
				for (int col = 0; col < numero_columnas_fila_nueva; col++)
					matriz_privada[fil][col]=matriz_privada[fil-1][col];
			}
			
			// Copiar en el "hueco" (fila "num_fila") el contenido de 
			// la secuencia "fila_nueva"
			
			for (int col = 0; col < numero_columnas_fila_nueva; col++)
				matriz_privada[num_fila][col]=fila_nueva.Elemento(col);	
			
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
			
				int num_columnas = cols_utilizadas;
					
				for (int c=0; c<num_columnas; c++) 
					matriz_privada[fil][c]=matriz_privada[fil+1][c];
			}
			
			filas_utilizadas--; // Actualización del tamaño de la tabla.
		}
	}
	
	/***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////


/***************************************************************************/
	
int main (void)
{
	// Solicitar y filtrar las dimensiones de la tabla
	
	int num_filas, num_columnas; // filas y columnas de la tabla rectangular

	do{
		cout << "Número de filas: ";
		cin >> num_filas; 
	} while (num_filas < 0);

	do{
		cout << "Número de columnas: ";
		cin >> num_columnas; 
	} while (num_columnas < 0);


	// Crear la tabla (inicialmente vacía)
	
	TablaRectangularCaracteres matriz (num_columnas);


	// Lectura de los datos que compondrán la tabla

	cout << endl;
	cout << "Introduzca los caracteres de la matriz por filas:" << endl;
	cout << "(solo se consideraran los primeros " << setw(3) << num_columnas 
		 << " caracteres)" << endl;
	cout << endl;
	
	// Los datos que compondrán cada fila se leerán en un string.
	// De esta manera permitimos espacios en blanco.
	// A partir del string construimos una SecuenciaCaracteres y de esa 
	// secuencia nos quedaremos con los primeros "num_columnas" elementos.
	
	string una_cadena;

	for (int f=0; f<num_filas; f++) {

		cout << "Fila " << setw(3) << f << ": "; 

		// Leer cadena. Descartar las que sen demasiado cortas.  
		do {
			getline(cin, una_cadena);
		} while (una_cadena.length() < num_columnas);
/*		
		cout << "string = " << una_cadena;
		cout << endl << endl; 
*/			
		// Crear una secuencia a partir de la cadena leida
		SecuenciaCaracteres una_fila (una_cadena); 

/*
		cout << "una_fila = ";	
		cout << "|";
		for (int p=0; p<una_fila.TotalUtilizados(); p++)
			cout << una_fila.Elemento(p) << "|";
		cout << endl << endl; 
*/
			 
		// Nos quedamos con la subsecuencia inicial de tamaño "num_columnas"
		una_fila = una_fila.Subsecuencia(0,num_columnas); 
		
/*		
		cout << "una_fila (después de ajustar) = ";	
		cout << "|";
		for (int p=0; p<una_fila.TotalUtilizados(); p++)
			cout << una_fila.Elemento(p) << "|";
		cout << endl << endl;
*/	
		
		// Añadimos la secuencia a la matriz
		// Estamos seguros de que tiene el tamaño correcto. 
		
		matriz.Aniade (una_fila);
	}
	
	// Impresión de la tabla
	
	cout << endl << endl;
	cout << "Matriz original: " << endl;		
	cout << endl << endl;

	for (int f=0; f<matriz.FilasUtilizadas(); f++) {

		for (int c=0; c<matriz.ColumnasUtilizadas(); c++) {
			cout << matriz.Elemento(f,c) << "  ";	
		}
		cout << endl;
	}
	cout << endl << endl;


	
	// Inserción de una nueva fila
	
	// Lectura y filtrado de la posición de inserción

	int pos_insercion;
	
	do {	
		cout << "Posicion de insercion= ";
		cin >> pos_insercion;
	} while ((pos_insercion<0) || (pos_insercion>matriz.FilasUtilizadas()));

	// Petición de una nueva fila

	cout << "Contenido de la fila a insertar: ";
	
	// Leer cadena. Descartar las que saen demasiado cortas.  
	
	do {
		getline(cin, una_cadena);
	} while (una_cadena.length() < num_columnas);
	
	// Crear una secuencia a partir de la cadena leida
	SecuenciaCaracteres fila_a_insertar (una_cadena); 

	// Nos quedamos con la subsecuencia inicial de tamaño "num_columnas"
	fila_a_insertar = fila_a_insertar.Subsecuencia(0,num_columnas); 
		
		
	// Insertamos la secuencia en la matriz
	// Estamos seguros de que se cumplen las precondiciones. 
		
	matriz.Inserta (pos_insercion, fila_a_insertar);



	// Impresión de la tabla resultante después de la inserción 
	
	cout << endl << endl;
	cout << "Matriz tras la insercion: " << endl;		
	cout << endl << endl;
		
	for (int f=0; f<matriz.FilasUtilizadas(); f++) {

		for (int c=0; c<matriz.ColumnasUtilizadas(); c++) {
			cout << matriz.Elemento(f,c) << "  ";	
		}
		cout << endl;
	}
	cout << endl << endl;

	
	// Borrado de una fila
	
	// Lectura y filtrado de la posición de inserción

	int pos_borrado;
	
	do {	
		cout << "Posicion de borrado= ";
		cin >> pos_borrado;
	} while ((pos_borrado<0) || (pos_borrado>=matriz.FilasUtilizadas()));

		
	// Borramos la fila seleccionada.
	// Estamos seguros de que se cumplen las precondiciones. 
		
	matriz.Elimina(pos_borrado);
	

	// Impresión de la tabla resultante después del borrado
	
	cout << endl << endl;
	cout << "Matriz tras el borrado: " << endl;		
	cout << endl << endl;
		
	for (int f=0; f<matriz.FilasUtilizadas(); f++) {

		for (int c=0; c<matriz.ColumnasUtilizadas(); c++) {
			cout << matriz.Elemento(f,c) << "  ";	
		}
		cout << endl;
	}
	cout << endl << endl;


	return (0);
}	
