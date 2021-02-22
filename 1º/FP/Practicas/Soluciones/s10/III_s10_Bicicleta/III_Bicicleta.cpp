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
Se quiere construir una clase para representar la tracción de una bicicleta, es decir, el
conjunto de estrella (engranaje delantero), cadena y piñón (engranaje trasero). Supon-
dremos que la estrella tiene tres posiciones (numeradas de 1 a 3, siendo 1 la estrella
más pequeña) y el piñón siete (numeradas de 1 a 7, siendo 1 el piñón más grande).

La posición inicial de marcha es estrella = 1 y piñón = 1.

La clase debe proporcionar métodos para cambiar la estrella y el piñón, sabiendo que
la estrella avanza o retrocede de 1 en 1 y los piñones cambian a saltos de uno o de
dos. Si ha llegado al límite superior (inferior) y se llama al método para subir (bajar) la
estrella, la posición de ésta no variará. Lo mismo se aplica al piñón.

Cread un programa principal que lea desde un fichero externo los movimientos rea-
lizados e imprima la situación final de la estrella y piñón. Los datos se leerán en el
siguiente formato: tipo de plato (piñón o estrella) seguido del tipo de movimiento. Para
codificar esta información se usarán las siguientes letras: E indica una estrella, P un pi-
ñón, S para subir una posición, B para bajar una posición, T para subir dos posiciones
y C para bajar dos posiciones. T y C sólo se aplicarán sobre los piñones.

E S P S P S P S P C E S E B

En este ejemplo los movimientos serían: la estrella sube, el piñón sube en tres oca-
siones sucesivas, el piñón baja dos posiciones de golpe, la estrella sube y vuelve a
bajar. Supondremos siempre que la posición inicial de la estrella es 1 y la del piñón 1.
Así pues, la posición final será Estrella=1 y Piñón=2.

Mejorad la clase para que no permita cambiar la marcha (con la estrella o el piñón)
cuando haya riesgo de que se rompa la cadena. Este riesgo se produce cuando la
marcha a la que queremos cambiar es de la siguiente forma:

• Estrella igual a 1 y piñón mayor o igual que 5
• Estrella igual a 2 y piñón o bien igual a 1 o bien igual a 7
• Estrella igual a 3 y piñón menor o igual que 3
*/

#include <iostream>
using namespace std;


/*
TraccionBicicleta_vs_Mala_1
	- int estrella
   - int pinion
   + TraccionBicicleta_vs_Mala_1()
   + int GetEstrella()
   + int GetPinion()
   + void Cambia_a(int tipo_plato, int numero)
*/

class TraccionBicicleta_vs_Mala_1{
		/*
		Estrella pequeña: 1
		Estrella grande: 3
		Piñón grande: 1
		Piñón pequeño: 7
		*/
private:
	int estrella, pinion;
public:
	TraccionBicicleta_vs_Mala_1()
		:estrella(1), pinion(1)
	{
	}
	int GetEstrella(){
		return estrella;
	}
	int GetPinion(){
		return pinion;
	}

	// plato = 1 => Estrella
	// plato = 2 => Piñón
	// numero = 1,2 o 3 si es estrella
	// numero = 1, ..., 7 si es piñón

	void Cambia_a(int tipo_plato, int numero){
      if (tipo_plato == 1){  // Estrella
		   if (1 <= numero && numero <= 3)
			   estrella = numero;
      }
      else if (1 <= numero && numero <= 7)
			pinion = numero;
	}
};

/*
   Si sólo tenemos estrella y piñón, no debemos usar un entero para englobar
   ambos casos (1 == Estrella y 2 == Piñón)
	Además el rango del segundo parámetro depende del primero
	puesto que admitimos de 1 a 3 si es estrella y de 1 a 7 si es piñón.
	Esta dependencia hace que el diseño no sea correcto. 
   La interfaz pública se queda mucho más clara si distinguimos estrella y piñón de forma independiente.
*/


/*
TraccionBicicleta_vs_Mala_2
	- int estrella
   - int pinion
   + TraccionBicicleta_vs_Mala_2()
   + int GetEstrella()
   + int GetPinion()
   + void CambiaEstrella_a(int estrella_objetivo)
   + void CambiaPinion_a(int pinion_objetivo)
*/


class TraccionBicicleta_vs_Mala_2{
		/*
		Estrella pequeña: 1
		Estrella grande: 3
		Piñón grande: 1
		Piñón pequeño: 7
		*/
private:
	int estrella, pinion;
public:
	TraccionBicicleta_vs_Mala_2()
		:estrella(1), pinion(1)
	{
	}
	int GetEstrella(){
		return estrella;
	}
	int GetPinion(){
		return pinion;
	}
	void CambiaEstrella_a(int estrella_objetivo){
		if ((1 <= estrella_objetivo) && (estrella_objetivo <= 3)
			 && abs(estrella - estrella_objetivo) < 1)
			estrella = estrella_objetivo;
	}
	void CambiaPinion_a(int pinion_objetivo){
		if ((1 <= pinion_objetivo) && (pinion_objetivo <= 7)
			 && abs(pinion - pinion_objetivo) < 2)
			pinion = pinion_objetivo;
	}
};

/*
	No es muy intuitivo que ofrezcamos un método CambiaEstrella_a 
	a un entero cualquiera cuando realmente éste sólo puede tomar 3 valores distintos.
	Además, la cabecera del método da la impresión que podemos cambiar del 1 al 3 cuando 
	realmente sólo permitimos avanzar de 1 en 1
	Por tanto, cambiamos el método y definimos, en su lugar, los métodos
	SubeEstrella() y BajaEstrella()
	Hacemos lo mismo con los piñones.
*/


/*
TraccionBicicleta_BuenaInterfaz_ImplementacionRegular
	- int estrella
   - int pinion
   + TraccionBicicleta_BuenaInterfaz_ImplementacionRegular()
   + int  GetEstrella()
   + int  GetPinion()
   + void BajaEstrella()
	+ void SubeEstrella()
   + void SubePinion()
   + void SubePinionDoble()
   + void BajaPinion()
   + void BajaPinionDoble()
*/


class TraccionBicicleta_BuenaInterfaz_ImplementacionRegular{
		/*
		Estrella pequeña: 1
		Estrella grande: 3
		Piñón grande: 1
		Piñón pequeño: 7
		*/
private:
	int estrella, pinion;
public:
	TraccionBicicleta_BuenaInterfaz_ImplementacionRegular()
		:estrella(1), pinion(1)
	{
	}
	int GetEstrella(){
		return estrella;
	}
	int GetPinion(){
		return pinion;
	}
	void BajaEstrella(){
		if (estrella > 1)
			estrella--;
	}
	void SubeEstrella(){
		if (estrella < 3)
			estrella++;
	}
	void SubePinion(){
		if (pinion < 7)
			pinion++;
	}
	void SubePinionDoble(){
		if (pinion < 6)
			pinion = pinion+2;
	}
	void BajaPinion(){
		if (pinion > 1)
			pinion--;
	}
	void BajaPinionDoble(){
		if (pinion > 2)
			pinion = pinion-2;
	}
};

/*
   Todos los if de los métodos los podemos centralizar en un método privado.
	Además, para que no se salga la cadena, podemos impedir los cambios
	cuando la estrella esté muy baja y el piñón muy alto (idem al revés)
   Todas las restricciones las centralizamos en un único método PRIVADO Cambia_a
   Este es el antiguo Cambia_a al que le pasábamos como parámetro
   la estrella y el piñón! Pero no hay problema ya que es privado!
	
	Debe ser privado ya que no queremos que los clientes de la clase
	puedan ejecutar el método Cambia_a para cambiar la estrella, por ejemplo,
   desde la tercera hasta la primera directamente. 
   Sólo queremos permitir cambios de estrella
	de uno en uno: por eso hemos definido los métodos SubeEstrella, BajaEstrella
	
	Sin embargo, sí lo permitimos como método privado ya que me permite
	centralizar todos los cambios de la tracción en un único método.
*/

/*
TraccionBicicleta
	- int estrella
   - int pinion
   - void Cambia_a(int estrella_objetivo, int pinion_objetivo)
   + TraccionBicicleta()
   + int GetEstrella()
   + int GetPinion()
   + void BajaEstrella()
	+ void SubeEstrella()
   + void SubePinion()
   + void SubePinionDoble()
   + void BajaPinion()
   + void BajaPinionDoble()
*/


class TraccionBicicleta{
		/*
		Estrella pequeña: 1
		Estrella grande: 3
		Piñón grande: 1
		Piñón pequeño: 7
		*/
private:
	int estrella, pinion;

   void Cambia_a(int estrella_objetivo, int pinion_objetivo){
	   bool es_correcto_cambio;

		es_correcto_cambio =   (
					((estrella_objetivo == 1) && ( (pinion_objetivo <= 4) && (pinion_objetivo >= 1) ))
					||
					((estrella_objetivo == 2) && ( (pinion_objetivo >= 2) && (pinion_objetivo <= 6) ))
					||
					((estrella_objetivo == 3) && ( (pinion_objetivo >= 5) && (pinion_objetivo <= 7) ))
					);

      if (es_correcto_cambio){
         pinion = pinion_objetivo;
         estrella = estrella_objetivo;
      }
	}
public:
	TraccionBicicleta(){
		estrella = 1;
      pinion  = 1;
	}
	int GetEstrella(){
		return estrella;
	}
	int GetPinion(){
		return pinion;
	}
	void BajaEstrella(){
		Cambia_a(estrella - 1, pinion);
	}
	void SubeEstrella(){
		Cambia_a(estrella + 1, pinion);
	}
	void SubePinion(){
		Cambia_a(estrella, pinion + 1);
	}
	void SubePinionDoble(){
		Cambia_a(estrella, pinion + 2);
	}
	void BajaPinion(){
		Cambia_a(estrella, pinion - 1);
	}
	void BajaPinionDoble(){
		Cambia_a(estrella, pinion - 2);
	}
};

int main(){
   const char TERMINADOR = '#';
   const char ESTRELLA = 'E';
   const char PINION = 'P';
   const char SUBE = 'S';
   const char BAJA = 'B';
   const char SUBE_DOBLE = 'T';
   const char BAJA_DOBLE = 'C';
   
   TraccionBicicleta mi_traccion;
   char plato, movimiento;
   
   cin >> plato;
   
   while (plato != TERMINADOR){
      cin >> movimiento;
      
      if (plato == ESTRELLA){
         if (movimiento == SUBE)
            mi_traccion.SubeEstrella();
         else if (movimiento == BAJA)
            mi_traccion.BajaEstrella();
      }
      else if (plato == PINION){
         if (movimiento == SUBE)
            mi_traccion.SubePinion();
         else if (movimiento == BAJA)
            mi_traccion.BajaPinion(); 
         else if (movimiento == SUBE_DOBLE)
            mi_traccion.SubePinionDoble();
         else if (movimiento == BAJA_DOBLE)
            mi_traccion.BajaPinionDoble(); 
      }
      
      cin >> plato;
   }
	
	cout << "\n\nEstado actual:\n";
	cout << "Estrella -> " << mi_traccion.GetEstrella() << "\n";
	cout << "Piñón    -> " << mi_traccion.GetPinion();

	cout << "\n\n";
	system("pause");
	
	// ESPSPSPSPCESEB#
}
