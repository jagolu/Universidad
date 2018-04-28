#ifndef _DOSPELOTASUNIDAS
#define _DOSPELOTASUNIDAS

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

class dosPelotasUnidas: public objeto_revolucion{
	private:
		paloPelota pp1;
		paloPelota pp2;
		cubo c;
	public:
	dosPelotasUnidas();
	dosPelotasUnidas(float size, int veces);
	void draw_points(float n);
	void draw_edges(float n);
	void draw_solid(float n);
	void draw_solid_chess(float n);
};

#endif
