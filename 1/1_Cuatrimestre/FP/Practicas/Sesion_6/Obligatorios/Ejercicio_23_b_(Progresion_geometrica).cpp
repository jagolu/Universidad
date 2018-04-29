/*Supongamos una serie num�rica cuyo t�rmino general es:
ai = a1ri..1
Se pide crear un programa que lea desde teclado r, el primer elemento a1 y el tope k
y calcule la suma de los primeros k valores de la serie, es decir:
Xi=k
i=1
ai
Si analizamos la expresi�n algebraica de la serie num�rica, nos damos cuenta
que es una progresi�n geom�trica ya que cada t�rmino de la serie queda definido
por la siguiente expresi�n:
ai+1 = ai  r
Es decir, una progresi�n geom�trica es una secuencia de elementos en la que
cada uno de ellos se obtiene multiplicando el anterior por una constante denominada
raz�n o factor de la progresi�n.
Cread el programa pedido usando esta f�rmula. NO puede utilizarse la funci�n
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
