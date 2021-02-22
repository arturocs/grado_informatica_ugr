///////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Juan Carlos Cubero
//
///////////////////////////////////////////////////////

/* 
   Número feliz: 
	Todo número natural que cumple que si sumamos los cuadrados de sus dígitos y seguimos el proceso con 
	los resultados obtenidos el resultado es 1. 
	Se dice que un número es feliz de grado k si se ha podido
   demostrar que es feliz en un máximo de k iteraciones.

	Por ejemplo, el número 203 es un número feliz de grado 3 (en general, de grado cualquier k>=3) ya que 
	
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
   Algoritmo (Número feliz):
	
	   Mientras n no es feliz && no ha llegado al tope de ciclos 
		   num_digitos = Número de dígitos de n  
		   Recorrer los num_digitos dígitos de n
			   Actualizar suma con el cuadrado del último dígito
		   Asignar a n dicha suma    
   */

   /*
   int num_digitos;
   
	while (!es_feliz && quedan_ciclos){
		n_div_10 = n_copia;												// Calcular núm digitos de n
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
	Observad que en la solución anterior, se realiza
	dos veces la misma operación de extraer los dígitos
	(una primera vez para contar el número de dígitos
	y una segunda vez para ir extrayéndolos y sumándolos)
	Podemos mejorarlo ya que no es necesario contar primero el número
	de dígitos para luego extraerlos.

   Algoritmo (Número feliz):
   
	   Mientras n no es feliz && no ha llegado al tope de ciclos
		   Recorrer los dígitos de n, hasta que sólo quede uno
			   Actualizar suma con el cuadrado del último dígito				    
		   Asignarle a n dicha suma 

   Para no modificar la variable original n, necesitaré:
      n_copia
   Y para extraer los dígitos de n_copia, necesitaré:
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
