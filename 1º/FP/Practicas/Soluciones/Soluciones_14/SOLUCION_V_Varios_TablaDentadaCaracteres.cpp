/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS V
// EJERCICIO 20
//
/*	
	Este programa presenta la clase "TablaDentadaCaracteres".
	Se emplea como dato miembro privado una matriz "cl�sica" de caracteres.
*/
/*********************************************************************/


#include <iostream>
#include <iomanip>
using namespace std;


/////////////////////////////////////////////////////////////////////////////

class SecuenciaCaracteres  
{
	// ......
};

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// Tabla dentada de caracteres
//
// Representaci�n: matriz "cl�sica"

class TablaDentadaCaracteres
{
	
private:

    static const int MAX_FIL = 50;  // Filas disponibles
    static const int MAX_COL = 40;  // Columnas disponibles

    char matriz_privada[MAX_FIL][MAX_COL];

    // PRE: 0 <= filas_utilizadas < MAX_FIL

    int filas_utilizadas;

    // PRE: 0 <= num_cols_utilizadas[i] < MAX_COL
    //      para i=0,1,...,filas_utilizadas-1
    // N�mero de columnas ocupadas en cada fila

    int num_cols_utilizadas[MAX_FIL];

public:

	/***********************************************************************/
	// Constructor sin argumentos.

	TablaDentadaCaracteres (void)
		: filas_utilizadas(0)
	{
	}
	/***********************************************************************/
	// Constructor con argumentos. Recibe una secuencia de caracteres, que 
	// ser� la primera fila de la tabla. 

	TablaDentadaCaracteres (SecuenciaCaracteres primera_fila)
		: filas_utilizadas(0)
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}
	
	/***********************************************************************/
	// M�todo de lectura: n�mero m�ximo de filas

	int CapacidadFilas (void)
	{
		return (MAX_FIL);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero m�ximo de columnas

	int CapacidadColumnas (void)
	{
		return (MAX_COL);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero real de filas usadas

	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero real de columnas usadas en la fila "fila"
	// 
	// PRE: 0 <= fila < filas_utilizadas
	
	int ColumnasUtilizadas (int fila)
	{
		return (num_cols_utilizadas[fila]);
	}

	/*****************************************************************/
	// M�todo de lectura: devuelve el dato que ocupa la casilla 
	// de coordenadas (fila, columna)
	//
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < num_cols_utilizadas[fila]	
	
	char Elemento (int fila, int columna)
	{
		return (matriz_privada[fila][columna]);
	}

	/***********************************************************************/
	// Devuelve true si la tabla est� vac�a

	bool EstaVacia (void) 
	{
		return (filas_utilizadas == 0);
	}
	
	/***********************************************************************/
	// "Vac�a" una tabla
	
	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}
	
	/*****************************************************************/
	// Devuelve una fila completa, como un objeto de la clase 
	// "SecuenciaCaracteres"
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaCaracteres Fila (int indice_fila)
	{
		SecuenciaCaracteres la_fila;
					
		if ((0 <= indice_fila) && (indice_fila < filas_utilizadas)) {
					
			int num_columnas = num_cols_utilizadas[indice_fila];
			
			for (int c=0; c<num_columnas; c++) 
				la_fila.Aniade (matriz_privada[indice_fila][c]);
		}
		return (la_fila);
	}

	/*****************************************************************/
	// A�ade una fila completa. La fila se porporciona en un objeto de 
	// la clase "SecuenciaCaracteres".
	// 
	// PRE:  fila_nueva.TotalUtilizados() <= MAX_COL
	// PRE:  filas_utilizadas < MAX_FIL
	
	void Aniade (SecuenciaCaracteres fila_nueva)
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
	// Inserta una fila completa en una posici�n dada. 
	// La fila se porporciona en un objeto "SecuenciaCaracteres".
	// 
	// Recibe: num_fila, la posici�n que ocupar� "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase SecuenciaCaracteres. 
	//
	// PRE:  fila_nueva.TotalUtilizados() <= MAX_COL
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
			(numero_columnas_fila_nueva <= MAX_COL) && 
			(0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La �ltima fila se copia en una NUEVA FILA que ocupa la 
			// posici�n "filas_utilizadas", la pen�ltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todav�a) "filas_utilizadas" 
			
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
			
				int num_columnas = num_cols_utilizadas[fil+1];
					
				for (int c=0; c<num_columnas; c++) 
					matriz_privada[fil][c]=matriz_privada[fil+1][c];
					
				num_cols_utilizadas[fil] = num_cols_utilizadas[fil+1];
			}
			
			filas_utilizadas--; // Actualizaci�n del tama�o de la tabla.
		}
	}
		
	/*****************************************************************/
	// Calcula si dos matrices dentadas son iguales

	bool EsIgual (TablaDentadaCaracteres otra_tabla)
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

void MuestraTablaDentada (TablaDentadaCaracteres tabla, string titulo)
{
	cout << endl;
	cout <<  titulo << endl; 	
	cout << endl;
	cout << "------------------------------------------------------" << endl; 
	
	int num_filas = tabla.FilasUtilizadas();
	
	for (int fila=0; fila<num_filas; fila++) {

		
		SecuenciaCaracteres la_secuencia = tabla.Fila(fila);
		
		int num_datos = la_secuencia.TotalUtilizados();

		cout << "Fila " << setw(2) << fila+1; 
		cout << " (" << setw(2) << num_datos << " datos): "; 
			
		for (int num_dato=0; num_dato<num_datos; num_dato++) {
			char dato = la_secuencia.Elemento(num_dato);
			cout << "|" << dato << "|";
		}
		cout << endl;
	}
	cout << "------------------------------------------------------" << endl; 	
	cout << endl << endl;	
	
}

/***************************************************************************/

int main (void)
{
	// A�adir datos a la primera fila
	
	SecuenciaCaracteres una_fila; 
	
	una_fila.Aniade ('c'); una_fila.Aniade ('b');	
	una_fila.Aniade ('a'); una_fila.Aniade ('l');

	// Crear la tabla a partir de la primera fila
	
	TablaDentadaCaracteres matriz;
	
	matriz.Aniade (una_fila);

	// Vaciar la secuencia, y a�adir una nueva fila a "matriz" 
	
	una_fila.EliminaTodos();	// Para poder utilizarse posteriormente
		
	una_fila.Aniade ('f'); una_fila.Aniade ('g');	
	una_fila.Aniade ('h'); 
	
	matriz.Aniade (una_fila);
		
	una_fila.EliminaTodos();	// Para poder utilizarse posteriormente
		
	
	
	// Mostrar los datos leidos
	
	MuestraTablaDentada (matriz, "Tabla orginal:"); 	
	
	
	// Rellenar una secuencia pra insertarla en "matriz" 
		
	una_fila.Aniade ('d'); una_fila.Aniade ('d');	
	una_fila.Aniade ('e');
	
	matriz.Inserta (1, una_fila);
		
	una_fila.EliminaTodos();	// Para poder utilizarse posteriormente
	
		
		
	// Mostrar la matriz tras la inserci�n
	
	MuestraTablaDentada (matriz, "Tabla tras insercion:"); 	
	
	
	// Rellenar una secuencia para insertarla en "matriz" 
		
	una_fila.Aniade ('a'); una_fila.Aniade ('b');	
	
	matriz.Inserta (matriz.FilasUtilizadas(), una_fila);
		
	una_fila.EliminaTodos();	// Para poder utilizarse posteriormente
	
		
	// Mostrar la matriz tras la inserci�n
	
	MuestraTablaDentada (matriz, "Tabla tras otra insercion:"); 	

	return (0);
}
