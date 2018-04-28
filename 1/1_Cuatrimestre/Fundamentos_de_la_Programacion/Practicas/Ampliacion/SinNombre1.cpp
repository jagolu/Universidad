#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n, j=0, longitud=0, longitudLarga, posicion=0, posicionmenor;
	
	do{
		cout<<"Introduzca un numero: ";
		cin>>n;
			
		if(0<=n && n<=100){
			posicion=posicion+1;
			if(j<=n){
				j=n;
				longitud=longitud+1;
				longitudLarga=longitud;
			}
			else{
				if(longitudLarga<=longitud){
					longitudLarga=longitud;
				}
				else{
					longitud=0;
				}
			}
			if(longitudLarga<=longitud){
				posicionmenor=posicion;
			}
		}
	}while(0<=n && n<=100);
	cout<<"La subsecuencia empieza en la posicion "<<posicionmenor<<"y tiene longitud "<<longitudLarga<<endl;
	system("pause");
}
