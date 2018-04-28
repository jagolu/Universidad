/*Se quiere construir una clase Nomina para realizar la funcionalidad descrita en el
ejercicio 12 de la relación de problemas I sobre la nómina del fabricante y diseñador
(página RP-I.5). Cread los siguientes programas (entregad un fichero por cada uno de
los apartados):
a) Suponed que sólo gestionamos la nómina de una empresa en la que hay un fabricante
y tres diseñadores. Los salarios brutos se obtienen al repartir los ingresos
de la empresa, de forma que el diseñador cobra el doble de cada fabricante.
El programa leerá el valor de los ingresos totales y calculará los salarios brutos
de los fabricantes y diseñador, llamando a los métodos oportunos de la clase
Nomina.*/
#include <iostream>
#include <cmath>

using namespace std;

class nomina{
private:
	int ganancia;
public:
	nomina(int ganancia1){
		ganancia=ganancia1;
	}
	double disenador_gana(){
		double disenadorGana;
		disenadorGana=(ganancia/5)*2;
		return disenadorGana;
	}
	double fabricanteGana(){
		double fabricantegana;
		fabricantegana=ganancia/5;
		return fabricantegana;
	}
};

int main(){
	int gananciaA;
	double fabricantesA, disenadorA;

	cout<<"Introduzca la ganancia total: ";
	cin>>gananciaA;
	nomina objeto(gananciaA);
	fabricantesA=objeto.fabricanteGana();
	disenadorA=objeto.disenador_gana();
	
	cout<<"Cada uno de los fabricantes gana: "<<fabricantesA<<" euros \nEl diseniador cobra: "<<disenadorA<<endl;
}
