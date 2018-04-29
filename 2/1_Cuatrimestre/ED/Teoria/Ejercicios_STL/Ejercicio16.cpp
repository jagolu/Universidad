#include <iostream>
#include <queue>

using namespace std;

class Hospital{
	private:
		string nombre;
		string apellidos;
		string dni;
		string gravedad;
		queue<Hospital>cola;
	public:
		queue<Hospital> getCola(){
			return cola;
		}
		string getNombre(){
			return nombre;
		}
		string getApellidos(){
			return apellidos;
		}
		string getDni(){
			return dni;
		}
		string getGravedad(){
			return gravedad;
		}
		void nuevoCliente(string n, string a, string d, string g){
			Hospital h;
			h.apellidos=a;
			h.dni=d;
			h.nombre=n;
			h.gravedad=g;
			cola.push(h);
		}
		void eliminarCliente(string n, string a, string d, string g){
			cola.pop();
		}
};
