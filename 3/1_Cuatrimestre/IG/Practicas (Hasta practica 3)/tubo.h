#ifndef _TUBO
#define _TUBO

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

class tubo: public objeto_revolucion{
	public:
	tubo();
	tubo(float size, int veces);
};

#endif
