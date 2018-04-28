#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n, i, k, n2, m, cifra;
	
	cout<<"Introduzca un numero: ";
	cin>>n;
	
	k=n;
	n2=0;
	m=0;
	do{
		for(i=1;i<=n;i=i*10){
			cifra=k%10;
			k=k/10;
			n2=n2+(pow(cifra,2));}
		n=n2;
		m=m+1;
	}while(n==1 || n==2);{
		if(n==1){
			cout<<"El numero es feliz de grado "<<m<<" :) "<<endl;
		}
		else{
			cout<<"El numero no es feliz :( "<<endl;
		}
	}
	system("pause");
}
