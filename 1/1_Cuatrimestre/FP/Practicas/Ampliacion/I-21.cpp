#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int x1, y1, x2, y2;
	double distancia;
	cout<<"Introduce la coordenada x del punto P1: ";
	cin>>x1;
	cout<<"Introduce la coordenada y del punto P1: ";
	cin>>y1;
	cout<<"Introduce la coordenada x del punto P2: ";
	cin>>x2;
	cout<<"Introduce la coordenada y del punto P2: ";
	cin>>y2;
	distancia=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	cout<<"La distancia euclidea entre P1 y P2 es: " <<distancia <<endl;
	system("pause");
}
