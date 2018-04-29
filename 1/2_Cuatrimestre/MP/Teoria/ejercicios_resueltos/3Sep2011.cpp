#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main(int argc, char* argv[]){
	if(argc==4){
		ifstream f1(argv[1]);
		ifstream f2(argv[2]);
		ofstream archivo(argv[3]);
		if(f1 && f2 && archivo){
			double *ff1;
			double *ff2;
			int t1=0;
			ff1=new double[0];
			ff2=new double[0];
			int t2=0;
			double leyendo;
			while(f1>>leyendo){
				double *aux;
				aux=new double[t1+1];
				for(int i=0;i<t1;i++){
					aux[i]=ff1[i];
				}
				aux[t1]=leyendo;
				delete [] ff1;
				ff1=aux;
				t1++;
			}
			while(f2>>leyendo){
				double *aux;
				aux=new double[t2+1];
				for(int i=0;i<t2;i++){
					aux[i]=ff2[i];
				}
				aux[t2]=leyendo;
				delete [] ff2;
				ff2=aux;
				t2++;
			}
			double *f3;
			int t3=t1+t2;
			f3=new double[t3];
			for(int i=0;i<t1;i++){
				f3[i]=ff1[i];
			}
			for(int i=0;i<t2;i++){
				f3[t1+i]=ff2[i];
			}
			for(int i=0;i<t3-1;i++){
				int a=f3[i];
				int indice=-1;
				int b=f3[i+1];
				for(int j=i;j<t3;j++){
					if(f3[j]<=a && f3[j]<=b){
				 		indice=j;
				 		b=f3[j];
					}
				}
				if(indice!=-1){
					int bb=f3[indice];
					f3[indice]=a;
					f3[i]=bb;
				}
			}
			delete [] ff1;
			delete [] ff2;
			for(int i=0;i<t3;i++){
				archivo<<f3[i]<<" ";
			}
		}
	}
}
