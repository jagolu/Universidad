#include <iostream>
#include <list>

using namespace std;

list<int> mezclar(const list<int> &l1, const list<int> &l2){
	list<int>a;
	for(list<int>::const_iterator i=l1.begin();i!=l1.end();i++){
		a.push_back(*i);
	}
	list<int>::const_iterator j=l2.begin();
	list<int>::iterator i=a.begin();
	for(;i!=a.end();i++){
		if(*i>=*j && j!=l2.end()){
			a.insert(i,*j);
			j++;
		}
	}
	if(j!=l2.end()){
		for(;j!=l2.end();j++){
			a.insert(i,*j);
		}
	}
		
	return a;
}
int main(){}
