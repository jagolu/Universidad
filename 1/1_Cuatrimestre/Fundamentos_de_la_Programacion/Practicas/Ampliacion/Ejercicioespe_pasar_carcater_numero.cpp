#include <iostream>

using namespace std;

int main(){
	char a;
	int b;
	do{
		cout<<"Introduce un numero del 0 al 9: ";
		cin>>b;
	}while(0<b && b>9);
	a=b+'0';
	cout<<a<<endl;
}
