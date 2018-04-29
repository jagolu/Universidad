/*Escribid un programa en C++ para que lea tres enteros desde teclado y nos diga si
están ordenados (da igual si es de forma ascendente o descendente) o no lo están.*/
#include <iostream>

using namespace std;

int main(){
	int num1, num2, num3;
	cout<<"Introduzca el primer numero entero: ";
	cin>>num1;
	cout<<"Introduzca el segundo numero entero: ";
	cin>>num2;
	cout<<"Introduzca el tercer numero entero: ";
	cin>>num3;
	
	if((num1<num2 && num2<num3) || (num1>num2 && num2>num3)){ /*Con este if damos la condicion de que esten ordenados creciente o drecrecientemente*/
		cout<<"Los numeros estan ordenados." <<endl;
	}
	else{ /*Aqui damos la condicion contraria (que no esten ordenados)*/
		cout<<"Los numeros no estan ordenados." <<endl;
	}
	system("pause");
}
