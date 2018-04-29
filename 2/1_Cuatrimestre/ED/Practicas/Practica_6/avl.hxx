#include "bintree.h"
#include <iostream>
#include "avl.h"

using namespace std;


typedef int altura;

template <typename T>
int AVL<T>::max(T n1, T n2){
	if(n1>=n2){
		return n1;
	}
	else{
		return n2;
	}
}
template <typename T>
typename AVL<T>::altura AVL<T>::h(typename bintree<pair<T, AVL<T>::altura> >::node & n){
	int hh=0;
	if(!n.null()){
		hh=max( h(n.left()), h(n.right()) )+1;
	}
	return hh;
}
template <typename T>
typename AVL<T>::altura AVL<T>::h(typename bintree<pair<T, AVL<T>::altura> >::const_node & n){
	int hh=0;
	if(!n.null()){
		hh=max( h(n.left()), h(n.right()) )+1;
	}
	return hh;
}

//Constructores
template <typename T>
AVL<T>::AVL(){
	tama=0;
}
template <typename T>
AVL<T>::AVL(const AVL<T> & A){
	el_avl=A.el_avl;
	tama=A.tama;
}
//Operador de asignacion
template <typename T>
AVL<T> & AVL<T>::operator=(const AVL &A){
	if(this!=&A){
		el_avl=A;
	}
	return *this;
}


//Rotaciones
template <typename T>
void AVL<T>::insertarAltura(typename bintree<pair<T, altura> >::node & n){
	(*n).second=h(n);
}
template <typename T>
void AVL<T>::RSD(typename bintree<pair<T, altura> >::node & n){
	typename bintree<pair<T, altura> >::node padre=n.parent();
	typename bintree<pair<T, altura> >::node p=n;
	typename bintree<pair<T, altura> >::node q=p.left();
	typename bintree<pair<T, altura> >::node b=q.right();
	
	if(!padre.null())
		if(padre.right()==p){
			insertarAltura(q);
			padre.right()==q;
		}
		else{
			insertarAltura(q);
			padre.right()==q;
		}
	else{
		insertarAltura(q);
		el_avl.root()=q;
	}

	insertarAltura(b);
	insertarAltura(p);
	p.left()=b;
	q.right()=p;

	insertarAltura(q);
	p.parent()=q;
	if(!b.null()){
		insertarAltura(p);				
		b.parent()=p;
	}
	insertarAltura(padre);
	q.parent()=padre;

}

template <typename T>
void AVL<T>::RSI(typename bintree<pair<T, altura> >::node & n){
	typename bintree<pair<T, altura> >::node padre=n.parent();
	typename bintree<pair<T, altura> >::node p=n;
	typename bintree<pair<T, altura> >::node q=p.left();
	typename bintree<pair<T, altura> >::node b=q.right();

	if(!padre.null())
		if(padre.left()==p) {
			insertarAltura(b);
			padre.left()=b;
		}
		else{
			insertarAltura(b);
			padre.left()==b;
		}
	else{
		insertarAltura(b);
		el_avl.root()=b;
	}
	insertarAltura(q);
	insertarAltura(p);
	p.right()=q;
	p.left()=p;

	insertarAltura(b);
	p.parent()=b;
	if( !q.null()) {
		insertarAltura(p);
		q.parent()=p;
	}
	insertarAltura(padre);
	b.parent()=padre;
}
template <typename T>
void AVL<T>::RDD(typename bintree<pair<T, altura> >::node & n){
	typename bintree<pair<T, altura> >::node padre=n.parent();
	typename bintree<pair<T, altura> >::node p=n;
	typename bintree<pair<T, altura> >::node q=p.left();
	typename bintree<pair<T, altura> >::node r=q.right();
	typename bintree<pair<T, altura> >::node b=r.left();
	typename bintree<pair<T, altura> >::node c=r.right();
	
	if(!padre.null()){
		if(padre.right()==n){
			padre.right()=r;
			insertarAltura(padre.right());
		}
		else{
			padre.left()=r;
			insertarAltura(padre.left());
		}
	}
	else{
		el_avl.root()=r;
		insertarAltura(el_avl.root());
	}

	q.right()=b;
	p.left()=c;
	r.left()=q;
	r.right()=p;
	insertarAltura(q.right());
	insertarAltura(p.left());
	insertarAltura(r.left());
	insertarAltura(r.right());
	
	r.parent()=padre;
	p.parent()=r;
	q.parent()=r;
	insertarAltura(r.parent());
	insertarAltura(p.parent());
	insertarAltura(p.parent());
	if(!b.null()){
		b.parent()=q;
		insertarAltura(b.parent());
	}
	if(!c.null()){
		c.parent()=p;
		insertarAltura(c.parent());
	}
}
template <typename T>
void AVL<T>::RDI(typename bintree<pair<T, altura> >::node & n){
	typename bintree<pair<T, altura> >::node padre=n.parent();
	typename bintree<pair<T, altura> >::node p=n;
	typename bintree<pair<T, altura> >::node q=p.left();
	typename bintree<pair<T, altura> >::node r=q.right();
	typename bintree<pair<T, altura> >::node b=r.left();
	typename bintree<pair<T, altura> >::node c=r.right();
	
	if(!padre.null()){
		if(padre.left()==n){
			padre.left()=r;
			insertarAltura(padre.left());
		}
		else{
			padre.right()=r;
			insertarAltura(padre.right());
		}
	}
	else{
		el_avl.root()=r;
		insertarAltura(el_avl.root());
	}

	q.left()=c;
	p.right()=b;
	r.right()=r;
	r.left()=p;
	insertarAltura(q.left());
	insertarAltura(p.right());
	insertarAltura(r.right());
	insertarAltura(r.left());
	
	r.parent()=padre;
	p.parent()=r;
	q.parent()=r;
	insertarAltura(r.parent());
	insertarAltura(p.parent());
	insertarAltura(p.parent());
	if(!b.null()){
		b.parent()=p;
		insertarAltura(b.parent());
	}
	if(!c.null()){
		c.parent()=q;
		insertarAltura(c.parent());
	}
}
template <typename T>
void AVL<T>::reequilibradoInsercion(typename bintree<pair< T, altura> >::node & n){
	if(!n.null()){
		if( ((*n.left()).second-(*n.right()).second <=-2) && ( (*n.left().left()).second-(*n.left().right()).second<=-1 ) ){
			RSD(n);
		}
		else if(  ((*n.left()).second-(*n.right()).second <=-2) && ( (*n.left().left()).second-(*n.left().right()).second>=1 )  ){
			RDD(n);
		}
		else if(  ((*n.left()).second-(*n.right()).second >=2) && ( (*n.right().left()).second-(*n.right().right()).second<=-1 )  ){
			RDI(n);
		}
		else if(  ((*n.left()).second-(*n.right()).second >=2) && ( (*n.right().left()).second-(*n.right().right()).second>=1 ) ){
			RSI(n);
		}
		reequilibradoInsercion(n.left());
		reequilibradoInsercion(n.right());
	}
}
template <typename T>
void AVL<T>::reequilibradoBorrado(typename bintree<pair<T, altura> >::node & n){
	if(!n.null()){
		if( ((*n.left()).second-(*n.right()).second <=-2) && ( (*n.left().left()).second-(*n.left().right()).second<=-1 ) ){
			RSD(n);
		}
		else if( ((*n.left()).second-(*n.right()).second <=-2) && ( (*n.left().left()).second-(*n.left().right()).second==0 ) ){
			RSD(n);
		}
		else if(  ((*n.left()).second-(*n.right()).second <=-2) && ( (*n.left().left()).second-(*n.left().right()).second>=1 )  ){
			RDD(n);
		}
		else if(  ((*n.left()).second-(*n.right()).second >=2) && ( (*n.right().left()).second-(*n.right().right()).second<=-1 )  ){
			RDI(n);
		}
		else if( ((*n.left()).second-(*n.right()).second >=2) && ( (*n.right().left()).second-(*n.right().right()).second==0 ) ){
			RSI(n);
		}
		else if(  ((*n.left()).second-(*n.right()).second >=2) && ( (*n.right().left()).second-(*n.right().right()).second>=1 ) ){
			RSI(n);
		}
		reequilibradoBorrado(n.left());
		reequilibradoBorrado(n.right());
	}
}

//iterdores

//Capacidad
template <typename T>
bool AVL<T>::empty(){
	return el_avl.empty();
}
template <typename T>
int AVL<T>::size(){
	return el_avl.size();
}

//Operaciones
template <typename T>
typename bintree<pair<T, altura> >::node & AVL<T>::find(typename bintree<pair<T, altura> >::const_node & n1, typename bintree<pair<T, altura> >::const_node & n2){
	if(n1!=n2 && !n1.null()){
		find(n1.left(), n2);
		find(n1.right(), n2);
	}
	return n2;
}
template <typename T>
void AVL<T>::lower_bound2(typename bintree<pair<T, altura> >::node & n1, typename bintree<pair<T, altura> >::node & n2, typename bintree<pair<T, altura> >::node & n3){
	if(!n1.null()){
		if( (*n1).first<(*n3).first ){
			n2=n1;
			lower_bound2(n1.right(), n2, n3);
		}
		else{
			lower_bound2(n1.left(), n2, n3);
		}
	}
}
template <typename T>
typename bintree<pair<T, altura> >::node & AVL<T>::lower_bound(bintree<pair<T, altura> >arb, typename bintree<pair<T, altura> >::node & n2){
	typename bintree<pair<T, altura> >::node n=arb.root();
	lower_bound(arb.root(),n, n2);
	if((*n).first>=(*n2).first) return NULL;
	else return n;
}
template <typename T>
void AVL<T>::upper_bound2(typename bintree<pair<T, altura> >::node & n1, typename bintree<pair<T, altura> >::node & n2, typename bintree<pair<T, altura> >::node & n3){
	if(!n1.null()){
		if( (*n1).first==(*n3).first){
			n2=n1;
		}
		else if( (*n1).first> (*n3).first ){
			n2=n1;
			upper_bound2(n1.left(), n2, n3);
		}
		else{
			upper_bound2(n1.right(), n2, n3);
		}
	}
}
template <typename T>
typename bintree<pair<T, altura> >::node & upper_bound( bintree<pair<T, altura> >arb, typename bintree<pair<T, altura> >::node & n2){
	typename bintree<pair<T, altura> >::node n=arb.root();
	upper_bound(arb.root(), n, n2);
	if( (*n).first<(*n2).first) return NULL;
	else return n;
}
//Modificadores
template <typename T>
void AVL<T>::insert(const T & f){
	typename bintree<pair<T, altura> >::node n2;
	(*n2).first=f;
	typename bintree<pair<T, altura> >::node n=el_avl.root();
	bool hayIgual=false;
	while(!n.null()){
		if( (*n2).first > (*n).first ) n=n.right();
		else if ( (*n2).first <(*n).first) n=n.left();
		else{
			hayIgual=true;
			break;
		}
	}
	if(!hayIgual){
		n=n2;
		insertarAltura(n);
		reequilibradoInsercion(el_avl.root());
	}	
	tama++;			
}
template <typename T>
void AVL<T>::insertarUnPrune(typename bintree<pair<T, altura> >::node & n){
	if(!n.null()){
		insert( (*n).first );
		insertarUnPrune(n.left());
		insertarUnPrune(n.right());
	}
}
template <typename T>
void AVL<T>::erase(typename bintree<pair<T, altura> >::node & n){
	typename bintree<pair<T, altura> >::node n2=find(el_avl.root(), n);
	if(!n2.null()){
		bintree<pair<T, altura> >prunIzq;
		bintree<pair<T, altura> >prunDech;
		el_avl.prune_left(n2,prunIzq);
		el_avl.prune_right(n2,prunDech);
		insertarUnPrune(prunIzq.root());
		insertarUnPrune(prunDech.root());
		reequilibradoBorrado(el_avl.root());
	}
	tama--;
} 
template <typename T>
void AVL<T>::swap(typename bintree<pair<T, altura> >::node & n1, typename bintree<pair<T, altura> >::node & n2){
	n1=n2;
	insertarAltura(n1);
	insertarAltura(n2);
}
template <typename T>
void AVL<T>::clear(){
	el_avl.clear();
	tama=0;
}
