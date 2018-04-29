#ifndef _CILINDRO
#define _CILINDRO

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "vertex.h"
#include "OB3D.h"
#include "O3D.h"
#include "objeto_revolucion.h"
#include <vector>
#include <iostream>

using namespace std;

class cilindro: public objeto_revolucion{
	public:
	cilindro();
	cilindro(float size, int veces);
};

#endif
