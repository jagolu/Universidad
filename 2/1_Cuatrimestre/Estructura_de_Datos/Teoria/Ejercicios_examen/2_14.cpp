#include <iostream>
#include <set>

using namespace std;

multiset<int> multi_interseccion(const multiset<int> & m1, const multiset<int> & m2){
	multiset<int> res;
	int anterior=*m1.begin();
	for(multiset<int>::iterator i=m1.begin();i!=m1.end();i++){
		if(i==m1.begin() || anterior!=*i){
			anterior=*i;
			int veces1=m1.count(*i);
			int veces2=m2.count(*i);
			int menor;
			if(veces1<=veces2) menor=veces1;
			else menor=veces2;
			for(int j=0;j<menor;j++) res.insert(*i);
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
	multiset<int>m1, m2;
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
	multiset<int>m3=multi_interseccion(m1,m2);
	mostrar(m3);
}
				
