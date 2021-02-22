/*
Definir la clase AlumnoFP, que almacene el nombre, el primer apellido, el DNI del
alumno y cada una de las partes consideradas en la evaluación de la asignatura: teo-
ría, parcial_pract1, parcial_pract2, participación_clase. La escala utilizada para eva-
luar cada parte es de 0 a 10

• Construir los constructores necesarios para poder asignar valores a los miembros
de la clase.
• Construir un método que calcule la nota final del alumno. Para ello se debe de
tener en cuenta los porcentajes de las distintas partes consideradas: 70% teoría,
5% parcial 1, 15% parcial 2 y 10% participación.
• Construir un método que calcule la nota final del alumno.
• Construir un programa que lea los datos del alumno y en caso de haber obtenido
una nota inferior a 5 en alguna de las partes que indique la nota obtenida en dicha
parte.
*/

#include <iostream>
#include <cctype>
using namespace std;

/*
   AlumnoFP
      - string nombre
      - string apellido
      - string DNI
      - double nota_teoria 
      - double nota_pract1 
      - double nota_pract2 
      - double nota_eval_continua
      
      + AlumnoFP (string nombre_alumno, string apellido_alumno, string DNI_alumno)
      + double PorcentajeTeoria()
      + double PorcentajePract1()
      + double PorcentajePract2()
      + double PorcentajeEvalContinua()
      + void   SetNotasPracticas(double pract1, double pract2)
      + void   SetNotaEvaluacionContinua(double eval_continua)
      + void   SetNotaTeoria(double teoria)
      + double NotaTeoria()
      + double NotaPract1()
      + double NotaPract2()
      + double NotaEvalContinua()
      + double CalificacionFinal()
*/

class AlumnoFP{
private:
   string nombre;
   string apellido;
   string dni;
   double nota_teoria  = 0.0;
   double nota_pract1 = 0.0;
   double nota_pract2 = 0.0;
   double nota_eval_continua = 0.0;
   
   bool EsCorrectaNota(double nota){
      return (0 <= nota && nota <= 10);
   }
   bool EsCorrectoDNI (string DNI_propuesto){
      bool es_correcto = true;
      
      es_correcto = DNI_propuesto.size() == 8;
      
      if (es_correcto){      
         for (int i=0; i<8 && es_correcto ; i++)
            es_correcto = isdigit(DNI_propuesto[i]);
      }

      return es_correcto;
   }
   
public:
   AlumnoFP (string nombre_alumno, string apellido_alumno, string DNI_alumno){
      if (EsCorrectoDNI(DNI_alumno)){
         nombre = nombre_alumno;
         apellido = apellido_alumno;
         dni = DNI_alumno;
      }
   }
   
   // Los porcentajes podrían declararse como constantes estáticas
   // Pero entonces deben definirse fuera de la clase
   // Podemos evitarlo usando métodos
   
   double PorcentajeTeoria(){
      return 0.7;
   }
   
   double PorcentajePract1(){
      return 0.05;
   }   
   
   double PorcentajePract2(){
      return 0.15;
   }
   
   double PorcentajeEvalContinua(){
      return 0.1;
   }
   
   void SetNotasPracticas(double pract1, double pract2){
      if (EsCorrectaNota(pract1) && EsCorrectaNota(pract2)){
         nota_pract1 = pract1;
         nota_pract2 = pract2;
      }
   }
   
   void SetNotaEvaluacionContinua(double eval_continua){
      if (EsCorrectaNota(eval_continua))
         nota_eval_continua = eval_continua;
   }
   
   void SetNotaTeoria(double teoria){
      if (EsCorrectaNota(teoria))
         nota_teoria = teoria;
   }
   
   double NotaTeoria(){
      return nota_teoria;
   }
   
   double NotaPract1(){
      return nota_pract1;
   }
   
   double NotaPract2(){
      return nota_pract2;
   }
   
   double NotaEvalContinua(){
      return nota_eval_continua;
   }
   
   double CalificacionFinal(){
      return   nota_pract1 * PorcentajePract1() +
               nota_pract2 * PorcentajePract2() +
               nota_eval_continua * PorcentajeEvalContinua() +
               nota_teoria * PorcentajeTeoria();
   }
   
   string Nombre(){
      return nombre;
   }
   
   string Apellido(){
      return apellido;
   }
   
   string DNI(){
      return dni;
   }
};


/*
   Nota:
      Hubiese sido mejor separar el diseño de esta clase en dos clases:
      Una clase para gestionar los datos del alumno
      Otra clase para gestionar las notas
      De esta forma tendríamos un objeto DatosAlumno y un objeto Notas 
      corresponciente a las notas de dicho alumno. 
      Ambos objetos estarían incluidos como datos miembro dentro 
      de un tercer objeto Alumno
      
      En el último tema veremos este tipo de relaciones entre clases.
*/

/*
class DatosAlumno{
private:
   string nombre;
   string apellido;
   string dni;

   bool EsCorrectoDNI (string DNI_propuesto){
      bool es_correcto = true;
      
      es_correcto = DNI_propuesto.size() == 8;
      
      if (es_correcto){      
         for (int i=0; i<8 && es_correcto ; i++)
            es_correcto = isdigit(DNI_propuesto[i]);
      }

      return es_correcto;
   }
   
public:
   DatosAlumno (string nombre_alumno, string apellido_alumno, string DNI_alumno){
      if (EsCorrectoDNI(DNI_alumno)){
         nombre = nombre_alumno;
         apellido = apellido_alumno;
         dni = DNI_alumno;
      }
   }

   string Nombre(){
      return nombre;
   }
   
   string Apellido(){
      return apellido;
   }
   
   string DNI(){
      return dni;
   }
};

class Notas{
private:
   double nota_teoria  = 0.0;
   double nota_pract1 = 0.0;
   double nota_pract2 = 0.0;
   double nota_eval_continua = 0.0;
   
   bool EsCorrectaNota(double nota){
      return (0 <= nota && nota <= 10);
   }

public:   
   // Los porcentajes podrían declararse como constantes estáticas
   // Pero entonces deben definirse fuera de la clase
   // Podemos evitarlo usando métodos
   
   double PorcentajeTeoria(){
      return 0.7;
   }
   
   double PorcentajePract1(){
      return 0.05;
   }   
   
   double PorcentajePract2(){
      return 0.15;
   }
   
   double PorcentajeEvalContinua(){
      return 0.1;
   }
   
   void SetNotasPracticas(double pract1, double pract2){
      if (EsCorrectaNota(pract1) && EsCorrectaNota(pract2)){
         nota_pract1 = pract1;
         nota_pract2 = pract2;
      }
   }
   
   void SetNotaEvaluacionContinua(double eval_continua){
      if (EsCorrectaNota(eval_continua))
         nota_eval_continua = eval_continua;
   }
   
   void SetNotaTeoria(double teoria){
      if (EsCorrectaNota(teoria))
         nota_teoria = teoria;
   }
   
   double NotaTeoria(){
      return nota_teoria;
   }
   
   double NotaPract1(){
      return nota_pract1;
   }
   
   double NotaPract2(){
      return nota_pract2;
   }
   
   double NotaEvalContinua(){
      return nota_eval_continua;
   }
   
   double CalificacionFinal(){
      return   nota_pract1 * PorcentajePract1() +
               nota_pract2 * PorcentajePract2() +
               nota_eval_continua * PorcentajeEvalContinua() +
               nota_teoria * PorcentajeTeoria();
   }
};
*/


int main(){
   AlumnoFP alumno("Juan Carlos", "Cubero", "22222222");

   alumno.SetNotasPracticas(9.8, 9.7);
   alumno.SetNotaEvaluacionContinua(9.1);
   alumno.SetNotaTeoria(9.9);
   
   cout << "\nNota Final: " << alumno.CalificacionFinal();

   cout << "\n\n";
}
