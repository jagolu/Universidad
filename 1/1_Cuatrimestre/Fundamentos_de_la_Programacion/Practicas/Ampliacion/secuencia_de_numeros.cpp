#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n, posicion=0, longitud=0, j=0, posicion1=0;
	
	do{
		cout<<"Introduzca un numero: ";
		cin>>n;
		
		posicion=posicion+1;
		if(j<=n && (n>=0 && n<=100)){
			longitud=longitud+1;
			j=n;
			longitud=longitud+1;
			while(posicion1>posicion);
			posicion1=posicion;
		}
		if(j>n && (n>=0 && n<=100)){
			posicion1=0;
			longitud=0;
		}
		if(n>=0 && n<=100){
		}
	}while(n>=0 && n<=100);
	cout<<"Empieza en la posicion "<<posicion1<<" y tiene longitud "<<longitud<<endl;
	system("pause");
}
		
