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
	Se pide implementar la función CambiaMayMin, a la que se le pase como parámetro un char y haga lo siguiente:
		 si el argumento es una letra en mayúscula, devuelve su correspondiente letra en minúscula,
		 si el argumento es una letra en minúscula, devuelve su correspondiente letra en	mayúscula,
		 si el argumento no es ni una letra mayúscula, ni una letra mayúscula, devuelve el carácter pasado como argumento.
	
	Observad que la constante de amplitud
		const int DIFERENCIA_MAY_MIN = 'a'-'A';
	habría que declararla como constante local en ambas funciones. 
	Para no repetir este código, ¿qué podemos hacer?
		Primera solución:
			Declarar la constante como un dato GLOBAL.
			Al ser constante no se pueden producir efectos laterales (ver transparencias de teoría)
 
		Segunda solución:
			Declarar una función que devuelva dicho valor.
			
		Ambas aproximaciones serían correctas.
*/

#include <iostream>
using namespace std;

enum EnumTipoLetra {mayuscula, minuscula, otro_caracter};
const int DIFERENCIA_MAY_MIN = 'a'-'A';      

EnumTipoLetra Capitalizacion (char caracter){
	EnumTipoLetra tipo_de_letra;
	
   if (caracter >= 'A' && caracter <= 'Z')
      tipo_de_letra = mayuscula;
   else if (caracter >= 'a' && caracter <= 'z')
      tipo_de_letra = minuscula;
   else
      tipo_de_letra = otro_caracter;
   
   return tipo_de_letra;
}

/*
int main(){
   char letra;
   EnumTipoLetra tipo_letra;
  
   cout << "\nIntroduzca una letra  --> ";
   cin >> letra;
   
	tipo_letra = Capitalizacion(letra);
	
	if (tipo_letra == mayuscula)
		cout << letra << " es mayúscula";
	else if (tipo_letra == minuscula)
		cout << letra << " es minúscula";
	else
		cout << letra << " no es ni mayúscula ni minúscula";

   cout << tipo_letra;

   cout << "\n\n";   
   system("pause");
}
*/


////////////////////////////////////////////////////////////////////
// Primera versión

/*
char Convierte_a_Mayuscula (char caracter){             
	char caracter_convertido;

	if (Capitalizacion(caracter) == minuscula)
		caracter_convertido = caracter - DIFERENCIA_MAY_MIN;
	else
		caracter_convertido = caracter;

	return caracter_convertido;
}

char Convierte_a_Minuscula (char caracter){             
	char caracter_convertido;

	if (Capitalizacion(caracter) == mayuscula)
		caracter_convertido = caracter + DIFERENCIA_MAY_MIN;
	else
		caracter_convertido = caracter;

	return caracter_convertido;
}

char CambiaMayMin (char caracter){           
	char caracter_convertido;
	EnumTipoLetra capitalizacion;
	
	capitalizacion = Capitalizacion(caracter);
	
	if (capitalizacion == minuscula)
		caracter_convertido = Convierte_a_Mayuscula(caracter);  
	else if (capitalizacion == mayuscula)
		caracter_convertido = Convierte_a_Minuscula(caracter);
	else
		caracter_convertido = caracter;

	return caracter_convertido;

}
*/

/*
	Dentro de CambiaMayMin se comprueba if (Capitalizacion(caracter) == minuscula)
	Luego llama a la función Convierte_a_Mayuscula(caracter) y ésta vuelve
	a comprobar lo mismo.
	Esto supone una recarga computacional que, seguramente será inapreciable
	en las aplicaciones que realicemos, pero podría ser importante si
	se llamase a CambiaMayMin dentro de un bucle (por ejemplo, para cambiar
	las letras en un texto muy grande)
	
	Para evitarlo, nos preguntamos si hubiese sido mejor implementar
	la función CambiaMayMin como sigue:
	*/
	
	/*
	char CambiaMayMinINCORRECTA (char caracter){           
		char caracter_convertido;
		EnumTipoLetra capitalizacion;
		
		capitalizacion = Capitalizacion(caracter);
	
		if (capitalizacion == minuscula)
			caracter_convertido = caracter + DIFERENCIA_MAY_MIN; 
		else if (capitalizacion == mayuscula)
			caracter_convertido = caracter - DIFERENCIA_MAY_MIN;
		else
			caracter_convertido = caracter;

		return caracter_convertido;
	}
*/
	
/*
	La respuesta es que no.
	
	Si lo hiciésemos, tendríamos duplicado en varias funciones 
	el código que realiza la transformación en mayúscula (restarle DIFERENCIA_MAY_MIN) 
	o en minúscula (sumarle DIFERENCIA_MAY_MIN)	
	De hecho, hemos introducido una errata a propósito en el código
	anterior ya que había que restar (sumar) cuando hemos puesto sumar (restar)	
	
	Si nos quisiéramos evitar la doble comprobación if (Capitalizacion(caracter) == minuscula)
	bastaría con definir una función más (ToMayuscula) que realizase la transformación
	de una forma "no segura" y llamarla donde fuese necesario.
*/

////////////////////////////////////////////////////////////////////
// Segunda versión


char ToMinuscula (char caracter){                
	return caracter + DIFERENCIA_MAY_MIN;        // Único sitio en el que se hace esta tarea
}

char ToMayuscula (char caracter){             
	return caracter - DIFERENCIA_MAY_MIN;        // Único sitio en el que se hace esta tarea
}

char Convierte_a_Mayuscula (char caracter){             
	char caracter_convertido;

	if (Capitalizacion(caracter) == minuscula)
		caracter_convertido = ToMayuscula(caracter);
	else
		caracter_convertido = caracter;

	return caracter_convertido;
}

char Convierte_a_Minuscula (char caracter){             
	char caracter_convertido;

	if (Capitalizacion(caracter) == mayuscula)
		caracter_convertido = ToMinuscula(caracter);
	else
		caracter_convertido = caracter;

	return caracter_convertido;
}

char CambiaMayMin (char caracter){           
	char caracter_convertido;
	EnumTipoLetra capitalizacion;
	
	capitalizacion = Capitalizacion(caracter);
	
	if (capitalizacion == minuscula)
		caracter_convertido = ToMayuscula(caracter);  
	else if (capitalizacion == mayuscula)
		caracter_convertido = ToMinuscula(caracter);
	else
		caracter_convertido = caracter;

	return caracter_convertido;
}
	


// Solución con una función en vez de una constante. 
// Usar la función DiferenciaEntreMayusculas_y_Minusculas() en vez de la cte 

/*
int DiferenciaEntreMayusculas_y_Minusculas(){
	return 'a'-'A';
}      
*/

int main(){
   char letra, convertida;
  
   cout << "\nIntroduzca una letra  --> ";
   cin >> letra;
   
	convertida = CambiaMayMin (letra);

   cout << "\nEl carácter " << letra  << " una vez convertido es: " << convertida;

   cout << "\n\n";   
   system("pause");
}

