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
public:
	typedef crimen entrada;
	typedef unsigned int size_type;
	conjunto( );
	conjunto (const conjunto & d);
	pair<conjunto::entrada,bool>  findID( const long int & id) const;
	conjunto findIUCR( const string & iucr) const;
	conjunto  findDESCR( const string & descr) const;
	
	bool insert( const conjunto::entrada & e);
	bool erase(const long int & id);
	bool erase(const  conjunto::entrada & e);
	
	conjunto & operator=( const conjunto & org);
	
	size_type size() const;
	bool empty() const;

};
ostream &  operator << ( ostream & sal, const conjunto & D);
#include "conjunto.hxx"
#endif

