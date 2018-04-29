#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n, cifra, i, n2, j;
	
	cout<<"Introduzca un numero: ";
	cin>>n;
	
	n2=n;
	
	for(i=10;i<=n;i=i*10){
	}
	for(j=i;j>=1;j=j/10){
		n2=n/j;
		n=n%j;
		cout<<n2<<" ";
	}
	cout<<endl;
	system("pause");
}
