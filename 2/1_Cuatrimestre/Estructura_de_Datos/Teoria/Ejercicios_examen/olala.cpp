#include <iostream>
#include <list>

using namespace std;

template <class T>
void postintercalar(list<T> & l1, list<T> & l2){
	if(!l1.empty() && !l2.empty()){
		typename list<T>::iterator it2=l2.end();
		it2--;
		while(!l1.empty() && it2!=l2.begin()){
			l2.insert(it2, l1.front());
			l1.pop_front();
			it2--;
			it2--;
		}
		while(!l1.empty()){
			l2.insert(it2, l1.front());
			l1.pop_front();
		}
	}
}

template <class T>
void mostrar(const list<T> & l){
	typename list<T>::const_iterator it=l.begin();
	for(it;it!=l.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl<<endl;
}

int main(){
	list<char>l1, l2;
	l1.push_back('x');
	l1.push_back('y');
	l1.push_back('z');
	l2.push_back('a');
	l2.push_back('b');
	l2.push_back('c');
	l2.push_back('d');
	l2.push_back('e');
	l2.push_back('f');
	mostrar(l1);
	mostrar(l2);
	postintercalar(l1, l2);
	mostrar(l1);
	mostrar(l2);
}
		
