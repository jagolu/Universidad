/*Modifiquemos el ejercicio 2 del capital y los intereses de la primera relaci�n. Supongamos
ahora que se quiere reinvertir todo el dinero obtenido (el original C m�s los
intereses producidos) en otro plazo fijo a un a�o. Y as�, sucesivamente. Construid un
programa para que lea el capital, el inter�s y un n�mero de a�os N, y calcule e imprima
todo el dinero obtenido durante cada uno de los N a�os, suponiendo que todo
lo ganado (incluido el capital original C) se reinvierte a plazo fijo durante el siguiente
a�o.*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double  capital, interes, anos, i, contador=0;
	
	cout<<"Introduzca su capital: ";
	cin>>capital;
	cout<<"Introduzca su interes: ";
	cin>>interes;
	cout<<"Introduzca el numero de anios: ";
	cin>>anos;
	
	while(contador<anos){ /*Este bucle hara el contador para mostrar el numero de a�os de menor a mayor al final*/
		contador=contador+1;
		for(i=1;i<=1;i=i+1){ /*Este for contara el capital para cada a�o, y se parara cuando el contador se detenga*/
			capital=capital+(capital*(interes/100));
		}
		cout<<"Para el ano "<<contador<<" = "<<capital<<" euros"<<endl;
	}
	
	system("pause");
}
