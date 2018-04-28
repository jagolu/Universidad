#include "tubo.h"
tubo::tubo(){}
tubo::tubo(float size, int veces){
	float div=size/2;
	vector<_vertex3f> v;
	v.push_back(_vertex3f(0+div, 0-div, 0));
	v.push_back(_vertex3f(0+div, 0+div, 0));
	objeto_revolucion::generarFigura(v, veces);
}
