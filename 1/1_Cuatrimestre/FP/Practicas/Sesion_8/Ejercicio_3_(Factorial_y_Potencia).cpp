#include <iostream>

using namespace std;

int potencial(int base, int exponente){
	int base2=base;
	int resultado1;
	for(int i=2;i<=exponente;i++){
		base=base*base2;
	}
	if(exponente==0){
		resultado1=1;
	}
	else{
		resultado1=base;
	}
	return resultado1;
}
int exponencial(int numeroexp){
	int resultado;
	int resultado2;
	int j1=1;
	for(int j=1;j<=numeroexp;j++){
		j1=j1*j;
		resultado=j1;
	}
	if(numeroexp==0){
		resultado2=1;
	}
	else{
		resultado2=resultado;
	}
	return resultado2;
}
int main(){
	int basea, exponentea, exponenciala;
	
	cout<<"Introduzca una base: ";
	cin>>basea;
	cout<<"Introduzca un exponente: ";
	cin>>exponentea;
	
	cout<<"La base "<<basea<<" elevada al exponente "<<exponentea<<" es: "<<potencial(basea, exponentea)<<endl;
	cout<<"Introduzca un numero para hacer el exponencial: ";
	cin>>exponenciala;
	
	cout<<"El exponencial de "<<exponenciala<<" es: "<<exponencial(exponenciala)<<endl;
	system("pause");
}
