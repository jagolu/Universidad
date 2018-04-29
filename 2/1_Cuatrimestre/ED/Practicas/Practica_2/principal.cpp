#include "fecha.h"
#include "crimen.h"
#include "conjunto.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;
	

/** 
@brief Transforma un string a un objeto tipo crimen
@param s string con los datos del crimen
@return devuelve un objeto tipo crimen con los parametros del string en c
*/	
crimen toCrimen(string s){
	crimen c;
	int i=0;
	string aux;
	int j=0;
	for(i=0,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	int id=atoi (aux.c_str());
	long int id2=id;
	c.setID(id2);
	aux.erase(0,aux.size());
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	c.setCaseNumber(aux);
	aux.erase(0,aux.size());
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	fecha f(aux);
	c.setDate(f);
	aux.erase(0,aux.size());
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
	}
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	c.setIUCR(aux);
	aux.erase(0,aux.size());
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	c.setPrimaryType(aux);
	aux.erase(0,aux.size());
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	c.setDescription(aux);
	aux.erase(0,aux.size());
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	c.setLocalitationDescription(aux);
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
	c.setArrest(b);
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
	c.setDomestic(b);
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
	c.setLatitude(numero);
	aux.erase(0,aux.size());
	
	for(i=i+1,j=0;s[i]!=',';i++,j++){
		aux.push_back(s[i]);
	}
	numero = atof(aux.c_str());
	c.setLongitude(numero);
	aux.erase(0,aux.size());
	return c;	
}
/** 
@brief lee un fichero de delitos, linea a linea
@param[in] s nombre del fichero
@param[in,out] C conjunto sobre el que se lee
@return true si la lectura ha sido correcta, false en caso contrario
*/
bool load(conjunto &  C, const string & s) {
 ifstream fe;
 string cadena;

 cout << "Abrimos "<< s << endl;
 fe.open(s.c_str(), ifstream::in);
 if (fe.fail())    
 {
   cerr << "Error al abrir el fichero " << s << endl;
 } else {
   getline(fe,cadena,'\n'); //leo la cabecera del fichero
   cout << cadena << endl;
    while ( !fe.eof() )
      { getline(fe,cadena,'\n');
       	if (!fe.eof()) {
	   cout << "leo:: "<< cadena << endl;
	   crimen aux=toCrimen(cadena);
           C.insert(aux);
         }
     }
    fe.close();
    return true;
    } // else
  fe.close();
  return false;
 }

int main()
{
    conjunto ChicagoDB;
    crimen d;
    fecha f;
 
    

    load(ChicagoDB, "crimenes.csv");

   return 0;
}
