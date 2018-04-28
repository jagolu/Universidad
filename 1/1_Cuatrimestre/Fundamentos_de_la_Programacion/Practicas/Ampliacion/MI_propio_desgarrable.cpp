#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n, i, n2, uno, dos, aa, a1=0;
	
	cout<<"Introduzca un numero: ";
	cin>>n;
	
	n2=n;
	
	for(i=1;i<=n;i=i*10){
		uno=n/i;
		dos=n%i;
		aa=pow((uno+dos),2);
		if(aa==n){
			a1=1;
		}
	}
	if(a1==1){
		cout<<"El numero es desgarrable"<<endl;
	}
	else{
		cout<<"El numero no es desgarrable"<<endl;
	}
	system("pause");
}
