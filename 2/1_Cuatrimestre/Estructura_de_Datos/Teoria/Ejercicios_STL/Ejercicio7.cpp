#include <iostream>
#include <list>

using namespace std;

bool contenida(const list<int> &l1, const list<int> &l2){
	if(l2.size()<l1.size()){
		return false;
	}
	bool devolver=false;
	for(list<int>::const_iterator i=l2.begin();i!=l2.end();i++){
		list<int>::const_iterator j=l1.begin();
		if(*j==*i){
			int contador=0;
			list<int>::const_iterator i2=i;
			for(;j!=l1.end();j++,i2++){
				if(*j==*i2){
					cout<<*j<<"   "<<*i2<<endl;
					contador++;
				}
			}
			if(contador==l1.size()){
				return true;
			}
		}
	}
	return devolver;
}
