#include <iostream>
#include <cmath>

using namespace std;

int main(){
	const int TAM=100;
	int V[TAM];
	int total=0;
	int a, i=0, c;
	do{
		cout<<"Introduzca un numero (TERMINADOR=0): ";
		cin>>a;
		if(a!=0){
			V[i]=a;
			i++;
			total++;
		}
	}while(a!=0 || total<2);
	cout<<"APARTADO A\n";
	c=V[0];
	for(i=1;i<total;i++){
		int b;
		b=V[i];
		if(c<b){
			c=b;
		}
	}
	cout<<"El maximo valor es: "<<c<<endl;
	cout<<"APARTADOR B\n";
	c=V[0];
	for(i=1;i<total;i++){
		int b=V[i];
		if(c>b){
			c=b;
		}
	}
	cout<<"El minimo valor es: "<<c<<endl;
	cout<<"APARTADO C\n";
	int contador=0;
	for(i=0;i<total;i++){
		int b;
		b=V[i];
		contador=contador+b;
	}
	cout<<"La media es: "<<contador/total<<endl;
	cout<<"APARTADO D\n";
	cout<<"Que valor desea contar? : ";
	cin>>a;
	contador=0;
	for(i=0;i<total;i++){
		int b;
		b=V[i];
		if(b==a){
			contador++;
		}
	}
	if(contador==0){
		cout<<a<<" no aparece ninguna vez\n";
	}
	else{
		if(contador==1){
			cout<<a<<" aparece una vez\n";
		}
		else{
			cout<<a<<" aparece "<<contador<<" veces\n";
		}
	}
	cout<<"APARTADO E\n";
	contador=0;
	const int max=100;
	int vector[max];
	int total1=0;
	vector[0]=V[0];
	c=0;
	for(i=1;i<total;i++){
		int b;
		b=V[i];
		for(int k=0;k<=total1;k++){
			int d;
			d=vector[k];
			if(d==b){
				c=1;
			}
		}
		if(c==0){
			total1++;
			vector[total1]=b;
		}
		c=0;
	}
	cout<<"Hay "<<total1<<" elementos diferentes, que son: \n";
	for(i=0;i<=total1;i++){
		cout<<vector[i]<<"  ";
	}
	cout<<"\nAPARTADO F\n";
	c=0;
	int d;
	int no_ordenada=0;
	d=V[0];
	for(i=1;i<total;i++){
		int b;
		b=V[i];
		if(d>b){
			d=b;
		}
		if(d<b){
			c=1;
		}
	}
	if(c==0){
		cout<<"La secuencia esta ordenada de mayor a menor\n";
	}
	else{
		no_ordenada=1;
	}
	d=V[0];
	if(c==1){
		c=0;
		for(i=1;i<total;i++){
			int b;
			b=V[i];
			if(d<b){
				d=b;
			}
			if(d>b){
				c=1;
			}
		}
	
		if(c==0){
			cout<<"La secuencia esta ordenada de menor a mayor\n";
			no_ordenada=0;
		}
		else{
			no_ordenada=1;
		}
	}
	if(no_ordenada==1){
		cout<<"La secuencia no esta ordenada\n";
	}
	
	cout<<"APARTADO G\n";
	c=0;
	d=V[0];
	for(i=0;i<total;i++){
		int b;
		b=V[i];
		if(d>b){
			d=b;
			c=i;
		}
	}
	cout<<"El minimo se encuentra en la posicion "<<c<<endl;
	c=0;
	d=V[0];
	for(i=0;i<total;i++){
		int b;
		b=V[i];
		if(d<b){
			d=b;
			c=i;
		}
	}
	cout<<"El maximo se encuentra en la posicion "<<c<<endl;
	system("pause");
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
