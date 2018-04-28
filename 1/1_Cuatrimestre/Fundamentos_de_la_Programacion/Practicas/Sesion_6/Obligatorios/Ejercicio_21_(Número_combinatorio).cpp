/*Calcular mediante un programa en C++ el combinatorio

n
m

con n, m valores
enteros. No pueden usarse las funciones de la biblioteca cmath.*/
#include <iostream>

using namespace std;

int main(){
	int n, m, nm, n_exponencial, m_exponencial, nm_exponencial, i, j, k;
	double total;
	
	do{ /*Aqui obligamos a que n sea mayor o igual que m*/
	cout<<"Introduzca un numero n: ";
	cin>>n;
	cout<<"Introduzca un numero m: ";
	cin>>m;
	}while(n<=m);{ 
		nm=n-m;
		n_exponencial=1;
		m_exponencial=1;
		nm_exponencial=1;
	
		for(i=1;i<=n;i=i+1){ /*Calculamos el exponencial de n*/
			n_exponencial=n_exponencial*i;
		}
		for(j=1;j<=m;j=j+1){ /*Calculamos el exponencial de m*/
			m_exponencial=m_exponencial*j;
		}
		for(k=1;k<=nm;k=k+1){ /*Calculamos el exponencial de n-m*/
			nm_exponencial=nm_exponencial*k;
		}
		total=n_exponencial/(m_exponencial*nm_exponencial); /*Calculamos el combinatorio y lo imprimimos*/
		cout<<"El combinatorio de n y m es: "<<total<<endl;
	}
	system("pause");
}
