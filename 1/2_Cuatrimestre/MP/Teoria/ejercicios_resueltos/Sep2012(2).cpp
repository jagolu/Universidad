#include <iostream>
using namespace std;

struct Localizacion{
	double longitud, latitud, altura;
};
class Ruta{
private:
	Localizacion *locs;
	int n;
public:
	Ruta(){
		locs=new Localizacion[0];
		n=0;
	}
	~Ruta(){
		delete [] locs;
	}
	Ruta(const Ruta& r){
		locs=new Localizacion[r.n];
		n=r.n;
		for(int i=0;i<n;i++){
			locs[i]=r.locs[i];
		}
	}
	Ruta& operator=(const Ruta& r){
		if(&r!=this){
			delete [] this->locs;
			this->n=r.n;
			this->locs=new Localizacion[r.n];
			for(int i=0;i<this->n;i++){
				this->locs[i]=r.locs[i];
			}
		}
		return *this;
	}
	Ruta operator+(const Localizacion &l){
		Ruta l2;
		delete [] l2.locs;
		l2.locs=new Localizacion [this->n+1];
		for(int i=0;i<this->n;i++){
			l2.locs[i]=this->locs[i];
		}
		l2.locs[this->n].altura=l.altura;
		l2.locs[this->n].latitud=l.latitud;
		l2.locs[this->n].longitud=l.longitud;
		l2.n=this->n+1;
		return l2;
	}
	Ruta operator+(Ruta& r){
		Ruta l2;
		delete [] l2.locs;
		l2.locs=new Localizacion [this->n+1];
		for(int i=1;i<this->n;i++){
			l2.locs[i]=this->locs[i-1];
		}
};
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
