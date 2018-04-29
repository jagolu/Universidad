/*Modificad los dos ejercicios anteriores para que se lea desde teclado el valor inicial
y el número de filas a imprimir.*/
#include <iostream>

using namespace std;

int main(){
	int inicial, columna, i, j, k, fila;
	
	cout<<"Introduzca el numero incial: ";
	cin>>inicial;
	cout<<"Introduzca el numero de columnas: ";
	cin>>fila;
	k=fila+inicial-1; /*Guardamos las filas en una variable*/
	columna=fila+inicial-1; /*Guardamos en una variable el numero de columnas que se haran*/
	
	for(i=inicial;i<=columna;i++){ /*Aqui se haran el numero de filas*/
		for(j=i;j<=k;j++){ /*Aqui se haran los elementos de cada fila*/
			cout<<j<<" ";
		}
		cout<<endl;
		k++;
	}
	system("pause");
}
