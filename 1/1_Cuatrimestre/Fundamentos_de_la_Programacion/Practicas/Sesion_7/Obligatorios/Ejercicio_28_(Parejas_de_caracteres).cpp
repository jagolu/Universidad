/*Escribid un programa que lea cuatro valores de tipo char
(min1, max1, min2, max2) e imprima las parejas que pueden formarse con
los conjuntos {min1 ... max1} y {min2 ... max2}.*/
#include <iostream>

using namespace std;

int main(){
	char min1, max1, min2, max2, i, j;
	
	cout<<"Introduzca el caracter minimo 1: ";
	cin>>min1;
	cout<<"Introduzca el caracter maximo 1: ";
	cin>>max1;
	cout<<"Introduzca el caracter minimo 2: ";
	cin>>min2;
	cout<<"Introduzca el caracter maximo 2: ";
	cin>>max2;
	
	for(i=min1;i<=max1;i=i+1){ /*Hara el bucle desde el minimo 1 al maximo 1 (primera letra)*/
		for(j=min2;j<=max2;j=j+1){ /*Aqui hara el bucle desde el minimo 2 al maximo 2 (segunda letra)*/
			cout<<i<<j<<" ";
		}
		cout<<endl;
	}
	system("pause");
}
