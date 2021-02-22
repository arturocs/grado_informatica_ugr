//==============================================================
// Práctica 1 - IG
// Arturo Cortés Sánchez
//==============================================================

#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#include <vector>
using namespace std;


class Objeto3D{
	protected:

		vector<float> vertices; //uso vector para poder usar size()
		vector<int> aristas; 
		bool puntos, alambre, relleno, ajedrez, rellenoybordes;

	public:
		vector<float> vectorcolor(float a, float b, float c);
		void enablecl();
		void disablecl();
		void dibujar_puntos();
		void dibujar_alambre();
		void dibujar_relleno();
		void dibujar_ajedrez();
		void dibujar();
		void modo(char ch);
		
};


#endif
