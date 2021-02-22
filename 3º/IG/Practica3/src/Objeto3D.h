//==============================================================
// Práctica 3 - IG
// Arturo Cortés Sánchez
//==============================================================

#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#include <vector>
#include "file_ply_stl.h"
using namespace std;


class Objeto3D{
	private:	
		void enablecl();
		void disablecl();
		void dibujar_puntos();
		void dibujar_alambre();
		void dibujar_relleno();
		void dibujar_ajedrez();

	protected:
	//	vector<float> vertices; //uso vector para poder usar size()
		vector<int> colores;
		vector<int> aristas; 
		bool puntos, alambre, relleno, ajedrez, rellenoybordes;
		void push_back_3(vector<float> & v, float a, float b, float c);
		void push_back_3(vector<int> & v, int a, int b, int c);

	public:
		vector<float> vertices; 
		vector<float> vectorcolor(float a, float b, float c);
		vector<float> vectorcolorrainbow();
		void dibujar();
		void modo(char ch);
		void zoom(float zm);
		float media();

};


#endif
