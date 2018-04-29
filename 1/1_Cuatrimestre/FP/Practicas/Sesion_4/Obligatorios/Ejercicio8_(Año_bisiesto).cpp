/*Cread un programa que lea el número de un año e indique si es bisiesto o no. Un año
es bisiesto si es múltiplo de cuatro, pero no de cien. Excepción a la regla anterior son
los múltiplos de cuatrocientos que siempre son bisiestos. Por ejemplo, son bisiestos:
1600,1996, 2000, 2004. No son bisiestos: 1700, 1800, 1900, 1998, 2002.*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int ano;
	double a,b,c;
	
	cout<<"Introduce un anyo: ";
	cin>> ano;
	
	a=ano%4;
	b=ano%100;
	c=ano%400;

	
	if((a==0 && b!=0) || (c==0)){ /*Aqui ponemos el algoritmo para decir si el año es bisiesto o no*/
		cout<<"El anyo es bisiesto." <<endl;
	}
	else{ /*Aqui damos la condicion contraria (que no sea bisiesto)*/
		cout<<"El anyo no es bisiesto." <<endl;
	}
	system("pause");
}
