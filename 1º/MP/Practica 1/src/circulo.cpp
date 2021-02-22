#include <iostream>
#include <cmath> 
#include "punto.h"
#include "circulo.h"

using namespace std;



void EscribirCirculo(const Circulo &p)
{
	cout << "C: ";
	EscribirPunto(p.centro);
	cout << " - " << p.radio << endl;
}

Circulo LeerCirculo()
{
	Circulo c;
	cout << "Introduce círculo:";
	c.centro = LeerPunto();
	cin >> c.radio;
	return c;
}

double AreaCirculo(const Circulo &c)
{
	return M_PI*pow(c.radio,2);
}
/* Fin: circulomedio.cpp */
