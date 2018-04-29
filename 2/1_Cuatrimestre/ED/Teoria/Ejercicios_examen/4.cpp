#include <iostream>
#include <set>
using namespace std;


bool Contenido( set<int> c1,  set<int> c2){
	if(c1.size()>c2.size()) return false;
	bool esta=true;
	for(set<int>::iterator i=c1.begin();i!=c1.end() && esta;++i){
		if(c2.find(*i)==c2.end()) esta=false;
	}
	return esta;		
}
void mostrar(const set<int> & s){
	for(set<int>::const_iterator i=s.begin();i!=s.end();++i){
		cout<<*i<<" ";
	}
	cout<<endl<<endl;
}
int main(){
	set<int>c1, c2;
	c1.insert(1);
	c1.insert(2);
	c1.insert(3);
	c1.insert(4);
	c2.insert(1);
	c2.insert(2);
	c2.insert(4);
	c2.insert(2);
	c2.insert(3);
	c2.insert(1);
	c2.insert(1);
	c2.insert(2);
	c2.insert(0);
	c2.insert(4);
	mostrar(c1);
	mostrar(c2);
	cout<<Contenido(c1,c2);
}
