#include <iostream>
#include <list>

using namespace std;

list<int> nuevaLista(const list<int> &l, const list<int> &li){
	list<int>l2;
	int pos=0;
	list<int>::const_iterator j=li.begin();
	for(list<int>::const_iterator i=l.begin();i!=l.end();i++){
		if(pos==*j){
			l2.push_back(*i);
			j++;
		}
		pos++;
	}
	return l2;
}
