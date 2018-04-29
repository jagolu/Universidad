#include "punto.h"
#include "rectangulo.h"
#include <iostream>

using namespace std;

int main(){
	Punto v[100];
	int total=1;
	char a;
	cout<<"Introduca un punto ";
	v[0]=LeerPunto();
	do{
		cout<<"Introduzca otro punto: ";
		v[total]=LeerPunto();
		do{
			cout<<"Introducir mas puntos? (s/n) ";
			cin>>a;
			a=tolower(a);
		}while(a!='s' && a!='n');
		total++;
	}while(a!='n');
	Rectangulo res;
	InicializarRectangulo(res, InferiorIzquierda(Delimitador(v,total)), SuperiorDerecha(Delimitador(v,total)));
	EscribirRectangulo(res);
	cout<<endl;
}
