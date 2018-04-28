/*Cread un programa que ofrezca en pantalla la siguiente salida:
1 2 3 4 5 6
2 3 4 5 6 7
3 4 5 6 7 8
4 5 6 7 8 9
5 6 7 8 9 10
6 7 8 9 10 11
*/
#include <iostream>

using namespace std;

int main(){
	int n, i, j, k=6;
	
	cout<<"Introduzca el numero inicial: ";
	cin>>n;
	
	for(i=n;i<=6;i++){ /*Aqui haremos el numero de filas segun el numero inicial hasta 6*/
		for(j=i;j<=k;j++){ /*Aqui haremos el numero de columnas para cada fila*/
			cout<<j<<" ";
		}
		k=k+1;
		cout<<endl;
	}
	system("pause");
}
