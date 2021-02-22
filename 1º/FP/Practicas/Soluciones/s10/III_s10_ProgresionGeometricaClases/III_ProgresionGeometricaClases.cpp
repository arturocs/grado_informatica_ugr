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
   Definid una clase para representar una progresión geométrica.

   a) Diseñad la clase pensando cuáles serían los datos miembro esenciales que definen
      una progresión geométrica, así como el constructor de la clase.
   b) Definid los métodos SumaHastaInfinito, SumaHasta, MultiplicaHasta.
   c) Cread un programa principal que llame a los anteriores métodos.
*/


#include <iostream>
#include <cmath>
using namespace std;
	/*
	Un objeto del concepto (clase) "Progresión geométrica" queda completamente determinado por el
	primer término y la razón. Esos serán sus únicos datos miembro.
   Los pasamos como parámetros al constructor para tener el objeto en un estado válido
   en el momento de su definición. 

	¿Qué funcionalidad -métodos- podemos definir para esta clase?
	- Sumar hasta un tope todos los términos de la progresión
	- Obtener el término n-ésimo de la progresión
	- .....

	En el diseño de esta clase se ha decidido que, una vez creado el objeto,
	no se pueda cambiar ni el primer término ni la razón de la progresión.
	En caso contrario, habría que añadir los métodos correspondientes
		SetRazon
		SetPrimerTermino
	*/
   /*
   Este ejercicio muestra la facilidad de uso de las clases.
   Con funciones, tendríamos que crear las funciones siguientes:
			double SumaHasta(double primer_termino_progresion, double razon_progresion, int k)
			double Termino(double primer_termino_progresion, double razon_progresion, int k)
			double ProductoHasta(double primer_termino_progresion, double razon_progresion, int k)
			double SumaHastaInfinito(double primer_termino_progresion, double razon_progresion)
   Y cada vez que necesitásemos calcular algo, tendríamos que volver a pasar los dos parámetros
   iniciales primer_termino_progresion y razon_progresion
   
   Con clases, le asignaremos unos valores de primer término y razón
   en el constructor:
      ProgresionGeometrica prog(5, 3);
   y con esos valores vamos llamando a los método:
      cout << prog.Termino(4);
      cout << prog.Termino(5);
      cout << prog.SumaHasta(8);
      cout << prog.SumaHastaInfinito();
      ......
   */

/*
   ProgresionGeometrica
      - double primer_termino
      - double razon
      + ProgresionGeometrica(double primer_termino_progresion, 
                             double razon_progresion)
      + double PrimerTermino()
      + double Razon()
      + double Termino(int k)
      + double SumaHasta(int k)
      + double SumaHastaInfinito()
      + double ProductoHasta(int k)      
*/

class ProgresionGeometrica{
private:
   double primer_termino;
   double razon;
public:
   ProgresionGeometrica(double primer_termino_progresion, double razon_progresion){
      primer_termino = primer_termino_progresion;
      razon = razon_progresion;
   }

   double PrimerTermino(){
      return primer_termino;
   }

   double Razon(){
      return razon;
   }

	// Precondición: k > 0. También podríamos haber usado un tipo unsigned int
   double Termino(int k){
      /*
      Para calcular el término k-ésimo, 
      o bien usamos directamente la fórmula:
         return primer_termino * pow(razon, k-1);
      o bien lo calculamos con un bucle.
      Ambas implementaciones serían correctas.
      */
		double termino = primer_termino;

		for (int i=2; i<=k; i++)
			termino = termino * razon;

		return termino;
   }
  
   /*
      Si optásemos por eliminar la precondición, podríamos devolver un valor
      especial en el caso de que nos pasasen un valor de k erróneo.
      Por ejemplo, devolver indeterminación.
      
      Las dos soluciones -comprobar la precondición o no comprobarla-
      serían correctas. Si tenemos previsto llamar intensivamente a
      este método podríamos optar por no comprobar la precondición.
   */
   /*
   double Termino(int k){
      double termino = primer_termino;
      
      if (k > 0){
   		for (int i=2; i<=k; i++)
   			termino = termino * razon;
      }    
      else{
         double indet = 0.0;
			termino = indet / indet;     // Indeterminación
      }  
      
		return termino;
   }
   */


	// Precondición: k > 0	
	double SumaHasta(int k){
		double suma;

		suma = primer_termino;

		for (int i = 2; i <= k; i++)
			suma = suma + Termino(i);

		return suma;
	}

	// Versión de SumaHasta aplicando directamente la fórmula correspondiente:
	/*
	// Precondición: k > 0
   double SumaHasta(int k){
      return primer_termino * (pow(razon,k) - 1) / (razon - 1);
   }
	*/
	

   double SumaHastaInfinito(){
      double suma;
      int denominador = 0;

      if (fabs(razon) <= 1)
         suma = primer_termino / (1 - razon);
      else
         suma = 1.0 / denominador;    //  Devuelve infinito

      return suma;
   }

	// Fórmula de ProductoHasta(h) = sqrt(pow(a_1 * a_k , k))
	// ¿Pasamos como parámetro el valor de a_k al método ProductoHasta?
	//		double ProductoHasta(int k, double ak)
	// La respuesta es que NO.
	// Si lo hiciésemos, el correcto funcionamiento de ProductoHasta DEPENDERÍA
	// de que en la llamada, le pasen el correcto valor de a_k 
	// Cada método debe ser responsable de realizar sus cómputos correctamente
	// y no delegar en la llamada a que en ella se realicen otras acciones
	// necesarias iniciales para que funcione correctamente.

	// Precondición: k > 0
   double ProductoHasta(int k){
      return sqrt( pow(primer_termino * Termino(k) , k));
   }
};



/*
	AMPLIACIÓN:

	El cómputo de Termino(k) se ha realizado de la forma siguiente:
	
	O bien aplicando la fórmula directamente con pow:

		double Termino(int k){
			return primer_termino * pow(razon, k-1);
		}
	
	O bien realizando los cómputos en un bucle:

		double Termino(int k){
			double termino = primer_termino;

			for (int i=2; i<=k; i++)
				termino = termino * razon;

			return termino;
	   }

	Si desde el main queremos, por ejemplo, imprimir los 20 primeros valores:

	int main(){
		ProgresionGeometrica progresion(2,5);
			for (int i=0; i<20; i++)
				cout << progresion.Termino(i);
	
	Cada llamada a progresion.Termino(i) implica volver a hacer las mismas operaciones una y otra vez.
	Por lo tanto, hubiese sido más eficiente haber usado la expresión   
      termino_k = termino_(k-1) * r
   que calcular el término k-ésimo en función del término (k-1)-ésimo
	
	¿Cómo lo hacemos?
	La forma más sencilla es proporcionar otro método llamado Next() de forma que
	cada vez que se llame, devuelva el siguiente término al generado la última vez con el propio Next()
	Sería como un "iterador" que va recorriendo los elementos de la progresión geométrica.

	Habría dos formas de implementar este método:

	1. Añadiendo un dato miembro:
			double ultimo_termino_calculado;
		El método Next quedaría:

		double Next(){
			ultimo_termino_calculado = ultimo_termino_calculado * razon;

			return ultimo_termino_calculado;
		}

	2. Mejor aún, para no tener que añadir otro dato miembro, podríamos
	   usar una variable estática. 
		Las variables estáticas son variables locales a una función (o método)
		cuyo contenido se mantiene entre distintas llamadas a dicha función (o método)

			double Next(){
				static double ultimo_termino_calculado = primer_termino;

				ultimo_termino_calculado = ultimo_termino_calculado * razon;

				return termino;
			}
	
	Nota. 
		La clase ofrecería un método
			Termino(k)
		para devolver el término k-ésimo directamente
		y otro método
			Next()
		para devolver el siguiente al generado en la llamada anterior a Next()
		Debe quedar claro en la documentación que la llamada a Termino(k)
		no influye en la salida que da el método Next() cada vez que se llama,
      es decir, que se invocan de forma independiente.
*/
class ProgresionGeometrica_Optimizada_AMPLIACION{
private:
   double primer_termino;
   double razon;
public:
   ProgresionGeometrica_Optimizada_AMPLIACION(double primer_termino_progresion, double razon_progresion){
      primer_termino = primer_termino_progresion;
      razon = razon_progresion;
   }

   double PrimerTermino(){
      return primer_termino;
   }

   double Razon(){
      return razon;
   }
   
   // Devuelve el siguiente término de la progresión.
	double Next(){
		static double termino = primer_termino;

		termino = termino * razon;

		return termino;
	}
	
	// AMPLIACIÓN (2)
	// En la versión anterior, cuando se ha creado el objeto progresión,
	// la primera llamada a Next devuelve el siguiente al primer término
	// Esto es correcto. En cualquier caso, si hubiésemos querido que
	// la primera llamada a Next devuelva el primer elemento de la progresión
	// tendríamos que haberlo programado como sigue:
	
   //	double Next(){
   //	   static bool primera_vez = true;
   //		static double termino = primer_termino;
   //
   //      if (primera_vez)
   //         primera_vez = false;
   //      else
   //         termino = termino * razon;
   //
   //		return termino;
   //	}
	
	// Precondición: k > 0
   double Termino(int k){
		return primer_termino * pow(razon, k-1);
   }

	// Otra versión de SumaHasta
	/*
		double SumaHasta(int k){
			double suma;

			suma = primer_termino;

			for (int i = 2; i <= k; i++)
				suma = suma + Termino(i);

			return suma;
		}
	*/

		
	// Precondición: k > 0
   double SumaHasta(int k){
      return primer_termino * (pow(razon,k) - 1) / (razon - 1);
   }

   double SumaHastaInfinito(){
      double suma;
      int denominador = 0;

      if (abs(razon) <= 1)
         suma = primer_termino / (1 - razon);
      else
         suma = 1.0 / denominador;    //  Devuelve infinito

      return suma;
   }

	// Precondición: k > 0
   double ProductoHasta(int k){
      return sqrt( pow(primer_termino * Termino(k) , k));
   }
};


int main(){
   double primer_termino, razon;
   int tope;

   cout << "\nIntroduzca el primer término de la progresión ";
   cin >> primer_termino;
   cout << "\nIntroduzca la razón de la progresión ";
   cin >> razon;

   ProgresionGeometrica progresion(primer_termino, razon);
   
   cout << "\nIntroduzca el índice del último término ";
   cin >> tope;   
   
   cout << "\nSuma hasta " << tope << " = "  << progresion.SumaHasta(tope);
   cout << "\nSuma hasta infinito" << " = "  << progresion.SumaHastaInfinito();
   cout << "\nProducto hasta " << tope << " = " << progresion.ProductoHasta(tope);
   cout << "\n\nLos " << tope << " primeros términos de la serie son\n";

   for (int i = 1; i <= tope; i++)
      cout << progresion.Termino(i) << "\n";

   //////////////////////////////////////////////////////////////////////////////////
   
	ProgresionGeometrica_Optimizada_AMPLIACION progresion_optima(primer_termino, razon);

	cout << "\n\n" << progresion_optima.PrimerTermino(); 

	for (int i = 2; i <= tope; i++)
      cout << "\n" << progresion_optima.Next();
	

   cout << "\n\n";
   system("pause");
}
