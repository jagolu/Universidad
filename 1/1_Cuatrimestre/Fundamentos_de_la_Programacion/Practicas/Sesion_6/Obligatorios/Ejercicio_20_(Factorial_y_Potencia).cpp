/*Calcular mediante un programa en C++ la función potencia xn, y la función factorial
n! con n un valor entero y x un valor real. No pueden usarse las funciones de la
biblioteca cmath.*/
#include <iostream>

using namespace std;

int main(){
	
	int base, potencia, potencia2, i, exponencial, exponencial2, j;
	
	cout<<"Introduzca una base: ";
	cin>>base;
	cout<<"Introduzca una potencia: ";
	cin>>potencia;
	
	potencia2=base; /*Aqui guardamos la base en otra variable*/
	
	for(i=2;i<=potencia;i=i+1){
		base=base*potencia2; /*Aqui multiplicamos la base por si mismas tantas veces como la potencia diga*/
	}
	if(potencia==0){
		cout<<"La base elevada a la potencia es: 1"<<endl; /*Si queremos elevar el numero a 0, directamente el programa imprimira que es 1*/
	}
	else{
		cout<<"La base elevada a la potencia es: "<<base<<endl; /*Aqui imprimira el resultado del for, para elevar a un valor distinto a 0*/
	}
	
	cout<<"Introduzca un numero al que desea aplicar el exponencial: ";
	cin>>exponencial;
	
	exponencial2=1;
	for(j=1;j<=exponencial;j=j+1){
		exponencial2=exponencial2*j; /*Aqui iremos multiplicando por el valor de la i, que ira aumentando en 1 hasta el valor de exponencial*/
	}
	if(exponencial==0){
		cout<<"El exponencial del numero elegido es: 1"<<endl; /*Si el exponencial que queremos calcular es del 0, el programa imprimira que es 1*/
	}
	else{
		cout<<"El exponencial del numero elegido es: "<<exponencial2<<endl; /*Aqui imprimira el valor del for*/
	}
	system("pause");
}
