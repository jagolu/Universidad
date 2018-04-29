#ifndef _ESFERA
#define _ESFERA

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "vertex.h"
#include "OB3D.h"
#include "O3D.h"
#include "objeto_revolucion.h"
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class esfera: public objeto_revolucion{
	public:
	esfera();
	esfera(float size, int veces);
};

#endif
