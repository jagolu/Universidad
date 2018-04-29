/*Leer los datos de otra matriz y multiplicar ambas matrices (las dimensiones de la
segunda matriz han de ser compatibles con las de la primera para poder hacer la
multiplicación)*/
#include <iostream>

using namespace std;

int main(){
	int filas1, filas2, columnas1, columnas2;
	int i=0, j=0, a;
	
	cout<<"Introduzca las filas de la primera matriz: ";
	cin>>filas1;
	cout<<"Introduzca las columnas de la primera matriz: ";
	cin>>columnas1;
	int matriz1[filas1][columnas1];
	for(i=0;i<filas1;i++){
		for(j=0;j<columnas1;j++){
			cout<<"Elemento ("<<i<<" ,"<<j<<" ): ";
			cin>>a;
			matriz1[i][j]=a;
		}
	}
	
	for(i=0;i<filas1;i++){
		for(j=0;j<columnas1;j++){
			cout<<matriz1[i][j]<<"  ";
		}
		cout<<endl;
	}
	
	cout<<"Introduzca las filas de la segunda matriz: ";
	cin>>filas2;
	cout<<"introduzca las columnas de la segunda matriz: ";
	cin>>columnas2;
	int matriz2[filas2][columnas2];
	for(i=0;i<filas2;i++){
		for(j=0;j<columnas2;j++){
			cout<<"Elemento ("<<i<<" ,"<<j<<" ): ";
			cin>>a;
			matriz2[i][j]=a;
		}
	}
	
	for(i=0;i<filas2;i++){
		for(j=0;j<columnas2;j++){
			cout<<matriz2[i][j]<<"  ";
		}
		cout<<endl;
	}
	int matriz_multiplicada[filas1][columnas2];
	if(columnas1!=filas2){
		cout<<"\nLa multiplicacion no es posible\n";
	}
	else{
		int a, b=0;;
		cout<<"\nMultiplicando...\n";
		for(i=0;i<filas1;i++){
			for(j=0;j<columnas2;j++){
				for(int ii=0;ii<filas2;ii++){
					a=matriz1[0+i][ii]*matriz2[ii][0+j];
					b=b+a;
				}
				matriz_multiplicada[i][j]=b;
				b=0;
			}
		}
		for(i=0;i<filas1;i++){
			for(j=0;j<columnas2;j++){
				cout<<matriz_multiplicada[i][j]<<"  ";
			}
			cout<<endl;
		}
	}
	system("pause");
}
	
