#ifndef _BARRIDO_H
#define _BARRIDO_H
#include "Objeto3D.h"
#include <vector>

class Barrido : public Objeto3D{

	public:
		Barrido();
		void perfilBar(int n);
};

#endif