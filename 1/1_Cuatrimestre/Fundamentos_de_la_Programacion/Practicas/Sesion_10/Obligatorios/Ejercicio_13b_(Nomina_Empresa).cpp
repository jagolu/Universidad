/*Se quiere construir una clase Nomina para realizar la funcionalidad descrita en el
ejercicio 12 de la relación de problemas I sobre la nómina del fabricante y diseñador
(página RP-I.5). Cread los siguientes programas (entregad un fichero por cada uno de
los apartados):
Supongamos que se aplica una retención fiscal y que ésta es la misma para
los fabricantes y el diseñador. En el constructor se establecerá el porcentaje de
retención fiscal (de tipo double) y posteriormente no se permitirá que cambie, de 
forma que todas las operaciones que se hagan serán siempre usando la misma
retención fiscal. Los salarios netos se obtienen al aplicar la retención fiscal a los
salarios brutos (después de repartir los ingresos totales de la empresa):
salario_neto = salario_bruto -
salario_bruto * retencion_fiscal / 100.0
El programa leerá el valor de los ingresos totales y la retención fiscal a aplicar y
calculará los salarios brutos y netos de los fabricantes y diseñador, llamando a
los métodos oportunos de la clase Nomina.*/
#include <iostream>
#include <cmath>

using namespace std;

class nomina{
private:
	int ganancia;
	double retencion_fiscal;
public:
	double fabricantegana1, disenadorgana1;
	nomina(int ganancia1, double retencionfiscal){
		ganancia=ganancia1;
		retencion_fiscal=retencionfiscal;
	}
	double disenador_gana(){
		double disenadorGana;
		disenadorGana=(ganancia/5)*2;
		disenadorgana1=disenadorGana;
		return disenadorGana;
	}
	double disenadorRetencion(){
		double disenadorReten;
		disenadorReten=disenadorgana1-disenadorgana1*(retencion_fiscal/100.0);
		return disenadorReten;
	}
	double fabricanteGana(){
		double fabricantegana;
		fabricantegana=ganancia/5;
		fabricantegana1=fabricantegana;
		return fabricantegana;
	}
	double fabricanteRetencion(){
		double fabricanteReten;
		fabricanteReten=fabricantegana1-fabricantegana1*(retencion_fiscal/100.0);
		return fabricanteReten;
	}
};

int main(){
	int gananciaA, retencionfiscalA;
	double fabricantesA, disenadorA, fabricantesB, disenadorB;

	cout<<"Introduzca la ganancia total y la retencion fiscal: ";
	cin>>gananciaA;
	cin>>retencionfiscalA;
	nomina objeto(gananciaA, retencionfiscalA);
	fabricantesA=objeto.fabricanteGana();
	disenadorA=objeto.disenador_gana();
	fabricantesB=objeto.fabricanteRetencion();
	disenadorB=objeto.disenadorRetencion();
	
	cout<<"Cada uno de los fabricantes gana: "<<fabricantesA<<" euros \nEl diseniador cobra: "<<disenadorA<<endl;
	cout<<"CON LA RETENCION:\n"<<endl;
	cout<<"Cada uno de los fabricantes gana: "<<fabricantesB<<" euros \nEl diseniador cobra: "<<disenadorB<<endl;
}
