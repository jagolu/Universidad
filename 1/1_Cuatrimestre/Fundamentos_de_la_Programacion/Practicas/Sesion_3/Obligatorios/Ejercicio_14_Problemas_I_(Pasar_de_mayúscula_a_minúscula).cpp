/*Este programa cambia una letra mayuscula a minuscula
	Necesita:
		Una letra mayuscula(mayus)*/
#include <iostream>

using namespace std;

int main(){
	
	char mayus, minus;
	
	cout<<"Introduce una letra en mayuscula: " ;
	cin>> mayus;
	
	minus=mayus+' ';
	/*Introducimos una letra mayuscula que al estar declarado como char, el programa lo leera en codigo AS-CII y como de cada letra mayuscula a su respectiva
	minuscula hay +32 unidades, a la letra mayuscula le sumo 32 unidades en AS-CII que es el espacio, y nos imprimira la respectiva minuscula*/
	cout<<minus <<endl ;
	
	system("pause");
	
}
