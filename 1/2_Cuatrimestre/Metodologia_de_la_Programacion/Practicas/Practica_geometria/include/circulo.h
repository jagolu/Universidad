#ifndef _CIRCULO_H_
#define _CIRCULO_H_
#include "punto.h" 
struct Circulo {
    Punto centro;
    double radio;
};
Circulo LeerCirculo();
void EscribirCirculo(const Circulo& c);
void InicializarCirculo(Circulo& c, const Punto& centro, const double& radio);
Punto Centro(const Circulo& c);
double Radio(const Circulo& c);
double Area(const Circulo& c);
bool Interior(const Punto& p, const Circulo& c);
double Distancia(const Circulo& c1, const Circulo& c2);
#endif
