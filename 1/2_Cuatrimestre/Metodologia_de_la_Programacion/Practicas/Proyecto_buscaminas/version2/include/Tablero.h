#ifndef _TABLERO_H_
#define _TABLERO_H_
struct Casilla{
	bool Bomba;
	bool Abierta;
	bool Marcada;
};

class Tablero{
private:
	Casilla *m;
	int filas, columnas;
public:
	Tablero(const int& f, const int& c);
	Tablero(const Tablero& t);
	~Tablero();
	Tablero& operator=(const Tablero& t);
	void operator()(Casilla& c1, const Casilla& c2);
	Casilla& operator()(const int& f, const int& c)const;
	int Get_Filas()const;
	int Get_Columnas()const;
	Casilla& Get_Elemento(const int& f, const int& c)const;
	void Set_Elemento(const int& f, const int& c, const Casilla& p);
	bool Escribir(std::ostream& fs, const Casilla& C);
	bool Leer(std::istream& fs, Casilla& C);
};
#endif
