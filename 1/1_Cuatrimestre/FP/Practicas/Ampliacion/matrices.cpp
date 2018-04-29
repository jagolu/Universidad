#include <iostream>

using namespace std;	

int main(){
	int filas, columnas, a;
	char b;
	
	cout<<"Introduzca el numero de filas y columnas: \n";
	cin>>filas;
	cin>>columnas;
	int matriz[filas][columnas];
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<"Elemento ( "<<i<<", "<<j<<" ): ";
			cin>>a;
			matriz[i][j]=a;
		}
	}
	cout<<endl;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<matriz[i][j]<<"  ";
		}
		cout<<endl;
	}
	cout<<"Calcular inversa? (s/n): ";
	cin>>b;
	if(b=='s'){
		int matriz1[columnas][filas];
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				matriz1[j][i]=matriz[i][j];
			}
		}
		for(int i=0;i<columnas;i++){
			for(int j=0;j<filas;j++){
				cout<<matriz1[i][j]<<"  ";
			}
			cout<<endl;
		}
	}
	const int max=100;
	int vector[max];
	int total=0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<matriz[i][j]<<"  ";
		}
		cout<<endl;
	}
	int c, d, fil, colum;
	for(int i=0;i<filas;i++){
		c=matriz[i][0];
		for(int j=0;j<columnas;j++){
			d=matriz[i][j];
			if(c>d){
				c=d;
			}
		}
		vector[total]=c;
		total++;
	}
	c=vector[0];
	for(int i=0;i<total;i++){
		d=vector[i];
		if(c<d){
			c=d;
			fil=i;
		}
	}
	for(int i=0;i<columnas;i++){
		d=matriz[fil][i];
		if(c==d){
			colum=i;
		}
	}
	cout<<"EL numero buscado es: "<<c<<" que esta en ( "<<fil<<" ,"<<colum<<" )"<<endl;	
	c=0;
	for(int i=0;i<filas;i++){
		a=matriz[i][0];
		for(int j=0;j<columnas;j++){
			b=matriz[i][j];
			if(a<b){
				a=b;
			}
		}
		for(int k=0;k<columnas;k++){
			d=matriz[i][k];
			if(a>d){
				c=1;
			}
		}
	
	
	
	
	

















}
