#include "OB3D.h"
OB3D::OB3D(){}
OB3D::OB3D(vector<_vertex3f>a){
	edges=a;
}
vector<_vertex3f> OB3D::getEdges(){	
	return edges;
}
void OB3D::draw_points(){
	glBegin(GL_POINTS);
	for(int i=0;i<edges.size();i++){
		glVertex3f(edges[i].x, edges[i].y, edges[i].z);
	}
	glEnd();
}

