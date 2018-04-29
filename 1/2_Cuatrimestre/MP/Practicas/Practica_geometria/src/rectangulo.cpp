#include "rectangulo.h"
#include <iostream>


using namespace std;
Rectangulo LeerRectangulo(){
	Rectangulo r;
	char a;
	r.inf_izq=LeerPunto();
	cin>>a;
	r.sup_dech=LeerPunto();
	return r;
}
void EscribirRectangulo(const Rectangulo& r){
	EscribirPunto(r.inf_izq);
	cout<<" - ";
	EscribirPunto(r.sup_dech);
}
void InicializarRectangulo (Rectangulo& r, const Punto& p1, const Punto& p2){
	r.inf_izq=p1;
	r.sup_dech=p2;
}
Punto InferiorIzquierda (const Rectangulo& r){
	return r.inf_izq;
}
Punto SuperiorDerecha (const Rectangulo& r){
	return r.sup_dech;
}
double Area(const Rectangulo &r){
	Punto sup_izq;
	sup_izq.x=GetX(SuperiorDerecha(r));
	sup_izq.y=GetY(InferiorIzquierda(r));	
	double area;
	area=Distancia(sup_izq,r.sup_dech)*Distancia(sup_izq,r.inf_izq);
	return area;
}
bool Interior (const Punto& p, const Rectangulo& r){
	double x_min, x_max, y_min, y_max;
	bool esta_contenido;
	x_min=r.inf_izq.x;
	x_max=r.sup_dech.x;
	y_min=r.inf_izq.y;
	y_max=r.sup_dech.y;
	if(x_min<= p.x && p.x<=x_max && y_min<=p.y && p.y<=y_max){
		esta_contenido=true;
	}
	else{
		esta_contenido=false;
	}
	return esta_contenido;
}
Rectangulo Delimitador(const Punto v[], const int& total){
	Rectangulo vector[100];
	int total_vector=0;
	for(int i=0;i<total;i++){
		for(int j=0;j<total;j++){
			if(i!=j){
				Rectangulo r;
				InicializarRectangulo (r, v[i], v[j]);
				bool esta=true;
				for(int i=0;i<total;i++){
					if(Interior(v[i],r)==false){
						esta=false;
					}
				}
				if(esta==true){
					vector[total_vector]=r;
					total_vector++;
				}
			}
		}
	}
	
	int mayor_area=0;
	double el_area=Area(vector[0]);
	for(int i=0;i<total_vector;i++){
		if(Area(vector[i])<el_area){
			el_area=Area(vector[i]);
			mayor_area=i;
		}
	}
	return vector[mayor_area];
}
