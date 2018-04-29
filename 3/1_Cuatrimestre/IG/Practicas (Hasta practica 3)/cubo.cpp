#include "cubo.h"
cubo::cubo(){}
cubo::cubo(double size){
	_vertex3ui t1;t1._0=0; t1._1=2; t1._2=3;
	_vertex3ui t2;t2._0=0; t2._1=1; t2._2=3;
	_vertex3ui t3;t3._0=1; t3._1=3; t3._2=7;
	_vertex3ui t4;t4._0=1; t4._1=5; t4._2=7;
	_vertex3ui t5;t5._0=2; t5._1=6; t5._2=7;
	_vertex3ui t6;t6._0=2; t6._1=3; t6._2=7;
	_vertex3ui t7;t7._0=0; t7._1=4; t7._2=1;
	_vertex3ui t8;t8._0=1; t8._1=4; t8._2=5;
	_vertex3ui t9;t9._0=2; t9._1=4; t9._2=6;
	_vertex3ui t10;t10._0=0; t10._1=2; t10._2=4;
	_vertex3ui t11;t11._0=5; t11._1=6; t11._2=7;
	_vertex3ui t12;t12._0=4; t12._1=5; t12._2=6;

	O3D::triangles.push_back(t1);
	O3D::triangles.push_back(t2);
	O3D::triangles.push_back(t3);
	O3D::triangles.push_back(t4);
	O3D::triangles.push_back(t5);
	O3D::triangles.push_back(t6);
	O3D::triangles.push_back(t7);
	O3D::triangles.push_back(t8);
	O3D::triangles.push_back(t9);
	O3D::triangles.push_back(t10);
	O3D::triangles.push_back(t11);
	O3D::triangles.push_back(t12);

	double div=size/2;
	OB3D::edges.push_back(_vertex3f(0-div, 0+div, 0+div)); 
	OB3D::edges.push_back(_vertex3f(0+div, 0+div, 0+div)); 
	OB3D::edges.push_back(_vertex3f(0-div, 0-div, 0+div)); 
	OB3D::edges.push_back(_vertex3f(0+div, 0-div, 0+div)); 
	OB3D::edges.push_back(_vertex3f(0-div, 0+div, 0-div)); 
	OB3D::edges.push_back(_vertex3f(0+div, 0+div, 0-div)); 
	OB3D::edges.push_back(_vertex3f(0-div, 0-div, 0-div)); 
	OB3D::edges.push_back(_vertex3f(0+div, 0-div, 0-div)); 
}
