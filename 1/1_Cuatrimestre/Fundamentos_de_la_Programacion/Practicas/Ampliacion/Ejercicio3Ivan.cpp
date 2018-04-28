#include <iostream>

using namespace std;

int main(){
	const int max=100;
	int vector[max];
	int total=0, a;
	do{
		cout<<"Introduzca un dato (Terminador=0): ";
		cin>>a;
		if(a!=0){
			vector[total]=a;
			total++;
		}
	}while(a!=0);
	cout<<"VECTOR ORIGINAL: \n";
	for(int i=0;i<total;i++){
		cout<<vector[i]<<"  ";
	}
	cout<<endl;
	cout<<"VECTOR INVERTIDO: \n";
	for(int i=total-1;i>=0;i--){
		cout<<vector[i]<<"  ";
	}
	cout<<endl;
	system("pause");
}
