#include <iostream>
#include <cmath>

using namespace std;


int SumaHasta(int a1, int r, int k){
	int ai, sumatorio=0;
	for(int i=1;i<=k;i++){
		ai=a1*pow(r,(i-1));
		sumatorio=sumatorio+ai;
	}
	return sumatorio;
}

int main(){
	int a1, r, k, sumahasta1;
	
	cout<<"Introduzca a1: ";
	cin>>a1;
	cout<<"Introduzca r: ";
	cin>>r;
	cout<<"Introduzca k: ";
	cin>>k;
	
	sumahasta1=SumaHasta( a1, r, k);
	cout<<"El sumatorio es: "<<sumahasta1<<endl;
	system("pause");
}
