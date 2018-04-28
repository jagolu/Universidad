/*Se quiere construir una clase Nomina para realizar la funcionalidad descrita en el
ejercicio 12 de la relaci�n de problemas I sobre la n�mina del fabricante y dise�ador
(p�gina RP-I.5). Cread los siguientes programas (entregad un fichero por cada uno de
los apartados):
Supongamos que gestionamos las n�minas de varias sucursales de una empresa.
Queremos crear objetos de la clase Nomina que se adapten a las caracter�sticas
de cada sucursal:
 En cada sucursal hay un �nico dise�ador pero el n�mero de fabricantes es
distinto en cada sucursal. Por tanto, el n�mero de fabricantes habr� que especificarlo
en el constructor y posteriormente no podr� cambiarse.
 La forma de repartir el dinero es la siguiente: el dise�ador se lleva una parte
del total y el resto se reparte a partes iguales entre los fabricantes. En los
apartados anteriores, por ejemplo, la parte que se llevaba el dise�ador era
2/5 y el resto (3/5) se repart�a entre los tres fabricantes. La parte que el dise�ador
se lleva puede ser distinta entre las distintas sucursales (2/5, 1/6,
etc), pero no cambia nunca dentro de una misma sucursal. Por tanto, el porcentaje
de ganancia (2/5, 1/6, etc) habr� que especificarlo en el constructor
y posteriormente no podr� cambiarse.
 Las retenciones fiscales de los fabricantes y dise�ador son distintas. Adem�s,
se prev� que �stas puedan ir cambiando durante la ejecuci�n del programa.
Por lo tanto, no se incluir�n como par�metros en el constructor.
El programa leer� los siguientes datos desde un fichero externo:
 El n�mero de sucursales.
 Los siguientes valores por cada una de las sucursales:
� Ingresos totales a repartir
� N�mero de fabricantes
� Parte que se lleva el dise�ador
� Retenci�n fiscal del dise�ador
� Retenci�n fiscal de los fabricantes
Por ejemplo, el siguiente fichero indica que hay dos sucursales. La primera tiene
unos ingresos de 300 euros, 3 fabricantes, el dise�ador se lleva 1/6, la retenci�n
del dise�ador es del 20% y la de cada fabricante un 18 %. Los datos para la
segunda son 400 euros, 5 fabricantes, 1/4, 22% y 19 %.*/
#include <iostream>
#include <cmath>

using namespace std;

class nomina{
private:
	int ganancia;
	double retencion_fiscalDisen, retencion_fiscalFabric, partedisenador, partefabric;
	int numfabric;
public:
	nomina(int ganancia1, double retencion_fiscalDisen1, double retencion_fiscalFabric1, double partedisenador1, int numfabric1){
		ganancia=ganancia1;
		retencion_fiscalDisen=retencion_fiscalDisen1;
		retencion_fiscalFabric=retencion_fiscalFabric1;
		partedisenador=partedisenador1;
		partefabric=((1-partedisenador1)/numfabric1);
		numfabric=numfabric1;
	}
	double salariodisenador(){
		double salariodisen11;
		salariodisen11=(ganancia*partedisenador)-((ganancia*partedisenador)*(retencion_fiscalDisen/100));
		return salariodisen11;
	}
	double salariofabricante(){
		double salariofabric11;
		salariofabric11=(ganancia*partefabric)-((ganancia*partefabric)*(retencion_fiscalFabric/100));
		return salariofabric11;
	}
};

int main(){
	int gananciaA, numsucursales, numfabricA, i;
	double retencionfiscalDisenA, retencionfiscalFabricA, partdisenA;
	double sueldofinalDisen, sueldofinalFabric;
	
	
	do{
		cout<<"Introduzca el numero de sucursales: ";
		cin>>numsucursales;
	}while(numsucursales<=0);
	for(i=1;i<=numsucursales;i++){
		cout<<"Introduzca la ganancia total \nla retencion fiscal del disenador \nla retenion fiscal de cada uno de los fabricantes \nla parte que se lleva el disenador  \nel numero de fabricantes \nde la sucursal "<<i<<": "<<endl;
		cin>>gananciaA;
		cin>>retencionfiscalDisenA;
		cin>>retencionfiscalFabricA;
		cin>>partdisenA;
		cin>>numfabricA;
		nomina objeto(gananciaA, retencionfiscalDisenA, retencionfiscalFabricA, partdisenA, numfabricA);
		sueldofinalDisen=objeto.salariodisenador();
		sueldofinalFabric=objeto.salariofabricante();
		cout<<"En la sucursal "<<i<<endl;
		cout<<"Cada uno de los fabricantes gana: "<<sueldofinalFabric<<" euros \nEl diseniador cobra: "<<sueldofinalDisen<<endl;
	}
}
