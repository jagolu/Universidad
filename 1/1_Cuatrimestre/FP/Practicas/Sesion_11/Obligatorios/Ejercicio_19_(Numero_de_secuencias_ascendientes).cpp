/*Defina la clase SecuenciaEnteros análoga
a SecuenciaCaracteres. Defina lo que sea necesario para calcular el número
de secuencias ascendientes del vector. Por ejemplo, el vector {2,4,1,1,7,2,1}
tiene 4 secuencias que son {2,4}, {1,1,7}, {2}, {1}.*/
#include <iostream>
#include <cmath>

using namespace std;

class SecuenciaEnteros{
private:
	static const int max=50;
	int vector[max];
	int total_utilizados;
public:
	SecuenciaEnteros(){
		total_utilizados=0;
	}
	void anide(int numero){
		if(numero!=0){
			vector[total_utilizados]=numero;
			total_utilizados++;
		}
	}
	void mostrar_elementos(){
		for(int i=0;i<total_utilizados;i++){
			cout<<vector[i]<<"  ";
		}
	}
	void mostrar_secuencia(){
		int a, b, i;
		for(i=0;i<total_utilizados;i++){
			a=vector[i];
			b=vector[i+1];
			if(a<=b){
				cout<<a<<"  ";
			}
			else{
				cout<<a<<endl;
			}
		}
	}
};
int main(){
	SecuenciaEnteros objeto;
	int a;
	
	do{
		cout<<"Introduzca un dato (terminador=0): ";
		cin>>a;
		objeto.anide(a);
	}while(a!=0);
	objeto.mostrar_elementos();
	cout<<"\nMostrando sub secuencias:\n";
	objeto.mostrar_secuencia();
		
	
	system("pause");
}
