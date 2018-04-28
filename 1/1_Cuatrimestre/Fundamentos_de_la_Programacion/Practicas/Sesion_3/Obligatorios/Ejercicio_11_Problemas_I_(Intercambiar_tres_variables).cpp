/*Este es un programa que intercambia 3 variables dandole a la ultima variable el valor de la segunda, a la segunda el valor de la primera y a la primera el valor de la ultima
		Necesita:
			El valor de la primera variable (x=10)
			El valor de la segunda variable (y=20)
			El valor de la tercera variable (z=30)*/
#include <iostream>

using namespace std;

int main(){
	int x=10, y=20, z=30, aux;
		cout<<"El valor de la variable X es: " <<x <<endl;
		cout<<"El valor de la variable Y es: " <<y <<endl;
		cout<<"El valor de la variable Z es: " <<z <<endl;
		
		/*X=Valor de z
			Y=Valor de x
			Z=Valor de y*/
	
		aux=x;
		x=z;
		z=y;
		y=aux;
		/*Primero declaramos una variable auxiliar dandole el valor de x, despues el valor de la x se lo cambiamos al de z,
		despues el valor de z se lo cambiamos por el de y, y el de y lo cambiamos por el de aux(que es el valor de la auxiliar
		Es importante en mantener un orden para que intercambie los valores correctamente*/
		
		cout<<"X= " <<x <<endl;
		cout<<"Y= " <<y <<endl;
		cout<<"Z= " <<z <<endl;
		system("pause");
		
}
