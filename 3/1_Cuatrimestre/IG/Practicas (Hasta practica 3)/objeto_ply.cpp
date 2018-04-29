#include "objeto_ply.h"
objeto_ply::objeto_ply(){}
objeto_ply::objeto_ply(char * nombre){
	_file_ply fp;
	fp.open(nombre);
	vector<int>faces;
	vector<float>vertices;
	fp.read(vertices,faces);
	fp.close();
	
	for(int i=0;i<vertices.size();i=i+3){
		_vertex3f v2;
		v2.x=vertices[i];
		v2.y=vertices[i+1];
		v2.z=vertices[i+2];
		OB3D:edges.push_back(v2);
	}
	for(int i=0;i<faces.size();i=i+3){
		_vertex3ui v2;
		v2._0=faces[i];
		v2._1=faces[i+1];
		v2._2=faces[i+2];
		O3D:triangles.push_back(v2);	
	}
}
