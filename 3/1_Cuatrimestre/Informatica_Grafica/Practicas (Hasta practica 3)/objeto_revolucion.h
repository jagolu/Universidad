#ifndef _OBJETO_REVOLUCION
#define _OBJETO_REVOLUCION
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "vertex.h"
#include <vector>
#include <iostream>
#include "OB3D.h"
#include "O3D.h"
#include "file_ply_stl.h"
#include "objeto_ply.h"
#include <math.h>




//ultimo tapa arriba
//penultimo parte de abajo

using namespace std;



class objeto_revolucion: public O3D{
	private:
		_vertex3f RotarY(_vertex3f p, double rotacion);
	public:
		objeto_revolucion();
		objeto_revolucion(vector<_vertex3f> datov, int veces);
		void generarFigura(vector<_vertex3f> datov, int veces);

};
#endif
