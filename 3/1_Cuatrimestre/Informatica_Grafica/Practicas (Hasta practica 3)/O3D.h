#ifndef _O3D
#define _O3D

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "vertex.h"
#include "OB3D.h"
#include <vector>
#include <iostream>

using namespace std;

class O3D : public OB3D{
	protected:
		vector<_vertex3ui> triangles;
	public:
		O3D();
		O3D(vector<_vertex3ui> t, vector<_vertex3f> a);
		void draw_edges();
		void draw_solid();
		void draw_solid_chess();
};

#endif
		
