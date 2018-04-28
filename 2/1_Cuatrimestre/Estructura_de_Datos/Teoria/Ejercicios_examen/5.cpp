#include <iostream>
#include <list>

using namespace std;

list<int> mezclar(const list<int> & l1, const list<int> &l2){
	list<int> l3;
	int cont=0;
	list<int>::const_iterator i=l1.begin();
	list<int>::const_iterator j=l2.begin();
	if(*i>*j){
		l3.push_back(*j);
		j++;
	}
	else{
		l3.push_back(*i);
		i++;
	}
	while(i!=l1.end() && j!=l2.end()){
		if(*i>*j){
			if(*j!=l3.back()){
				l3.push_back(*j);
			}
			j++;
		}
		else{
			if(*i!=l3.back()){
				l3.push_back(*i);
			}
			i++;
		}
	}
	while(i!=l1.end()){
		if(l3.back()!=*i){
			l3.push_back(*i);
		}
		i++;
	}
	while(j!=l2.end()){
		if(l3.back()!=*j){
			l3.push_back(*j);
		}
		j++;
	}
	return l3;
}
void mostrar(list<int> & l){
	for(list<int>::iterator i=l.begin();i!=l.end();i++){
		cout<<*i<<" ";
	}
	cout<<endl;
}
int main(){
	list<int> l1,l2;
	l1.push_back(1);
	l1.push_back(3);
	l1.push_back(6);
	l1.push_back(8);
	l1.push_back(13);
	l1.push_back(18);
	l1.push_back(22);
	l2.push_back(5);
	l2.push_back(6);
	l2.push_back(7);
	l2.push_back(22);
	mostrar(l1);
	mostrar(l2);
	list<int>l3=mezclar(l1,l2);
	mostrar(l3);
}
