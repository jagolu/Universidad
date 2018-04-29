#ifndef _PUNTO_H_
#define _PUNTO_H_
struct Punto{
    double x,y;
};
Punto LeerPunto();
void EscribirPunto(const Punto& p);
void InicializarPunto(Punto &p, const double& cx, const double& cy);
double GetX(const Punto& p);
double GetY(const Punto& p);
double Distancia(const Punto& p1, const Punto& p2);
Punto PuntoMedio(const Punto& p1, const Punto& p2);
double LongitudTrayecto (const Punto v[], const int& total);
#endif
