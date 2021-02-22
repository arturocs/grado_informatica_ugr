////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
Se dice que un número es triangular si se puede poner como la suma de los primeros
m valores enteros, para algún valor de m. Por ejemplo, 6 es triangular ya que 6 = 1 +
2 + 3. Se pide construir un programa que obtenga todos los números triangulares que
hay menores que un entero tope introducido desde teclado. Para ello, debe ir probando
la suma de todas las posibles secuencias de enteros menores que el número dado.
Hay que calcular explícitamente la suma con un bucle, por lo que no puede aplicarse
la fórmula que nos da la sumatoria de los n primeros valores, a saber, n(n + 1)=2
*/

#include <iostream>
using namespace std;

int main(){
	const string MSJ_ES_TRIANGULAR = " es triangular\n";
	int suma, tope, sumando, entero;
	bool es_triangular;
	
	cout << "Número triangular\n\n";
	cout << "Introduzca el tope ";
	cin >> tope;
	cout << "\n\n";
	
	/*
		Algoritmo (Números triangulares hasta tope):
		
			Recorrer los enteros -entero- desde 1 hasta tope 
				Recorrer los números menores que entero e ir sumándolos
				hasta que obtengamos el entero (es triangular)
				o hasta que la suma lo sobrepase
	*/

	for (entero = 1; entero <= tope; entero++){
		es_triangular = false;
		suma = 0;
		sumando = 1;
		
		while(suma < entero && !es_triangular){		
			suma = suma + sumando;
			es_triangular = suma == entero;
			sumando++;
		}
		
		if (es_triangular)
			cout << entero << MSJ_ES_TRIANGULAR;
	}
	
	cout << "\n\n";
	
	/*
		Podemos mejorar el algoritmo de la siguiente forma.
		Podemos detectar directamente cuáles son los números triangulares,
		calculando las sumas sucesivas de los n primeros números. 
		Todos ellos son triangulares.
			
		En cada iteración sumábamos los términos desde 1 hasta un tope.
		Podemos aprovechar los cómputos hechos en cada iteración ya que si
		hemos calculado
			1+2+3+4+5
		no es necesario volver a calcular la misma sumatoria para el siguiente entero:
			1+2+3+4+5  +6
		
		Algoritmo (Números triangulares hasta tope):
		
			Repetir hasta que suma sobrepase a tope	
				suma es un número triangular => imprimirlo			
				Si suma no sobrepasa el tope es un número triangular <= tope
				Incrementar n (+1) y suma (+n)
	*/
	
	int n;
		
	n = 1;
	suma = 1;

	while (suma <= tope){
		cout << suma << MSJ_ES_TRIANGULAR;
		n++;
		suma = suma + n;
	}
	
	cout << "\n\n";	
	
	/*
		Y de otra forma análoga:
		
		Algoritmo (Números triangulares hasta tope). 
		
			Repetir hasta que suma sobrepase a tope	
				Calcular la suma de los n primeros números aplicando la fórmula n(n+1)/2
				Dicha suma es un número triangular => Imprimirlo
				Incrementar n (+1)
	*/
	
	cout << "\n\n";
	
	
	n = 1;
	suma = 1;
	
	while (suma <= tope){
		cout << suma << MSJ_ES_TRIANGULAR;
		n++;
		suma = n*(n+1)/2;
	}
		
	cout << "\n\n";
   system ("pause");
}

