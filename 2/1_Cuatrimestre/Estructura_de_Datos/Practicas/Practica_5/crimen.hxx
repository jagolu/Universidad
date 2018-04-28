#include <iostream>
#include <string>
#include "fecha.h"
#include "crimen.h"

using namespace std;

/**
@brief constructor primitivo
@post define un crimen vacio
*/
crimen::crimen():Date(){
	ID=0;
	CaseNumber=' ';
	IUCR=' ';
	PrimaryType=' ';
	Description=' ';
	LocalitationDescription=' ';
	Arrest=false;
	Domestic=false;
	Latitude=0.0;
	Longitude=0.0;
}
/**
@brief constructor copia de otro crimen
@param x el crimen que vamos a copiar
Nos inicializa nuestro crimen a una copia exacta de x
*/
crimen::crimen(const crimen& x){
	ID=x.ID;
	CaseNumber=x.CaseNumber;
	Date=x.Date;
	IUCR=x.IUCR;
	PrimaryType=x.PrimaryType;
	Description=x.Description;
	LocalitationDescription=x.LocalitationDescription;
	Arrest=x.Arrest;
	Domestic=x.Domestic;
	Latitude=x.Latitude;
	Longitude=x.Longitude;
}
/**
@brief Set de ID
@param id identificador que queremos asignar
Asigna id a nuestro ID
*/
void crimen::setID(long int & id){
	ID=id;
}
/**
@brief Set de CaseNumber
@param s Numero de caso que queremos asignar
Asigna s a nuestro CaseNumber
*/
void crimen::setCaseNumber(const string & s){
	CaseNumber=s;
}
/**
@brief Set de Date
@param d fecha que queremos asignar
Asigna d a nuestro Date
*/
void crimen::setDate(const fecha & d){
	Date=d;
}
/**
@brief Set de IUCR
@param i IUCR que queremos asignar
Asigna i a nuestro IUCR
*/
void crimen::setIUCR(const string & i){
	IUCR=i;
}
/**
@brief Set de PrimaryType
@param pt PrimaryType que queremos asignar
Asigna pt a nuestro PrimaryType
*/
void crimen::setPrimaryType(const string & pt){
	PrimaryType=pt;
}
/**
@brief Set de Description
@param d Descripcion que queremos asignar
Asigna d a nuestro Description
*/
void crimen::setDescription(const string & d){
	Description=d;
}
/**
@brief Set de LocalitationDescription
@param ld LocalitationDescription que queremos asignar
Asigna ld a nuestro LocalitationDescription
*/
void crimen::setLocalitationDescription(const string & ld){
	LocalitationDescription=ld;
}
/**
@brief Set de Arrest
@param a Arrest que queremos asignar
Asigna a a nuestro Arrest
*/
void crimen::setArrest(const bool & a){
	Arrest=a;
}
/**
@brief Set de Domestic
@param d Domestic que queremos asignar
Asigna d a nuestro Domestic
*/
void crimen::setDomestic(const bool & d){
	Domestic=d;
}
/**
@brief Set de Latitude
@param l Latitude que queremos asignar
Asigna l a nuestro Latitude
*/
void crimen::setLatitude(const float & l){
	Latitude=l;
}
/**
@brief Set de Longitude
@param l Longitude que queremos asignar
Asigna l a nuestro Longitude
*/
void crimen::setLongitude(const float & l){
	Longitude=l;
}
/**
@brief Get de ID
@return devuelve un long int con nuestro ID
@post no modifica el crimen
*/	  
long int crimen::getID( )const{
	return ID;
}
/**
@brief Get de CaseNumber
@return devuelve un string con nuestro CaseNumber
@post no modifica el crimen
*/
string crimen::getCaseNumber()const{
	return CaseNumber;
}
/**
@brief Get de Date
@return devuelve un objeto fecha de nuestro Date
@post no modifica el crimen
*/
fecha crimen::getDate()const{
	return Date;
}
/**
@brief Get de IUCR
@return devuelve un string con nuestro IUCR
@post no modifica el crimen
*/
string crimen::getIUCR()const{
	return IUCR;
}
/**
@brief Get de PrimaryType
@return devuelve un string con nuestro PrimaryType
@post no modifica el crimen
*/
string crimen::getPrimaryType()const{
	return PrimaryType;
}
/**
@brief Get de Description
@return devuelve un string con nuestro Description
@post no modifica el crimen
*/
string crimen::getDescription()const{
	return Description;
}
/**
@brief Get de LocalitationDescription
@return devuelve un string con nuestro LocalitationDescription
@post no modifica el crimen
*/
string crimen::getLocalitationDescription()const{
	return LocalitationDescription;
}
/**
@brief Get de Arrest
@return devuelve un booleano con nuestro Arrest
@post no modifica el crimen
*/
bool crimen::getArrest()const{
	return Arrest;
}
/**
@brief Get de Domestic
@return devuelve un booleano con nuestro Domestic
@post no modifica el crimen
*/
bool crimen::getDomestic()const{
	return Domestic;
}
/**
@brief Get de Latitude
@return devuelve un double con nuestro Latitude
@post no modifica el crimen
*/
float crimen::getLatitude()const{
	return Latitude;
}
/**
@brief Get de Longitude
@return devuelve un double con nuestro Longitude
@post no modifica el crimen
*/
float crimen::getLongitude()const{	
	return Longitude;
}
/**
@brief Operador de igual a
@param c El crimen que vamos a comparar
Nos dice si dos crimenes son iguales
@post no modifica el crimen
*/
crimen & crimen::operator=(const crimen & c){
	if(this!=&c){
		this->ID=c.ID;
		this->CaseNumber=c.CaseNumber;
		this->Date=c.Date;
		this->IUCR=c.IUCR;
		this->PrimaryType=c.PrimaryType;
		this->Description=c.Description;
		this->LocalitationDescription=c.LocalitationDescription;
		this->Arrest=c.Arrest;
		this->Domestic=c.Domestic;
		this->Latitude=c.Latitude;
		this->Longitude=c.Longitude;
	}
	return *this;
}
/**
@brief Operador de menor estricto
@param x El crimen que vamos a comparar
Nos dice si un crimen es menor que otro
@post no modifica el crimen
*/
bool crimen::operator==(const crimen & x) const{
	if(ID==x.ID){
		return true;
	}
	else{
		return false;
	}
}
/**
@brief Operador de menor estricto
@param x El crimen que vamos a comparar
Nos dice si un crimen es mayor que otro
@post no modifica el crimen
*/
bool crimen::operator<(const crimen & x) const{
	if(ID<x.ID){
		return true;
	}	
	else{
		return false;
	}
}	

/**
@brief Operador salida
@param c El crimen que vamos a mostrar
@param os El flujo por donde vamos a mostrar el crimen
Nos muestra un crimen por un flujo
@post no modifica el crimen
*/
ostream& operator<< ( ostream& os, const crimen& c){
	os<<c.getID()<<","<<c.getCaseNumber()<<","<<c.getDate()<<","<<c.getIUCR()<<","<<c.getPrimaryType()<<","<<c.getDescription()<<","<<c.getLocalitationDescription()<<","<<c.getArrest()<<","<<c.getDomestic()<<","<<c.getLatitude()<<","<<c.getLongitude();
	return os;
}


/** 
@brief Transforma un string a un objeto tipo crimen
@param s string con los datos del crimen
@return devuelve un objeto tipo crimen con los parametros del string en c
*/	
crimen::crimen(const string & s){
	int i=0;
	string aux;
	int j=0;
	for(i=0,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	int id=atoi (aux.c_str());
	long int id2=id;
	setID(id2);
	aux.erase(0,aux.size());
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	setCaseNumber(aux);
	aux.erase(0,aux.size());
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	fecha f(aux);
	setDate(f);
	aux.erase(0,aux.size());
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
	}
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	setIUCR(aux);
	aux.erase(0,aux.size());
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	setPrimaryType(aux);
	aux.erase(0,aux.size());
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	setDescription(aux);
	aux.erase(0,aux.size());
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	setLocalitationDescription(aux);
	aux.erase(0,aux.size());
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	bool b;
	if(aux=="true"){
		b=true;
	}
	else{
		b=false;
	}
	setArrest(b);
	aux.erase(0,aux.size());
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	if(aux=="true"){
		b=true;
	}
	else{
		b=false;
	}
	setDomestic(b);
	aux.erase(0,aux.size());
	
	for(i=i+1,j=0;j<9;i++){
		if(s[i]==','){
			j++;
		}
	}
	
	for(i=i,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	double numero = atof(aux.c_str());
	setLatitude(numero);
	aux.erase(0,aux.size());
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	numero = atof(aux.c_str());
	setLongitude(numero);
	aux.erase(0,aux.size());
}
