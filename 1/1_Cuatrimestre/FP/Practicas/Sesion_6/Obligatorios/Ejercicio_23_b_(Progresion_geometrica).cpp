/*Supongamos una serie numérica cuyo término general es:
ai = a1ri..1
Se pide crear un programa que lea desde teclado r, el primer elemento a1 y el tope k
y calcule la suma de los primeros k valores de la serie, es decir:
Xi=k
i=1
ai
Si analizamos la expresión algebraica de la serie numérica, nos damos cuenta
que es una progresión geométrica ya que cada término de la serie queda definido
por la siguiente expresión:
ai+1 = ai  r
Es decir, una progresión geométrica es una secuencia de elementos en la que
cada uno de ellos se obtiene multiplicando el anterior por una constante denominada
razón o factor de la progresión.
Cread el programa pedido usando esta fórmula. NO puede utilizarse la función
pow.*/
#include <iostream>

using namespace std;

int main(){
	int a1, r, k, sumatorio, i;
	
	cout<<"Introduzca un numero r: ";
	cin>>r;
	cout<<"Introduzca un numero a1: ";
	cin>>a1;
	cout<<"Introduzca un numero k: ";
	cin>>k;
	
	sumatorio=a1;
	
	for(i=2;i<=k;i=i+1){ /*Aqui se calculara el valor incial y se calculara el sumatorio a partir de el y de r*/
		a1=a1*r;
		sumatorio=sumatorio+a1;
	}
	cout<<"El sumatorio de ai es: "<<sumatorio<<endl;
	system("pause");
}
