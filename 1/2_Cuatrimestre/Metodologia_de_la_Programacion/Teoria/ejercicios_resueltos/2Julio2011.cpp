#include <iostream>
using namespace std;
struct dato{
	float elem;
	int siguiente;
};
class Lista{
private:
	dato *elementos;
	int primero;
	int nelems;
public:
	Lista(const Lista& l){
		elementos=new dato[l.nelems];
		primero=l.primero;
		nelems=l.nelems;
		for(int i=0;i<nelems;i++){
			elementos[i]=l.elementos[i];
		}
	}
	Lista& operator=(const Lista& l){
		if(&l!=this){
			delete [] this->elementos;
			this->elementos=new dato[l.nelems];
			this->primero=l.primero;
			this->nelems=l.nelems;
			for(int i=0;i<this->nelems;i++){
				this->elementos[i]=l.elementos[i];
			}
		}
		return *this;
	}
	bool operator==(Lista& l){
		if(this->nelems==l.nelems){
			bool vamos=true;
			int pr1=this->primero;
			int pr2=l.primero;
			for(int i=0;i<this->nelems;i++){
				if(this->elementos[pr1].elem!=l.elementos[pr2].elem) vamos=false;
				pr1=this->elementos[pr1].siguiente;
				pr2=l.elementos[pr2].siguiente;
			}
			return vamos;
		}
		else return false;
	}
	bool Leer(std::istream& is,
};
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
