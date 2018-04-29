#ifndef _MATRIZ_BIT2_H_
#define _MATRIZ_BIT2_H_
struct MatrizBit{
	bool vector[100];
	int f;
	int c;
};
bool Inicializar(MatrizBit& m, int fils, int cols);
int Filas (const MatrizBit& m);
int Columnas( const MatrizBit& m);
bool Get(const MatrizBit& m, int f, int c);
void Set(MatrizBit& m, int f, int c, bool v);
#endif
