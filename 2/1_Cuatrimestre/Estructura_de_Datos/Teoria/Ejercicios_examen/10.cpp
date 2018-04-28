#include <iostream>
#include <list>

using namespace std;

list<list<int> >funcion(const list<int> & l1){
	list<list<int> >res;
	for(list<int>::const_iterator i=l1.begin();i!=l1.end();i++){
		bool ya=false, otro=false;
		list<list<int> >::iterator i2=res.end();
		for(list<list<int> >::iterator j=res.begin();j!=res.end() && !ya && !otro;j++){
			if(*i==*(*j).begin()){
				ya=true;
				i2=j;
			}
			if(*i<*(*j).begin()){
				otro=true;
				i2=j;
			}
		}
		if(ya){
			(*i2).push_back(*i);
		}
		else{
			list<int>aa;
			aa.push_back(*i);
			res.insert(i2,aa);
		}
	}
	return res;
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
	list<list<int> >l2=funcion(l1);
	cout<<"{ ";
	for(list<list<int> >::iterator i=l2.begin();i!=l2.end();i++){
		cout<<"{";
		for(list<int>::iterator j=(*i).begin();j!=(*i).end();j++){
			cout<<*j;
			list<int>::iterator j2=j;
			j2++;
			if(j2!=(*i).end()) cout<<",";
		}
		cout<<"}";
		list<list<int> >::iterator i2=i;
		i2++;
		if(i2!=l2.end())cout<<",";
		else cout<<" ";
	}
	cout<<"}\n";
}
