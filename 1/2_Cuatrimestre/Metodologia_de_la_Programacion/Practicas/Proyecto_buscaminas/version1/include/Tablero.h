#ifndef _TABLERO_H_
#define _TABLERO_H_
struct Casilla{
	bool Bomba;
	bool Abierta;
	bool Marcada;
};

class Tablero{
private:
	Casilla m[20][20];
	int filas, columnas;
public:
	Tablero(const int& f, const int& c){
		filas=f;
		columnas=c;
	}
	int Get_Filas(){
		return filas;
	}
	int Get_Columnas(){
		return columnas;
	}
	Casilla Get_Elemento(const int& f, const int& c){
		return m[f][c];	
	}	
	void Set_Elemento(const int& f, const int& c, const Casilla& p){
		m[f][c]=p;
	}
};
#endif
