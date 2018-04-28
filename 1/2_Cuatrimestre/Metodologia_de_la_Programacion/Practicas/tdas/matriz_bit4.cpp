#include <iostream>
#include <cmath>
#include "matriz_bit4.h"
using namespace std;
bool Inicializar(MatrizBit& m, int fils, int cols){
	bool exito=true;
	if((fils*cols)>(100*32)){
		exito=false;
	}
	else{
		int f[8];
		int c[8];
		for(int i=0;i<8;i++){
			f[i]=0;
			c[i]=0;
		}
		for(int i=0;fils!=0 || cols!=0;i++){
			if(fils%2==1) f[i]=1;
			else f[i]=0;
			fils=fils/2;
			if(cols%2==1) c[i]=1;
			else c[i]=0;
			cols=cols/2;
		}
		int fxc2[16], i2=0;
		for(int i=7;i>=0;i--){
			fxc2[i2]=f[i];
			i2++;
		}
		for(int i=7;i>=0;i--){
			fxc2[i2]=c[i];
			i2++;
		}
		int k=0;
		unsigned short int suma=0;
		for(int i=15;i>=0;i--){
			if(fxc2[i]) suma=suma+(pow(2,k));
			k++;
		}
		m.fxc=suma;

	}
	return exito;
}
int Filas (const MatrizBit& m){
	int i2=0, f[8], filas;
	for(int j=15;j>=0;j--){
		if(j>7){	
			if((m.fxc&(1<<j))!=0){
				f[i2]=1;
				i2++;
			}
			else{
				f[i2]=0;
				i2++;
			}
		}
	}
	int suma1=0;
	int k=0;
	for(int i=7;i>=0;i--){
		suma1=suma1+(pow(2,k))*f[i];
		k++;
	}
	filas=suma1;
	return filas;
}
int Columnas(const MatrizBit& m){
	int i2=0, c[8], columnas;
	for(int j=15;j>=0;j--){
		if(j<=7){	
			if((m.fxc&(1<<j))!=0){
				c[i2]=1;
				i2++;
			}
			else{
				c[i2]=0;
				i2++;
			}
		}
	}
	int suma1=0;
	int k=0;
	for(int i=7;i>=0;i--){
		suma1=suma1+(pow(2,k))*c[i];
		k++;
	}
	columnas=suma1;
	return columnas;
}
bool Get(const MatrizBit& m, int f, int c){
	int indice=(f*Columnas(m))/32;
	int indice2=32-((Columnas(m)*f)+c+1);
	return m.vector[indice]&(1<<indice2);
}
void Set(MatrizBit& m, int f, int c, bool v){
	int indice=(f*Columnas(m))/32;
	int vector1[32];
	int ind=0;
	for(int i=31;i>=0;i--){
		if((m.vector[indice]&(1<<i))!=0){
			vector1[ind]=1;
			ind++;
		}
		else{
			vector1[ind]=0;
			ind++;
		}
	}
	int indice2=((Columnas(m)*f)+c);
	if(v==1){
		vector1[indice2]=1;
	}
	else{
		vector1[indice2]=0;
	}
	m.vector[indice]=0;
	int k=0;
	for(int i=31;i>=0;i--){
		m.vector[indice]=m.vector[indice]+(pow(2,k))*vector1[i];
		k++;
	}
}
