#include <iostream>
#include <list>

using namespace std;

class PilotosFI{
	private:
		string nombre;
		string apellido;
		int posicion;
		string escuderia;
		list<PilotosFI> pilotos;
	public:
		list<PilotosFI> getListaPilotos(){
			return pilotos;
		}
		string getNombre(){
			return nombre;
		}
		string getApellido(){
			return apellido;
		}
		int getPosicion(){
			return posicion;
		}
		string getEscuderia(){
			return escuderia;
		}
};
int main(){
	PilotosFI a;
	list<PilotosFI>::iterator i=a.getListaPilotos().begin();
	(*i).getPosicion();
}
