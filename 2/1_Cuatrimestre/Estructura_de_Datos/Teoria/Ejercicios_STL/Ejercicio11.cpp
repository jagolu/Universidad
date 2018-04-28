#include <iostream>
#include <list>

using namespace std;

list<pair<int, int> > comprimir(const list<int> &l){
	list<pair<int,int> > comprimido;
	for(list<int>::const_iterator i=l.begin();i!=l.end();++i){
		pair<int, int> a;
		int veces=0;
		int valor=*i;
		a.first=valor;
		list<int>::const_iterator j=i;
		bool distintoAcabado=false;
		while(!distintoAcabado){
			if(*j==*i){
				veces++;
				i=j;
			}
			if(*j!=*i){
				distintoAcabado=true;
			}
			if(j==l.end()){
				distintoAcabado=true;
			}
			j++;
		}
		a.second=veces;
		comprimido.push_back(a);
	}
	return comprimido;
}
list<int> descomprimir (const list<pair<int, int> > &lc){
	list<int> descomprimido;
	for(list<pair<int, int> >::const_iterator i=lc.begin();i!=lc.end();i++){
		for(int i2=0;i2<(*i).second;i2++){
			descomprimido.push_back((*i).first);
		}
	}
	return descomprimido;
}
