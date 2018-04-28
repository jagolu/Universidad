#include <iostream>

using namespace std;

int main(){
	int x, y, exponencial;
	cout<<"Introduzca la base: ";
	cin>>x;
	do{
		cout<<"Introduzca el exponente: "; //Se pone esto, para que solo te lo pida entre 0 e infinito
		cin>>y;                           // y el do while hace que te pida el exponente hasta que te de un numero entre 0 e infinto
	}while(y<0);
	if(y==0){  //Cualquier num elevado a 0, es 1, y eso solo se puede hacer asignandolo a parte
		exponencial=1;
	}
	else{
		exponencial=x;
		for(int i=2;i<=y;i++){ 
			exponencial=exponencial*x;
		}
	}
	cout<<exponencial<<endl;
}
