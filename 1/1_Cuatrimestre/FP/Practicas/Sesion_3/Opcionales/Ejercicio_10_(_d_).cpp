/*Este programa multiplica dos reales (real1 y real2) y devuelve su resultado*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double resultado, real1, real2;
	real1=123456789.1;
	real2=123456789.2;
	resultado=real1*real2;
	cout.precision(10); /*Utilizo esto para darle al resultado una precision de 10 digitos*/
	cout<<resultado <<endl;
	/*Hay un problema de precision si con la funcion "cout.precision(numero_digitos)" y le ponemos menos de 17 digitos, a partir de los 17 si da el numero exacto*/
	system("pause");
}
