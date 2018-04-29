/*Este es un programa que a partir de dos alturas y que luego devuelve su multiplicacion
		Necesita: las dos alturas (chico1, chico2)*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int chico, chico1, chico2;
	chico1 = 123456789;
	chico2 = 123456780;
	chico = chico1*chico2;
	cout<<chico <<endl;
	/*Hay un problema de desbordamiento ya que al multiplicar dos variables enteras y enviarlo a otra variable entera, esta multiplicacion no cable en un int*/

	system("pause");
}
