#include <iostream>
#include <cmath>
#include "codificar.h"
using namespace std;
bool Ocultar(unsigned char buffer[], char mensaje[], int f, int c){
	int p=-1, i=0;
	bool bien=false;
	int o=0;
	while(mensaje[o]!='\0'){
		o++;
	}
	if(f*c>o*8){
		bien=true;
	}
	if(bien==true){
		while(mensaje[i]!='\0'){
			for(int j=7;j>=0;j--){
				p++;
				if((mensaje[i]&(1<<j))!=0){
					buffer[p]=buffer[p]|1;
				}
				else{
					buffer[p]=buffer[p]&(~1);
				}
			}
			i++;
		}
		for(int j=7;j>=0;j--){
			p++;
			if((mensaje[i]&(1<<j))!=0){
				buffer[p]=buffer[p]|1;
			}
			else{
				buffer[p]=buffer[p]&(~1);
			}
		}
	}
	return bien;
}
bool Revelar(unsigned char buffer[], char mensaje[], int total_mensaje, int total_buffer){
	int i=-1, total_vector=0, total=0;
	int vector[8];
	bool lala=true;
	bool bien=false;
	int contador=0;
	for(int j=0;j<total_buffer;j++){
		if((buffer[j]&(1<<0))!=0){
			contador=0;
		}
		else{
			contador++;
		}
		if(contador==8){
			bien=true;
		}
	}
	if(bien){
		int t=0;
		while(buffer[t]!='\0'){
			t++;
		}
		if(t/8>total_mensaje){
			bien=true;
		}
		else{
			bien=false;
		}
	}
	if(bien){
		do{
			i++;
			if((buffer[i]&(1<<0))!=0){
				vector[total]=1;
				total++;
			}
			else{
				vector[total]=0;
				total++;
			}
			if(total==8){
				int suma=0;
				int k=0;
				for(int i=7;i>=0;i--){
					suma=suma+(pow(2,k))*vector[i];
					k++;
				}
				mensaje[total_vector]=suma;
				total_vector++;
				total=0;
				if(suma=='\0'){
					lala=false;
				}
			}
		}while(lala);
		if(total_vector==0){
			cout<<"No hay mesaje que mostrar\n";
		}
		else{
			cout<<"El mensaje oculto es:\n";
			int i=0;
			while(mensaje[i]!='\0'){
				cout<<mensaje[i];
				i++;			
			}
		}
	}
	return bien;
}

