#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n, k=0, suma=0;
	
	cout<<"Introduzca un numero entero: ";
	cin>>n;
	
	do{
		k=k+1;
		suma=(k*(k+1))/2;
	}
	while(suma!=n && suma<n );{
		if(suma==n){
			cout<<"El numero si es triangular"<<endl;
		}
		else{
			cout<<"El numero no es triangular"<<endl;
		}
	}
	system("pause");
}
