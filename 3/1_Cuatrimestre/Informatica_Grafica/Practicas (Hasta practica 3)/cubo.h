#ifndef _CUBO
#define _CUBO

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
class cubo : public O3D{
	public:
	cubo();
	cubo(double size);
}; 		

#endif
