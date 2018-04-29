#include <iostream>
#include <list>

using namespace std;

list<int> invertir(list<int> l){
	list<int>l2;
	for(list<int>::iterator i=l.begin();i!=l.end();i++){
		l2.push_front(*i);
	}
	return l2;
}
