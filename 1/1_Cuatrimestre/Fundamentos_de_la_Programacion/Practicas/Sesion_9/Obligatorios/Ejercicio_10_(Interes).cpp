/*ciendo
la funcionalidad descrita en los ejercicios 15 (reinvierte capital e interés un
número de años) y 16 (reinvierte capital e interés hasta obtener el doble de la cantidad
inicial) de la relación de problemas II (página RP-II.7). Por tanto, la clase debe
proporcionar, para un capital y unos intereses dados, métodos para:
a) Calcular el capital que se obtendrá al cabo de un número de años,
b) Calcular el número de años que deben pasar hasta obtener el doble de la cantidad
inicial.
A la hora de diseñar la clase, tendremos que analizar cuestiones como:
 ¿Cuáles son sus datos miembro? Parece claro que el capital y el interés sí lo
serán ya que cualquier operación que se nos ocurra hacer con un objeto de la
clase DepositoSimulacion involucra a ambas cantidades. ¿Pero y el número
de años?
 ¿Qué constructor definimos?
 ¿Queremos modificar el capital y el interés una vez creado el objeto?
 ¿Queremos poder modificarlos de forma independiente?
 ¿Hay alguna restricción a la hora de asignar un valor al capital e interés?
 ¿Es mejor un método para calcular el número de años hasta obtener el doble de
la cantidad inicial, o por el contrario es mejor un método para calcular el número
de años hasta obtener una cantidad específica?*/
#include <iostream>
#include <cmath>

using namespace std;

class DepositoSimulacion{
private:
	double capital, interes;
	int ano;
	
public:
	DepositoSimulacion(double capital1, double interes1, int ano1){
		capital=capital1;
		interes=interes1;
		ano=ano1;
	}
	double Reinvertido_ano(){
		double total1;
		total1=capital;
		for(int i;i<ano;i++){
			total1=total1+(total1*(interes/100));
		}
		return total1;
	}
	double ano_capitalDoble(){
		int j;
		double dobleA, total2A;
		dobleA=capital*2;
		total2A=capital;
		total2A=total2A+(total2A*(interes/100));
		for(j=1;total2A<=dobleA;j++){
			total2A=total2A+(total2A*(interes/100));
		}
		return j;
	}
	double getAno_capitalDoble(){
		int k;
		double dobleB, total2B;
		dobleB=capital*2;
		total2B=capital;
		for(k=1;total2B<=dobleB;k++){
			total2B=total2B+(total2B*(interes/100));
		}
		return total2B;
	}
	int getAno(){
		return ano;
	}
	double getCapital(){
		return capital;
	}
	double getInteres(){
		return interes;
	}
};

int main(){
	double capital, interes;
	int ano;
	double reinvertido, dobladoanos;
	
	cout<<"Introduzca su capital inicial, el interes y el numero de anios: "<<endl;
	cin>>capital;
	cin>>interes;
	cin>>ano;
	
	DepositoSimulacion Deposito(capital, interes, ano);
	reinvertido=Deposito.Reinvertido_ano();
	dobladoanos=Deposito.ano_capitalDoble();
	
	cout<<"Para su capital inicial ( "<<Deposito.getCapital()<<" euros ) y su interes fijo ( "<<Deposito.getInteres()<<" % )."<<endl;
	cout<<"En "<<Deposito.getAno()<<" anio/s, su capital sera: "<<reinvertido<<" euros"<<endl;
	cout<<"En "<<Deposito.ano_capitalDoble()<<" anio/s habra doblado su capital con "<<Deposito.getAno_capitalDoble()<<" euros"<<endl;
	system("pause");
}
	

