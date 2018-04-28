#include <iostream>

using namespace std;

int main(){
	const int max=20;
	int vector[max];
	int total=0, a;
	
	do{
		cout<<"Introduzca un numero positivo (terminador=0): ";
		cin>>a;
		if(a!=0 && a>0){
			vector[total]=a;
			total++;
		}
	}while(a!=0);
	for(int i=0;i<total;i++){
		cout<<vector[i]<<"  ";
	}cout<<endl;
	cout<<"NUEVO VECTOR: \n";
	const int max1=100;
	int vector1[max1];
	int total1=0;
	vector1[0]=vector[0];
	int c=0;
	for(int i=1;i<total;i++){
		int b;
		b=vector[i];
		for(int k=i+1;k<=total;k++){
			int d;
			d=vector[k];
			if(d==b){
				c=1;
			}
		}
		if(c==1){
			total1++;
			vector1[total1]=b;
		}
		c=0;
	}
	int contador=0;
	for(int i=0;i<total;i++){
		int b, d;
		b=vector[i];
		for(int k=0;k<=total1;k++){
			d=vector1[k];
			if(b==d){
				c=1;
			}
		}
		if(c==1){
			vector[i]=-1;
			contador++;
		}
		c=0;
	}
	cout<<"\nCambios realizados: "<<contador<<endl;
	cout<<endl;
	for(int i=0;i<total;i++){
		cout<<vector[i]<<"  ";
	}
	cout<<endl;
}
