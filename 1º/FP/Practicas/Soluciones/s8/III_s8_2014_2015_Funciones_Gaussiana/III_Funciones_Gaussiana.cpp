////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
	Gaussiana
*/

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415927; 

/*
	Aunque es este ejemplo la �nica funci�n que necesita conocer PI es la funci�n 
	EvaluaGaussiana
	hemos optado por ponerla como una constante global ya que es de esperar que 
	se a�adan otras funciones que tambi�n necesiten conocer el valor de PI
*/

/*
	Jam�s escribiremos una funci�n en la que, dentro de ella,
	se hagan a la misma vez E/S y C�mputos.
	Al hacerlo, estamos obligando a calcular siempre la gaussiana
	leyendo los datos con cin, pero �stos podr�an venir de cualquier otra forma.
*/
/*
double GaussianaSUSPENSO(){
	double abscisa, ordenada, esperanza, desviacion;

   // Jam�s incluiremos las siguientes sentencias de entrada de datos en esta funci�n que lo
   // que hace es realizar un c�mputo (la evaluaci�n de la funci�n en un punto)
   
	cout << "\nIntroduzca el valor del par�metro 'esperanza' : ";
	cin >> esperanza;                                                     // :-(
	cout << "\nIntroduzca el valor del par�metro 'desviacion' : ";
	cin >> desviacion;                                                    // :-(
	cout << "\nIntroduzca el valor de la abscisa: ";
	cin >> abscisa;                                                       // :-(
   
	ordenada = exp(-(pow( (abscisa - esperanza)/desviacion  ,  2)) / 2) /
	          (desviacion * sqrt(2*PI));
	
	return ordenada;
}

int main(){
	double ordenada;

	ordenada = Gaussiana();   // :-(
	cout << "\n\nEl valor de la funci�n gaussiana  es " << ordenada;

	cout << "\n\n";
   system("pause");
}
*/

//	Potencia de un n�mero elevado a un entero.
double Potencia(double la_base, int el_exponente){
	// Observad que si exponente fuese cero, la variable potencia se quedar�a con 1,
	// lo que es correcto ya que base elevado a 0 es siempre 1	

	double potencia;
	int exponente_positivo;

	if (la_base == 0 && el_exponente == 0)
		potencia = sqrt (-1.0);						   // Devuelve NaN (Indeterminaci�n)
	else{
		exponente_positivo = abs(el_exponente);
		potencia = 1;								   	// �Y si empezase con potencia = base?

		for (int i = 1; i <= exponente_positivo; i++)
			potencia = potencia * la_base;
	}

	if (el_exponente < 0)
		potencia = 1/potencia;

	return potencia;
}

// Valor de la funci�n Gaussiana (o "Normal") en un punto abscisa
double EvaluaGaussiana(double esperanza, double desviacion, double abscisa){ 
	double ordenada;

	ordenada = exp(-(pow( (abscisa - esperanza)/desviacion  ,  2)) / 2.0) /
		(desviacion * sqrt(2*PI));

	return ordenada;
}

// �rea hasta x que queda por debajo de la Gaussiana
double AreaHastaGaussiana(double esperanza, double desviacion, double abscisa){
	// Aproximaci�n dada por Zelen & Severo (1964) 
	// -ver Wikipedia (Normal distribution) para otras aproximaciones-		
	const double b0 = 0.2316419, b1 = 0.319381530, b2 = -0.356563782, 
		          b3 = 1.781477937, b4 = -1.821255978, b5 = 1.330274429;
	double area_hasta;
	double t;

	t = 1 / (1 + b0 * abscisa);
	area_hasta = 1 -  EvaluaGaussiana(esperanza, desviacion, abscisa) 
							* 
							(b1*t + b2*Potencia(t,1) + b3*Potencia(t,3) + b4*Potencia(t,4) + b5*Potencia(t,5));

	return area_hasta;
}


int main(){
	double x, y;
	double esperanza, desviacion;
	double area;

	cout << "\nIntroduzca el valor del par�metro 'esperanza' : ";
	cin >> esperanza;
	cout << "\nIntroduzca el valor del par�metro 'desviacion' : ";
	cin >> desviacion;
	cout << "\nIntroduzca el valor de la abscisa: ";
	cin >> x;

	y		= EvaluaGaussiana(esperanza, desviacion, x);
	area	= AreaHastaGaussiana(esperanza, desviacion, x);

	cout << "\n\nEl valor de la funci�n gaussiana en " << x << " es " << y;
	cout << "\n\nEl �rea hasta " << x << " es " << area;
	cout << "\n\n";
	system("pause");
}
