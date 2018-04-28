#include <iostream>
#include "matriz_bit2.h"
using namespace std;
bool Inicializar(MatrizBit& m, int fils, int cols){
	bool exito=true;
	if((fils*cols)>100){
		exito=false;
	}
	else{
		m.f=fils;
		m.c=cols;
	}
	return exito;
}
int Filas (const MatrizBit& m){
	return m.f;
}
int Columnas( const MatrizBit& m){
	return m.c;
}
bool Get(const MatrizBit& m, int f, int c){
	return m.vector[(Columnas(m)*f)+c];
}
void Set(MatrizBit& m, int f, int c, bool v){
	m.vector[(Columnas(m)*f)+c]=v;
}
