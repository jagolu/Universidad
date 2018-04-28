#ifndef _OBJETO_PLY
#define _OBJETO_PLY

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "vertex.h"
#include "OB3D.h"
#include "O3D.h"
#include "file_ply_stl.h"
#include <vector>
#include <iostream>

using namespace std;
class objeto_ply : public O3D{
	public:
	objeto_ply();
	objeto_ply(char * nombre);
};






#endif
