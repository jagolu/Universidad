/*Este es un programa que multiplica dos variables de tipo entero (chico1 y chico2)
		Necesita la altura de dos chicos (las dos variables de tipo entero)*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	float grande;
	float chico1, chico2;
	chico1=123456789;
	chico2=123456780;
	grande=chico1*chico2;
	cout<<grande <<endl;
	/*Hay un error de desbordamiento porque la multiplicacion de estos dos numeros no cabe en un long, y da un numero incoerente, una de las formas de que
	si de el resultado exacto es declarar las variables grande y chico1, chico2 como float*/
	system("pause");
}
