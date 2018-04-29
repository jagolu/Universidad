#ifndef _CRIMEN_H_
#define _CRIMEN_H_
#include <string>
#include <iostream>
#include "fecha.h"
using namespace std;
class crimen {
private:
  long int ID; 
  string CaseNumber;
  fecha Date;
  string IUCR;
  string PrimaryType;
  string Description;
  string LocalitationDescription;
  bool Arrest;
  bool Domestic;
  double Latitude;
  double Longitude;
public:
	crimen();
 	crimen(const crimen& x);
	crimen(const string& s);

 	void setID(long int & id);
 	void setCaseNumber(const string & s);
	void setDate(const fecha & d);
 	void setIUCR(const string & i);
 	void setPrimaryType(const string & pt);
 	void setDescription(const string & d);
 	void setLocalitationDescription(const string & ld);
 	void setArrest(const bool & a);
 	void setDomestic(const bool & d);
 	void setLatitude(const double & l);
 	void setLongitude(const double & l);

 	long int getID( )const;
 	string getCaseNumber()const;
 	fecha getDate()const;
 	string getIUCR()const;
 	string getPrimaryType()const;
 	string getDescription()const;
 	string getLocalitationDescription()const;
 	bool getArrest()const;
 	bool getDomestic()const;
 	double getLatitude()const;
 	double getLongitude()const;

 	crimen & operator=(const crimen & c);
 	bool operator==(const crimen & x) const;
 	bool operator<(const crimen & x) const;	
};
ostream& operator<< ( ostream& os, const crimen& c);
#include "crimen.hxx"
#endif
