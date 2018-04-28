#include <iostream>

using namespace std;

int main(){
	int numero, contador_numeros=0, sumador_numeros=0;
	double media;
	
	do{
		cout<<"Introduzca un numero: ";
		cin>>numero;
		contador_numeros=contador_numeros+1;
		sumador_numeros=sumador_numeros+numero;
	}while(numero!=0);{
		
	
	media=sumador_numeros/contador_numeros;
	cout<<"Usted ha escrito "<<contador_numeros<<" numeros, la suma total de los numeros escritos es "<<sumador_numeros<<" y su media es "<<media<<endl;
	}
	system("pause");
}
