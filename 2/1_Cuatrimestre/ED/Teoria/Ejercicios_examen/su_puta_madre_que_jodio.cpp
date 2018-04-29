#include <iostream>
#include <list>

using namespace std;

typedef pair<int, int> intervalo;
bool Extraer(list<intervalo> & l1, intervalo x, list<intervalo> & l2){
	bool encontrado=false;
	list<intervalo>::iterator it1;
	for(list<intervalo>::iterator i=l1.begin();i!=l1.end() && !encontrado;i++){
		if( (*i).first>=x.first && (*i).second<=x.second ){
			it1=i;
			encontrado=true;
		}
	}
	if(encontrado){
		cout<<"olala\n";
		if( (*it1).first==x.first && (*it1).second==x.second ){
			l1.erase(it1);
		}
		else if( (*it1).first< x.first && (*it1).second==x.second ){
			(*it1).second=x.second-1;
		}
		else if( (*it1).first==x.first && (*it1).second>x.second ){
			(*it1).first=x.first+1;
		}
		else{
			intervalo p1;
			p1.first= (*it1).first;
			p1.second=(*it1).first-1;
			l1.insert(it1, p1);
			(*it1).first=(*it1).second;
			(*it1).second=(*it1).second+1;
		}
		encontrado=false;
		list<list<intervalo>::iterator> l3;
		for(list<intervalo>::iterator i=l2.begin();i!=l2.end() && !encontrado;i++){
			if( ( (*i).first>=x.first && (*i).second<=x.second ) || ( (*i).first<=x.first && (*i).second<=x.second ) || ( (*i).first>=x.first && (*i).second<=x.second ) || ( (*i).first<=x.first && (*i).second>=x.second) ){
				l3.push_back(i);
			}
			if( (*i).second >=x.second ){
				encontrado =true;
			}
		}
		return true;
	}
	return false;
}
void mostrar( list<pair<int, int> > l){
	for(list<pair<int, int> >::iterator i=l.begin();i!=l.end();i++){
		cout<<(*i).first<<" "<<(*i).second<<"    ";
	}
	cout<<endl<<endl;
}
int main(){
	list<pair<int, int> >l1, l2;
	l1.push_back( pair<int, int>(1,7) );
	l1.push_back( pair<int, int>(10,14) );
	l1.push_back( pair<int, int>(18,20) );
	l1.push_back( pair<int, int>(25,26) );
	l2.push_back( pair<int, int>(0,1) );
	l2.push_back( pair<int, int>(14,16) );
	l2.push_back( pair<int, int>(20,23) );
	mostrar(l1);
	Extraer(l1, pair<int, int>(12,14), l2);
	mostrar(l1);
}
			
		
