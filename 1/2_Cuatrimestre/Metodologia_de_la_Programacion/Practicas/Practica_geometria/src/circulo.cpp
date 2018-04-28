#include <iostream>
#include <cmath>
#include "circulo.h"
using namespace std;

Circulo LeerCirculo(){
	Circulo c;
	char b;
	cin>>c.radio;
	cin>>b;
	c.centro=LeerPunto();
	return c;
}

void EscribirCirculo(const Circulo& c){
	cout<<c.radio<<"-";
	EscribirPunto(c.centro);
}

void InicializarCirculo (Circulo& c, const Punto& centro, const double& radio){
	c.centro=centro;
	c.radio=radio;
}

Punto Centro (const Circulo& c){
	return c.centro;
}

double Radio (const Circulo& c){
	return c.radio;
}

double Area (const Circulo& c){
	double a;
	a=2*c.radio*M_PI;
	return a;
}

bool Interior (const Punto& p, const Circulo& c){
	bool esta_contenido=false;
	double distancia_centro;
	distancia_centro= Distancia(p,c.centro);
	if(distancia_centro<c.radio){
		esta_contenido=true;
	}
	return esta_contenido;
}

double Distancia (const Circulo& c1, const Circulo& c2){
	double distancia;
	distancia=Distancia(c1.centro, c2.centro);
	distancia=distancia-c1.radio-c2.radio;
	return distancia;
}
