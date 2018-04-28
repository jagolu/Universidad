/*Se quiere construir una clase Nomina para realizar la funcionalidad descrita en el
ejercicio 12 de la relaci�n de problemas I sobre la n�mina del fabricante y dise�ador
(p�gina RP-I.5). Cread los siguientes programas (entregad un fichero por cada uno de
los apartados):
Supongamos que se aplica una retenci�n fiscal y que �sta es la misma para
los fabricantes y el dise�ador. En el constructor se establecer� el porcentaje de
retenci�n fiscal (de tipo double) y posteriormente no se permitir� que cambie, de 
forma que todas las operaciones que se hagan ser�n siempre usando la misma
retenci�n fiscal. Los salarios netos se obtienen al aplicar la retenci�n fiscal a los
salarios brutos (despu�s de repartir los ingresos totales de la empresa):
salario_neto = salario_bruto -
salario_bruto * retencion_fiscal / 100.0
El programa leer� el valor de los ingresos totales y la retenci�n fiscal a aplicar y
calcular� los salarios brutos y netos de los fabricantes y dise�ador, llamando a
los m�todos oportunos de la clase Nomina.*/
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
