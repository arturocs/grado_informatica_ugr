/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2014-2015
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 2
// EJERCICIO 9
//
/*
	Una compa��a a�rea establece el precio del billete como sigue: 
	1)	En primer lugar se fija una tarifa base de 150 euros, la misma para 
		todos los destinos. 
	2)	Si el destino est� a menos de 200 kil�metros, el precio final es la 
		tarifa inicial. 
	3)	Para destinos a m�s de 200 Km, se suman 10 c�ntimos por cada kil�metro 
		de distancia al destino (a partir del Km 200).

	En una campa�a de promoci�n se va a realizar una rebaja lineal de 15 
	euros a todos los viajes. Adem�s, se pretenden a�adir otras rebajas 
	y se barajan las siguientes alternativas de pol�ticas de descuento:

	a)	Una rebaja del 3% en el precio final, para destinos a m�s de 600Km.
	b)	Una rebaja del 4% en el precio final, para destinos a m�s de 1100Km. 
		En este caso, no se aplica el anterior descuento.
	c)	Una rebaja del 5% si el comprador es cliente previo de la empresa.

	El programa lee el n�mero de kil�metros al destino y si el billete
	corresponde a un cliente previo de la empresa. 
	Se calcula el precio final del billete con las siguientes pol�ticas: 
	
	1)	Aplicando c) de forma adicional a los descuentos a) y b)
	2)	Aplicando c) de forma exclusiva con los anteriores, 
		es decir, que si se aplica c), no se aplicar�a ni a) ni b)
*/
/*********************************************************************/

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	const double TARIFA_BASE = 150.0;

	const int    LIMITE_KMS_TARIFICACION_ADICIONAL = 200;
	const double TARIFA_POR_KM_ADICIONAL = 0.1;

	const int    MINIMO_KMS_TRAYECTO_MEDIO = 600;
	const int    MINIMO_KMS_TRAYECTO_LARGO = 1100;

	const double DESCUENTO_TRAYECTO_MEDIO = 3.0;  // 3%
	const double DESCUENTO_TRAYECTO_LARGO = 4.0;  // 4%
	const double DESCUENTO_CLIENTE_PREVIO = 5.0;  // 5%

	const double REBAJA_LINEAL = 15.0;			  // 15 Euros

	double	tarifa_con_km_adicionales, 
			tarifa_final_descuentos_acumulados, 
			tarifa_final_descuentos_excluyentes, 
			rebaja;

	int distancia_recorrido, 
		distancia_tarificacion_adicional;

	bool es_cliente_previo;
	bool es_trayecto_medio, es_trayecto_largo;


	// Lectura de datos
	
	cout << "\nIntroduzca la distancia del recorrido del viaje: ";
	cin >> distancia_recorrido;


	char opcionSN;
	
	cout << "�Es un cliente previo (s/n)? ";
	cin >> opcionSN;
	
	es_cliente_previo = (toupper(opcionSN) == 'S');
	

	// C�lculos
	
	tarifa_con_km_adicionales = TARIFA_BASE;

	if (distancia_recorrido > LIMITE_KMS_TARIFICACION_ADICIONAL) {

		distancia_tarificacion_adicional = 
		         distancia_recorrido - LIMITE_KMS_TARIFICACION_ADICIONAL;

		tarifa_con_km_adicionales = tarifa_con_km_adicionales + 
			(distancia_tarificacion_adicional) * TARIFA_POR_KM_ADICIONAL;
	}

	es_trayecto_medio = 
		(distancia_recorrido >= MINIMO_KMS_TRAYECTO_MEDIO) && 
		(distancia_recorrido <  MINIMO_KMS_TRAYECTO_LARGO);

	es_trayecto_largo = 
		(distancia_recorrido >= MINIMO_KMS_TRAYECTO_LARGO);


	// Pol�tica 1

	rebaja = REBAJA_LINEAL;

	if (es_cliente_previo)
		rebaja = rebaja + 
               (tarifa_con_km_adicionales * DESCUENTO_CLIENTE_PREVIO/100.0);

	if (es_trayecto_medio)
		rebaja = rebaja + 
		       (tarifa_con_km_adicionales * DESCUENTO_TRAYECTO_MEDIO/100.0);
	else 
		if (es_trayecto_largo)
			rebaja = rebaja + 
			    (tarifa_con_km_adicionales * DESCUENTO_TRAYECTO_LARGO/100.0);
	

	// Cuidado: por si la rebaja lineal fuese mayor que el precio del billete

	if (rebaja < tarifa_con_km_adicionales)                     
		tarifa_final_descuentos_acumulados = 
				tarifa_con_km_adicionales - rebaja;
	else
		tarifa_final_descuentos_acumulados = 0.0;

	cout << "\n\nTarifa final (todos los descuentos): ";
	cout << tarifa_final_descuentos_acumulados;


	// Pol�tica 2

	rebaja = REBAJA_LINEAL;

	if (es_cliente_previo)
		rebaja = rebaja + 
		        (tarifa_con_km_adicionales * DESCUENTO_CLIENTE_PREVIO/100.0);
	else if (es_trayecto_medio)
		rebaja = rebaja + 
		        (tarifa_con_km_adicionales * DESCUENTO_TRAYECTO_MEDIO/100.0);
	else if (es_trayecto_largo)
			rebaja = rebaja + 
			    (tarifa_con_km_adicionales * DESCUENTO_TRAYECTO_LARGO/100.0);

	// Cuidado: por si la rebaja lineal fuese mayor que el precio del billete
   	
   if (rebaja < tarifa_con_km_adicionales)                     
	   tarifa_final_descuentos_excluyentes = 
			tarifa_con_km_adicionales - rebaja;
   else
      tarifa_final_descuentos_excluyentes = 0.0;


	cout << "\n\nTarifa final (cliente previo, de forma excluyente) ";
	cout << tarifa_final_descuentos_excluyentes;

	cout << "\n\n";
	
	return(0);
}
