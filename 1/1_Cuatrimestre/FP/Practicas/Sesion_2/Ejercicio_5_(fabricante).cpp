
/* Este programa que calcula a partir del valor de ganancia total de una empresa, lo que cobrara cada uno de los fabricantes y el dise�ador.
		Necesita: 
			La ganancia total de la empresa: ganancia.
		Calcula:
			Lo que gana cada uno de los fabriantes
				fabricantes=ganancia/5
			Lo que gana el dise�ador
				dise�ador=fabricantes*2  */
	

#include <iostream>
#include <cmath>

using namespace std;


int main() {
	double ganancia, disenador, fabricantes ;
	
	cout<<"Introduzca la ganancia total de la empresa: " ;
	cin>> ganancia;
	
	fabricantes=ganancia/5 ;
	disenador=fabricantes*2;
	
	cout<<"La parte que pertenece a cada fabricante es: "<<fabricantes <<endl ;
	cout<<"La parte que pertenece al dise�ador es: "<<disenador  <<endl;
	system("pause");
	
}
