#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int num;
	bool es_primo;
	es_primo=true;
	
	cout<<"Introduzca el numero. ";
	cin>>num;
	
	for(int i=2;i<num;i++){
		double resto;
		resto=num%i;
		if(resto==0){
			es_primo=false;
		}
	}
	if(es_primo==true){
		cout<<"Si es primo\n";
	}
	else{
		cout<<"No es primo\n";
	}
}
