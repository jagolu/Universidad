#include <iostream>
#include <cmath>
#include "matriz_bit3.h"
using namespace std;
bool Inicializar(MatrizBit& m, int fils, int cols){
	bool exito=true;
	if((fils*cols)>100){
		exito=false;
	}
	else{
		bool f[16];
		bool c[16];
		for(int i=0;i<16;i++){
			f[i]=0;
			c[i]=0;
		}
		for(int i=0;fils!=0 || cols!=0;i++){
			f[i]=fils%2;
			fils=fils/2;
			c[i]=cols%2;
			cols=cols/2;
		}
		int fxc2[32], i2=0;
		for(int i=15;i>=0;i--){
			fxc2[i2]=f[i];
			i2++;
		}
		for(int i=15;i>=0;i--){
			fxc2[i2]=c[i];
			i2++;
		}
		int k=0, suma=0;
		for(int i=31;i>=0;i--){
			suma=suma+(pow(2,k))*fxc2[i];
			k++;
		}
		m.fxc=suma;
	}
	return exito;
}
int Filas (const MatrizBit& m){
	int i2=0, f[16], filas;
	for(int j=31;j>=0;j--){
		if(j>15){	
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
	for(int i=15;i>=0;i--){
		suma1=suma1+(pow(2,k))*f[i];
		k++;
	}
	filas=suma1;
	return filas;
}
int Columnas( const MatrizBit& m){
	int i2=0, c[16], columnas;
	for(int j=31;j>=0;j--){
		if(j<=15){	
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
	for(int i=15;i>=0;i--){
		suma1=suma1+(pow(2,k))*c[i];
		k++;
	}
	columnas=suma1;
	return columnas;
}
bool Get(const MatrizBit& m, int f, int c){
	bool v;
	if(m.vector[(Columnas(m)*f)+c]=='0'){
		v=0;
	}
	else{
		v=1;
	}
	return v;
}
void Set(MatrizBit& m, int f, int c, bool v){
	char vv;
	if(v==1){
		vv='1';
	}
	else{
		vv='0';
	}
	m.vector[(Columnas(m)*f)+c]=vv;
}
