#include <iostream>
using namespace std;
int main(){
	const int max=4;
	int vector1[max];
	int vector2[max];
	int n;
	/*Para 4 valores fijos*/
	vector1[0]=3;
	vector1[1]=1;
	vector1[2]=5;
	vector1[3]=6;
	cout<<"Primer vector original:\n";
	for(int i=0;i<max;i++){
		cout<<vector1[i]<<" ";
	}
	cout<<endl<<"Primer vector ordenado de mayor a menor:\n";
	for(int i=0;i<max;i++){
		int a, b, indice=-1;
		a=vector1[i];
		b=vector1[i+1];
		for(int j=i+1;j<max;j++){
			if(a<=vector1[j] && b<=vector1[j]){
				indice=j;
				b=vector1[j];
			}
		}
		if(indice!=-1){
			a=vector1[i];
			b=vector1[indice];
			vector1[i]=b;
			vector1[indice]=a;
		}
	}
	for(int i=0;i<max;i++){
		cout<<vector1[i]<<" ";
	}
	/*Para 4 valores a eleccion del usuario*/
	cout<<endl<<"Introduzca 4 datos del segundo vector:\n";
	
	for(int i=0;i<max;i++){
		cout<<i+1<<": ";
		cin>>n;
		vector2[i]=n;
	}
	cout<<"\nVector 2 original:\n";
	for(int i=0;i<max;i++){
		cout<<vector2[i]<<" ";
	}
	cout<<"\nVector 2 ordenado de mayor a menor:\n";
	for(int i=0;i<max;i++){
		int a, b, indice=-1;
		a=vector2[i];
		b=vector2[i+1];
		for(int j=i+1;j<max;j++){
			if(a<=vector2[j] && b<=vector2[j]){
				indice=j;
				b=vector2[j];
			}
		}
		if(indice!=-1){
			a=vector2[i];
			b=vector2[indice];
			vector2[i]=b;
			vector2[indice]=a;
		}
	}
	cout<<endl;
	for(int i=0;i<max;i++){
		cout<<vector2[i]<<" ";
	}
	cout<<endl;
	system("pause");
}
