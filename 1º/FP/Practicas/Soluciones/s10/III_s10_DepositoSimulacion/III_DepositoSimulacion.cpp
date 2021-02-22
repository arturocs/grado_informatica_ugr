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
   Se quiere construir una clase DepositoSimulacion para simular préstamos, ofreciendo
   la funcionalidad descrita en los ejercicios 15 (reinvierte capital e interés un
   número de años) y 16 (reinvierte capital e interés hasta obtener el doble de la cantidad
   inicial) de la relación de problemas II (página RP-II.7). Por tanto, la clase debe
   proporcionar, para un capital y unos intereses dados, métodos para:
   
   a) Calcular el capital que se obtendrá al cabo de un número de años,
   b) Calcular el número de años que deben pasar hasta obtener el doble de la cantidad
      inicial.
         
   A la hora de diseñar la clase, tendremos que analizar cuestiones como:
   
    ¿Cuáles son sus datos miembro? Parece claro que el capital y el interés sí lo
      serán ya que cualquier operación que se nos ocurra hacer con un objeto de la
      clase DepositoSimulacion involucra a ambas cantidades. ¿Pero y el número
      de años?
    ¿Qué constructor definimos?
    ¿Queremos modificar el capital y el interés una vez creado el objeto?
    ¿Queremos poder modificarlos de forma independiente?
    ¿Hay alguna restricción a la hora de asignar un valor al capital e interés?
    ¿Es mejor un método para calcular el número de años hasta obtener el doble de
      la cantidad inicial, o por el contrario es mejor un método para calcular el número
      de años hasta obtener una cantidad específica?
*/

#include <iostream>
using namespace std;

   /*
   DepositoSimulacion
      - double capital
      - double interes
      - bool   EsCorrectoCapital(double un_capital)
      - bool   EsCorrectoInteres(double un_interes)
      + DepositoSimulacion(double capital_deposito, double interes_deposito)
      + double Capital()
      + double Interes()
      + void   SetCapital(double nuevo_capital)
      + void   SetInteres(double nuevo_interes)
      + double TotalObtenidoDespues_de (int anios_totales)
   */
   /*
	   Un método del tipo
		   int NumeroAniosHastaObtenerElDoble()
	   es demasiado específico. ¿Y si quiero el triple?
	   Es mucho mejor definir el método
		   int NumeroAniosHastaObtener (double cantidad_objetivo)
	   y pasarle como parámetro actual la cantidad a obtener
	   (que podrá ser el doble, el triple, una cantidad exacta, etc)

   */
   int NumeroAniosHastaObtener (double cantidad_objetivo){
      double total;
      int numero_anios;

      total = capital;
      numero_anios = 0;

      while (total < cantidad_objetivo){
         numero_anios = numero_anios + 1;
         total = total + total*interes/100.0;
      }
*/


class DepositoSimulacion{
	/*
	Parece lógico permitir cambiar el capital y el interés una vez creado
	el objeto, para así poder hacer simulaciones con distintos valores.
	Además, lo lógico es cambiarlos independientemente, por lo que
	definiremos los métodos SetCapital y SetInteres
	*/
private:
   double capital = 0.0;
   double interes = 0.0;
   
   bool EsCorrectoCapital(double un_capital){
      return (un_capital >= 0);
   }
   
   bool EsCorrectoInteres(double un_interes){
      return (0 < un_interes  &&  un_interes < 100);
   }
public:
   DepositoSimulacion(double capital_deposito, double interes_deposito)
   {
      SetCapital(capital_deposito);      
      SetInteres(interes_deposito);
   }

   double Capital(){
      return capital;
   }

   double Interes(){
      return interes;
   }

   void SetCapital(double nuevo_capital){
      if (EsCorrectoCapital(nuevo_capital))
         capital = nuevo_capital;
   }

   void SetInteres(double nuevo_interes){
      if (EsCorrectoInteres(nuevo_interes))
         interes = nuevo_interes;
   }

   double TotalObtenidoDespues_de (int anios_totales){
      double total;
      int anio;

      total = capital;

      for(anio = 1; anio <= anios_totales; anio++)
         total = total + total*interes/100.0;

      return total;
   }

   /*
	   Un método del tipo
		   int NumeroAniosHastaObtenerElDoble()
	   es demasiado específico. ¿Y si quiero el triple?
	   Es mucho mejor definir el método
		   int NumeroAniosHastaObtener (double cantidad_objetivo)
	   y pasarle como parámetro actual la cantidad a obtener
	   (que podrá ser el doble, el triple, una cantidad exacta, etc)

   */
   int NumeroAniosHastaObtener (double cantidad_objetivo){
      double total;
      int numero_anios;

      total = capital;
      numero_anios = 0;

      while (total < cantidad_objetivo){
         numero_anios = numero_anios + 1;
         total = total + total*interes/100.0;
      }
      return numero_anios;
   }
};

int main(){

   double capital_deposito, interes_deposito, capital_a_obtener;
   int anios;

   cout << "Introduzca capital inicial --> ";
   cin >> capital_deposito;
   cout << "\nIntroduzca interés (como un %) --> ";
   cin >> interes_deposito;

   DepositoSimulacion deposito(capital_deposito, interes_deposito);

   cout << "\nCual es el número de años que mantendrá el depósito --> ";
   cin >> anios;

   cout << "\n\nAl término de " << anios << " años, habrá obtenido " <<
            deposito.TotalObtenidoDespues_de(anios) << " euros\n";

   cout << "\nPara obtener el doble del capital inicial han de pasar "
        << deposito.NumeroAniosHastaObtener (2 * deposito.Capital()) << " años\n";

   cout << "\nCual es la cantidad que querría obtener --> ";
   cin >> capital_a_obtener;

   cout << "\n\nPara obtener " << capital_a_obtener << " euros, han de pasar " <<
           deposito.NumeroAniosHastaObtener(capital_a_obtener) << " años\n";

   cout << "\n\n";
   system("pause");
}

