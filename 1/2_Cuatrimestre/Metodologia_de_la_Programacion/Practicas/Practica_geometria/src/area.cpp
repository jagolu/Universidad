#include <iostream>
#include "punto.h"
#include "circulo.h"
using namespace std;
int main(){
	Circulo c1;
	cout<<"Introduzca un circulo en formato radio-(x,y): ";
	c1= LeerCirculo();
	cout<<"El area es:  "<<Area(c1)<<endl;
}
