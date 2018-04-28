#ifndef _CAMPOMINAS_H_
#define _CAMPOMINAS_H_
#include "Tablero.h"
class CampoMinas{
private:
	Tablero m;
	int Bombas_Cercanas(const int& f, const int& c);
public:
	CampoMinas(const int& f, const int& c, const int& num_minas);
	int Get_Filas(){
		return m.Get_Filas();
	}
	int Get_Columnas(){
		return m.Get_Columnas();
	}

	bool Mina_explosionada();
	bool Victoria();
	bool Marcar(const int& f, const int& c);
	bool Abrir(const int& f, const int& c);
	void PrettyPrint();
	void Tablero_Final_Partida();
};
#endif

