/*Este es un programa multiplicara dos valores de tipo double y nos imprimira el resultado tambien en double
	Necesita los dos datos reales (real1 y real2)*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double resultado, real1, real2;
	real1 = 123.1;
	real2 = 124.2;
	resultado = real1 * real2;
	cout.precision(20); /*Con esto hago que la variable resultado tenga 20 digitos de precision*/
	cout<<resultado <<endl;
	/*Hay un problema de precision, porque al ejecutar el programa te da un numero (justo con sus 20 digitos), pero si le cambiamos la precision a 
	30 digitos, al ejecutarlo siguen saliendo digitos. Nunca daremos con el numero preciso, por tanto tenemos un problema de precision*/
	system("pause");
}
