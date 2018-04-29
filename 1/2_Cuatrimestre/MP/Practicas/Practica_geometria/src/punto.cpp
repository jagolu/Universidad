#include <iostream>
#include <cmath>
#include "punto.h"

using namespace std;


Punto LeerPunto(){
	Punto p;
	char c;
	cin>>c;
	cin>>p.x;
	cin>>c;
	cin>>p.y;
	cin>>c;
	return p;
}

void EscribirPunto (const Punto& p){
	cout<<"("<<p.x<<","<<p.y<<")";
}

void InicializarPunto (Punto &p, const double& cx,const double& cy){
	p.x=cx;
	p.y=cy;
}

double GetX (const Punto& p){
	return p.x;
}

double GetY (const Punto& p){
	return p.y;
}

double Distancia (const Punto& p1, const Punto& p2){
	double x, y, distancia;
	x=p1.x-p2.x;
	y=p1.y-p2.y;
	distancia=sqrt((x*x)+(y*y));
	return distancia;
}

Punto PuntoMedio (const Punto& p1, const Punto& p2){
	Punto p3;
	p3.x=(p1.x+p2.x)/2;
	p3.y=(p1.y+p2.y)/2;
	return p3;
}
double LongitudTrayecto (const Punto v[], const int& total){
	double suma=0;
	for(int i=0;i<total-1;i++){
		suma=suma+Distancia(v[i],v[i+1]);
	}
	return suma;
}
