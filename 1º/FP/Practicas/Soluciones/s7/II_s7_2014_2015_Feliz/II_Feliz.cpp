///////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Juan Carlos Cubero
//
///////////////////////////////////////////////////////

/* 
   N�mero feliz: 
	Todo n�mero natural que cumple que si sumamos los cuadrados de sus d�gitos y seguimos el proceso con 
	los resultados obtenidos el resultado es 1. 
	Se dice que un n�mero es feliz de grado k si se ha podido
   demostrar que es feliz en un m�ximo de k iteraciones.

	Por ejemplo, el n�mero 203 es un n�mero feliz de grado 3 (en general, de grado cualquier k>=3) ya que 
	
	2^2 + 0^2 + 3^2 = 13  ->  1^2 + 3^2 = 10  ->  1^2 + 0^2 = 1
*/

#include <iostream>
using namespace std;

int main(){
	int tope_ciclos, ciclo;
	int n, n_copia, suma, n_div_10, ultimo_digito; 
	bool es_feliz, quedan_ciclos;

	cout << "\nIntroduzca el entero a comprobar si es feliz: ";
	cin >> n;
	cout << "\nIntroduzca el tope de ciclos permitido: ";
	cin >> tope_ciclos;
	
   /*
   Algoritmo (N�mero feliz):
	
	   Mientras n no es feliz && no ha llegado al tope de ciclos 
		   num_digitos = N�mero de d�gitos de n  
		   Recorrer los num_digitos d�gitos de n
			   Actualizar suma con el cuadrado del �ltimo d�gito
		   Asignar a n dicha suma    
   */

   /*
   int num_digitos;
   
	while (!es_feliz && quedan_ciclos){
		n_div_10 = n_copia;												// Calcular n�m digitos de n
		num_digitos = 1;

		while (n_div_10 > 9){
			n_div_10 = n_div_10 / 10;
			num_digitos++;
		}

		suma = 0;
		n_div_10 = n_copia;

		for (int i=1; i<=num_digitos ; i++){
			ultimo_digito = n_div_10 % 10;
			suma = suma + (ultimo_digito * ultimo_digito);
			n_div_10 = n_div_10/10;
		}

		if (suma == 1)
			es_feliz = true;
		else
			if (ciclo >= tope_ciclos)
				quedan_ciclos = false;
			else{
				n_copia = suma;
				ciclo++;
			}
	}
   */

   /*
	Observad que en la soluci�n anterior, se realiza
	dos veces la misma operaci�n de extraer los d�gitos
	(una primera vez para contar el n�mero de d�gitos
	y una segunda vez para ir extray�ndolos y sum�ndolos)
	Podemos mejorarlo ya que no es necesario contar primero el n�mero
	de d�gitos para luego extraerlos.

   Algoritmo (N�mero feliz):
   
	   Mientras n no es feliz && no ha llegado al tope de ciclos
		   Recorrer los d�gitos de n, hasta que s�lo quede uno
			   Actualizar suma con el cuadrado del �ltimo d�gito				    
		   Asignarle a n dicha suma 

   Para no modificar la variable original n, necesitar�:
      n_copia
   Y para extraer los d�gitos de n_copia, necesitar�:
      n_div_10	
   */

	n_copia = n;
	ciclo = 0;	
	es_feliz = false;
	quedan_ciclos = true;

	while (!es_feliz && quedan_ciclos){
		n_div_10 = n_copia;	
		suma = 0;

		while (n_div_10 != 0){
			ultimo_digito = n_div_10 % 10;
			suma = suma + ultimo_digito * ultimo_digito ;
			n_div_10 = n_div_10 / 10;
		}

		ciclo++;

		if (suma == 1)
			es_feliz = true;
		else
			if (ciclo == tope_ciclos)
				quedan_ciclos = false;
			else
				n_copia = suma;
	}

	
	if (es_feliz)
		cout << "\nEs Feliz para cualquier grado >= " << ciclo;
	else
		cout << "\nNo es Feliz de grado " << tope_ciclos;

   cout << "\n\n";
	system("pause");
}
