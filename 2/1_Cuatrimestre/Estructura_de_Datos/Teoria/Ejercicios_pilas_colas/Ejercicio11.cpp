#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct nombres{
	string apellidos;
	string nombre;
	int prioridad;
	
	bool operator<(const nombres & b)const{
		return b.prioridad;
	}
	bool operator>(const nombres & b)const{
		return b.prioridad;
	}
};

int main(){
	priority_queue<nombres,vector<nombres>,less<nombres> >ce_m;
}
