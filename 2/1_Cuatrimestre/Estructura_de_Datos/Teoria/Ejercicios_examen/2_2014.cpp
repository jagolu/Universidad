#include <iostream>
#include <list>

using namespace std;

void postintercalar(list<char> & l1, list<char> & l2){
	if(!l1.empty() && !l2.empty()){
		list<char>::iterator it2=l2.end();
		it2--;
		while(!l1.empty() && it2!=l2.begin()){
			l2.insert(it2,l1.front());
			l1.pop_front();
			it2--;
			it2--;
		}
		while(!l1.empty()){
			l2.insert(it2,l1.front());
			l1.pop_front();
		}
	}
}
void mostrar(const list<char> & l){
	for(list<char>::const_iterator i=l.begin();i!=l.end();i++){
		cout<<*i<<" ";
	}
	cout<<endl<<endl;
}
int main(){
	list<char>l1;
	l1.push_back('x');
	l1.push_back('y');
	l1.push_back('z');
	list<char>l2;
	l2.push_back('a');
	l2.push_back('b');
	l2.push_back('c');
	l2.push_back('d');
	l2.push_back('e');
	l2.push_back('f');
	mostrar(l1);
	mostrar(l2);
	postintercalar(l1,l2);
	mostrar(l1);
	mostrar(l2);	
}
