//==============================================================
// Práctica 2 - IG
// Arturo Cortés Sánchez
//==============================================================

#ifndef _OBJPLY_H
#define _OBJPLY_H
#include "Objeto3D.h"
#include <vector>
#include "vertex.h"
#include <file_ply_stl.h>

class Objply: public Objeto3D{
	private:
		_file_ply File_ply;
		vector<_vertex3f> vertices_h;
  		vector<_vertex3i> triangles_h;
 

  	public:
		Objply();
		void figply(string s);
};

#endif
