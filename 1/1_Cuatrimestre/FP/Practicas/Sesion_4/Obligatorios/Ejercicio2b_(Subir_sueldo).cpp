/*Realizad el mismo ejercicio pero subiendo el salario un 4% si es mayor de 65 o menor
de 35 años. Además, si también tiene un salario inferior a 300 euros, se le subirá otro
3%.*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int edad;
	double salario, Ssalario, Sedad, total, total1;
	cout<<"Introduzca su edad: ";
	cin>>edad;
	cout<<"Introduzca su salario: ";
	cin>>salario;
	
	if(edad>65 || edad<35){ /*Damos la primera condicion, para que tenga o mas de 65 o menos de 35 años*/
		Sedad=salario*0.04;
		total1=salario+Sedad;
			if(salario<300){ /*Con este if damos la primera subcondicion (sueldo inferior a 300 euros)*/
				Ssalario=salario*0.03;
				total=Sedad+Ssalario+salario;
				cout<<"Su nuevo salario es: " <<total <<"\n";
			}
			else{ /*Con este else damos la segunda subcondicion (sueldo superior a 300 euros)*/
				cout<<"Su nuevo salario es: " <<total1 <<"\n";
			}
	}
	else{ /*Con este else damos la condicion contraria al primer if (que la edad este entre 35 y 65 años)*/
		cout<<"No es aplicable la subida. Su salario es: " <<salario <<"\n";
	}
		system("pause");
	}
