#ifndef _RECTANGULO_H_
#define _RECTANGULO_H_
#include "punto.h"
struct Rectangulo{
	Punto inf_izq;
	Punto sup_dech;
};
Rectangulo LeerRectangulo();
void EscribirRectangulo(const Rectangulo& r);
void InicializarRectangulo (Rectangulo& r, const Punto& p1, const Punto& p2);
Punto InferiorIzquierda (const Rectangulo& r);
Punto SuperiorDerecha (const Rectangulo& r);
double Area(const Rectangulo &r);
bool Interior (const Punto& p, const Rectangulo& r);
Rectangulo Delimitador(const Punto v[], const int& total);
#endif
