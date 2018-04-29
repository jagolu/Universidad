#ifndef _OB3D
#define _OB3D

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "vertex.h"
#include <vector>
#include <iostream>

using namespace std;

class OB3D{
	protected:
		vector<_vertex3f>edges;
	public:
		OB3D();
		OB3D(vector<_vertex3f>a);
		vector<_vertex3f> getEdges();
		void draw_points();
};

#endif
