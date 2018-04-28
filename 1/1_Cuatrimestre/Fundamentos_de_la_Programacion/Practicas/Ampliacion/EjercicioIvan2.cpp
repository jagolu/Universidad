#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double e, sumatorio2=0, sumatorio1=0;
	double i=1, absoluto;
	cout<<"Introduce epsilon: ";
	cin>>e;
	
	do{
		for(int j=1;j<=i;j++){
			int exp=j+1;
			sumatorio1=sumatorio1+((pow(-1,exp))/j);
		}
		for(int j=1;j<=i+1;j++){
			int exp=j+1;
			sumatorio2=sumatorio2+((pow(-1,exp))/j);
		}
		absoluto=abs(sumatorio1-sumatorio2);
		i++;
	}while(absoluto>e);
	cout<<"El minimo m para que se cumpla la igualdad es: "<<i-1<<endl;
	system("pause");
}
	
