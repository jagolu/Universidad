#include "tetraedro.h"
tetraedro::tetraedro(){}
tetraedro::tetraedro(float size){
	for(int i=0;i<4-2;i++){
		for(int j=i+1;j<4-1;j++){
			for(int k=j+1;k<4;k++){
				_vertex3ui v3i;
				v3i._0=i;
				v3i._1=j;
				v3i._2=k;
				O3D::triangles.push_back(v3i);
			}
		}
	}

	float div=size/2;
	OB3D::edges.push_back(_vertex3f(0+div, 0-div, 0));
	OB3D::edges.push_back(_vertex3f(0-div, 0-div, 0-div));
	OB3D::edges.push_back(_vertex3f(0-div, 0-div, 0+div));
	OB3D::edges.push_back(_vertex3f(0, 0+div, 0));

}
