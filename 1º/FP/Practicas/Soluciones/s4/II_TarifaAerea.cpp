/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2014-2015
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
// EJERCICIO 9
//
/*
	Una compañía aérea establece el precio del billete como sigue: 
	1)	En primer lugar se fija una tarifa base de 150 euros, la misma para 
		todos los destinos. 
	2)	Si el destino está a menos de 200 kilómetros, el precio final es la 
		tarifa inicial. 
	3)	Para destinos a más de 200 Km, se suman 10 céntimos por cada kilómetro 
		de distancia al destino (a partir del Km 200).

	En una campaña de promoción se va a realizar una rebaja lineal de 15 
	euros a todos los viajes. Además, se pretenden añadir otras rebajas 
	y se barajan las siguientes alternativas de políticas de descuento:

	a)	Una rebaja del 3% en el precio final, para destinos a más de 600Km.
	b)	Una rebaja del 4% en el precio final, para destinos a más de 1100Km. 
		En este caso, no se aplica el anterior descuento.
	c)	Una rebaja del 5% si el comprador es cliente previo de la empresa.

	El programa lee el número de kilómetros al destino y si el billete
	corresponde a un cliente previo de la empresa. 
	Se calcula el precio final del billete con las siguientes políticas: 
	
	1)	Aplicando c) de forma adicional a los descuentos a) y b)
	2)	Aplicando c) de forma exclusiva con los anteriores, 
		es decir, que si se aplica c), no se aplicaría ni a) ni b)
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
	
	cout << "¿Es un cliente previo (s/n)? ";
	cin >> opcionSN;
	
	es_cliente_previo = (toupper(opcionSN) == 'S');
	

	// Cálculos
	
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


	// Política 1

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


	// Política 2

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
