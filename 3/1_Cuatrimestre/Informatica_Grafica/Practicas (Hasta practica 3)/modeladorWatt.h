#ifndef _MODELADORWATT
#define _MODELADORWATT

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
#include "base.h"
#include "dosPelotasUnidas.h"
#include "objeto_revolucion.h"
#include <vector>
#include <iostream>

using namespace std;

class modeladorWatt: public objeto_revolucion{
	private:
		base b;
		dosPelotasUnidas pp; 	
	public:
	modeladorWatt();
	modeladorWatt(float size, int veces);
	void draw_points(float n, int giro);
	void draw_edges(float n, int giro);
	void draw_solid(float n, int giro);
	void draw_solid_chess(float n, int giro);
};

#endif
