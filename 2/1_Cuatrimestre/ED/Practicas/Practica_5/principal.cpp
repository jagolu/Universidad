#include "fecha.h"
#include "crimen.h"
#include "CSS.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <list>
#include <vector>

using namespace std;


int main(){
	CSS ChicagoDB;
	crimen d;
	fecha f;
	ChicagoDB.load("crimenes.csv");
	
	ChicagoDB.mostrar();
	
	
		//MAIN
	
	cout<<"\n\nBase de datos recorrida por iteradores:\n";
	for(CSS::iterator i=ChicagoDB.begin();i!=ChicagoDB.end();++i){
		cout<<(*i).second<<endl;
	}
	cout<<"\n\nPrueba de erase\n";
	cout<<"Introduzca el ID que quiera eliminar: ";
	ID id;
	cin>>id;
	ChicagoDB.erase(id);
	cout<<"\n\nBase de datos recorrida por iteradores con el crimen eliminado:\n";
	for(CSS::iterator i=ChicagoDB.begin();i!=ChicagoDB.end();++i){
		cout<<(*i).second<<endl;
	}
	cout<<"\n\nBase de datos recorrida por iteradores ordenados por IUCR:\n";
	for(CSS::IUCR_iterator i=ChicagoDB.ibegin();i!=ChicagoDB.iend();++i){
		cout<<(*ChicagoDB.find_ID(*i)).second.getIUCR()<<" "<<(*ChicagoDB.find_ID(*i)).second<<endl;
	}
	cout<<"\n\nPrueba de lower_bound para IUCR\n";
	string iucr;
	cout<<"Introduzca IUCR para probar lower_bound: ";
	cin>>iucr;
	cout<<(*ChicagoDB.find_ID(*ChicagoDB.lower_bound(iucr))).second<<endl;
	cout<<"\n\nPrueba de upper_bound para IUCR\n";
	cout<<"Introduzca IUCR para probar upper_bound: ";
	cin>>iucr;
	cout<<(*ChicagoDB.find_ID(*ChicagoDB.upper_bound(iucr))).second<<endl;
	cout<<"\n\nBase de datos recorrida por iteradores ordenados por fecha:\n";
	for(CSS::Date_iterator i=ChicagoDB.dbegin();i!=ChicagoDB.dend();++i){
		cout<<(*ChicagoDB.find_ID(*i)).second.getDate()<<" "<<(*ChicagoDB.find_ID(*i)).second<<endl;
	}
	cout<<"\n\nPrueba de lower_bound para Date\n";
	cout<<"Introduzca ID para probar lower_bound (De ese ID se sacara la fecha): ";
	cin>>id;
	cout<<(*ChicagoDB.find_ID(*ChicagoDB.lower_bound( (*ChicagoDB.find_ID(id)).second.getDate() ))).second<<endl;
	cout<<"\n\nPrueba de upper_bound para Date\n";
	cout<<"Introduzca ID para probar upper_bound (De ese ID se sacara la fecha): ";
	cin>>id;
	cout<<(*ChicagoDB.find_ID(*ChicagoDB.upper_bound( (*ChicagoDB.find_ID(id)).second.getDate() ))).second<<endl;
	cout<<"\n\nFIND_ID\n\n";
	cout<<"\n\nID a buscar: ";
	cin>>id;
	if(ChicagoDB.find_ID(id)!=ChicagoDB.end()){
		cout<<(*ChicagoDB.find_ID(id)).second<<endl;
	}
	else{
		cout<<"No existe ningun crimen con esa ID\n";
	}
	cout<<"\n\nINAREA\n\n";
	latitud l11, l12;
	longitud l21, l22;
	cout<<"Primeras longitud y latitud:\n";
	cin>>l11;
	cin>>l21;
	cout<<"Segundas longitud y latitud:\n";
	cin>>l12;
	cin>>l22;
	cout<<"Crimenes entre esas coordenadas:\n";
	list<ID>ia=ChicagoDB.inArea(l21, l11, l22, l12);
	for(list<ID>::iterator i=ia.begin();i!=ia.end();++i){
		cout<<(*ChicagoDB.find_ID(*i)).second<<endl;
	}
	cout<<"\n\nQUERY\n\n";
	string b;
	int k;
	list<string>lista;
	cout<<"Introduzca descripciones de crimen (\"0\" para parar de introducir:\n";
	do{
		getline(cin,b);
		if(b!="0"){
			lista.push_front(b);
		}
	}while(b!="0");
	cout<<"Introduzca k: ";
	cin>>k;
	vector<pair<ID, float> >a=ChicagoDB.Query(lista, k);
	for(vector<pair<ID, float> >::iterator i=a.begin();i!=a.end();i++){
		cout<<i->first<<" "<<i->second<<endl;
	}
	
   return 0;
}
