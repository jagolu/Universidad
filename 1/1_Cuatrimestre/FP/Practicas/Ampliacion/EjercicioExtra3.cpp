#include <iostream>

using namespace std;

int main(){
	const int max=100; /*Declaramos un vector con un maximo de 100 elementos*/
	int vector[max];
	int total=0, a; /*Declaramos el total de elementos y lo inicializamos en 0*/
	do{
		cout<<"Introduzca un dato (Terminador=0): ";
		cin>>a;
		if(a!=0){ /*Con este if el vector solo cogera los elementos distintos de 0, ya que 0 no vale porque es el terminador*/
			vector[total]=a;
			total++;
			/*Al ir incrementando el total el numero introducido se mete en una posicion consecutiva a la anterior, y se queda 1 valor por encima*/
		}
	}while(a!=0); /*Pararemos de introducir datos cuando el usuario introduzca el 0*/
	cout<<"VECTOR ORIGINAL: \n";
	for(int i=0;i<total;i++){ /*Mostramos el vector*/
		cout<<vector[i]<<"  "; /*Al ir incrementando la i, se mostraran las posiciones del vector desde 0 hasta total-1 (ya que total se queda un valor por encima*/
	}
	cout<<endl;
	cout<<"VECTOR INVERTIDO: \n";
	for(int i=total-1;i>=0;i--){ /*Para invertir el vector simplemente lo mostramos desde el final hasta el principio, inicialiando i en el total-1 y haciendo que el bucle termine en 0*/
		cout<<vector[i]<<"  "; /*Se mostraran las posiciones n, n-1, n-2,...,0*/
	}
	cout<<endl;
	system("pause");
}
