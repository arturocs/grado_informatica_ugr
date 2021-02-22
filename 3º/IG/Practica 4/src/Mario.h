//==============================================================
// Práctica 3 - IG
// Arturo Cortés Sánchez
//==============================================================

#ifndef _MARIO_H
#define _MARIO_H
#include "Pierna.h"
#include "Brazo.h"
#include "Objply.h"
#include <vector>

class Mario{
	bool arriba, abajo;
	Objply cabeza, cuerpo, bloque, moneda;
	int hombro_der, hombro_iz, cadera_der, cadera_iz, mon_y, mar_y;
	int inc_hombro_der, inc_hombro_iz, inc_cadera_der, inc_cadera_iz, inc_mon_y, inc_mar_y;

public:
	bool animacion;
	Pierna derecha, izquierda;
	Brazo derecho, izquierdo;
	
	Mario();
	void dibujar();

	void hombro_der_inc();
	void hombro_der_dec();
	void hombro_iz_inc();
	void hombro_iz_dec();

	void cadera_der_inc();
	void cadera_der_dec();
	void cadera_iz_inc();
	void cadera_iz_dec();

	void cambio_inc_hombro_der(double i);
	void cambio_inc_hombro_iz(double i);
	void cambio_inc_cadera_der(double i);
	void cambio_inc_cadera_iz(double i);

	void mon_y_inc();
	void mon_y_dec();

	void mar_y_inc();
	void mar_y_dec();

	void cambio_inc_mon_y(double i);
	void cambio_inc_mar_y(double i);

	void saltar();
	void bajar();
	void pose_original();

	void modo(char c);
	void cambio_velocidad(double v);

};

#endif
