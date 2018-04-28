/*Diseñar un programa para calcular la suma de los 100 primeros términos de la sucesión
siguiente:
ai =
(..1)i(i2 .. 1)
2i
No puede usarse la función pow. Hacedlo calculando explícitamente, en cada iteración,
el valor (..1)i (usad un bucle for). Posteriormente, resolvedlo calculando dicho
valor a partir del calculado en la iteración anterior, es decir, (..1)i..1.*/
#include <iostream>

using namespace std;

int main(){
	int i, ai, uno, suma, suma2, j, a2, dos;
	
	uno=-1;
	suma=0;
	suma2=0;
	
	for(j=1;j<=100;j=j+1){ /*Primero calculamos si i es par o impar, para elevar el -1*/
		dos=j%2;
		if(dos==0){ /*Si es par sera 1*/
			a2=(1*((j*j)-1))/(2*j);
		}
		else{ /*Si es impar sera -1*/
			a2=(-1*((j*j)-1))/(2*j);
		}
		suma2=suma2+a2;
	}
	cout<<"La suma es: "<<suma2<<endl;
	for(i=1;i<=100;i=i+1){ /*Aqui calcularemos ai sobre la itineracion anterior*/
		uno=uno*-1;
		ai=(uno*((i*i)-1))/(2*i);
		suma=suma+ai;
	}
	cout<<"La suma es: "<<suma<<endl;
	system("pause");
}
