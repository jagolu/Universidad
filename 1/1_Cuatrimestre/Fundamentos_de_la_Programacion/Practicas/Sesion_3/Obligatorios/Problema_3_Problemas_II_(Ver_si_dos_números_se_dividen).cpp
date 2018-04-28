/*Este programa a partir de dos variables enteros nos dira si son divisibles entre si
	Necesitara dos numeros (valor1, valor2)*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int valor1, valor2, resto1, resto2;
	
	cout<<"Introduce un valor entero que sea distinto de 0: ";
	cin>>valor1;
	cout<<"Introduce otro valor entero que sea disinto de 0: ";
	cin>>valor2;
	
	resto1=valor1%valor2;
	resto2=valor2%valor1;
	/*Aqui el algoritmo calcula el resto de dividir el primer numero entre el segundo y vicebersa*/
	if(resto1==0 || resto2==0)
	cout<<"Uno divide de forma entera al otro (Si son divisibles)." <<endl;
	else 
	cout<<"No se dividen de forma entera (No son divisbles)." <<endl;
	/*Aqui pondremos la condicion de que si el primer resto  o el segundo da 0 (que sea divisible) el programa imprimira que si son divisibles, en cambio
	si ninguno de los restos es 0, el programa imprimira que no son divisibles*/
	system ("pause");
	
}
