#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "fecha.h"

using namespace std;

/**
@brief constructor primitivo
@post define la fecha 01/01/2000 00:00:00
*/
fecha::fecha (){
	sec=0;
	min=0;
	hour=0;
	mday=1;
	mon=1;
	year=2000;
}
/**
@brief constructor copia de un string
@param s el string del cual se va a sacar la fecha y hora
Nos inicializa la fecha y hora a la misma que hay en s
*/
fecha::fecha (const string & s){
	int contador=0;
	string s2;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			s2.push_back(s[i]);
		}
		else if(s[i]=='/' || s[i]==':' || s[i]==' ' && contador<6){
			if(contador==0){
				mon=atoi(s2.c_str());
  	 			}
			else if(contador==1){
				mday=atoi (s2.c_str());
			}
			else if(contador==2){
				year=atoi (s2.c_str());
			}
			else if(contador==3){
				bool tarde=false;
				for(int i=0;i<s.size();i++){
					if(s[i]=='P'){
						tarde=true;
						hour=atoi (s2.c_str())+12;
					}
				}
				if(tarde==false){
					hour=atoi (s2.c_str());
				}
			}
			else if(contador==4){
				min=atoi (s2.c_str());
			}
			else if(contador==5){
				sec=atoi (s2.c_str());
			}
			contador++;
			s2.erase(0,s2.size());
		}
	}
}
/**
@brief Constructor copia de un objeto de la clase fecha
@param f El objeto fecha del cual se van a copiar los datos
*/
fecha::fecha(const fecha & f){
	sec=f.sec;
	min=f.min;
	hour=f.hour;
	mday=f.mday;
	mon=f.mon;
	year=f.year;
}
/**
@brief Transforma un objeto de la clase fecha a un string
@return devuelve un string del formato mm/dd/aaaa hh:mm:ss AM/PM
@post no modifica la fecha
*/
string fecha::toString( ) const{
	string la_fecha, cadena;
	cadena = static_cast<stringstream*>(&(ostringstream() << mon))->str();
	for(int i=0;i<cadena.size();i++){
		la_fecha.push_back(cadena[i]);
	}
	la_fecha.push_back('/');
	cadena.erase(0,cadena.size());
	cadena = static_cast<stringstream*>(&(ostringstream() << mday))->str();
	for(int i=0;i<cadena.size();i++){
		la_fecha.push_back(cadena[i]);
	}
	la_fecha.push_back('/');
	cadena.erase(0,cadena.size());
	cadena = static_cast<stringstream*>(&(ostringstream() << year))->str();
	for(int i=0;i<cadena.size();i++){
		la_fecha.push_back(cadena[i]);
	}
	cadena.erase(0,cadena.size());
	la_fecha.push_back(' ');
	if(hour>12){
		int hour2=hour-12;
		cadena = static_cast<stringstream*>(&(ostringstream() << hour2))->str();
		for(int i=0;i<cadena.size();i++){
			la_fecha.push_back(cadena[i]);
		}
		cadena.erase(0,cadena.size());
	}
	else{
		cadena = static_cast<stringstream*>(&(ostringstream() << hour))->str();
		for(int i=0;i<cadena.size();i++){
			la_fecha.push_back(cadena[i]);
		}
		cadena.erase(0,cadena.size());
	}
	la_fecha.push_back(':');
	cadena = static_cast<stringstream*>(&(ostringstream() << min))->str();
	for(int i=0;i<cadena.size();i++){
		la_fecha.push_back(cadena[i]);
	}
	cadena.erase(0,cadena.size());
	la_fecha.push_back(':');
	cadena = static_cast<stringstream*>(&(ostringstream() << sec))->str();
	for(int i=0;i<cadena.size();i++){
		la_fecha.push_back(cadena[i]);
	}
	la_fecha.push_back(' ');
	if(hour>12){
		la_fecha.push_back('P');
		la_fecha.push_back('M');
	}
	else{
		la_fecha.push_back('A');
		la_fecha.push_back('M');
	}
	return la_fecha;
}
/**
@brief Operador de asignacion
@param f El parametro de tipo fecha que vamos a igualar
Crea una fecha duplicado exacto de f
*/
fecha & fecha::operator=(const fecha & f){
	if(this!=&f){
		this->sec=f.sec;
		this->min=f.min;
		this->hour=f.hour;
		this->mday=f.mday;
		this->mon=f.mon;
		this->year=f.year;
	}
	return *this;
}
/**
@brief Operador de asignacion
@param s El parametro de tipo string que vamos a igualar
Crea una fecha duplicado exacto de s, pero en formato fecha
*/
fecha & fecha::operator=(const string & s){
	int contador=0;
	string s2;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			s2.push_back(s[i]);
		}
		else if(s[i]=='/' || s[i]==':' || s[i]==' ' && contador<6){
			if(contador==0){
				this->mon=atoi(s2.c_str());
  	 			}
			else if(contador==1){
				this->mday=atoi (s2.c_str());
			}
			else if(contador==2){
				this->year=atoi (s2.c_str());
			}
			else if(contador==3){
				bool tarde=false;
				for(int i=0;i<s.size();i++){
					if(s[i]=='P'){
						tarde=true;
						this->hour=atoi (s2.c_str())+12;
					}
				}
				if(tarde==false){
					this->hour=atoi (s2.c_str());
				}	
			}
			else if(contador==4){
				this->min=atoi (s2.c_str());
			}
			else if(contador==5){
				this->sec=atoi (s2.c_str());
			}
			contador++;
			s2.erase(0,s2.size());
		}
	}
	return *this;
}
/**
@brief Operador de igual a
@param f La fecha que vamos a comparar
Nos dice si dos fechas son iguales
@post no modifica la fecha
*/
bool fecha::operator==(const fecha & f) const{
	if(sec==f.sec && min==f.min && hour==f.hour && mday==f.mday && mon==f.mon && year==f.year){
		return true;
	}
	else{
		return false;
	}
}
/**
@brief Operador de menor estricto
@param f La fecha que vamos a comparar
Nos dice si una fecha es menor que otra
@post no modifica la fecha
*/
bool fecha::operator<(const fecha & f)const{
	if(year>f.year){
		return false;
	}
	else if(year<f.year){
		return true;
	}
	else{
		if(mon>f.mon){
			return false;
		}
		else if(mon<f.mon){
			return true;
		}
		else{
			if(mday>f.mday){
				return false;
			}
			else if(mday<f.mday){
				return true;
			}
			else{
				if(hour>f.hour){
					return false;
				}
				else if(hour<f.hour){
					return true;
				}
				else{
					if(min>f.min){
						return false;
					}
					else if(min<f.min){
						return true;
					}
					else{
						if(sec>f.sec){
							return false;
						}
						else if(sec==f.sec){
							return false;
						}
						else{
							return true;
						}
					}
				}
			}
		}
	}
}
/**
@brief Operador de menor estricto
@param f La fecha que vamos a comparar
Nos dice si una fecha es mayor que otra
@post no modifica la fecha
*/
bool fecha::operator>(const fecha & f) const{
	if(year<f.year){
		return false;
	}
	else if(year>f.year){
		return true;
	}
	else{
		if(mon<f.mon){
			return false;
		}
		else if(mon>f.mon){
			return true;
		}
		else{
			if(mday<f.mday){
				return false;
			}
			else if(mday>f.mday){
				return true;
			}
			else{
				if(hour<f.hour){
					return false;
				}
				else if(hour>f.hour){
					return true;
				}
				else{
					if(min<f.min){
						return false;
					}
					else if(min>f.min){
						return true;
					}
					else{
						if(sec<f.sec){
							return false;
						}
						else if(sec==f.sec){
							return false;
						}
						else{
							return true;
						}
					}
				}
			}
		}
	}
}
/**
@brief Operador de menor o igual
@param f La fecha que vamos a comparar
Nos dice si una fecha es menor o igual que otra
@post no modifica la fecha
*/
bool fecha::operator<=(const fecha & f)const{
	if(year>f.year){
		return false;
	}
	else if(year<f.year){
		return true;
	}
	else{
		if(mon>f.mon){
			return false;
		}
		else if(mon<f.mon){
			return true;
		}
		else{
			if(mday>f.mday){
				return false;
			}
			else if(mday<f.mday){
				return true;
			}
			else{
				if(hour>f.hour){
					return false;
				}
				else if(hour<f.hour){
					return true;
				}
				else{
					if(min>f.min){
						return false;
					}
					else if(min<f.min){
						return true;
					}
					else{
						if(sec>f.sec){
							return false;
						}
						else if(sec<=f.sec){
							return true;
						}
					}
				}
			}
		}
	}
}
/**
@brief Operador de mayor o igual
@param f La fecha que vamos a comparar
Nos dice si una fecha es mayor o igual que otra
@post no modifica la fecha
*/
bool fecha::operator>=(const fecha & f) const{
	if(year<f.year){
		return false;
	}
	else if(year>f.year){
		return true;
	}
	else{
		if(mon<f.mon){
			return false;
		}
		else if(mon>f.mon){
			return true;
		}
		else{
			if(mday<f.mday){
				return false;
			}
			else if(mday>f.mday){
				return true;
			}
			else{
				if(hour<f.hour){
					return false;
				}
				else if(hour>f.hour){
					return true;
				}
				else{
					if(min<f.min){
						return false;
					}
					else if(min>f.min){
						return true;
					}
					else{
						if(sec<f.sec){
							return false;
						}
						else if(sec>=f.sec){
							return false;
						}
					}
				}
			}
		}
	}
}
/**
@brief Operador distinto que
@param f La fecha que vamos a comparar
Nos dice si una fecha es distinta de otra
@post no modifica la fecha
*/
bool fecha::operator!=(const fecha & f)const{
	if(sec!=f.sec || min!=f.min || hour!=f.hour || mday!=f.mday || mon!=f.mon || year!=f.year){
		return true;
	}
	else{
		return false;
	}
}
/**
@brief Operador salida
@param f La fecha que vamos a mostrar
@param os El flujo por donde vamos a mostrar la fecha
Nos muestra una fecha por un flujo
@post no modifica la fecha
*/	
ostream& operator<< ( ostream& os, const fecha & f){
 	os<<f.mon<<"/"<<f.mday<<"/"<<f.year<<" ";
	if(f.hour>12){
		os<<f.hour-12<<":"<<f.min<<":"<<f.sec<<" "<<"PM";
	}
	else{
		os<<f.hour<<":"<<f.min<<":"<<f.sec<<" "<<"AM";	
	}
	return os;
}
