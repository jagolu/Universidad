#include <iostream>

using namespace std;

int main(){
	long long int n, n2, cifra, contador1=0, i, contador2=0, j=0, pi, par, impar, s, s2, dc;
	
	cout<<"Introduzca un numero: ";
	cin>>n;
	
	n2=n;
	
	for(i=1;i<=n;i=i*10){
		cifra=n2%10;
		n2=n2/10;
		j=j+1;
		pi=j%2;
		if(pi==1){
			contador1=contador1+cifra;
		}
		else{
			contador2=contador2+cifra;
		}
	}
	if(pi==0){
		par=contador1;
		impar=contador2;
	}
	else{
		par=contador2;
		impar=contador1;
	}
	s=par+3*impar;
	s2=((s+10)/10)*10;
	dc=s2-s;
	cout<<"s="<<par<<"+3*"<<impar<<endl;
	cout<<"par-->"<<par<<endl<<"impar-->"<<impar<<endl<<"s-->"<<s<<endl<<"s2-->"<<s2<<endl;
	if(dc==10){
		cout<<"El digito de control es 0"<<endl;
	}
	else{
		cout<<"El digito de control es: "<<dc<<endl;
	}
	system("pause");
}
