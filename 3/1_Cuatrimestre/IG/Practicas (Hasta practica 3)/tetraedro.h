#ifndef _TETRAEDRO
#define _TETRAEDRO

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "vertex.h"
#include "OB3D.h"
#include "O3D.h"
#include <vector>
#include <iostream>

using namespace std;

class tetraedro: public O3D{
	public:
	tetraedro();
	tetraedro(float size);
};

#endif
