#ifndef _PALOPELOTA
#define _PALOPELOTA

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "vertex.h"
#include "OB3D.h"
#include "O3D.h"
#include "esfera.h"
#include "cilindro.h"
#include "objeto_revolucion.h"
#include <vector>
#include <iostream>

using namespace std;

class paloPelota: public objeto_revolucion{
	private:
		esfera e;
		cilindro c1;
		cilindro c2;
	public:
	paloPelota();
	paloPelota(float size, int veces);
	void draw_points(float n);
	void draw_edges(float n);
	void draw_solid(float n);
	void draw_solid_chess(float n);
};

#endif
