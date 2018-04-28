/*Sobre la solución del ejercicio 15 de esta relación de problemas, se pide lo siguiente.
Supondremos que sólo pueden introducirse intereses enteros (1, 2, 3, etc). Se pide
calcular el capital obtenido al término de cada año, pero realizando los cálculos para
todos los tipos de interés enteros menores o iguales que el introducido (en pasos de
1).*/
#include <iostream>

using namespace std;

int main(){
	double capital, interes, ano, i, j, capital2;
	
	cout<<"Introduzca el valor del capital: ";
	cin>>capital;
	cout<<"Introduzca el valor del interes (entero): ";
	cin>>interes;
	cout<<"Introduzca el numero de anios: ";
	cin>>ano;
	
	capital2=capital; /*Aqui guardamos el capital inicial en otra variable*/
	
	for(i=1;i<=interes;i=i+1){ /*Aqui realizara todos los valores desde el 1 al valor introducido de interes*/
		cout<<"Calculos realizados para el "<<i<<" % :"<<endl;
		capital=capital2; /*Antes de entrar en el segundo for, el capital siempre valdra el capital inicial*/
		for(j=1;j<=ano;j=j+1){/*Calculamos el capital para los anios y el interes*/
			capital=capital+(capital*(i/100));
			cout<<"Total en el anio numero "<<j<<" = "<<capital<<endl;
		}
	}
	system("pause");
}
