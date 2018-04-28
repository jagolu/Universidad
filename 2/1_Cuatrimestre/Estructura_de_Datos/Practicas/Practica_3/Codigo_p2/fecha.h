#ifndef _FECHA_H_
#define _FECHA_H_
#include <string>
#include <iostream>
using namespace std;
class fecha {
private:
  int  sec;
  int  min;
  int  hour;
  int  mday;
  int  mon;
  int  year;
  friend  ostream& operator<< ( ostream& os, const fecha & f);	
public:
	fecha ();
	fecha (const string & s);
	fecha(const fecha & f);
	
	string toString( ) const;
	fecha & operator=(const fecha & f);
	fecha & operator=(const string & s);

	bool operator==(const fecha & f) const;
	bool operator<(const fecha & f)const;
	bool operator>(const fecha & f) const;
	bool operator<=(const fecha & f)const;
	bool operator>=(const fecha & f) const;
	bool operator!=(const fecha & f)const;	
};
ostream& operator<< ( ostream& os, const fecha & f);
#include "fecha.hxx"
#endif
