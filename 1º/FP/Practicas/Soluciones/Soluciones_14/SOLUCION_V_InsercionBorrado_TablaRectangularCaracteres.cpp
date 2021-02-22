/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS V
// EJERCICIO 15
//
/*	
	Este programa amplia la clase "TablaRectangularCaracteres", clase 
	sobre la que se ha trabajado en los ejercicios 13 y 14.  

	Se emplea como dato miembro privado una matriz "cl�sica".

	En este programa se incorporan dos m�todos a la clase:
	
	1)  Inserta(), que permite insertar una fila completa en una 
		posici�n (de fila) determinada:
	
			void Inserta (int num_fila, SecuenciaCaracteres fila_nueva);
		
		Tras la inserci�n, la tabla tiene una fila m�s, la fila de la 
		posici�n "num_fila" contiene una copia de "fila_nueva", la fila que 
		ocupaba la posici�n  "num_fila" est� en la posici�n "num_fila"+1, 
		la de "num_fila"+1 en "num_fila"+2, y as� sucesivamente.
		
	2) Elimina(), que borra una fila completa de la matriz, 
	
			void Elimina (int num_fila);
		
		Tras la eliminaci�n, la tabla tiene una fila menos: la que ocupaba 
		la posici�n "num_fila".
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

	static const int TAMANIO = 50; // N�mero de casillas disponibles
	char vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// N�mero de casillas ocupadas

public:
	
	/*
		M�todos de la clase "SecuenciaCaracteres"
	*/
};

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// La clase "PosicionEnMatriz" es �til para representar posiciones 
// (coordenadas) en una tabla bidimensional.

class PosicionEnMatriz
{
private:
	int fila;
	int columna;

public: 
	
	/*
		M�todos de la clase "PosicionEnMatriz"
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
		Otros m�todos de la clase "TablaRectangularCaracteres"
	*/

	/*****************************************************************/
	// A�ade una fila completa. La fila se porporciona en un objeto de 
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
	// Inserta una fila completa en una posici�n dada. 
	// La fila se porporciona en un objeto "SecuenciaCaracteres".
	// 
	// Recibe: num_fila, la posici�n que ocupar� "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase Secuenciacaracteres. 
	//
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" ser� la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" ser� la nueva 
	//		 �ltima fila (el resultado ser� equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaCaracteres fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		// Comprobar precondiciones
		
		if ((filas_utilizadas < MAX_FIL) && 
			(numero_columnas_fila_nueva == cols_utilizadas) && 
			(0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La �ltima fila se copia en una NUEVA FILA que ocupa la 
			// posici�n "filas_utilizadas", la pen�ltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todav�a) "filas_utilizadas" 
			
			for (int fil=filas_utilizadas; fil>num_fila; fil--) {
				
				for (int col = 0; col < numero_columnas_fila_nueva; col++)
					matriz_privada[fil][col]=matriz_privada[fil-1][col];
			}
			
			// Copiar en el "hueco" (fila "num_fila") el contenido de 
			// la secuencia "fila_nueva"
			
			for (int col = 0; col < numero_columnas_fila_nueva; col++)
				matriz_privada[num_fila][col]=fila_nueva.Elemento(col);	
			
			filas_utilizadas++; // Actualizaci�n del tama�o de la tabla.
		}
	}

	/*****************************************************************/
	// Elimina una fila completa, dada una posici�n. 
	// 
	// Recibe: num_fila, la posici�n de la fila a eliminar.
	//
	// PRE:  0 <= num_fila < TotalUtilizados()
	
	void Elimina (int num_fila)
	{		
		// Comprobar precondiciones
		
		if ((0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones bajas. 
			// En la posici�n "num_fila" se copia la que est� en la posici�n
			// siguiente ("num_fila"+1), en su lugar se copia que est� en 
			// "num_fila"+2, ... y en la posici�n "total_utilizados"-2 se 
			// copia la de "total_utilizados"-1. 
			
			for (int fil=num_fila; fil<filas_utilizadas-1; fil++) {
			
				int num_columnas = cols_utilizadas;
					
				for (int c=0; c<num_columnas; c++) 
					matriz_privada[fil][c]=matriz_privada[fil+1][c];
			}
			
			filas_utilizadas--; // Actualizaci�n del tama�o de la tabla.
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
		cout << "N�mero de filas: ";
		cin >> num_filas; 
	} while (num_filas < 0);

	do{
		cout << "N�mero de columnas: ";
		cin >> num_columnas; 
	} while (num_columnas < 0);


	// Crear la tabla (inicialmente vac�a)
	
	TablaRectangularCaracteres matriz (num_columnas);


	// Lectura de los datos que compondr�n la tabla

	cout << endl;
	cout << "Introduzca los caracteres de la matriz por filas:" << endl;
	cout << "(solo se consideraran los primeros " << setw(3) << num_columnas 
		 << " caracteres)" << endl;
	cout << endl;
	
	// Los datos que compondr�n cada fila se leer�n en un string.
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
			 
		// Nos quedamos con la subsecuencia inicial de tama�o "num_columnas"
		una_fila = una_fila.Subsecuencia(0,num_columnas); 
		
/*		
		cout << "una_fila (despu�s de ajustar) = ";	
		cout << "|";
		for (int p=0; p<una_fila.TotalUtilizados(); p++)
			cout << una_fila.Elemento(p) << "|";
		cout << endl << endl;
*/	
		
		// A�adimos la secuencia a la matriz
		// Estamos seguros de que tiene el tama�o correcto. 
		
		matriz.Aniade (una_fila);
	}
	
	// Impresi�n de la tabla
	
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


	
	// Inserci�n de una nueva fila
	
	// Lectura y filtrado de la posici�n de inserci�n

	int pos_insercion;
	
	do {	
		cout << "Posicion de insercion= ";
		cin >> pos_insercion;
	} while ((pos_insercion<0) || (pos_insercion>matriz.FilasUtilizadas()));

	// Petici�n de una nueva fila

	cout << "Contenido de la fila a insertar: ";
	
	// Leer cadena. Descartar las que saen demasiado cortas.  
	
	do {
		getline(cin, una_cadena);
	} while (una_cadena.length() < num_columnas);
	
	// Crear una secuencia a partir de la cadena leida
	SecuenciaCaracteres fila_a_insertar (una_cadena); 

	// Nos quedamos con la subsecuencia inicial de tama�o "num_columnas"
	fila_a_insertar = fila_a_insertar.Subsecuencia(0,num_columnas); 
		
		
	// Insertamos la secuencia en la matriz
	// Estamos seguros de que se cumplen las precondiciones. 
		
	matriz.Inserta (pos_insercion, fila_a_insertar);



	// Impresi�n de la tabla resultante despu�s de la inserci�n 
	
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
	
	// Lectura y filtrado de la posici�n de inserci�n

	int pos_borrado;
	
	do {	
		cout << "Posicion de borrado= ";
		cin >> pos_borrado;
	} while ((pos_borrado<0) || (pos_borrado>=matriz.FilasUtilizadas()));

		
	// Borramos la fila seleccionada.
	// Estamos seguros de que se cumplen las precondiciones. 
		
	matriz.Elimina(pos_borrado);
	

	// Impresi�n de la tabla resultante despu�s del borrado
	
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
