#include <iostream>
#include <string>
#include <vector>
#include "fecha.h"
#include "crimen.h"
#include "conjunto.h"

using namespace std;

typedef crimen entrada;
typedef unsigned int size_type;
/**
@brief Chequea el Invariante de la representacion 
@return true si el invariante es correcto, falso en caso contrario
*/
bool conjunto::cheq_rep( ) const{
	bool devolver=true;
	for(int i=0;i<tamano;i++){
		if(vc.at(i).getID()<=0){
			devolver=false;
		}
	}
	for(int i=0;i<tamano-1;i++){
		if(vc.at(i).getID()>=vc.at(i+1).getID()){
			devolver=false;
		}
	}
	return devolver;
}
/** 
@brief constructor primitivo. 
@post define la entrada nula como el par ("",-1)
*/
conjunto::conjunto( ){
	vc.reserve(1);
	crimen a;
	vc.push_back(a);
	tamano=0;
}
/**
@brief constructor de copia
@param[in] d conjunto a copiar
*/
conjunto::conjunto (const conjunto & d){
	vc.clear();
	vc.resize(d.tamano);
	vc=d.vc;
	tamano=d.tamano;
}
/**
@brief busca un crimen en el conjunto	
@param id identificador del crimen  buscar
@return Si existe una entrada en el conjunto devuelve un par con una copia de la entrada en el conjunto y con el segundo valor a true. Si  no se encuentra devuelve la entrada con la definicion por defecto y false 
@post no modifica el conjunto.
*/
pair<conjunto::entrada,bool>  conjunto::findID( const long int & id) const{
	int arriba=tamano-1;
	int abajo=0;
	int centro;
	int indice;
	bool encontrado=false;
	while(abajo<=arriba){
		centro=(arriba+abajo)/2;
		if(vc.at(centro).getID()==id){
			indice=centro;
			abajo=arriba+1;
			encontrado=true;	
		}
		else{
			if(id<vc.at(centro).getID()){
			
				arriba=centro-1;
			}
			else{
				abajo=centro+1;
			}
		}
	}
	if(!encontrado){
		indice=-1;
	}
	if(indice!=-1){
		conjunto::entrada a(vc.at(indice));
		pair<conjunto::entrada,bool> olala(a,true);
		return olala;
	}
	else{
		entrada a;
		pair<conjunto::entrada,bool> olala(a,false);
		return olala;
	}
}
/**
@brief busca los crimenes con el mismo codigo IUCR
@param icur identificador del crimen  buscar
@return Devuelve un  conjunto con todos los crimenes con el codigo IUCR. Si no existe ninguno devuelve el conjunto vacio.
@post no modifica el conjunto.
*/
conjunto conjunto::findIUCR( const string & iucr) const{
	conjunto n;
	for(int i=0;i<tamano;i++){
		if(vc.at(i).getIUCR()==iucr){
			n.insert(vc.at(i));
		}
	}
	return n;
}
/**
@brief busca los crimenes que contienen una determinada descripcion 
@param descr string que representa la descripcion del delito buscar
@return Devuelve un  conjunto con todos los crimenes  que contengan descr en su descripcionR. Si no existe ninguno devuelve el conjunto vacio.
@post no modifica el conjunto.
*/	
conjunto  conjunto::findDESCR( const string & descr) const{
	conjunto n;	
	for(int i=0;i<tamano;i++){
		if(vc.at(i).getDescription()==descr){
			n.insert(vc.at(i));
		}
	}
	return n;
}/**
@brief Inserta una entrada en el conjunto
@param e entrada a insertar
@return true si la entrada se ha podido insertar con éxito, esto es, no existe un delito con igual ID en el conjunto. False en caso contrario
@post 	 Si e no esta en el conjunto, el size() sera incrementado en 1.
*/
bool conjunto::insert( const conjunto::entrada & e){
	bool esta=true;
	int indice=-1;
	for(int i=0;i<tamano;i++){
		if(vc.at(i).getID()==e.getID()){
			esta=false;
		}
		else if(vc.at(i).getID()<e.getID()){
			indice=i;
		}
	}
	if(esta){
		if(indice==-1){
			tamano++;
			vector<conjunto::entrada>aux;
			aux.reserve(tamano);
			aux.push_back(e);
			for(int i=0;i<tamano-1;i++){
				aux.push_back(vc.at(i));
			}
			vc.clear();
			vc.resize(tamano);
			vc=aux;
		}
		else{
			tamano++;
			vector<conjunto::entrada>aux;
			aux.reserve(tamano);
			for(int i=0;i<tamano-1;i++){
				if(i==indice){
					aux.push_back(vc.at(i));
					aux.push_back(e);
				}
				else{
					aux.push_back(vc.at(i));
				}
			}
			vc.clear();
			vc.resize(tamano);
			vc=aux;
		}
	}
	return esta;
}
/**
@brief Inserta una entrada en el conjunto
@param id entrada con la identificacion id a insertar
@return true si la entrada se ha podido insertar con éxito, esto es, no existe un delito con igual ID en el conjunto. False en caso contrario
@post 	 Si e no esta en el conjunto, el size() sera incrementado en 1.
*/
bool conjunto::erase(const long int & id){
	bool devolver=false;
	vector<entrada>aux;
	for(int i=0;i<tamano;i++){
		if(vc.at(i).getID()!=id){
			aux.push_back(vc.at(i));
		}
		else{
			devolver=true;
		}
	}
	if(devolver){
		tamano--;
		vc.clear();
		vc=aux;
	}
	return devolver;
}  
/**
@brief Inserta una entrada en el conjunto
@param e entrada  a insertar
@return true si la entrada se ha podido insertar con éxito, esto es, no existe un delito con igual ID en el conjunto. False en caso contrario
@post 	 Si e no esta en el conjunto, el size() sera incrementado en 1.
*/ 
bool conjunto::erase(const  conjunto::entrada & e){
	bool devolver=false;
	vector<conjunto::entrada>aux;
	for(int i=0;i<tamano;i++){
		if(vc.at(i).getID()!=e.getID()){
			aux.push_back(vc.at(i));
		}
		else{
			devolver=true;
		}
	}
	if(devolver){
		tamano--;
		vc.clear();
		vc=aux;
	}
	return devolver;
}
/**
@brief operador de asignación
@param[in] org conjunto  a copiar.
Crea un conjunto duplicado exacto de org.
*/
conjunto & conjunto::operator=( const conjunto & org){
	if(this!=&org){
		this->vc.clear();
		this->vc=org.vc;
		this->tamano=org.tamano;
	}
	return *this;
}
/** 
@brief numero de entradas en el conjunto
@post  No se modifica el conjunto.
*/
size_type conjunto::size() const{
	return tamano;
}
/** @brief vacia
Chequea si el conjunto esta vacio (size()==0)
*/
bool conjunto::empty() const{
	if(tamano==0){
		return true;
	}
	else{
		return false;
	}
}
/**
@brief imprime todas las entradas del conjunto 
@post  No se modifica el conjunto.
@todo implementar esta funcion
*/
ostream &  operator << ( ostream & sal, const conjunto & D){
	for(int i=0;i<D.tamano;i++){
		sal<<D.vc.at(i)<<endl<<endl<<endl<<endl<<endl;
	}
	return sal;
}
