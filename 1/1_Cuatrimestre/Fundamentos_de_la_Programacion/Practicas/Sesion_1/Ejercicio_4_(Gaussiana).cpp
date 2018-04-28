/* Este es un programa que calcula la funcion gaussiana de x.
		Necesita:
			La desviacion tipica: desviacion
			La media: media
			El valor de la abcisa: abcisa
			Teniendo como constante pi=3.1415927
		Calculara el valor de la funcion en dicha abcisa: 	gaussiana= (1/(desviacion*sqrt(2*pi)))*(exp((-0.5)*(pow(((abcisa-media)/desviacion),2)))) */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double media, desviacion, abcisa, gaussiana  ;
	const double pi=3.1415927 ;
	
	cout<<"Introduzca el valor de la media: " ;
	cin>> media ;
	cout<<"Introduzca el valor de la desviacion tipica: " ;
	cin>> desviacion ;
	cout<<"Introduzca el valor de la abcisa: " ;
	cin>> abcisa;
	
	gaussiana= (1/(desviacion*sqrt(2*pi)))*(exp((-0.5)*(pow(((abcisa-media)/desviacion),2))));
	cout<<"El valor de la funcion gaussiana es: " <<gaussiana <<endl ;
	system("pause") ;
	
}
