#ifndef _CAMPOMINAS_H_
#define _CAMPOMINAS_H_
#include "Tablero.h"
class CampoMinas{
private:
	Tablero m;
	int Bombas_Cercanas(const int& f, const int& c);
	bool Explosion;
public:
	CampoMinas(const int& f, const int& c, const int& num_minas);
	int Get_Filas()const{
		return m.Get_Filas();
	}
	int Get_Columnas()const{
		return m.Get_Columnas();
	}

	bool Mina_explosionada();
	bool Victoria();
	bool Marcar(const int& f, const int& c);
	bool Abrir(const int& f, const int& c);
	void PrettyPrint(std::ostream& os);
	void Tablero_Final_Partida();
	bool Escribir(std::ostream& fs,Tablero& P);
	bool Leer(std::istream& fs, Tablero& P);
	bool Escribir(std::ostream& fs,CampoMinas& P);
	bool Leer(std::istream& fs,CampoMinas& P);
};
#endif

