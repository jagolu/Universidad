#include "O3D.h"
O3D::O3D(){}
O3D::O3D(vector<_vertex3ui> t, vector<_vertex3f> a){
	triangles=t;

}

void O3D::draw_edges(){
	int Vertex_1, Vertex_2, Vertex_3;
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glBegin(GL_TRIANGLES);
	for(int i=0;i<triangles.size();i++){	
		Vertex_1=triangles[i]._0;
		Vertex_2=triangles[i]._1;
		Vertex_3=triangles[i]._2;
		glVertex3f( OB3D::edges[Vertex_1].x, OB3D::edges[Vertex_1].y, OB3D::edges[Vertex_1].z);
		glVertex3f( OB3D::edges[Vertex_2].x, OB3D::edges[Vertex_2].y, OB3D::edges[Vertex_2].z);
		glVertex3f( OB3D::edges[Vertex_3].x, OB3D::edges[Vertex_3].y, OB3D::edges[Vertex_3].z);
	}
	glEnd();
}

void O3D::draw_solid(){
	int Vertex_1, Vertex_2, Vertex_3;
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glBegin(GL_TRIANGLES);
	for(int i=0;i<triangles.size();i++){	
		Vertex_1=triangles[i]._0;
		Vertex_2=triangles[i]._1;
		Vertex_3=triangles[i]._2;
		glVertex3f( OB3D::edges[Vertex_1].x, OB3D::edges[Vertex_1].y, OB3D::edges[Vertex_1].z);
		glVertex3f( OB3D::edges[Vertex_2].x, OB3D::edges[Vertex_2].y, OB3D::edges[Vertex_2].z);
		glVertex3f( OB3D::edges[Vertex_3].x, OB3D::edges[Vertex_3].y, OB3D::edges[Vertex_3].z);
	}
	glEnd();
}

void O3D::draw_solid_chess(){
	int Vertex_1, Vertex_2, Vertex_3;
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	bool cara2=false;
	glColor3f(0,1,1);
	glBegin(GL_TRIANGLES);
	for(int i=0;i<triangles.size();i++){
		if(cara2){glColor3f(0,1,1); cara2=false;}
		else{glColor3f(1,1,0);cara2=true;}	
		Vertex_1=triangles[i]._0;
		Vertex_2=triangles[i]._1;
		Vertex_3=triangles[i]._2;
		glVertex3f( OB3D::edges[Vertex_1].x, OB3D::edges[Vertex_1].y, OB3D::edges[Vertex_1].z);
		glVertex3f( OB3D::edges[Vertex_2].x, OB3D::edges[Vertex_2].y, OB3D::edges[Vertex_2].z);
		glVertex3f( OB3D::edges[Vertex_3].x, OB3D::edges[Vertex_3].y, OB3D::edges[Vertex_3].z);
	}
	glEnd();
}
		
