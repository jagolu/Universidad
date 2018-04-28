#include <iostream>
#include <list>

using namespace std;

void introducir(list<int> &l, int x){
	list<int> l2;
	for(list<int>::iterator i=l.begin();i!=l.end();i++){
		if(*i!=x){
			l2.push_back(*i);
		}
		else{
			l2.push_back(*i);
			l2.push_back(*i-1);
		}
	}
	l=l2;
}
