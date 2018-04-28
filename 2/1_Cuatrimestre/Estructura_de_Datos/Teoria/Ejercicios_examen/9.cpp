#include <iostream>
#include <list>
using namespace std;

void agrupar(list<int> &entrada, const int& k){
	list<int>::iterator primero;
	bool encontrado=false;
	for(list<int>::iterator i=entrada.begin();i!=entrada.end();i++){
		if(*i==k){
			if(!encontrado){
				primero=i;
				encontrado=true;
			}
			else{
				entrada.insert(primero,k);
				entrada.erase(i);
				i--;
			}
		}
	}
}
void mostrar(const list<int> & l){
	for(list<int>::const_iterator i=l.begin();i!=l.end();i++){
		cout<<*i<<" ";
	}
	cout<<endl<<endl;
}
int main(){
	list<int>l1,l2;
	l1.push_back(1);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(1);
	l1.push_back(4);
	l2.push_back(3);
	l2.push_back(1);
	l2.push_back(4);
	l2.push_back(1);
	l2.push_back(4);
	l2.push_back(1);
	l2.push_back(1);
	mostrar(l1);
	agrupar(l1,1);
	mostrar(l1);
	mostrar(l2);
	agrupar(l2,1);
	mostrar(l2);
}
