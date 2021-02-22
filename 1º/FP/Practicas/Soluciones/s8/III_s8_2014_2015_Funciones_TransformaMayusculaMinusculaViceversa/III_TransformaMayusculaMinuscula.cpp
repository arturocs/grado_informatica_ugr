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
	Se pide implementar la funci�n CambiaMayMin, a la que se le pase como par�metro un char y haga lo siguiente:
		 si el argumento es una letra en may�scula, devuelve su correspondiente letra en min�scula,
		 si el argumento es una letra en min�scula, devuelve su correspondiente letra en	may�scula,
		 si el argumento no es ni una letra may�scula, ni una letra may�scula, devuelve el car�cter pasado como argumento.
	
	Observad que la constante de amplitud
		const int DIFERENCIA_MAY_MIN = 'a'-'A';
	habr�a que declararla como constante local en ambas funciones. 
	Para no repetir este c�digo, �qu� podemos hacer?
		Primera soluci�n:
			Declarar la constante como un dato GLOBAL.
			Al ser constante no se pueden producir efectos laterales (ver transparencias de teor�a)
 
		Segunda soluci�n:
			Declarar una funci�n que devuelva dicho valor.
			
		Ambas aproximaciones ser�an correctas.
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
		cout << letra << " es may�scula";
	else if (tipo_letra == minuscula)
		cout << letra << " es min�scula";
	else
		cout << letra << " no es ni may�scula ni min�scula";

   cout << tipo_letra;

   cout << "\n\n";   
   system("pause");
}
*/


////////////////////////////////////////////////////////////////////
// Primera versi�n

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
	Luego llama a la funci�n Convierte_a_Mayuscula(caracter) y �sta vuelve
	a comprobar lo mismo.
	Esto supone una recarga computacional que, seguramente ser� inapreciable
	en las aplicaciones que realicemos, pero podr�a ser importante si
	se llamase a CambiaMayMin dentro de un bucle (por ejemplo, para cambiar
	las letras en un texto muy grande)
	
	Para evitarlo, nos preguntamos si hubiese sido mejor implementar
	la funci�n CambiaMayMin como sigue:
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
	
	Si lo hici�semos, tendr�amos duplicado en varias funciones 
	el c�digo que realiza la transformaci�n en may�scula (restarle DIFERENCIA_MAY_MIN) 
	o en min�scula (sumarle DIFERENCIA_MAY_MIN)	
	De hecho, hemos introducido una errata a prop�sito en el c�digo
	anterior ya que hab�a que restar (sumar) cuando hemos puesto sumar (restar)	
	
	Si nos quisi�ramos evitar la doble comprobaci�n if (Capitalizacion(caracter) == minuscula)
	bastar�a con definir una funci�n m�s (ToMayuscula) que realizase la transformaci�n
	de una forma "no segura" y llamarla donde fuese necesario.
*/

////////////////////////////////////////////////////////////////////
// Segunda versi�n


char ToMinuscula (char caracter){                
	return caracter + DIFERENCIA_MAY_MIN;        // �nico sitio en el que se hace esta tarea
}

char ToMayuscula (char caracter){             
	return caracter - DIFERENCIA_MAY_MIN;        // �nico sitio en el que se hace esta tarea
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
	


// Soluci�n con una funci�n en vez de una constante. 
// Usar la funci�n DiferenciaEntreMayusculas_y_Minusculas() en vez de la cte 

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

   cout << "\nEl car�cter " << letra  << " una vez convertido es: " << convertida;

   cout << "\n\n";   
   system("pause");
}

