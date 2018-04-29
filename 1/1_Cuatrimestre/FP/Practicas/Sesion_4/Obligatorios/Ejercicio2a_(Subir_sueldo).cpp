/*Cread un programa que lea el valor de la edad (dato de tipo entero) y salario (dato de
tipo real) de una persona. Subid el salario un 5% si éste es menor de 300 euros y la
persona es mayor de 65 años. Imprimid el resultado por pantalla. En caso contrario
imprimid el mensaje "No es aplicable la subida". En ambos casos imprimid
el salario resultante.*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int edad;
	double salario, nuevo;
	cout<<"Introduzca su edad: ";
	cin>>edad;
	cout<<"Introduzca su salario: ";
	cin>>salario;

	if(edad>65 && salario<300){  /*Con este if calculamos el nuevo salario para la condicion dada*/
		nuevo=salario*1.05;
		cout<<"Su nuevo salario es: " <<nuevo <<endl;
	}
	else { /*Con este else damos el caso contrario al if*/
		cout<<"No es aplicable la subida. Su salario es: " <<salario <<endl;
	}
	system("pause");
}
			
