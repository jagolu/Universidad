#include <iostream>
#include <stdio.h>
#include <string.h>

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
		locs=new Localizacion [r.n];
		n=r.n;
		for(int i=0;i<n;i++){
			locs[i]=r.locs[i];
		}
	}
	Ruta& operator=(const Ruta& r){
		if(&r!=this){
			delete [] this->locs;
			this->locs=new Localizacion [r.n];
			this->n=r.n;
			for(int i=0;i<this->n;i++){
				this->locs[i]=r.locs[i];
			}
		}
		return *this;
	}
	friend Ruta operator+(const Ruta& r, const Localizacion& l);
	friend Ruta operator+(const Localizacion& l, const Ruta& r);
	bool Leer(std::istream& is, Ruta& r){
		if(is){
			char a[100];
			is.getline(a,100);
			if(strcmp(a,"RUTA-MP")==0){
				int nn;
				is>>nn;
				r.n=nn;
				delete [] r.locs;
				r.locs=new Localizacion [nn];
				for(int i=0;i<nn;i++){
					Localizacion l2;
					is>>l2.longitud>>l2.latitud>>l2.altura;
					r.locs[i]=l2;
				}
				return is;
			}
			else return false;
		}
		else return false;
	}
	bool Escribir(std::ostream& os, const Ruta& r){
		if(os){	
			os<<"RUTA-MP"<<endl;
			os<<r.n<<endl;;
			for(int i=0;i<r.n;i++){
				os<<r.locs[i].longitud<<" "<<r.locs[i].latitud<<" "<<r.locs[i].altura<<endl;
			}
			return os;
		}
		else return false;
	}
};
Ruta operator+(const Ruta& r, const Localizacion& l){
	Ruta l2;
	delete [] l2.locs;
	l2.locs=new Localizacion [r.n+1];
	l2.n=r.n+1;
	for(int i=0;i<r.n;i++){
		l2.locs[i]=r.locs[i];
	}
	l2.locs[r.n]=l;
	return l2;
}	
Ruta operator+(const Localizacion& l, const Ruta& r){
	Ruta l2;
	delete [] l2.locs;
	l2.n=r.n+1;
	for(int i=0;i<r.n;i++){
		l2.locs[i+1]=r.locs[i];
	}
	l2.locs[0]=l;
	return l2;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

