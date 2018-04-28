#ifndef _BASE
#define _BASE

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "vertex.h"
#include "OB3D.h"
#include "O3D.h"
#include "esfera.h"
#include "cubo.h"
#include "cilindro.h"
#include "paloPelota.h"
#include "objeto_revolucion.h"
#include <vector>
#include <iostream>

using namespace std;

class base: public objeto_revolucion{
	private:
		cubo c1;
		cubo c2;
		cilindro cin1;
		cilindro cin2; 	
	public:
	base();
	base(float size, int veces);
	void draw_points(float n, int giro);
	void draw_edges(float n, int giro);
	void draw_solid(float n, int giro);
	void draw_solid_chess(float n, int giro);
};

#endif
