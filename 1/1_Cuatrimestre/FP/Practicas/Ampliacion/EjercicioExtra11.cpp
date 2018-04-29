#include <iostream>

using namespace std;

int main(){
	int n, j1, j2, k1, k2, n2;
	
	cout<<"Introduzca n: ";
	cin>>n;
	
	cout<<endl<<"APARTADO A"<<endl<<endl;
	for(j1=1;j1<=n;j1++){
		for(k1=1;k1<=j1;k1++){
			cout<<"*";
		}
		cout<<endl;
	}
	
	cout<<endl<<"APARTADO B"<<endl<<endl;
	
	n2=n;
	
	for(j2=1;j2<=n;j2++){
		for(k2=1;k2<=n2;k2++){
			cout<<"*";
		}
		n2=n2-1;
		cout<<endl;
	}
	cout<<endl;
	system("pause");
}
