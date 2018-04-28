#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
int main(int argc, char* argv[]){
	if(argc==2){
		ifstream is(argv[1]);
		if(is){
			char **text;
			text=new char*[0];
			int lineas=0;
			while(!is.eof()){
				char a[100];
				is.getline(a,100);
				char **aux;
				aux=new char*[lineas+1];
				for(int i=0;i<lineas;i++){
					aux[i]=new char[strlen(text[i])];
					for(int j=0;j<strlen(text[i]);j++){
						aux[i][j]=text[i][j];
					}
				}
				for(int i=0;i<lineas;i++){
					delete [] text[i];
				}
				delete [] text;
				text=aux;
				text[lineas]=new char[strlen(a)];
				for(int i=0;i<strlen(a);i++){
					text[lineas][i]=a[i];
				}
				lineas++;
			}
			for(int i=lineas-1;i>=0;i--){
				for(int j=0;j<strlen(text[i]);j++){
					cout<<text[i][j];
				}
				cout<<endl;
			}
			for(int i=0;i<lineas;i++){
				delete [] text[i];
			}
			delete [] text;
		}
		else cout<<"El archivo no existe\n";
	}
	else cout<<"Introduzca un argumento que sea un fichero existente\n";
}
