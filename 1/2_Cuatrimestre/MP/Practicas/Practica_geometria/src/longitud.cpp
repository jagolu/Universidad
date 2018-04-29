#include <iostream>
#include "punto.h"

using namespace std;

int main(){
	Punto v[100];
	char continuar;
	int total=1;
	cout<<"Introduzca un punto del formato (x,y): ";
	v[0]=LeerPunto();
	do{
		cout<<"Introduca otro punto: ";
		v[total]=LeerPunto();
		do{
			cout<<"Introducir mas puntos? (s/n) ";
			cin>>continuar;
			continuar=tolower(continuar);
		}while(continuar!='s' && continuar !='n');
		total++;
	}while(continuar!='n');
	cout<<"La longitud del trayecto es: "<<LongitudTrayecto(v, total)<<endl;
}
