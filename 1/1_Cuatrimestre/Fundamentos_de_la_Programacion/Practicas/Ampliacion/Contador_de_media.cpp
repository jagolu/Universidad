#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int contador=0;
	int numeros;
	int contador_numeros=0;
	double media;
	
	cout<<"Introduce un numero: ";
	cin>>numeros;
	
	while(numeros!=0){
		contador_numeros=numeros+numeros;
		contador=contador+1;
		cout<<"Introduce otro numero: ";
		cin>>numeros;
	}
	media=contador_numeros/contador;
	cout<<"La media es: " <<media <<endl;
	system("pause");
}
