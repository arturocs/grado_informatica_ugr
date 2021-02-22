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
 Recupere la solución del ejercicio 28 (ventas de empresa) de la relación de problemas
III. Resuelva el problema pedido (calcular la sucursal con mayor número de ventas)
pero ahora considere que no conoce a priori el número de sucursales que hay, aunque
sabe que los códigos de éstas siempre son números entre 1 y 100 y que en total no
hay más de 100 sucursales. Por lo tanto, tendrá que añadir como dato miembro de
la clase, un vector con un tamaño máximo de 100. Cree un programa principal de
prueba.
*/

/*
Una empresa que tiene tres sucursales decide llevar la contabilidad de las ventas
de sus productos a lo largo de una semana. Para ello registra cada venta con tres
números, el identificador de la sucursal (1,2 ó 3), el código del producto (1, 2 ó 3) y
el número de unidades vendidas. Diseñar un programa que lea desde el teclado una
serie de registros compuestos por sucursal, producto, unidades y diga cuál
es la sucursal que más productos ha vendido. La serie de datos termina cuando la
sucursal introducida vale -1. Por ejemplo, con la serie de datos
2 a 20
1 b 10
1 b 4
3 c 40
1 a 1
2 b 15
1 a 1
1 c 2
2 b 6
-1
Se puede ver que la sucursal que más productos ha vendido es la número 2 con
41 unidades totales. La salida del programa deberá seguir exactamente el siguiente
formato:

SUCURSAL: 2
VENTAS: 41

Para comprobar que el programa funciona correctamente, cread un fichero de texto y
re-dirigid la entrada a dicho fichero.
*/


#include <iostream> 
#include <string>  
using namespace std;   

/*
VentasSucursales
   - const int NUMERO_SUCURSALES = 100
   - int num_ventas[NUMERO_SUCURSALES]
   + VentasSucursales()
   + void Actualiza(int identif_sucursal, int unidades_vendidas)
   + int IDSucursalGanadora()
   + int NumeroVentas(int id_sucursal)
*/   
   
class VentasSucursales{
private:
   static const int NUMERO_SUCURSALES = 100;
   static const int VACIO = -1;
   int num_ventas[NUMERO_SUCURSALES];   
public:
   VentasSucursales(){
      for (int i=0; i<NUMERO_SUCURSALES; i++)
         num_ventas[i] = VACIO;
   }   
   
   /*
   Normalmente empezaremos a llenar el vector desde la componente 0.
   Pero en este ejercicio, como queremos que los métodos devuelvan 
   identificadores de sucursales (o pasarlas como parámetros) y éstos
   son a partir de 1, para no tener que estar haciendo la conversión
   -/+ 1, empezaremos a rellenar desde la componente 1, de forma que
   establecemos una correspondencia directa:
      índice en el vector <--> identificador de sucursal
   */
   
   void Actualiza(int identif_sucursal, int unidades_vendidas){
      if (unidades_vendidas > 0){         
         if (1 <= identif_sucursal && identif_sucursal <= 100)
            num_ventas[identif_sucursal] = num_ventas[identif_sucursal] 
                                           + unidades_vendidas ;
      }
   }
   
   int IDSucursalGanadora(){
      int identif_sucursal_max_ventas;
      int primera_no_vacia;
      
      primera_no_vacia = 0;
      
      while (num_ventas[primera_no_vacia] != VACIO 
             && 
             primera_no_vacia < NUMERO_SUCURSALES){
             
         primera_no_vacia++;      
      }
      
      identif_sucursal_max_ventas = primera_no_vacia;
      
      for (int i=primera_no_vacia + 1; i < NUMERO_SUCURSALES; i++){
         if (num_ventas[i] != VACIO 
             &&
             num_ventas[i] > num_ventas[identif_sucursal_max_ventas])
             
            identif_sucursal_max_ventas = i;
      }
   
      return identif_sucursal_max_ventas;   
      
      // Nota: No sería necesario comprobar num_ventas[i] != VACIO
      // ya que el valor vacío es -1 que será siempre menor que cualquier venta
      // En cualquier caso, lo dejamos para que quede más claro.
   }
   
   int NumeroVentas(int id_sucursal){
      if (1 <= id_sucursal && id_sucursal <= NUMERO_SUCURSALES)
         return num_ventas[id_sucursal];
      else    
         return VACIO; 
   }
};


/*
   Observad que el main es exactamente el mismo que el de la Relación
   de Problemas III. Lo único que cambia es la creación del objeto ya que
   ahora no le pasamos los tres identificadores en el constructor,
   ya que pueden ser más de tres y pueden ser cualesquiera (lo único que
   se sabe es que son números entre 1 y 100)
*/

int main(){
   const int TERMINADOR = -1;   
   int identif_sucursal,  ID_sucursal_ganadora, unidades_vendidas;
   char cod_producto; 
   int  ventas_sucursal_ganadora;
   string mensaje_entrada;
   bool fichero_vacio;
   
   VentasSucursales ventas;
   
   mensaje_entrada = "\nSe procede a leer datos del fichero ... \n";
   cout << mensaje_entrada;
 
   ID_sucursal_ganadora = TERMINADOR;   // Por si no se introduce ninguna sucursal válida   
   cin >> identif_sucursal;  
   fichero_vacio = identif_sucursal  == TERMINADOR;
   
   if (!fichero_vacio){
      while (identif_sucursal != TERMINADOR){              
         cin >> cod_producto;
         cin >> unidades_vendidas;
         
         ventas.Actualiza(identif_sucursal, unidades_vendidas); 

         cin >> identif_sucursal;      
      }
      
      ID_sucursal_ganadora = ventas.IDSucursalGanadora();
      ventas_sucursal_ganadora = ventas.NumeroVentas(ID_sucursal_ganadora);            
   }   
   
   if (fichero_vacio)
      cout << "\nEl fichero estaba vacío";
   else{
      cout << "\nSucursal ganadora: " << ID_sucursal_ganadora;
      cout << "\nVentas realizadas: " << ventas_sucursal_ganadora;
   }
   
   cout << "\n\n";
   
   // 2 a 20   1 b 10   1 b 4 3 c 40   1 a 1 2 b 15   25 a 14  1 a 1    1 c 2    2 b 6    7 v 15      -1
}
