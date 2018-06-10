#include <iostream>
#include <set>

using namespace std;

int menor(const int & n1, const int & n2){
	if(n1<=n2){
		return n1;
	}
	else{
		return n2;
	}
}

multiset<int> multi_interseccion(const multiset<int> & m1, const multiset<int> & m2){
	multiset<int> res;
	bool primero=true;
	if(m1.size()>m2.size()) primero=false;
	int anterior;
	if(primero){
		for(multiset<int>::const_iterator i=m1.begin();i!=m1.end();i++){
			if(i==m1.begin() || *i!=anterior){
				anterior=*i;
				int nveces1=m1.count(*i);
				int nveces2=m2.count(*i);
				int menorVeces=menor(nveces1, nveces2);
				for(int j=0;j<menorVeces;j++){
					res.insert(*i);
				}
			}
		}
	}	
	else{
		for(multiset<int>::const_iterator i=m2.begin();i!=m2.end();i++){
			if(i==m2.begin() || *i!=anterior){
				anterior=*i;
				int nveces1=m1.count(*i);
				int nveces2=m2.count(*i);
				int menorVeces=menor(nveces1, nveces2);
				for(int j=0;j<menorVeces;j++){
					res.insert(*i);
				}
			}
		}
	}
	return res;
}
void mostrar(const multiset<int> & m){
	for(multiset<int>::iterator i=m.begin();i!=m.end();i++){
		cout<<*i<<" ";
	}
	cout<<endl<<endl;
}
int main(){
	multiset<int> m1, m2;
	m1.insert(2);
	m1.insert(2);
	m1.insert(2);
	m1.insert(3);
	m1.insert(3);
	m2.insert(1);
	m2.insert(2);
	m2.insert(2);
	m2.insert(2);
	m2.insert(2);
	m2.insert(3);
	m2.insert(3);
	m2.insert(3);
	m2.insert(4);
	mostrar(m1);
	mostrar(m2);
	multiset<int> m3=multi_interseccion(m1,m2);
	mostrar(m3);
}
	
