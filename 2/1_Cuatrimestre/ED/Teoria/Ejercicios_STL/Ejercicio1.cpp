#include <iostream>
#include <list>

using namespace std;

void EliminaElemento(list <int>& l, int n){
	list<int>::iterator i=l.begin();
	while(i !=l.end()){
		if(*i==n){
			l.erase(i++);
		}
		else{
			i++;
		}	
	}
	cout<<endl;
}
