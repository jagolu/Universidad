/*Sobre el mismo ejercicio del capital y los intereses, construid un programa para calcular
cuántos años han de pasar hasta llegar a doblar, como mínimo, el capital inicial.
Los datos que han de leerse desde teclado son el capital inicial y el interés anual.*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double  capital, interes, i, contador=0, capital2;

	cout<<"Introduzca su capital: ";
	cin>>capital;
	cout<<"Introduzca su interes: ";
	cin>>interes;
	
	capital2=capital; /*Aqui guardaremos el capital inicial en otra variable para usarlo mas tarde*/
	while(capital2<=capital*2){ /*El bucle se repetira hasta que el nuevo capital valga el doble que el capital inicial*/
		contador=contador+1;
		for(i=1;i<=1;i=i+1){ /*Aqui calcularemos el capital por año*/
			capital2=capital2+(capital2*(interes/100));
		}
	}
	cout<<"Dentro de "<<contador<<" anios, habra doblado su capital con "<<capital2<<" euros"<<endl;
	
	system("pause");
}
