//==============================================================
// Práctica 1 - IG
// Arturo Cortés Sánchez
//==============================================================

#ifndef _FIGREV_H
#define _FIGREV_H
#include "Objply.h"
#include <vector>

class Figrev: public Objply{
	private:
		bool tapa=false;
		vector<float> vertices_orig;
		void rotar(float x, float y, float z, float & x_out, float & y_out, float & z_out, float angulo);
		vector<int> unirPerfil(int i, int tope);
		void revolucion(int n, vector<float> & vertices, vector<int> & aristas);


	public:
		Figrev();
		void perfil(int n);
		void perfil(int n, string s);
		bool gettapa();
		void settapa(bool t);
		void ponertapas(vector<float> & v);
		void reset();

};

#endif
