#include <iostream>
#include <stack>
#include <list>

using namespace std;


list<list<int> > f(const list<int> & l){
	list<list<int > >res;
	for(list<int>::const_iterator i=l.begin();i!=l.end();i++){
		list<list<int> >::iterator it=res.end();bool esta=false;bool pos=false;
		for(list<list<int> >::iterator j=res.begin();j!=res.end() && !esta && !pos;j++){
			if(*(*j).begin()==*i){
				it=j;
				pos=true;
			}
			else if(*(*j).begin()>*i){
				it=j;
				esta=true;
			}
		}
		if(pos){
			(*it).push_back(*i);
		}
		else{
			list<int> a;
			a.push_back(*i);
			res.insert(it, a);
		}
	}
	return res;
}
void mostrar(const list<int> & l){
	for(list<int>::const_iterator i=l.begin();i!=l.end();i++){
		cout<<*i<<" ";
	}
	cout<<endl<<endl;
}
int main(){
	list<int>l1;
	l1.push_back(1);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	l1.push_back(6);
	l1.push_back(3);
	l1.push_back(2);
	l1.push_back(1);
	l1.push_back(4);
	l1.push_back(5);
	l1.push_back(5);
	l1.push_back(1);
	l1.push_back(1);
	l1.push_back(7);
	mostrar(l1);
	list<list<int > >l2=f(l1);
	cout<<"{ ";
	for(list<list<int> >::iterator i=l2.begin();i!=l2.end();i++){
		cout<<"{";
		for(list<int>::iterator j=(*i).begin();j!=(*i).end();j++){
			cout<<*j<<" ";
		}
		cout<<"}";
	}
	cout<<" }"<<endl;
	
}
	
