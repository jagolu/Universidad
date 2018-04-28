/*Realizar un programa que lea desde teclado un entero tope e imprima en pantalla todos
sus divisores propios. Para obtener los divisores, basta recorrer todos los enteros
menores que el valor introducido y comprobar si lo dividen. A continuación, mejorar el
ejercicio obligando al usuario a introducir un entero positivo, usando un filtro con un
bucle post test (do while).*/
#include <iostream>

using namespace std;

int main(){
	int tope, divisor;
	
	do{ 
	cout<<"Introduzca un numero positivo: ";
	cin>>tope;
	}while(tope<=0);{ /*Con este do while obligamos al usuario a introducir un numero positivo*/
		for(divisor=1;divisor<=tope;divisor=divisor+1){ /*Con este for hacemos que el divisor solo llegue hasta el tope, y vaya sumando +1 hasta llegar hasta el*/
			if(tope%divisor==0){ /*Con el if hacemos que el programa solo coja los numeros que dividen al tope*/
				cout<<divisor<<" ";
				cout<<"\n";
			}
		}
	}

	system("pause");
}
		
