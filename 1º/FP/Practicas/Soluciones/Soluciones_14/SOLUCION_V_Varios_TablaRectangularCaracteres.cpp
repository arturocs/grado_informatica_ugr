/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOSÉ CORTIJO BON
// (C) JUAN CARLOS CUBERO TALAVERA
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS V
// EJERCICIOS 13 y 14
//
/*	
	Este programa presenta la clase TablaRectangularCaracteres. 
	Esta clase es útil cuando se desea que forzosamente todas las filas 
	tengan el mismo número de columnas--> que sea una matriz rectangular.

	Se emplea como dato miembro privado una matriz "clásica" en la forma:

		char matriz_privada[MAX_FIL][MAX_COL];

	y se ofrecen, entre otros, métodos para:

	a)	Obtener el número de filas y columnas utilizadas.

			int FilasUtilizadas();
			int ColumnasUtilizadas();

	b)	Obtener como el carácter que hay en una fila y columna dadas.

			char Elemento (int fila, int columna);

	c) Devolver una fila y una columna completas. 
		Una fila y una columna son realmente una secuencia de caracteres: 
		ambos métodos devolverán un objeto de la clase SecuenciaCaracteres.

			SecuenciaCaracteres Fila    (int indice_fila);
			SecuenciaCaracteres Columna (int indice_columna);

	d) Añadir una fila entera. 
		La fila se proporciona como un objeto de la clase SecuenciaCaracteres.
	
			void Aniade(SecuenciaCaracteres fila_nueva);

	e-1) Encontrar un valor.

			bool Contiene (char buscado);

		Devuelve TRUE si la tabla contiene el carácter "buscado"

	e-2) Encontrar un carácter.

			PosicionEnMatriz PrimeraOcurrencia (char buscado);

		El valor devuelto contiene información acerca de la posición 
		(fila y columna) de "buscado".  En el caso de que no esté 
		contendrá {-1,-1}. 
		La consulta de la fila y la columna se delega en los métodos de 
		la clase "PosicionEnMatriz" 

	f)	Comprobar si es igual a otra matriz rectangular.

			bool EsIgual (TablaRectangularCaracteres otra_matriz);

	g)	Obtener la traspuesta de la matriz.

			TablaRectangularCaracteres Traspuesta();

	h)	Comprobar si es simétrica. 

			*	Puede hacerse calculando primero la traspuesta de la matriz 
				y viendo si es igual a su simétrica, usando los métodos 
				anteriores.

					bool EsSimetricaIneficiente()

			*	También puede hacerse comprobando directamente si cada 
				componente es igual a su simétrica y parando el recorrido 
				cuando encuentre una componente que no lo verifique.

					bool EsSimetricaEficiente()
*/
/*********************************************************************/


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
		Aquí se escribirían los métodos de la clase SecuenciaCaracteres
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
	
	/*****************************************************************/
	// Constructor por defecto
	// La posición {-1,-1} debe interpretarse como "posición no válida"
	// (resulta útil en métodos de búsqueda, por ejemplo). 

	PosicionEnMatriz (void) : fila(-1), columna(-1) { }

	/*****************************************************************/
	// Método de escritura: establece simultaneamente los dos valores

	void SetPosicion (int la_fila, int la_columna)
	{
		fila = la_fila;
		columna = la_columna;
	}

	/*****************************************************************/
	// Métodos Get

	int GetFila (void)
	{
		return (fila);
	}
	
	int GetColumna (void)
	{
		return (columna);
	}

	/*****************************************************************/
	// Devuelve TRUE si la posición no es válida--> {-1,-1}

	bool EsPosicionNoValida (void)
	{
		return ((fila == -1) && (columna == -1));
	}
	/*****************************************************************/
};

/////////////////////////////////////////////////////////////////////////////
// Tabla rectangular de caracteres
//
// Representación: matriz "clásica"

class TablaRectangularCaracteres
{

private:

	static const int MAX_FIL = 50;
	static const int MAX_COL = 40;

	char matriz_privada[MAX_FIL][MAX_COL];

    // PRE: 0 <= filas_utilizadas < MAX_FIL
    // PRE: 0 <= col_utilizadas < MAX_COL
	
	int filas_utilizadas;
	int cols_utilizadas;

public:

	/*
	Para obligar a que una matriz sea rectangular, lo podemos hacer 
	de varias formas. Por ejemplo:
	a)	El constructor de la matriz recibe "numero_de_columnas", que 
		indica el número de columnas que deben tener todas las filas.
	b)	El constructor de la matriz recibe una secuencia. La longitud 
		(número de casillas utilizadas) de esa secuencia será el valor 
		que se use dentro de la matriz como "numero_de_columnas"

	Para permitir ambas formas, sobrecargamos el constructor.
	*/
	
	/***********************************************************************/
	// Constructor a)
	// Recibe "numero_de_columnas" que indica el número de columnas 
	// que deben tener TODAS las filas.

	TablaRectangularCaracteres (int numero_de_columnas)
		: filas_utilizadas(0), 
		  cols_utilizadas(numero_de_columnas)
	{
	}

	/***********************************************************************/
	// Constructor b)
	// Recibe una secuencia de caracteres. El número de elementos de la 
	// secencia es el valor que se usa como "col_utilizadas"

	TablaRectangularCaracteres (SecuenciaCaracteres primera_fila)
		: filas_utilizadas(0), 
		  cols_utilizadas (primera_fila.TotalUtilizados())
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}

	/***********************************************************************/
	// Método de lectura: número máximo de filas

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
	// Método de lectura: número real de columnas usadas

	int ColumnasUtilizadas (void)
	{
		return (cols_utilizadas);
	}

	/*****************************************************************/
	// Método de lectura: devuelve el caracter que ocupa la casilla 
	// de coordenadas (fila, columna)
	//
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < cols_utilizadas	
	
	char Elemento (int fila, int columna)
	{
		return (matriz_privada[fila][columna]);
	}
	
	/***********************************************************************/
	// Devuelve true si la tabla está vacía

	bool EstaVacia (void) 
	{
		return (filas_utilizadas == 0);
	}
	
	/*****************************************************************/
	// Devuelve una fila completa, como un objeto de la clase 
	// "SecuenciaCaracteres"
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaCaracteres Fila (int indice_fila)
	{
		SecuenciaCaracteres fila;

		for (int col=0; col<cols_utilizadas; col++)
			fila.Aniade(matriz_privada[indice_fila][col]);

		return (fila);
	}

	/*****************************************************************/
	// Devuelve una columna completa, como un objeto de la clase 
	// "SecuenciaCaracteres"
	// PRE: 0 <= indice_columna < cols_utilizadas
	
	SecuenciaCaracteres Columna (int indice_columna)
	{
		SecuenciaCaracteres columna;

		for (int fil=0; fil<filas_utilizadas; fil++)
			columna.Aniade (matriz_privada[fil][indice_columna]);

		return (columna);
	}

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
	// Devuelve TRUE si la matriz contiene el valor "buscado"
	
	bool Contiene (char buscado)
	{
		bool encontrado = false;

		// Recorrido por columnas 

		int col = 0;

		while (col < cols_utilizadas && !encontrado) {

			int fil=0;

			while (fil < filas_utilizadas && !encontrado) {

				if (matriz_privada[fil][col] == buscado)
					encontrado = true;
				
				fil++;

			} // while fil

			col++; 

		} // while col

		return (encontrado);
	}
		
	/*****************************************************************/
	// Encontrar un carácter en la matriz y devolver su posición.
	// El valor devuelto contiene información acerca de la posición 
	// (fila y columna) de "buscado".  
	// 		En el caso de que no esté contendrá {-1,-1}. 
	// La consulta de la fila y la columna se delega en los métodos de 
	// la clase "PosicionEnMatriz" 

	PosicionEnMatriz PrimeraOcurrencia (char buscado)
	{
		PosicionEnMatriz posicion_dato_buscado; // Inicialmente {-1,-1}.
      
		bool encontrado = false;

		// Recorrido por filas 

		for (int i=0; i < filas_utilizadas && !encontrado ; i++){

			for (int j=0; j < cols_utilizadas && !encontrado; j++){

				if (matriz_privada[i][j] == buscado){
					encontrado = true;
					posicion_dato_buscado.SetPosicion (i,j);
				}

			} // for j

		} // for i
      
		return (posicion_dato_buscado);
	} 

	/*****************************************************************/
	// Calcula si dos matrices rectangulares son iguales
	//
	// PRE: filas_utilizadas = otra_tabla.FilasUtilizadas()
	// PRE: cols_utilizadas  = otra_tabla.ColumnasUtilizadas()

	bool EsIgual (TablaRectangularCaracteres otra_tabla)
	{
		bool son_iguales = true; 
		
		if ((filas_utilizadas != otra_tabla.FilasUtilizadas()) && 
			 (cols_utilizadas != otra_tabla.ColumnasUtilizadas()))		
			
			son_iguales = false;
		
		else {
			
			int f=0; 
			
			while (f<filas_utilizadas && son_iguales) {
				
				int c=0; 
				
				while (c<cols_utilizadas && son_iguales) {
			
					if (matriz_privada[f][c] != otra_tabla.Elemento(f,c)) 
						son_iguales = false;
						
					c++;
					
				} // while c
	
				f++;
					
			} // while f
					
		} // else 
	
		return (son_iguales);
	}

	/*****************************************************************/
	// Devuelve la traspuesta de la matriz.
	//
	// PRE: filas_utilizadas <= MAX_COL
	// PRE: cols_utilizadas  <= MAX_FIL
	
	TablaRectangularCaracteres Traspuesta (void)
	{
		// La traspuesta tiene tantas filas como columnas tiene la 
		// matriz original

		TablaRectangularCaracteres traspuesta (filas_utilizadas);


		SecuenciaCaracteres columna; // Las filas de "traspuesta" serán las 
									 // columnas de la tabla implícita 

		for (int col = 0; col < cols_utilizadas; col++){

			columna = Columna(col);
			traspuesta.Aniade(columna); 
		}

		return (traspuesta);
	}

	/*****************************************************************/
	// Calcula si una matriz es simétrica. 
	// Este método calcula primero la traspuesta de la tabla y 
	// después comprueba si es igual a su simétrica.
	// 
	// Solo puede calcularse si es posible calcular la traspuesta
	// 		PRE: filas_utilizadas <= MAX_COL
	// 		PRE: cols_utilizadas  <= MAX_FIL
	
	bool EsSimetricaIneficiente (void)
	{
		TablaRectangularCaracteres traspuesta (Traspuesta());
	
		return (EsIgual(traspuesta));
	}

	/*****************************************************************/
	// Calcula si una matriz es simétrica. 
	// Este método compueba directamente si cada componente es igual a 
	// su simétrica, parando el recorrido cuando encuentre una componente 
	// que no lo verifique.
	//
	// Evita el cálculo de la traspuesta, y el problema que puuede surgir 
	// si no se puede calcular la traspuesta de la matriz por problemas de 
	// capacidad. 

	bool EsSimetrica (void)
	{
		bool es_simetrica = true;
		
		// Si el número de filas y columnas no coinciden, no hay que seguir
		// porque la matriz no es simétrica.
		
		es_simetrica = (filas_utilizadas == cols_utilizadas);

		if (es_simetrica) {
		
			int f=0; 
			
			while (f<filas_utilizadas && es_simetrica) {
				
				int c=0; 
				
				while (c<cols_utilizadas && es_simetrica) {
			
					if (matriz_privada[f][c] != matriz_privada[c][f]) 
						es_simetrica = false;
						
					c++;
					
				} // while c
	
				f++;
					
			} // while f
			
		} // if (es_simetrica)
		
		return (es_simetrica);
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
	// "Vacía" una tabla
	
	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}
	
	/***********************************************************************/
			
};

/***********************************************************************/
	
///////////////////////////////////////////////////////////////////////

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
		
	for (int f=0; f<matriz.FilasUtilizadas(); f++) {

		for (int c=0; c<matriz.ColumnasUtilizadas(); c++) {
			cout << matriz.Elemento(f,c) << "  ";	
		}
		cout << endl;
	}
	cout << endl << endl;


	// Búsqueda

	char caracter_a_buscar; 

	cout << endl << endl;
	cout << "Introduzca el caracter a buscar: ";
	
	caracter_a_buscar = cin.get();	

	bool encontrado_caracter = matriz.Contiene (caracter_a_buscar);


	cout << endl;
	if (encontrado_caracter) 
		cout << "SE HA ENCONTRADO el caracter " << caracter_a_buscar;
	else 
		cout << "NO SE HA ENCONTRADO el caracter " << caracter_a_buscar;
	cout << endl << endl;


	PosicionEnMatriz posicion = matriz.PrimeraOcurrencia (caracter_a_buscar);

	if (posicion.EsPosicionNoValida()) 
		cout << "NO SE HA ENCONTRADO el caracter " << caracter_a_buscar;
	else {
		cout << "SE HA ENCONTRADO el caracter " << caracter_a_buscar;
		cout << " en la posicion (" << posicion.GetFila() 
			 << ", " <<posicion.GetColumna() << ")";
	}
	cout << endl << endl;


	// Traspuesta y simetría

	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << endl;
	cout << "Traspuesta." << endl;
	cout << endl;
	
	TablaRectangularCaracteres traspuesta(matriz.Traspuesta());
	
	cout << endl;
	cout << "Matriz Traspuesta:" << endl; 
	
	for (int f=0; f<traspuesta.FilasUtilizadas(); f++) {

		for (int c=0; c<traspuesta.ColumnasUtilizadas(); c++) {
			cout << traspuesta.Elemento(f,c) << "  ";	
		}
		cout << endl;
	}
	cout << endl << endl;
	

	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << endl;
	cout << "Simetria." << endl;
	cout << endl;

	bool es_simetrica;
	
	es_simetrica = matriz.EsSimetrica();

	if (es_simetrica)
		cout << "Es simétrica (eficiente)";
	else
		cout << "No es simétrica (eficiente)";
	cout << endl << endl;
		
	es_simetrica = matriz.EsSimetricaIneficiente();

	if (es_simetrica)
		cout << "\nEs simétrica (ineficiente)";
	else
		cout << "\nNo es simétrica (ineficiente)";
	cout << endl << endl;
	
	return (0);
}
