//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
Recupere la solución del ejercicio 6 de esta relación de problemas (cómputo del sa-
lario en función de las horas trabajadas) Defina una clase Nomina para gestionar el
cómputo del salario final. Suponga que el porcentaje de incremento en la cuantía de
las horas extras (50%) y el número de horas que no se tarifan como extra (40) son
valores que podrían cambiar, aunque no de forma continua. El número de horas tra-
bajadas y la cuantía a la que se paga cada hora extraordinaria, sí son cantidades que
varían de un trabajador a otro.
*/

/*
A un trabajador le pagan según sus horas trabajadas y la tarifa está a un valor por
hora. Si la cantidad de horas trabajadas es mayor de 40 horas, la tarifa por hora se
incrementa en un 50% para las horas extras (las que haya por encima de 40). Construir
una función que dado el número total de horas trabajadas y el precio por hora,
devuelva el salario del trabajador.
*/

#include <iostream>
using namespace std;

double AplicaPorcentaje (double cantidad, int porcentaje){
   return cantidad + cantidad * porcentaje / 100.0;
}

/*
   Asociaremos cada objeto de la clase Nomina con unos valores concretos
   de BASE_HORAS_EXTRA y PORCENTAJE_AUMENTO_HORAS_EXTRA.
   Éstos serán los datos miembro.
   
   Una vez fijados esos valores en el constructor, llamamos
   al método Salario con distintos valores de  
   horas_trabajadas y salario_por_hora (parámetros al método)
   
   Si otra delegación de la empresa considerase otros valores de
   BASE_HORAS_EXTRA y PORCENTAJE_AUMENTO_HORAS_EXTRA,
   bastaría crear otro objeto asociado a dicha delegación y pasaríamos
   en el constructor los valores pertinentes.
   
   Hemos considerado que el número de horas trabajadas y a lo que se paga
   cada una de ellas son datos que suelen variar bastante. Por eso, se han
   pasado como parámetros al método Salario. Si a lo que se paga cada hora
   fuese un dato fijo por delegación, también lo pondríamos como dato miembro.
   
   En definitiva:
      - Los datos miembro están asociados a propiedades o valores que
         no suelen cambiar mucho durante la vida del objeto
      - Los parámetros de los métodos están asociados a valores que suelen
         variar bastante de una ejecución a otra del método.
   
   Nomina
      - const int BASE_HORAS_EXTRA
      - const int PORCENTAJE_AUMENTO_HORAS_EXTRA
      + Nomina(int base_horas_extra, int porcentaje_aumento_horas_extra)
      + int BaseHorasExtra()
      + int PorcentajeAumentoHorasExtra()
      + double Salario(double horas_trabajadas, double salario_por_hora)
*/

class Nomina{
private:
   const int BASE_HORAS_EXTRA;
   const int PORCENTAJE_AUMENTO_HORAS_EXTRA;
public:
   Nomina(int base_horas_extra, int porcentaje_aumento_horas_extra)
      :BASE_HORAS_EXTRA(base_horas_extra) , 
       PORCENTAJE_AUMENTO_HORAS_EXTRA(porcentaje_aumento_horas_extra)
   {      
   }
   
   int BaseHorasExtra(){   
      return BASE_HORAS_EXTRA;
   }

   int PorcentajeAumentoHorasExtra(){   
      return PORCENTAJE_AUMENTO_HORAS_EXTRA;
   }
   
   double Salario(double horas_trabajadas, double salario_por_hora){
      double salario;     

      if (horas_trabajadas > BaseHorasExtra()){
         salario = BaseHorasExtra() * salario_por_hora +
                   AplicaPorcentaje( (horas_trabajadas - BaseHorasExtra()) * 
                                      salario_por_hora , 
                                      PorcentajeAumentoHorasExtra());                
      }
      else
         salario = horas_trabajadas * salario_por_hora;
      
      return salario;   
   }
};


int main(){
   double horas_de_trabajo, a_pagar_por_hora, salario_final;
   double porcentaje_aumento_horas_extra, base_horas_extra;
   
   cout << "Cómputo del salario en función de las horas trabajadas. \n\n";
   
   cout << "\nIntroduzca el porcentaje de aumento en el pago de las horas extra: ";
   cin >> porcentaje_aumento_horas_extra;
   cout << "\nIntroduzca el número de horas a partir del cual se considera que son horas extra: ";
   cin >> base_horas_extra;
   
   Nomina nomina(base_horas_extra, porcentaje_aumento_horas_extra);
   
   cout << "\n\nIntroduzca número de horas trabajas: ";
   cin >> horas_de_trabajo;
   cout << "\nIntroduzca el salario por hora: ";
   cin >> a_pagar_por_hora;
   
   salario_final = nomina.Salario(horas_de_trabajo, a_pagar_por_hora);
   
   cout << "\n\nSalario Final: " << salario_final;
}
