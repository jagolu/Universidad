/*Supongamos una serie numérica cuyo término general es:
ai = a1ri..1
Se pide crear un programa que lea desde teclado r, el primer elemento a1 y el tope k
y calcule la suma de los primeros k valores de la serie, es decir:
Xi=k
i=1
ai
Realizad la suma de la serie usando la función pow para el cómputo de cada
término ai. Los argumentos de pow no pueden ser ambos enteros, por lo que
forzaremos a que la base*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int r, a1, k, ai, i, sumatorio;
	
	cout<<"Introduzca un numero r: ";
	cin>>r;
	cout<<"Introduzca el numero a1: ";
	cin>>a1;
	cout<<"Introduzca el tope k: ";
	cin>>k;
	
	sumatorio=0;
	
	for(i=k;i>=1;i=i-1){ /*aqui iremos sumando los valores de a1, hasta el tope k*/
		ai=a1*pow(r,(i-1));
		sumatorio=sumatorio+ai;
	}
	cout<<"El sumatorio de a1 es: "<<sumatorio<<endl;
	
	system("pause");
}
