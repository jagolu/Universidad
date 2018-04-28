#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <sstream>
#include "fecha.h"
#include <fstream>
#include "crimen.h"
#include "CSS.h"
#include <set>
#include <unordered_map>
#include <list>

using namespace std;

void CSS::load(string nombreDB){
	ifstream fe;
	string cadena;
	cout << "Abrimos "<< nombreDB << endl;
	fe.open(nombreDB.c_str(), ifstream::in);
	if (fe.fail()){
		cerr << "Error al abrir el fichero " << nombreDB << endl;
	} 
	else {
   		getline(fe,cadena,'\n');
   		cout << cadena << endl;
    		for(int i=0;i<10;i++){
      			getline(fe,cadena,'\n');
       			if (!fe.eof()) {
	   			crimen aux(cadena);
           			insert(aux);
         		}
     		}
	}
    	fe.close();
}
void CSS::insert(const crimen & x){
	BaseDeDatos.insert(  pair<ID, crimen>(x.getID(),x) );
	map<ID, crimen>::iterator it=BaseDeDatos.find(x.getID());
	DateAccess.insert(pair<fecha, map<ID, crimen>::iterator>(x.getDate(), it) );
	IUCRAccess[x.getIUCR()].insert(x.getID());
	index[x.getDescription()].insert(x.getID());
	posicionGeo[x.getLongitude()].insert(pair<latitud, ID>( x.getLatitude(), x.getID() ) );
}
bool CSS::erase(unsigned int id){
	crimen c(BaseDeDatos[id]);
	bool sal=false;
	if(BaseDeDatos.find(id)!=BaseDeDatos.end()){
		if(IUCRAccess.count(c.getIUCR())==1){
			IUCRAccess.erase(c.getIUCR());
		}
		else{
			IUCRAccess[c.getIUCR()].erase(id);
		}
		if(index.count(c.getDescription())==1){
			index.erase(c.getDescription());
		}
		else{
			index[c.getDescription()].erase(id);
		}
		bool borrado=false;
		map<ID, crimen>::iterator it=BaseDeDatos.find(id);
		multimap<fecha, map<ID,crimen>::iterator >::iterator it_borrar;
		for(multimap<fecha, map<ID, crimen>::iterator>::iterator i=DateAccess.begin();i!=DateAccess.end();++i){
			if(i->first==c.getDate() && i->second==it){
				it_borrar=i;
				borrado=true;
			}
		}
		DateAccess.erase(it_borrar);
		multimap<latitud, ID>::iterator it_borrar2;
		int tam=0;
		for(map<longitud, multimap<latitud, ID> >::iterator i=posicionGeo.begin();i!=posicionGeo.end();++i){
			if(i->first==c.getLongitude() ){
				for(multimap<latitud, ID>::iterator j=i->second.begin();j!=i->second.end();++j){
					if(j->first==c.getLatitude() && j->second==id){
						tam++;
						it_borrar2=j;
					}
				}
			}
		}
		if(tam!=1){
			posicionGeo[c.getLongitude()].erase(it_borrar2);
		}
		else{
			posicionGeo.erase(c.getLongitude());
		}
		sal= BaseDeDatos.erase(id);
	}	
	return sal;
}
void CSS::setArrest(const unsigned int ID, bool value){
	BaseDeDatos[ID].setArrest(value);
}
void CSS::mostrar(){
	cout<<"\nPor ID\n";
	for(map<ID,crimen>::iterator i=BaseDeDatos.begin();i!=BaseDeDatos.end();++i){
		cout<<i->second<<endl;
	}
	cout<<"\nPor IUCR\n";
	for(map<IUCR,set<ID> >::iterator i=IUCRAccess.begin();i!=IUCRAccess.end();++i){
		cout<<i->first<<endl;
		for(set<ID>::iterator j=IUCRAccess[i->first].begin();j!=IUCRAccess[i->first].end();++j){
			cout<<"\t"<<*j<<endl;
		}
	}
	cout<<"\nPor termino\n";
	for(unordered_map<termino,set<ID> >::iterator i=index.begin();i!=index.end();++i){
		cout<<i->first<<endl;
		for(set<ID>::iterator j=i->second.begin();j!=i->second.end();++j){
			cout<<"\t"<<*j<<endl;
		}
	}
	cout<<"\nPor ubicacion\n";	
	for(map<longitud, multimap<latitud, ID> >::iterator i=posicionGeo.begin();i!=posicionGeo.end();++i){
		cout<<i->first<<endl;
		for(multimap<latitud, ID>::iterator j=i->second.begin();j!=i->second.end();++j){
			cout<<"\t"<<j->first<<endl;
			cout<<"\t\t"<<j->second<<endl;
		}
	}
	cout<<"\nPor fecha\n";
	for(multimap<fecha, map<ID,crimen>::iterator >::iterator i=DateAccess.begin();i!=DateAccess.end();++i){
		cout<<i->first<<endl;
		cout<<"\t"<<i->second->first<<endl;
	}
}
vector<pair<ID,float> > CSS::Query(list<string> & q, int k){
	vector<pair<ID,float> >sal;
	if(q.size()==1){
		for(set<ID>::iterator i=index[q.front()].begin();i!=index[q.front()].end();++i){
			sal.push_back( pair<ID,float>(*i,1.0) );
		}
	}
	else if(q.size()==2){
		map<ID, float>peso;
		set<ID>t1=index[q.front()];
		q.pop_front();
		set<ID>t2=index[q.front()];
		peso=unionPeso(t1, t2);
		for(map<ID, float>::iterator i=peso.begin();i!=peso.end();++i){
			sal.push_back( pair<ID, float>(i->first, i->second) );
		}
	}
	else{
		map<ID, float>peso;
		set<ID>t1=index[q.front()];
		q.pop_front();
		set<ID>t2=index[q.front()];
		peso=unionPeso(t1, t2);
		q.pop_front();
		for(list<string>::iterator i=q.begin();i!=q.end();++i){
			set<ID>t=index[q.front()];
			unionPeso( peso, t);
		}
		for(map<ID, float>::iterator i=peso.begin();i!=peso.end();++i){
			sal.push_back( pair<ID, float>(i->first, i->second) );
		}
			
	}
	int elementos=k;
	float pesomax=q.size()*1.0;
	vector<pair<ID, float> >sal2;
	do{
		for(vector<pair<ID, float> >::iterator i=sal.begin();i!=sal.end();++i){
			if(i->second==pesomax && elementos!=0){	
				sal2.push_back(*i);
				elementos--;
			}
		}
		if(sal2.size()==sal.size()){
			elementos=0;
		}
		pesomax--;
	}while(elementos!=0);	
	return sal2;
}
map<ID,float> CSS::unionPeso( const set<ID> & t1, const set<ID> &t2){
	map<ID, float>peso;
	for(set<ID>::iterator i=t1.begin();i!=t1.end();++i){
		peso[*i]=1.0;
	}
	for(set<ID>::iterator i=t2.begin();i!=t2.end();++i){
		if(peso.count(*i)==1){
			peso[*i]=2.0;
		}
		else if(peso.count(*i)==0){
			peso[*i]=1.0;
		}
	}
	return peso;
}
void CSS::unionPeso( map<ID,float> & m, set<ID> & t_i){
	for(set<ID>::iterator i=t_i.begin();i!=t_i.end();++i){
		if(m.count(*i)!=0){
			m[*i]+=1.0;
		}
		else if(m.count(*i)==0){
			m[*i]=1.0;
		}
	}
}
list<ID> CSS::inArea(longitud x1, latitud y1, longitud x2, latitud y2 ){
	list<ID>area;
	for(map<longitud, multimap<latitud, ID> >::iterator i=posicionGeo.begin();i!=posicionGeo.end();++i){
		if(i->first>=x1 && i->first<=x2){
			for(multimap<latitud, ID>::iterator j=i->second.begin();j!=i->second.end();++j){
				if(j->first>=y1 && j->first<=y2){
					area.push_front(j->second);
				}
			}
		}
	}
	return area;
}
//******************************************************ITERATOR****************************************************************
CSS::iterator CSS::begin(){
	CSS::iterator sal;
	map<ID,crimen>::iterator i=BaseDeDatos.begin();
	sal.i=i;
	return sal;
}
CSS::iterator CSS::end(){
	CSS::iterator sal;
	map<ID,crimen>::iterator i=BaseDeDatos.end();
	sal.i=i;	
	return sal;
}
CSS::iterator::iterator(){}
CSS::iterator::iterator(const CSS::iterator & it){
	i=it.i;
}
pair<const ID, crimen> & CSS::iterator::operator*(){
	return *i;
}
CSS::iterator CSS::iterator::operator++(){
	i++;
	return *this;
}
CSS::iterator CSS::iterator::operator--(){
	i--;
	return *this;
}
bool CSS::iterator::operator==(const CSS::iterator & it){
	if(i==it.i){
		return true;
	}
	else{
		return false;
	}
}
bool CSS::iterator::operator!=(const CSS::iterator & it){
	if(i!=it.i){
		return true;
	}
	else{
		return false;
	}
}
//*****************************************************FIND_ID******************************************************************

CSS::iterator CSS::find_ID(const unsigned int ID){
	for(CSS::iterator i=begin();i!=end();++i){
		if( (*i).second.getID()==ID){
			return i;
		}
	}
	return end();
}

//***************************************************IUCR_ITERATOR**************************************************************

CSS::IUCR_iterator CSS::ibegin(){
	CSS::IUCR_iterator sal;
	sal.css=this;
	map<IUCR, set<ID> >::iterator it_m2=IUCRAccess.begin();
	set<ID>::iterator it_s2=IUCRAccess[it_m2->first].begin();
	sal.it_m=it_m2;
	sal.it_s=it_s2;
	return sal;
}
CSS::IUCR_iterator CSS::iend(){
	CSS::IUCR_iterator sal;
	sal.css=this;
	map<IUCR, set<ID> >::iterator it_m2=IUCRAccess.end();
	it_m2--;
	set<ID>::iterator it_s2=IUCRAccess[it_m2->first].end();
	sal.it_m=it_m2;
	sal.it_s=it_s2;
	return sal;
}
CSS::IUCR_iterator CSS::lower_bound(IUCR iucr){
	for(CSS::IUCR_iterator i=ibegin();i!=iend();++i){
		if( (*find_ID(*i)).second.getIUCR()>=iucr ){
			return i;
		}
	}
	return iend();
}
CSS::IUCR_iterator CSS::upper_bound(IUCR iucr){
	for(CSS::IUCR_iterator i=ibegin();i!=iend();++i){
		if( (*find_ID(*i)).second.getIUCR()>iucr){
			return i;
		}
	}
	return iend();
}
CSS::IUCR_iterator::IUCR_iterator(){}
CSS::IUCR_iterator::IUCR_iterator(const CSS::IUCR_iterator & it){
	it_m=it.it_m;
	it_s=it.it_s;
	css=it.css;
}
const ID & CSS::IUCR_iterator::operator*(){
	return *it_s;
}
CSS::IUCR_iterator CSS::IUCR_iterator::operator++(){
	if(it_s==css->IUCRAccess[it_m->first].end() && *this!=css->iend()){
		it_m++;
		it_s=css->IUCRAccess[it_m->first].begin();
	}
	else if(it_s!=css->IUCRAccess[it_m->first].end()){
		it_s++;
		if(it_s==css->IUCRAccess[it_m->first].end() && *this!=css->iend()){
			it_m++;
			it_s=css->IUCRAccess[it_m->first].begin();
		}
	}
	return *this;
}
CSS::IUCR_iterator CSS::IUCR_iterator::operator--(){
	if(it_s==css->IUCRAccess[it_m->first].begin() && *this!=css->ibegin()){
		it_m--;
		it_s=css->IUCRAccess[it_m->first].end();
		it_s--;
	}
	else if(it_s!=css->IUCRAccess[it_m->first].begin()){
		it_s--;
		if(it_s==css->IUCRAccess[it_m->first].begin() && *this!=css->ibegin()){
			it_m--;
			it_s=css->IUCRAccess[it_m->first].end();
			it_s--;
		}
	}
	return *this;
}
bool CSS::IUCR_iterator::operator==(const CSS::IUCR_iterator & it){
	if(it_s==it.it_s){
		return true;
	}
	else{
		return false;
	}
}
bool CSS::IUCR_iterator::operator!=(const CSS::IUCR_iterator & it){
	if(it_s!=it.it_s){
		return true;
	}
	else{
		return false;
	}
}

//*************************************************DATE_ITERATOR*******************************************************

CSS::Date_iterator CSS::dbegin(){
	CSS::Date_iterator sal;
	multimap<fecha, map<ID,crimen>::iterator>::iterator it_mm2=DateAccess.begin();
	sal.it_mm=it_mm2;
	return sal;
}
CSS::Date_iterator CSS::dend(){
	CSS::Date_iterator sal;
	multimap<fecha, map<ID,crimen>::iterator>::iterator it_mm2=DateAccess.end();
	sal.it_mm=it_mm2;
	return sal;
}
CSS::Date_iterator CSS::lower_bound(fecha f){
	for(CSS::Date_iterator i=dbegin();i!=dend();++i){
		if( (*find_ID(*i)).second.getDate()>=f ){
			return i;
		}
	}
	return dend();
}
CSS::Date_iterator CSS::upper_bound(fecha f){
	for(CSS::Date_iterator i=dbegin();i!=dend();++i){
		if( (*find_ID(*i)).second.getDate()>f){
			return i;
		}
	}
	return dend();
}
CSS::Date_iterator::Date_iterator(){}
CSS::Date_iterator::Date_iterator (const Date_iterator & it){
	it_mm=it.it_mm;
}
const ID & CSS::Date_iterator::operator*(){
	return it_mm->second->first;
}
CSS::Date_iterator CSS::Date_iterator::operator++(){
	it_mm++;
	return *this;
}
CSS::Date_iterator CSS::Date_iterator::operator--(){
	it_mm--;
	return *this;
}
bool CSS::Date_iterator::operator==(const Date_iterator & it){
	if(it_mm==it.it_mm){
		return true;
	}
	else{
		return false;
	}
}
bool CSS::Date_iterator::operator!=(const Date_iterator & it){
	if(it_mm!=it.it_mm){
		return true;
	}
	else{
		return false;
	}
}
