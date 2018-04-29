#include <iostream>

using namespace std;

int main(){
	int n, espacio, arbol=1, filas, espaciobase, filasbase;
	
	cout<<"Introduzca un numero impar: ";
	cin>>n;
	
	espacio=(n/2)+2;
	filas=(n/2)+1;	
	espaciobase=(n/2)+1;
	filasbase=(n-1)-filas;
		
	for(int i=1;i<=filas;i++){
		for(int j=1;j<=espacio;j++){
			cout<<" ";
		}
		for(int k=1;k<=arbol;k++){
			cout<<"*";
		}
		arbol=arbol+2;
		espacio=espacio-1;
		cout<<endl;
	}
	for(int ii=1;ii<=filasbase;ii++){
		for(int jj=1;jj<=espaciobase;jj++){
			cout<<" ";
		}
		for(int kk=1;kk<=3;kk++){
			cout<<"*";
		}
		cout<<endl;
	}
}
		
