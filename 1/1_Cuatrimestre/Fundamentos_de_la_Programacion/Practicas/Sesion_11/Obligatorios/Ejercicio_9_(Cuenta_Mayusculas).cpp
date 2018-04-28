/*En este ejercicio no hay que definir ninguna clase. Todas las operaciones se realizan
directamente en el main.
Realizad un programa que vaya leyendo caracteres hasta que se encuentre un punto
'.'. Contad el número de veces que aparece cada una de las letras mayúsculas e
imprimirlo en pantalla.*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	static const int max=26;
	int vector_mayusculas[max];
	char caracter;
	int contador_mayusculas=0;
	
	for(int i=0;i<26;i++){
		vector_mayusculas[i]=0;
	}
	
	do{
		cout<<"Introduzca caracteres: ";
		cin>>caracter;
	
		if('A'<=caracter && caracter<='Z'){
			vector_mayusculas[caracter-'A']=vector_mayusculas[caracter-'A']+1;
			contador_mayusculas++;
		}
	}while(caracter!='.');
	cout<<"Ha escrito "<<contador_mayusculas<<" mayusculas \nLas mayusculas son: \n";
	for(int i=0;i<26;i++){
		int a=vector_mayusculas[i];
		if(a!=0){
			char abc=i+'A';
			cout<<abc<<" ---> "<<a<<endl;
		}
	}
	cout<<endl;
	system("pause");
}
