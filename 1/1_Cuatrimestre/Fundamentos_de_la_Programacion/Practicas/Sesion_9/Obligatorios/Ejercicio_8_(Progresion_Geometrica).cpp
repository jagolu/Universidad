/*En el ejercicio 4 de esta relación de problemas se definieron varias funciones para
operar sobre una progresión geométrica. Definid ahora una clase para representar
una progresión geométrica.
a) Diseñad la clase pensando cuáles serían los datos miembro esenciales que definen
una progresión geométrica, así como el constructor de la clase.
b) Definir un método Termino que devuelva el término k-ésimo.
c) Definid los métodos SumaHastaInfinito, SumaHasta, MultiplicaHasta.
d) Cread un programa principal que lea los datos miembro de una progresión, cree el
objeto correspondiente y a continuación lea un entero tope e imprima los tope
primeros términos de la progresión, así como la suma hasta tope de dichos
términos.*/
#include <iostream>
#include <cmath>

using namespace std;

class progresion{
private:
	double a1, r, k;
			 
public:
	progresion(double aa1, double rr, double kk){
		a1=aa1;
		r=rr;
		k=kk;
		
	}
	double termino(){
		 double ultimo_termino;
		 ultimo_termino=a1*pow(r,(k-1));
		 return ultimo_termino;
	}
	double suma_infinito(){
	double ai, sumatorio=0;
	for(int i;i<=999999;i++){
		ai=a1/(1-r);
		sumatorio=sumatorio+ai;
	}
	return sumatorio;
}
	double producto_hasta_forma1(){
		double j, producto=1, termino2;
		for(j=1;j<=k;j++){
			termino2=a1*pow(r,j);
			producto=producto*termino2;
		}
		return producto;
	}
	double producto_hasta_forma2(){
		long double producto2, interior, interior2;
		interior=((a1*r)*(a1*(pow(r,k))));
		interior2=pow(interior,k);
		producto2=sqrt(interior2);
		return producto2;
	}
	double suma_hasta(){
		double ii, sumahasta=0, termino3;
		termino3=a1*((pow(r,k)-1)/(r-1));
		for(ii=1;ii<=k;ii++){
			sumahasta=sumahasta+termino3;
		}
		return sumahasta;
	}
};
int main(){
	double datoa1, dator, datok;
	double termino, sumainfinito, producto1, producto2, sumahasta;
	
	cout<<"Introduzca el termino a1, r y k: "<<endl;
	cin>>datoa1;
	cin>>dator;
	cin>>datok;
	progresion progresion1(datoa1, dator, datok);
	termino=progresion1.termino();
	cout<<"El termino k-esimo es: "<<termino<<endl<<endl;;
	
	do{
		cout<<"Introduzca el termino a1, r y k (r debe estar entre 0 y 1): "<<endl;
		cin>>datoa1;
		cin>>dator;
		cin>>datok;
	}while(0>dator || 1<dator);
	progresion progresion2(datoa1, dator, datok);
	sumainfinito=progresion2.suma_infinito();
	cout<<"\"SumaHastaInfinito\" es: "<<sumainfinito<<endl<<endl;
	
	cout<<"Introduzca el termino a1, r y k: "<<endl;
	cin>>datoa1;
	cin>>dator;
	cin>>datok;
	progresion progresion3(datoa1, dator, datok);
	producto1=progresion3.producto_hasta_forma1();
	producto2=progresion3.producto_hasta_forma2();
	cout<<"\"MultiplicaHasta\" forma 1 es: "<<producto1<<endl;
	cout<<"\"MultiplicaHasta\" forma 2 es: "<<producto2<<endl<<endl;
	
	cout<<"Introduzca el termino a1, r y k: "<<endl;
	cin>>datoa1;
	cin>>dator;
	cin>>datok;
	progresion progresion4(datoa1, dator, datok);
	sumahasta=progresion4.suma_hasta();
	cout<<"\"SumaHasta\" es: "<<sumahasta<<endl;
	
	system("pause");
}
	
