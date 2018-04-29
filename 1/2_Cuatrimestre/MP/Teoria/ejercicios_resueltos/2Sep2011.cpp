#include <iostream>
using namespace std;
class MatrizBS{
private:
	int *q;
	int dimensiones;
	int valor_defecto;
public:
	MatrizBS(){
		valor_defecto=0;
		dimensiones=4;
		q=new int[dimensiones];
		for(int i=0;i<dimensiones;i++){
			q[i]=1;
		}
	}
	~MatrizBS(){
		delete [] q;
	}
	MatrizBS(const int& d, const int v[], const int& vd, const int& opcional){
		valor_defecto=vd;
		dimensiones=d;
		q=new	int[dimensiones];
		for(int i=0;i<dimensiones;i++){
			q[i]=v[i];
		}
	}
	MatrizBS& operator=(MatrizBS& m){
		if(&m!=this){
			delete [] this->q;
			this->dimensiones=m.dimensiones;
			this->valor_defecto=m.valor_defecto;
			this->q=new int [this->dimensiones];
			for(int i=0;i<this->dimensiones;i++){
				this->q[i]=m.q[i];
			}
		}
		return *this;
	}
};
						
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
