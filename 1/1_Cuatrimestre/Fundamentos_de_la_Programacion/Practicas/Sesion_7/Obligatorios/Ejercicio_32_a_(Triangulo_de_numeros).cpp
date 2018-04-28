#include <iostream>

using namespace std;

int main(){
	int inicial, columna, i, j, fila;
	
	cout<<"Introduzca el numero inicial: ";
	cin>>inicial;
	cout<<"Introduzca el numero de columnas: ";
	cin>>fila;
	
	columna=fila+inicial-1; /*Aqui se calculara el numero al que debe llegar el "pico" del triangulo*/
	for(i=inicial;i<=columna;i++){ /*Aqui se calcularan las filas*/
		for(j=i;j<=columna;j++){ /*Aqui se calcularan los elementos de cada fila*/
			cout<<j<<" ";
		}
		cout<<endl;
	}
	system("pause");
}
