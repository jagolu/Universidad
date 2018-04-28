#include <iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char * argv[]){
	pair<float, float>a;
	a=(make_pair(atof(argv[1]),atof(argv[2])));
	list<pair<float, float> >coordenadas;
	float 
	n;
	do{
		cout<<"Coordenada 1: ";
		cin>>n;
		if(n!=0){
			pair<double, double> a;
			a.first=n;
			cout<<"Coordenada 2: ";
			cin>>n;
			a.second=n;
			coordenadas.push_back(a);
		}
	}while(n!=0);
	pair<float,int>veces1=make_pair(a.first,0);
	pair<float,int>veces2=make_pair(a.second,0);
	for(list<pair<float, float> >::iterator i=coordenadas.begin();i!=coordenadas.end();i++){
		if(a.first==(*i).first){
			veces1.second=veces1.second+1;
		}
		if(a.first==(*i).second){
			veces1.second=veces1.second+1;
		}
		if(a.second==(*i).first){
			veces2.second=veces2.second+1;
		}
		if(a.second==(*i).second){
			veces2.second=veces2.second+1;
		}	
	}
	cout<<endl<<veces1.first<<" ----> "<<veces1.second<<" veces"<<endl;
	cout<<veces2.first<<" ----> "<<veces2.second<<" veces"<<endl;
}
