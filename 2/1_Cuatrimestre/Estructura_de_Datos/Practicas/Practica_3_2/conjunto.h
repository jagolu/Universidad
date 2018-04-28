#ifndef _CONJUNTO_H_
#define _CONJUNTO_H_
#include <iostream>
#include <string>
#include "fecha.h"
#include "crimen.h"
#include <vector>
using namespace std;
class conjunto{
private:
	vector<crimen> vc; 
	//He cambiado size por tamano, porque habia una funcion que se llamaba size, he visto mas 
	//conveniente cambiar el nombre de la variable privada en vez que el nombre de la funcion.
	unsigned int tamano;
	bool cheq_rep( ) const;
	friend ostream &  operator << ( ostream & sal, const conjunto & D);
	friend class iterator;
	friend class const_iterator;
	friend class arrest_iterator;
	friend class const_arrest_iterator;
	friend class description;
public:
	typedef crimen entrada;
	typedef unsigned int size_type;
	conjunto( );
	conjunto (const conjunto & d);
	conjunto findIUCR( const string & iucr) const;
	conjunto  findDESCR( const string & descr) const;
	
	bool insert( const conjunto::entrada & e);
	bool erase(const long int & id);
	bool erase(const  conjunto::entrada & e);
	
	conjunto & operator=( const conjunto & org);
	
	size_type size() const;
	bool empty() const;
	
	//*********************ITERADORES****************************
	
	class iterator;  
   	class const_iterator;
   	class arrest_iterator; 
	class const_arrest_iterator;
   	class description_iterator;  
   	class const_description_iterator;
	//********************ITERATOR********************************   	

   	iterator begin();
   	iterator end();
   	
   	class iterator {
        private:
        	friend class conjunto;
        	vector<entrada>::iterator itv;
        public:
	    	iterator();
    		iterator (const iterator & it);
       		const conjunto::entrada & operator*() const;
        	iterator operator++( int );
    		iterator & operator++();
  	    	iterator operator--(int );
   	   	iterator & operator--();
   	    	bool operator==(const iterator & it);
   		bool operator!=(const iterator & it);
	};
	//********************CONST_ITERATOR*****************************

	const_iterator cbegin() const;
   	const_iterator cend() const;
   	
   	class const_iterator {
	private:
		vector<entrada>::const_iterator c_itv;
		friend class conjunto;
	public:
		const_iterator();
		const_iterator(const const_iterator & it);
		const_iterator(const iterator & it);
		const conjunto::entrada & operator*() const;
		const_iterator operator++( int );
		const_iterator & operator++();
 		const_iterator operator--(int);
        	const_iterator & operator--();
		bool operator==(const const_iterator & it);
		bool operator!=(const const_iterator & it); 
	};
	//****************ARREST ITERATOR***************

	arrest_iterator abegin();
	arrest_iterator aend();

	class arrest_iterator{
	private:
		vector<entrada>::iterator itv;
		friend class conjunto;
		conjunto * c;
	public:
		arrest_iterator();
		arrest_iterator(const arrest_iterator & it);
		
		const conjunto::entrada & operator*()const;
		arrest_iterator operator++(int);
		arrest_iterator & operator++();
		arrest_iterator operator--(int);
		arrest_iterator & operator--();
		bool operator==(const arrest_iterator & it);
		bool operator!=(const arrest_iterator & it);
	};
	//****************CONST_ARREST_ITERATOR*********

	const_arrest_iterator cabegin()const;
	const_arrest_iterator caend()const;

	class const_arrest_iterator{
	private:
		vector<entrada>::const_iterator c_itv;
		friend class conjunto;
		conjunto * c;
	public:
		const_arrest_iterator();
		const_arrest_iterator(const const_arrest_iterator & it);
		
		const conjunto::entrada & operator*()const;
		const_arrest_iterator operator++(int);
		const_arrest_iterator & operator++();
		const_arrest_iterator operator--(int);
		const_arrest_iterator & operator--();
		bool operator==(const const_arrest_iterator & it);
		bool operator!=(const const_arrest_iterator & it);
	};	
	//****************DESCRIPTION ITERATOR**********
	
	description_iterator  dbegin(const string & descr);
	description_iterator  dend(const string & descr);
	
	class description_iterator {
	private:
		string descr;
		vector<entrada>::iterator itv;
		conjunto * c;
		friend class conjunto;
	public:
		description_iterator();
		description_iterator(const description_iterator & it);
         
		const conjunto::entrada & operator*() const; 
		description_iterator operator++( int );
		description_iterator & operator++();
 		description_iterator operator--(int);
        	description_iterator & operator--();
		bool operator==(const description_iterator & it);
		bool operator!=(const description_iterator & it);
	};
	//*************CONST_DESCRIPTION_ITERATOR***************
	
	const_description_iterator  cdbegin(const string & descr)const;
	const_description_iterator  cdend(const string & descr)const;
	
	class const_description_iterator {
	private:
		string descr;
		vector<entrada>::const_iterator c_itv;
		conjunto * c;
		friend class conjunto;
	public:
		const_description_iterator();
		const_description_iterator(const const_description_iterator & it);
         
		const conjunto::entrada & operator*() const; 
		const_description_iterator operator++( int );
		const_description_iterator & operator++();
 		const_description_iterator operator--(int);
        	const_description_iterator & operator--();
		bool operator==(const const_description_iterator & it);
		bool operator!=(const const_description_iterator & it);
	};

	
	////////////////////FIND_POR_ITERATOR/////////////////////////
	conjunto::iterator find(const long int & s);
	conjunto::const_iterator find(const long int & id)const;
};
ostream &  operator << ( ostream & sal, const conjunto & D);
#include "conjunto.hxx"
#endif

