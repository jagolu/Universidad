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
    for(int i=0;i<20;i++)
      { getline(fe,cadena,'\n');
       	if (!fe.eof()) {
	   //cout << "leo:: "<< cadena << endl;
	   crimen aux(cadena);
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
	//************ITERATOR************************
	for(conjunto::iterator i=ChicagoDB.begin();i!=ChicagoDB.end();i++){
		cout<<(*i)<<endl;
	}
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	//************CONST_ITERATOR************************
	for(conjunto::const_iterator i=ChicagoDB.cbegin();i!=ChicagoDB.cend();i++){
		cout<<(*i)<<endl;
	}
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	//************ARREST_ITERATOR************************
	for(conjunto::arrest_iterator i=ChicagoDB.abegin();i!=ChicagoDB.aend();i++){
		cout<<(*i)<<endl;
	}
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	//************CONST_ARREST_ITERATOR************************
	for(conjunto::const_arrest_iterator i=ChicagoDB.cabegin();i!=ChicagoDB.caend();i++){
		cout<<(*i)<<endl;
	}
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	long int a1, a2;
	cout<<"Introduzca las ID a buscar: \n";
	cin>>a1;
	cin>>a2;
	conjunto::iterator i=ChicagoDB.find(a1);
	conjunto::iterator i2=ChicagoDB.find(a2);
	conjunto::const_iterator j=ChicagoDB.find(a1);
	conjunto::const_iterator j2=ChicagoDB.find(a2);
	cout<<"Busqueda con iterator:\n";
	cout<<"1----->"<<(*i)<<endl;
	if(i2==ChicagoDB.end()){
		cout<<"2----->No esta\n";
	}
	cout<<"Busqueda con const_iterator:\n";
	cout<<"1----->"<<(*j)<<endl;
	if(j2==ChicagoDB.cend()){
		cout<<"2----->No esta\n";
	}
	













   return 0;
}
