#include <iostream>
using namespace std;
int main(){
	bool correcto=false;
	int num_adivinar;
	int n;
	char a;
	do{
		cout<<"Introduzca el numero que quiere que se adivine: ";
		cin>>num_adivinar;
		do{
			cout<<"Introduzca un numero: ";
			cin>>n;
			if(n<num_adivinar){
				cout<<"El numero es menor\n";
			}
			if(n>num_adivinar){
				cout<<"EL numero es mayor\n";
			}
			if(n==num_adivinar){
				correcto=true;
			}
		}while(correcto==false);
		cout<<"Ha acertado el numero\n";
		cout<<"Jugar mas? (s/n): ";
		cin>>a;
	}while(a!='n');
	system("pause");
}
