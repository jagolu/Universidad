#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
	char nombre[100];
	cout<<"Introduzca el nombre del archivo: ";
	cin.getline(nombre,100);
	ifstream is(nombre);
	char **texto;
	texto=new char*[0];
	char a[100];
	int lineas=0;
	while(is.getline(a,100)){
		char **aux;
		aux=new char*[lineas+1];
		for(int i=0;i<lineas;i++){
			aux[i]=new char[strlen(texto[i])+1];
			for(int j=0;j<strlen(texto[i])+1;j++){
				aux[i][j]=texto[i][j];
			}
		}
		for(int i=0;i<lineas;i++){
			delete [] texto[i];
		}
		delete [] texto;
		texto=aux;
		texto[lineas]=new char[strlen(a)+1];
		for(int i=0;i<strlen(a)+1;i++){
			texto[lineas][i]=a[i];
		}
		lineas++;
	}
	for(int i=lineas-1;i>=0;i--){
		for(int j=strlen(texto[i])-1;j>=0;j--){
			cout<<texto[i][j];
		}
		cout<<endl;
	}
		
}
