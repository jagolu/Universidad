#ifndef _MATRIZ_BIT1_H_
#define _MATRIZ_BIT1_H_
struct MatrizBit{
	bool matriz[10][10];
	int f;
	int c;
};
bool Inicializar(MatrizBit& m, int fils, int cols);
int Filas (const MatrizBit& m);
int Columnas( const MatrizBit& m);
bool Get(const MatrizBit& m, int f, int c);
void Set(MatrizBit& m, int f, int c, bool v);
#endif
