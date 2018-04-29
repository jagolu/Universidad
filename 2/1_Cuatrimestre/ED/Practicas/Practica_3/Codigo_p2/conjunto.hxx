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
		sal<<D.vc.at(i)<<endl;	
	}
	return sal;
}

///////////////////////ITERATOR//////////////////////

conjunto::iterator conjunto::begin(){
	conjunto::iterator sal;
	sal.itv=vc.begin();
	return sal;
}
conjunto::iterator conjunto::end(){
	conjunto::iterator sal;
	sal.itv=vc.end();
	return sal;
}
conjunto::iterator::iterator(){}
conjunto::iterator::iterator (const conjunto::iterator & it){
	itv=it.itv;
}
const conjunto::entrada & conjunto::iterator::operator*()const{
	return *itv;
}
conjunto::iterator conjunto::iterator::operator++(int){
	conjunto::iterator i(*this);
	itv++;
	return i;
}
conjunto::iterator & conjunto::iterator::operator++(){
	itv++;
	return *this;
}
conjunto::iterator conjunto::iterator::operator--(int){
	conjunto::iterator i(*this);
	itv--;
	return i;
}
conjunto::iterator & conjunto::iterator::operator--(){
	itv--;
	return *this;
}
bool conjunto::iterator::operator==(const conjunto::iterator & it){
	if(itv==it.itv){
		return true;
	}
	else{
		return false;
	}
}
bool conjunto::iterator::operator!=(const conjunto::iterator & it){
	if(itv!=it.itv){
		return true;
	}
	else{
		return false;
	}
}

//////////////////CONST_ITERATOR////////////////////////

conjunto::const_iterator conjunto::cbegin()const{
	conjunto::const_iterator sal;
	sal.c_itv=vc.begin();
	return sal;
}
conjunto::const_iterator conjunto::cend()const{
	conjunto::const_iterator sal;
	sal.c_itv=vc.end();
	return sal;
}
conjunto::const_iterator::const_iterator(){}
conjunto::const_iterator::const_iterator(const conjunto::const_iterator & it){
	c_itv=it.c_itv;
}	
conjunto::const_iterator::const_iterator(const conjunto::iterator & it){
	c_itv=it.itv;
}
const conjunto::entrada & conjunto::const_iterator::operator*()const{
	return *c_itv;
}
conjunto::const_iterator conjunto::const_iterator::operator++(int){
	conjunto::const_iterator i(*this);
	c_itv++;
	return i;
}
conjunto::const_iterator & conjunto::const_iterator::operator++(){
	c_itv++;
	return *this;
}
conjunto::const_iterator conjunto::const_iterator::operator--(int){
	conjunto::const_iterator i(*this);
	c_itv--;
	return i;
}
conjunto::const_iterator & conjunto::const_iterator::operator--(){
	c_itv--;
	return *this;
}
bool conjunto::const_iterator::operator==(const conjunto::const_iterator & it){
	if(c_itv==it.c_itv){
		return true;
	}
	else{
		return false;
	}
}
bool conjunto::const_iterator::operator!=(const conjunto::const_iterator & it){
	if(c_itv!=it.c_itv){	
		return true;
	}
	else{
		return false;
	}
}

/////////////////////////ARREST_ITERATOR///////////////////////////////

conjunto::arrest_iterator conjunto::abegin(){
	conjunto::arrest_iterator sal;
	sal.c=this;
	bool encontrado=false;
	for(vector<entrada>::iterator i=vc.begin();i!=vc.end() && !encontrado;i++){
		if( (*i).getArrest() ){
			encontrado=true;
			sal.itv=i;
		}
	}
	return sal;
}
conjunto::arrest_iterator conjunto::aend(){
	conjunto::arrest_iterator sal;
	sal.c=this;
	sal.itv=vc.end();
	return sal;
}
conjunto::arrest_iterator::arrest_iterator(){}
conjunto::arrest_iterator::arrest_iterator(const conjunto::arrest_iterator & it){
	itv=it.itv;
	c=it.c;
}
const conjunto::entrada & conjunto::arrest_iterator::operator*()const{
	return *itv;
}
conjunto::arrest_iterator conjunto::arrest_iterator::operator++(int){
	conjunto::arrest_iterator sal(*this);
	bool encontrado=false;
	for(;itv!=c->vc.end() && !encontrado;itv++){
		if( (*itv).getArrest() ){
			encontrado=true;
		}
	}
	if(!encontrado){
		itv=c->vc.end();
	}
	return sal;
}
conjunto::arrest_iterator & conjunto::arrest_iterator::operator++(){
	bool encontrado=false;
	for(;itv!=c->vc.end() && !encontrado;itv++){
		if( (*itv).getArrest() ){
			encontrado=true;
		}
	}
	if(!encontrado){
		itv=c->vc.end();
	}
	return *this;
}
conjunto::arrest_iterator conjunto::arrest_iterator::operator--(int){
	conjunto::arrest_iterator i(*this);
	bool encontrado=false;
	while(itv!=c->vc.begin()){
		if( (*itv).getArrest() && !encontrado){
			encontrado=true;
		}
		itv--;
	}
	if(!encontrado){
		itv=c->vc.begin();
	}
	return i;
}
conjunto::arrest_iterator & conjunto::arrest_iterator::operator--(){
	bool encontrado=false;
	while(itv!=c->vc.begin()){
		if( (*itv).getArrest() && !encontrado){
			encontrado=true;
		}
		itv--;
	}
	if(!encontrado){
		itv=c->vc.begin();
	}
	return *this;
}
bool conjunto::arrest_iterator::operator==(const conjunto::arrest_iterator & it){
	if(itv==it.itv){
		return true;
	}
	else{
		return false;
	}
}
bool conjunto::arrest_iterator::operator!=(const conjunto::arrest_iterator & it){
	if(itv!=it.itv){
		return true;
	}
	else{
		return false;
	}
}
///////////////////////CONST_ARREST_ITERATOR///////////////////////

conjunto::const_arrest_iterator conjunto::cabegin()const{
	conjunto::const_arrest_iterator sal;
	*sal.c=*this;
	bool encontrado=false;
	for(vector<entrada>::const_iterator i=vc.begin();i!=vc.end() && !encontrado;i++){
		if( (*i).getArrest() ){
			encontrado=true;
			sal.c_itv=i;
		}
	}
	return sal;
}
conjunto::const_arrest_iterator conjunto::caend()const{
	conjunto::const_arrest_iterator sal;
	*sal.c=*this;
	sal.c_itv=vc.end();
	return sal;
}
conjunto::const_arrest_iterator::const_arrest_iterator(){}
conjunto::const_arrest_iterator::const_arrest_iterator(const conjunto::const_arrest_iterator & it){
	c_itv=it.c_itv;
	c=it.c;
}
const conjunto::entrada & conjunto::const_arrest_iterator::operator*()const{
	return *c_itv;
}
conjunto::const_arrest_iterator conjunto::const_arrest_iterator::operator++(int){
	conjunto::const_arrest_iterator sal(*this);
	bool encontrado=false;
	for(;c_itv!=c->vc.end() && !encontrado;c_itv++){
		if( (*c_itv).getArrest() ){
			encontrado=true;
		}
	}
	if(!encontrado){
		c_itv=c->vc.end();
	}
	return sal;
}
conjunto::const_arrest_iterator & conjunto::const_arrest_iterator::operator++(){
	bool encontrado=false;
	for(;c_itv!=c->vc.end() && !encontrado;c_itv++){
		if( (*c_itv).getArrest() ){
			encontrado=true;
		}
	}
	if(!encontrado){
		c_itv=c->vc.end();
	}
	return *this;
}
conjunto::const_arrest_iterator conjunto::const_arrest_iterator::operator--(int){
	conjunto::const_arrest_iterator i(*this);
	bool encontrado=false;
	while(c_itv!=c->vc.begin()){
		if( (*c_itv).getArrest() && !encontrado){
			encontrado=true;
		}
		c_itv--;
	}
	if(!encontrado){
		c_itv=c->vc.begin();
	}
	return i;
}
conjunto::const_arrest_iterator & conjunto::const_arrest_iterator::operator--(){
	bool encontrado=false;
	while(c_itv!=c->vc.begin()){
		if( (*c_itv).getArrest() && !encontrado){
			encontrado=true;
		}
		c_itv--;
	}
	if(!encontrado){
		c_itv=c->vc.begin();
	}
	return *this;
}
bool conjunto::const_arrest_iterator::operator==(const conjunto::const_arrest_iterator & it){
	if(c_itv==it.c_itv){
		return true;
	}
	else{
		return false;
	}
}
bool conjunto::const_arrest_iterator::operator!=(const conjunto::const_arrest_iterator & it){
	if(c_itv!=it.c_itv){
		return true;
	}
	else{
		return false;
	}
}
///////////////////////DESCRIPTION_ITERATOR///////////////////////////
	 
conjunto::description_iterator conjunto::dbegin(const string & descr){
	conjunto::description_iterator sal;
	sal.descr=descr;
	sal.c=this;
	return sal;
}
conjunto::description_iterator conjunto::dend(const string & descr){
	conjunto::description_iterator sal;
	sal.descr=descr;
	sal.c=this;
	return sal;
}

conjunto::description_iterator::description_iterator(){}
conjunto::description_iterator::description_iterator(const conjunto::description_iterator & it){
	this->descr=it.descr;
	itv=it.itv;
	c=it.c;
}
const conjunto::entrada & conjunto::description_iterator::operator*() const{
	return *itv;
}
conjunto::description_iterator conjunto::description_iterator::operator++( int ){
	conjunto::description_iterator sal(*this);
	bool encontrado=false;
	for(;itv!=c->vc.end() && !encontrado;itv++){
		if( (*itv).getDescription()==descr ){
			encontrado=true;
		}
	}
	if(!encontrado){
		itv=c->vc.end();
	}
	return sal;
}
conjunto::description_iterator & conjunto::description_iterator::operator++(){
	bool encontrado=false;
	for(;itv!=c->vc.end() && !encontrado;itv++){
		if( (*itv).getDescription()==descr ){
			encontrado=true;
		}
	}
	if(!encontrado){
		itv=c->vc.end();
	}
	return *this;
}
conjunto::description_iterator conjunto::description_iterator::operator--(int){
	conjunto::description_iterator i(*this);
	bool encontrado=false;
	while(itv!=c->vc.begin()){
		if( (*itv).getArrest() && !encontrado){
			encontrado=true;
		}
		itv--;
	}
	if(!encontrado){
		itv=c->vc.begin();
	}
	return i;
}
conjunto::description_iterator & conjunto::description_iterator::operator--(){
	conjunto::description_iterator i(*this);
	bool encontrado=false;
	while(itv!=c->vc.begin()){
		if( (*itv).getArrest() && !encontrado){
			encontrado=true;
		}
		itv--;
	}
	if(!encontrado){
		itv=c->vc.begin();
	}
	return *this;
}
bool conjunto::description_iterator::operator==(const conjunto::description_iterator & it){
	if(itv==it.itv){
		return true;
	}
	else{
		return false;
	}
}
bool conjunto::description_iterator::operator!=(const conjunto::description_iterator & it){
	if(itv!=it.itv){
		return true;
	}
	else{
		return false;
	}
}

//////////////////////CONST_DESCRIPTION_ITERATOR///////////////////
	 
conjunto::const_description_iterator conjunto::cdbegin(const string & descr)const{
	conjunto::const_description_iterator sal;
	sal.descr=descr;
	*sal.c=*this;
	return sal;
}
conjunto::const_description_iterator conjunto::cdend(const string & descr)const{
	conjunto::const_description_iterator sal;
	sal.descr=descr;
	*sal.c=*this;
	return sal;
}

conjunto::const_description_iterator::const_description_iterator(){}
conjunto::const_description_iterator::const_description_iterator(const conjunto::const_description_iterator & it){
	this->descr=it.descr;
	c_itv=it.c_itv;
	c=it.c;
}
const conjunto::entrada & conjunto::const_description_iterator::operator*() const{
	return *c_itv;
}
conjunto::const_description_iterator conjunto::const_description_iterator::operator++( int ){
	conjunto::const_description_iterator sal(*this);
	bool encontrado=false;
	for(;c_itv!=c->vc.end() && !encontrado;c_itv++){
		if( (*c_itv).getDescription()==descr ){
			encontrado=true;
		}
	}
	if(!encontrado){
		c_itv=c->vc.end();
	}
	return sal;
}
conjunto::const_description_iterator & conjunto::const_description_iterator::operator++(){
	bool encontrado=false;
	for(;c_itv!=c->vc.end() && !encontrado;c_itv++){
		if( (*c_itv).getDescription()==descr ){
			encontrado=true;
		}
	}
	if(!encontrado){
		c_itv=c->vc.end();
	}
	return *this;
}
conjunto::const_description_iterator conjunto::const_description_iterator::operator--(int){
	conjunto::const_description_iterator i(*this);
	bool encontrado=false;
	while(c_itv!=c->vc.begin()){
		if( (*c_itv).getArrest() && !encontrado){
			encontrado=true;
		}
		c_itv--;
	}
	if(!encontrado){
		c_itv=c->vc.begin();
	}
	return i;
}
conjunto::const_description_iterator & conjunto::const_description_iterator::operator--(){
	conjunto::const_description_iterator i(*this);
	bool encontrado=false;
	while(c_itv!=c->vc.begin()){
		if( (*c_itv).getArrest() && !encontrado){
			encontrado=true;
		}
		c_itv--;
	}
	if(!encontrado){
		c_itv=c->vc.begin();
	}
	return *this;
}
bool conjunto::const_description_iterator::operator==(const conjunto::const_description_iterator & it){
	if(c_itv==it.c_itv){
		return true;
	}
	else{
		return false;
	}
}
bool conjunto::const_description_iterator::operator!=(const conjunto::const_description_iterator & it){
	if(c_itv!=it.c_itv){
		return true;
	}
	else{
		return false;
	}
}


//*********************FIND POR ITERATORS********************
conjunto::iterator conjunto::find(const long int & s){
	conjunto::iterator i=begin();
	bool encontrado=false;
	for(;i!=end() && !encontrado;i++){
		if((*i).getID()==s){
			encontrado=true;
		}
	}
	if(encontrado){
		return i;
	}
	else{
		return end();
	}
}
conjunto::const_iterator conjunto::find(const long int & s)const{
	conjunto::const_iterator i=cbegin();
	bool encontrado=false;
	for(;i!=cend() && !encontrado;i++){
		if((*i).getID()==s){
			encontrado=true;
		}
	}
	if(encontrado){
		return i;
	}
	else{
		return cend();
	}
}




