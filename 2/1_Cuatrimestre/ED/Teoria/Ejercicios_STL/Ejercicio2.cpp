#include <iostream>
#include <list>

using namespace std;

void elimina_duplicados(list<int> &l){
	for(list<int>::iterator i=l.begin();i!=l.end();i++){
		list<int>::iterator j=i;
		j++;
		for(;j!=l.end();j++){
			if(*i==*j){
				l.erase(j);
			}
		}
	}
}
