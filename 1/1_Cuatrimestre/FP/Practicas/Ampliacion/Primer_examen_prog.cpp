#include <iostream>

using namespace std;

int main(){
	int n1, n2, dato;
	
	n1=0;
	dato=0;
	
	do{
		cout<<"Introduzca un numero entero: ";
		cin>>dato;
		if(0<=dato && dato<=1000){
			n1=n1+dato;
		}
		else{
			cout<<"Numero no valido."<<endl;
		}
	}while(dato!=0);
	
	dato=0;
	n2=0;
	
	do{
		cout<<"Introduzca otro numero entero: ";
		cin>>dato;
		if(0<=dato && dato<=1000){
			n2=n2+dato;
		}
		else{
			cout<<"Numero no valido."<<endl;
		}
	}while(dato!=0);
	if(n1>=n2){
		cout<<"La primera secuencia (primer total= "<<n1<<" ) de datos es mayor que la segunda secuencia de datos (segundo total= "<<n2<<" )"<<endl;
	}
	else{
		cout<<"La primera secuencia (primer total= "<<n1<<" ) de datos es menor que la segunda secuencia de datos (segundo total= "<<n2<<" )"<<endl;
	}
	system("pause");
}
