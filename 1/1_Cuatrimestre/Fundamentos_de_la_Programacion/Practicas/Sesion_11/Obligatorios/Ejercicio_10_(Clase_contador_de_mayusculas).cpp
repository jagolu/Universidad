/*Sobre el ejercicio 9, cread una clase específica ContadorMayusculas que implemente
los métodos necesarios para llevar el contador de las mayúsculas. Lo que se
pretende es que la clase proporcione los métodos siguientes:
void IncrementaConteo (char mayuscula)
int CuantasHay (char mayuscula)
Modificad el programa principal para que cree un objeto de esta clase y llame a sus
métodos para realizar los conteos de las mayúsculas. Finalmente, hay que imprimir en
pantalla cuántas veces aparece cada mayúscula.*/
#include <iostream>
#include <cmath>

using namespace std;

class ContadorMayusculas{
private:
	static const int max=26;
	int vector_mayusculas[max];
	int contador_mayusculas;
public:
	ContadorMayusculas(){
		contador_mayusculas=0;
		for(int i=0;i<26;i++){
			vector_mayusculas[i]=0;
		}
	}
	int contadormayusculas(){
		return contador_mayusculas;
	}
	void IncrementoConteo(char mayuscula){
		if('A'<=mayuscula && mayuscula<='Z'){
			vector_mayusculas[mayuscula-'A']=vector_mayusculas[mayuscula-'A']+1;
			contador_mayusculas++;
		}
	}
	void LetraMayuscula(){
		int a, i;
		char b;
		for(i=0;i<26;i++){
			a=vector_mayusculas[i];
			if(a!=0){
				b=i+'A';
				cuantasHay(b);
				cout<<b<<"--> "<<cuantasHay(b);
				cout<<endl;
			}
		}
	}
	int cuantasHay(char mayuscula){
		return vector_mayusculas[mayuscula-'A'];
	}
};
int main(){
	ContadorMayusculas objeto;
	char caracter;
	
	do{
		cout<<"Introduzca caracteres: ";
		cin>>caracter;
		objeto.IncrementoConteo(caracter);
	}while(caracter!='.');
	cout<<"Ha escrito "<<objeto.contadormayusculas()<<" mayusculas \nLas mayusculas son: \n";
	objeto.LetraMayuscula();
	cout<<endl;
	system("pause");
}
