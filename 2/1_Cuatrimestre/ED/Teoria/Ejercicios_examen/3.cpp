#include <iostream>
#include <list>

using namespace std;

bool esPrimo(const int & n){
	bool primo=true;
	for(int i=2;i<n && primo;i++){
		if( (n%i)==0){
			primo=false;
		}
	}
	if(n==1) primo=true;
	return primo;
}

void Intercambiar(list<int>&l){
	list<int>::iterator i=l.begin();
	list<int>::iterator j=l.end();
	j--;
	
	while(i!=j){
		if( !esPrimo( (*i) ) && i!=j){
			i++;
		}
		if( !esPrimo( (*j) ) && i!=j){
			j--;
		}
		if( esPrimo((*i)) && esPrimo((*j))){
			int aux=*i;
			*i=*j;
			*j=aux;
			i++;
			j--;
		}
	}
}
void mostrar(const list<int>&l){
	for(list<int>::const_iterator i=l.begin();i!=l.end();i++){
		cout<<*i<<" ";
	}
	cout<<endl<<endl;
}
int main(){
	list<int>l;
	l.push_back(1);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	l.push_back(3);
	l.push_back(12);
	l.push_back(15);
	l.push_back(17);
	mostrar(l);
	Intercambiar(l);
	mostrar(l);
}
	
