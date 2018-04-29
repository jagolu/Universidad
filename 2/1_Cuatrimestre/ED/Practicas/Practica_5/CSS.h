#ifndef _CSS_H_
#define _CSS_H_
#include <iostream>
#include <string>
#include "fecha.h"
#include "crimen.h"
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <list>

using namespace std;

typedef float longitud;
typedef float latitud;
typedef unsigned int ID;
typedef string termino;
typedef string IUCR;

class CSS{
private:
	map<ID,crimen> BaseDeDatos;
	multimap<fecha, map<ID,crimen>::iterator >DateAccess;
	map<IUCR,set<ID> > IUCRAccess;
	unordered_map<termino, set<ID> > index;
	map<longitud, multimap<latitud, ID> > posicionGeo;
	friend class iterator;
	friend class IUCR_iterator;
	friend class Date_iterator;
public:
	void load(string nombreDB);
	void insert(const crimen & x);
	bool erase(unsigned int id);
	void setArrest(const unsigned int ID, bool value);
	void mostrar();
	map<ID,float> unionPeso( const set<ID> & t1, const set<ID> &t2); 
	void unionPeso( map<ID,float> & m, set<ID> & t_i);
	vector<pair<ID,float> > Query(list<string> & q, int k);
	list<ID> inArea(longitud x1, latitud y1, longitud x2, latitud y2 );


	//********************************************CLASES DE ITERADORES*****************************************************
	class iterator;
	class IUCR_iterator;
	class Date_iterator;
	//**************************************************ITERATOR***********************************************************

    	iterator begin();
    	iterator end();

	class iterator {
        private:
        	friend class CSS;
        	map<ID,crimen>::iterator i;
        public:
	    	iterator();
    		iterator (const iterator & it);
       		pair<const ID, crimen> & operator*() ;
        	iterator operator++();
  	    	iterator operator--();
   	    	bool operator==(const iterator & it);
   		bool operator!=(const iterator & it);
	};

	//*****************************************************FIND_ID*********************************************************	
		
    	iterator find_ID(const unsigned int ID);
	
	//************************************************IUCR_ITERATOR********************************************************

	
	IUCR_iterator ibegin();
    	IUCR_iterator iend();
  	IUCR_iterator lower_bound(IUCR iucr);
    	IUCR_iterator upper_bound(IUCR iucr);

	class IUCR_iterator {
        private:
        	friend class CSS;
		CSS * css;
        	map<IUCR,set<ID> >::iterator it_m;
		set<ID>::iterator it_s;
        public:
	    	IUCR_iterator();
    		IUCR_iterator (const IUCR_iterator & it);
       		const ID & operator*() ;
        	IUCR_iterator operator++();
  	    	IUCR_iterator operator--();
   	    	bool operator==(const IUCR_iterator & it);
   		bool operator!=(const IUCR_iterator & it);
	};

	//*************************************************DATE_ITERATOR*******************************************************

	Date_iterator dbegin();
    	Date_iterator dend();
    	Date_iterator lower_bound(fecha f);
    	Date_iterator upper_bound(fecha f);

	class Date_iterator {
        private:
        	friend class CSS;
        	multimap<fecha, map<ID,crimen>::iterator>::iterator it_mm;
        public:
	    	Date_iterator();
    		Date_iterator (const Date_iterator & it);
       		const ID & operator*() ;
        	Date_iterator operator++();
  	    	Date_iterator operator--();
   	    	bool operator==(const Date_iterator & it);
   		bool operator!=(const Date_iterator & it);
	};
};
#include "CSS.hxx"
#endif
