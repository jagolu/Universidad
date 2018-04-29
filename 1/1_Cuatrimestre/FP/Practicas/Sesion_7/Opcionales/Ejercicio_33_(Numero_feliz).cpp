#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n, n2, n3=0, i, cifra, m=0;
	
	cout<<"Introduzca un numero entero: ";
	cin>>n;
	
	do{
		n2=n;
		n3=0;
		for(i=1;i<=n;i=i*10){
			cifra=n2%10;
			n2=n2/10;
			n3=n3+(pow(cifra,2));
		}
		if(n3>=10){
			n=n3;
		}
		else if(n2==0){
			n=1;
		}
		m=m+1;
	}while(n>=10);
		if((n3==1 || n3==7) && m>=3){
			cout<<"El numero es feliz. De grado: "<<m<<endl;
		}
		else{
			cout<<"El numero es infeliz"<<endl;
		}
	system("pause");
}
