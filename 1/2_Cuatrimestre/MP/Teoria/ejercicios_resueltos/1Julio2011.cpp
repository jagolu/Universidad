#include <iostream>
using namespace std;
class VectorDinamico{
private:
	int NumMaxElems;
	int NumOcupados;
	int *v;
	bool redimensionar(int nuevotam){
		if(nuevotam>NumMaxElems){
			int *v2;
			v2=new int[nuevotam];
			for(int i=0;i<NumOcuppados;i++){
				v2[i]=v[i];
			}
			NumMaxElems=nuevotam;
			delete [] v;
			v=v2;
			return true;
		}
		else if(nuevotam<NumMaxElems{
			int *v2;
			v2=new int[nuevotam];
			for(int i=0;i<nuevotam;i++){
				v2[i]=v[i];
			}
			delete [] v;
			v=v2;
			NumMaxElems=nuevotam;
			NumOcupados=nuevotam;
			return false;
		}
	}			
};
	
