/*Calcular la traspuesta de la matriz, almacenando el resultado en otra matriz.*/
#include <iostream>

using namespace std;

int main(){
	int util_fila, util_columna;
	int a;
	
	cout<<"Introduzca el numero de filas: ";
	cin>>util_fila;
	cout<<"Introduzca el numero de columnas: ";
	cin>>util_columna;
	int matriz[util_fila][util_columna];
	for(int i=0;i<util_fila;i++){
		for(int j=0;j<util_columna;j++){
			cout<<"Elemento ("<<i<<" ,"<<j<<" ): ";
			cin>>a;
			matriz[i][j]=a;
		}
	}
	cout<<endl;
	for(int i=0;i<util_fila;i++){
		for(int j=0;j<util_columna;j++){
			cout<<matriz[i][j]<<"  ";
		}
		cout<<endl;
	}
	int matriz_traspuesta[util_columna][util_fila];
	cout<<"Calculando la inversa...\n";
	for(int i=0;i<util_fila;i++){
		for(int j=0;j<util_columna;j++){
			a=matriz[i][j];
			matriz_traspuesta[0+j][0+i]=a;
		}
	}
	for(int i=0;i<util_columna;i++){
		for(int j=0;j<util_fila;j++){
			cout<<matriz_traspuesta[i][j]<<"  ";
		}
		cout<<endl;
	}
}
