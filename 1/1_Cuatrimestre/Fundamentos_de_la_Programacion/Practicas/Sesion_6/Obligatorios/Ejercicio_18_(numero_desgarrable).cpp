/*Un número entero n se dice que es desgarrable (torn) si al dividirlo en dos partes
izda y dcha, el cuadrado de la suma de ambas partes es igual a n. Por ejemplo,
88209 es desgarrable ya que (88 + 209)2 = 88209. Cread un programa que lea un
entero n e indique si es o no desgarrable.*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n, n2, suma, longitud=1, exponente=0, sumando1;
	bool esDesgarrable;
	
	cout<<"Introduzca un numero: ";
	cin>>n;
	
	n2=n;
	
	while(n2/10!=0){ /*Con este while sacaremos el numero de cifras del numero*/
		n2/=10;
		longitud=longitud+1;
	}
	if(longitud<=1){ 
		cout<<"El numero no se puede dividir";
	}
	else{ /*Aqui haremos todas las combinaciones posibles*/
		for(int i=0;i<longitud;i=i+1){
			sumando1=n/pow(10,i);
			exponente=(int)pow(10,i);
			suma=sumando1+n%exponente;
			int n2=(int)pow(suma,2);
			if(n==n2){ /*Aqui cogera la opcion valida, si es que la tiene*/
				esDesgarrable=true;
			}
		}
	}
	if(esDesgarrable){
		cout<<"Es desgarrable"<<endl;
	}
	else{
		cout<<"No es desgarrable"<<endl;
	}
	system("pause");
}
