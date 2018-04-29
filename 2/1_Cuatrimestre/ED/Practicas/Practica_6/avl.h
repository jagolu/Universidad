#ifndef _AVL_H_
#define _AVL_H_
#include "bintree.h"
#include <iostream>

using namespace std;

template <typename T>
class AVL{

	private:
		typedef int altura;
		int max(T n1, T n2);
		AVL<T>::altura h(typename bintree<pair<T, AVL<T>::altura> >::node & n);
		AVL<T>::altura h(typename bintree<pair<T, AVL<T>::altura> >::const_node & n);

		bintree<pair<T, altura> >el_avl;
		unsigned int tama;
	public: 
		//Constructores
		AVL();
		AVL<T>(const AVL<T> & A);
		//Operador de asignacion
		AVL & operator=(const AVL &A);

		
		//Rotaciones
		void insertarAltura(typename bintree<pair<T, altura> >::node & n);
	
		void RSD(typename bintree<pair<T, altura> >::node & n);
		void RSI(typename bintree<pair<T, altura> >::node & n);
		void RDD(typename bintree<pair<T, altura> >::node & n);
		void RDI(typename bintree<pair<T, altura> >::node & n);
		void reequilibradoInsercion(typename bintree<pair< T, altura> >::node & n);
		void reequilibradoBorrado(typename bintree<pair<T, altura> >::node & n);
	
		//iterdores

		/*ME faltan los iteradores*/
	
		//Capacidad
		bool empty();
		int size();
		
		//Operaciones
		typename bintree<pair<T, altura> >::node & find(typename bintree<pair<T, altura> >::const_node & n1, typename bintree<pair<T, altura> >::const_node & n2);
		void lower_bound2(typename bintree<pair<T, altura> >::node & n1, typename bintree<pair<T, altura> >::node & n2, typename bintree<pair<T, altura> >::node & n3);
		typename bintree<pair<T, altura> >::node & lower_bound( bintree<pair<T, altura> >arb, typename bintree<pair<T, altura> >::node & n2);
		void upper_bound2(typename bintree<pair<T, altura> >::node & n1, typename bintree<pair<T, altura> >::node & n2, typename bintree<pair<T, altura> >::node & n3);
		typename bintree<pair<T, altura> >::node & upper_bound( bintree<pair<T, altura> >arb, typename bintree<pair<T, altura> >::node & n2);

		//Modificadores
		void insert(const T & f);
		void insertarUnPrune(typename bintree<pair<T, altura> >::node & n);
		void erase(typename bintree<pair<T, altura> >::node & n);
		void swap(typename bintree<pair<T, altura> >::node & n1, typename bintree<pair<T, altura> >::node & n2);
		void clear();
};
#include "avl.hxx"
#endif
