#ifndef _MATRIZ_BIT3_H_
#define _MATRIZ_BIT3_H_
struct MatrizBit{
	char vector[100];
	unsigned int fxc;
};
bool Inicializar(MatrizBit& m, int fils, int cols);
int Filas (const MatrizBit& m);
int Columnas( const MatrizBit& m);
bool Get(const MatrizBit& m, int f, int c);
void Set(MatrizBit& m, int f, int c, bool v);
#endif
