#include "esfera.h"
esfera::esfera(){}
esfera::esfera(float size, int veces){
	OB3D::edges.clear();
	double radio=size;
	double angulo=M_PI/50;
	for(float i=M_PI/2;i>=-M_PI/2-angulo;i-=angulo){
		_vertex3f rotada;
		rotada.x=radio*cos(i);
		rotada.y=radio*sin(i);
		rotada.z=0;
		OB3D::edges.push_back(rotada);
	}
	objeto_revolucion::generarFigura(OB3D::edges, veces);
}
