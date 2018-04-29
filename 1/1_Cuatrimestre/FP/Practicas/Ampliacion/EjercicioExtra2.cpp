#include <iostream>
#include <cmath>

using namespace std;

int main(){
	const int max=100;
	int vector[max];
	int total=0, a, i=0;
	
	do{
		cout<<"Introduzca un numero (TERMINADOR=0): ";
		cin>>a;
		if(a!=0){
			vector[i]=a;
			i++;
			total++;
		}
	}while(a!=0 || total<2);
	int c=0;
	int d;
	int no_ordenada=0;
	d=vector[0];
	for(i=1;i<total;i++){
		int b;
		b=vector[i];
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
	d=vector[0];
	if(c==1){
		c=0;
		for(i=1;i<total;i++){
			int b;
			b=vector[i];
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
		cout<<"La secuencia no esta ordenada\nOrdenando...\n";
		for(int k=0;k<99999;k++){
			for(i=0;i<total-1;i++){
				int b;
				d=vector[i];
				b=vector[i+1];
				if(d>b){
					vector[i]=b;
					vector[i+1]=d;
					d=b;
				}
			}
		}
		
		for(i=0;i<total;i++){
			cout<<vector[i]<<"  ";
		}
		cout<<endl;
	}
	for(i=0;i<total;i++){
		if((vector[i]%2)==0){
			cout<<vector[i]<<" en la posicion "<<i<<" es par\n";
		}
		else{
			cout<<vector[i]<<" en la posicion "<<i<<" es impar\n";
		}
	}
	system("pause");
}

