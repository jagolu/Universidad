#include <iostream>

using namespace std;

int main(){
	const int max=100;
	int vector[max];
	int n, total=0, indice;
	
	do{
		cout<<"Introduzca un termino del vector (Terminador==0): ";
		cin>>n;
		if(n!=0){
			vector[total]=n;
			total++;
		}
	}while(n!=0);
	cout<<"Introduzca el indice en que quiere insertar el nuevo numero: ";
	cin>>indice;
	if(indice>=total){
		cout<<"Ese indice no existe\n";
	}
	else{
		cout<<"Introduzca el entero que quiere introducir en el vector: ";
		cin>>n;
		for(int i=total-1;i>=indice;i--){
			int a;
			a=vector[i];
			vector[i+1]=a;
		}
		vector[indice]=n;
		cout<<endl;
		for(int i=0;i<total;i++){
			cout<<vector[i]<<" ";
		}
		cout<<endl;
	}
	system("pause");
}
