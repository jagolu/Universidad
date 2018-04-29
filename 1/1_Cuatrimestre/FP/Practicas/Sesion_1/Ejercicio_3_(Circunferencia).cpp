/* Este es un programa que sirve para calcular la longitud de la circunferencia y el area del circulo.
		Necesita:
			La longitud del radio: longitudR
			Teniendo como constante PI=3.1415927
		Calcula:
			Area del circulo: area=pi*longitudR*longitudR
			la longitud de la circunferencia:  longitudC=2*pi*longitudR */
			
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const double pi=3.1415927 ;
	double longitudR, area, longitudC ;
	 cout <<"Introduzca la longitud del radio: " ;
	 cin>> longitudR ;

	 
	 area=pi*longitudR*longitudR;
	 longitudC=2*pi*longitudR;
	 
	 cout<<"El area del ciruclo es: " <<area <<endl ;
	 cout<<"La longitud de la circunferencia es: " <<longitudC <<endl ;
	 system("pause");
	 
}
