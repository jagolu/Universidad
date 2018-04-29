#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n, m, i, cuenta=0, resto;
	
	cout<<"Introduzca el primer multiplicador: ";
	cin>>n;
	cout<<"Introduzca el segundo multiplicador: ";
	cin>>m;
	
	for(i=n;i>=1;i=i/2){
		resto=i%2;
		if(resto==1){
			cuenta=cuenta+m;
		}
		m=m*2;
	}
	cout<<"La multiplicacion es: "<<cuenta<<endl;
	system("pause");
}
