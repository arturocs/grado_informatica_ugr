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
   Cómputo del factorial y potencia de un número, con funciones

   Factorial:
      n! = 1 si n=0
      n! = n(n-1)(n-2)...1 si n>=1
   Potencia:

      x^n = x x ... x  (n veces)
*/

#include <iostream>
#include <cmath>
using namespace std;


/*
	¿Exigimos que se cumpla la precondición 0 <= n <= 20 en el parámetro n?
	¿O lo comprobamos dentro de la función?
	La respuesta depende de cada situación/problema.
	A veces es recomendable comprobar la precondición y otras no.
	Los criterios más importantes a seguir son:
		- ¿Si se viola la precondición se pueden producir errores importantes?
			Una situación límite sería que incluso el programa pudiese abortar.
			En este caso, las comprobaremos.
		- Si la respuesta a la anterior pregunta es que no.
			¿Es una función que va a ser llamada intensivamente dentro de bucles?
			¿Es muy costoso el comprobar la precondición?
			En caso afirmativo, mejor no comprobamos la precondición.
	
	En el ejemplo que nos ocupa, no está claro què decisión tomar.
	Tal vez, lo mejor sería optar por no comprobar la condición, ya que,
	en caso contrario, "solamente" se produciría un desbordamiento aritmético.
*/	

///////////////////////////////////////////////////////////////////////////////////////


// Versión de factorial imponiendo la precondición.


// n! = n(n-1)(n-2)...1 si n>=1. 0! = 1
// Precondición: 0 <= n <= 20
long long Factorial(int n){
   long long factorial;
	int  multiplicando;

	factorial = 1;

	for (multiplicando = 2; multiplicando <= n ; multiplicando++)
		factorial = factorial * multiplicando;

	return factorial;
}


/*
///////////////////////////////////////////////////////////////////////////////////////

// Versión de factorial comprobando dentro la precondición.
//	Si nos pasan un valor fuera del rango, devolveremos un valor especial
//	que no sea el factorial de ningún número. Por ejemplo, 0 o -1.
// Es importante destacar que, en este caso, en el programa principal,
// tendríamos que hacer la llamada en la siguiente forma:
// 
// if (Factorial(entero) == -1)
//		<desbordamiento> 
//		....
//
// Para no tener que comprobar SIEMPRE el valor devuelto por la función (if funcion(..) == valor especial)
// lo mejor es usar EXCEPCIONES. (se verá al final del cuatrimestre como Ampliación)

// n! = n(n-1)(n-2)...1 si n>=1. 0! = 1
long long Factorial(int n){
   long long factorial;
	int  multiplicando;

	if (n < 0 || n > 20)
		factorial = -1;
	else{
		factorial = 1;

		for (multiplicando = 2; multiplicando <=n ; multiplicando++)
			factorial = factorial * multiplicando;
	}

	return factorial;
}
*/

///////////////////////////////////////////////////////////////////////////////////////

/*
   En este ejemplo queremos devolver el valor especial "Not a Number" aplicable
   a los reales (coma flotante), en el caso de que base y exponente sean ambos cero.
   Pero también sería perfectamente válido poner como precondición de Potencia que
   ambos parámetros no puedes ser nulos simultáneamente
*/

// Versión sin imponer la precondición de que ambos parámetros no sean nulos
//	Potencia de un real elevado a un entero cualquiera

double Potencia(double la_base, int el_exponente){
   
   //Observad que si exponente fuese cero, la variable potencia se quedaría con 1,
   //lo que es correcto ya que base elevado a 0 es siempre 1	
   //
   //Y observad que este comentario va dentro de la función ya que
   //es una descripción de la implementación
   
	double provoca_indeterminacion = 0.0;
	double NaN = provoca_indeterminacion/provoca_indeterminacion;
	double potencia;
	int exponente_positivo;

	if (la_base == 0 && el_exponente == 0)
		potencia = NaN;				// Devuelve NaN (Indeterminación)
	else{
		exponente_positivo = abs(el_exponente);
		potencia = 1;								   					

		for (int i = 1; i <= exponente_positivo; i++)
			potencia = potencia * la_base;
	}

	if (el_exponente < 0)
		potencia = 1/potencia;

	return potencia;
}

////////////////////////////////////////////////////////////////////////////////////////


// Versión imponiendo la precondición de que ambos parámetros no sean nulos

// Prec: la_base y eñ_exponente no pueden ser cero simultáneamente
//	Potencia de un real elevado a un entero cualquiera

/*
double Potencia(double la_base, int el_exponente){
   
   //Observad que si exponente fuese cero, la variable potencia se quedaría con 1,
   //lo que es correcto ya que base elevado a 0 es siempre 1	
   //
   //Y observad que este comentario va dentro de la función ya que
   //es una descripción de la implementación

	double potencia;
	int exponente_positivo;

	exponente_positivo = abs(el_exponente);
	potencia = 1;								   					

	for (int i = 1; i <= exponente_positivo; i++)
		potencia = potencia * la_base;


	if (el_exponente < 0)
		potencia = 1/potencia;

	return potencia;
}
*/

int main(){
   long long factorial;
	int n;

	cout << "\nIntroduzca un entero positivo: ";
	cin >> n;

	/////////////////////////////////////////////////////////////
	// Versión "no segura" de la función factorial. 
	// Si no se cumple la precondición, se producirá un desbordamiento.
	// Esta solución es completamente válida. 

	factorial = Factorial(n);

	cout << "\nEl factorial de " << n << " es " << factorial;

	/////////////////////////////////////////////////////////////
	// Versión "segura" de la función factorial
	// Dentro de la propia función se comprueba la validez de los parámetros
	// Como devolvemos un código de error, la llamada implica usar un if
	// Esta solución también es completamente válida. 
	// En cualquier caso, es mejor usar EXCEPCIONES que devolver códigos de error.
	// Esto se verá como ampliación en el último tema. 
	
	factorial = Factorial(n);
	
	if (factorial == -1)
		cout << "\nEl factorial de " << n << " es " << factorial;
	else
		cout << "\nNo se puede calcular el factorial de " << n;
	
	/////////////////////////////////////////////////////////////
	
	double base;
	int exponente;
	double potencia;

	cout << "\n\nIntroduzca la base: ";
	cin >> base;
	cout << "\nIntroduzca el exponente: ";
	cin >> exponente;

	potencia = Potencia(base, exponente);

	cout << "\n" << base << " elevado a " << exponente << " es igual a " << potencia;
   cout << "\n\n";
	system("pause");
}
