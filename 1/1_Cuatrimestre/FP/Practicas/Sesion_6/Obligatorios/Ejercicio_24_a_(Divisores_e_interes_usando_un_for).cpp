/*Reescribid la solución a los ejercicios 12 (divisores) y 15 (interés) usando un bucle for*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int numero, i;
	double resto;
	
	do{ /*Aqui obligaremos al usuario a que introduzca un dato mayor que 0*/
		cout<<"Introduzca un numero entero positivo: ";
		cin>>numero;
	}while(numero<=0);{
		cout<<"Los divisores de "<<numero<<" son:"<<endl;
		for(i=1;i<=numero;i=i+1){ /*Aqui ira dividiento el numero por todos los numeros positivos desde el uno hasta nuestro numero*/
			resto=numero%i;
			if(resto==0){ /*Aqui solo cogera los numeros que lo dividen enteramente*/
				cout<<i<<endl;
			}
		}
	}
	cout<<"\n\n";
	system("pause");
}
