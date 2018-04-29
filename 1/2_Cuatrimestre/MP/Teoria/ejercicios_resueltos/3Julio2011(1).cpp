#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(int argc, char* argv[]){
	if(argc<=5){
		bool ficheros=true;
		for(int i=2;i<argc;i++){
			ifstream is(argv[i]);
			if(!is) ficheros=false;
		}
		if(ficheros){
			for(int k=2;k<argc;k++){
				ifstream is(argv[k]);
				cout<<argv[k]<<"\n";
				int nlinea=0;
				while(!is.eof()){
					char a[500];
					is.getline(a,500);
					bool palabra=false;
					for(int i=0;i<strlen(a);i++){
						if(a[i]==argv[1][0]){
							bool esta=true;
							for(int j=0;j<strlen(argv[1]);j++){
								if(a[i+j]!=argv[i][j]) esta=false;
							}
							if(esta) palabra=true;
						}
					}
					if(palabra){
						cout<<"(linea "<<nlinea<<") : ";
						for(int i=0;i<strlen(a);i++){
							cout<<a[i];
						}
					}
					cout<<endl;
				}
			}
		}
		else cout<<"No todos los ficheros existen\n";
	}
	else cout<<"Demasiados ficheros para buscar\n";
}
