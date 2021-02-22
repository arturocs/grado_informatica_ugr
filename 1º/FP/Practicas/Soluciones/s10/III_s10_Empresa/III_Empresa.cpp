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
   Podría definir los siguientes métodos 
      IDSucursalGanadora()
      NumeroVentasSucursalGanadora();
   De forma que en la función main haríamos las siguientes llamadas:
      id_ganador = ventas.IDSucursalGanadora()
      ventas_ganador = ventas.NumeroVentasSucursalGanadora();
   pero mejor si definimos un método general del tipo:
      NumeroVentasSucursal(int id_sucursal);
   El número de ventas de la sucursal ganadora lo obtenemos en el main de la forma siguiente:
      id_ganador = ventas.IDSucursalGanadora()
      ventas_ganador = ventas.NumeroVentasSucursal (id_ganador)
   o bien, directamente:
      ventas_ganador = ventas.NumeroVentasSucursal (ventas.IDSucursalGanadora())
      
   De esta forma, el método NumeroVentasSucursalGanadora() no es necesario
   
   Es cierto que en general no definiremos parámetros en los métodos que sólo
   admitan tres valores (en este caso los tres identificadores de las sucursales)
   En cualquier caso, este problema está pensado para que luego lo actualicemos
   con vectores y tengamos un conjunto mucho más grande de identificadores
   */
   
/*
VentasSucursales
   - const int id_suc_1
   - const int id_suc_2
   - const int id_suc_3
   - int num_ventas_1
   - int num_ventas_2
   - int num_ventas_3
   + VentasSucursales(int identif_sucursal_1, int identif_sucursal_2, int identif_sucursal_3)
   + void Actualiza(int identif_sucursal, int unidades_vendidas)
   + int IDSucursalGanadora()
   + int NumeroVentas(int id_sucursal)
*/   
   
class VentasSucursales{
private:
   const int id_suc_1, id_suc_2, id_suc_3;
   int num_ventas_1 = 0, 
       num_ventas_2 = 0, 
       num_ventas_3 = 0;
   
public:
   VentasSucursales(int identif_sucursal_1, int identif_sucursal_2, int identif_sucursal_3)
      :id_suc_1(identif_sucursal_1), id_suc_2(identif_sucursal_2), id_suc_3(identif_sucursal_3)
   {

   }
   
   void Actualiza(int identif_sucursal, int unidades_vendidas){
      if (unidades_vendidas > 0){         
         if (identif_sucursal ==  id_suc_1)
            num_ventas_1 = num_ventas_1 + unidades_vendidas;
         else if (identif_sucursal ==  id_suc_2)
            num_ventas_2 = num_ventas_2 + unidades_vendidas;
         else if (identif_sucursal ==  id_suc_3)
            num_ventas_3 = num_ventas_3 + unidades_vendidas; 
      }
   }
   
   int IDSucursalGanadora(){
      int num_max_ventas;
      int identif_sucursal_max_ventas;
   
      num_max_ventas = num_ventas_1;
      identif_sucursal_max_ventas = id_suc_1;
   
      if (num_ventas_2 > num_max_ventas){
         num_max_ventas = num_ventas_2;  
         identif_sucursal_max_ventas = id_suc_2;
      }       
   
      if (num_ventas_3 > num_max_ventas){
         num_max_ventas = num_ventas_3;  
         identif_sucursal_max_ventas = id_suc_3;
      }    
   
      return identif_sucursal_max_ventas;   
   }
   
   int NumeroVentas(int id_sucursal){
      if (id_sucursal == id_suc_1)
         return num_ventas_1;
      else if (id_sucursal == id_suc_2)
         return num_ventas_2;
      else if (id_sucursal == id_suc_3)
         return num_ventas_3;        
      else
         return -1; 
   }
};
    
int main(){
   const int TERMINADOR = -1;  
   const int ID_1 = 1; 
   const int ID_2 = 2; 
   const int ID_3 = 3; 

   int identif_sucursal,  ID_sucursal_ganadora, unidades_vendidas;
   char cod_producto; 
   int  ventas_sucursal_ganadora;
   string mensaje_entrada;
   bool fichero_vacio;
   
   VentasSucursales ventas(ID_1, ID_2, ID_3);
   
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
}
