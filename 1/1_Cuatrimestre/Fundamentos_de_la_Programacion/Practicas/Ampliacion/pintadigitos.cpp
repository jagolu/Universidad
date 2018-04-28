#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n, i, contador=0, j, cifra, pot;
	
	cout<<"Introduzca un numero n: ";
	cin>>n;
	
	for(i=1;i<=n;i=i*10){
		contador=contador+1;
	}
	for(j=contador-1;j>=0;j=j-1){
		pot=pow(10,j);
		cifra=(n/pot);
		cout<<cifra%10<<endl;
	}
	system("pause");
}
