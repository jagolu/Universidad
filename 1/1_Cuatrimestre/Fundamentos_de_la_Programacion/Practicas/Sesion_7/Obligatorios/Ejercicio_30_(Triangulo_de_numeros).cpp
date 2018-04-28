/*Cread un programa que ofrezca en pantalla la siguiente salida:
1 2 3 4 5 6
2 3 4 5 6
3 4 5 6
4 5 6
5 6
6
*/
#include <iostream>

using namespace std;

int main(){
	int n, i, j;
	
	cout<<"Introduzca el numero inicial: ";
	cin>>n;
	
	for(i=n;i<=6;i++){ /*Aqui hara para el numero inicial en el que empezara la primera fila, hasta el 6*/
		for(j=i;j<=6;j++){ /*Aqui calculara los elementos de cada fila hasta el 6*/
			cout<<j<<" ";
		}
		cout<<endl;
	}
	system("pause");
}
