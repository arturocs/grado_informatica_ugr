#include <iostream>
#include <cmath> 
#include "punto.h"
using namespace std;


void EscribirPunto(const Punto &p)
{
	cout << "P:" << p.x << ", " << p.y;
}

Punto LeerPunto()
{
	Punto p;
	cout << "Introduce punto: ";
	cin >> p.x >> p.y;
	return p;
}

double DistanciaPuntos(const Punto &p1, const Punto &p2)
{
	return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

Punto PuntoMedio(const Punto &p1, const Punto &p2)
{
	Punto p;
	p.x=(p1.x+p2.x)/2;
	p.y=(p1.y+p2.y)/2;
	return p;
}
