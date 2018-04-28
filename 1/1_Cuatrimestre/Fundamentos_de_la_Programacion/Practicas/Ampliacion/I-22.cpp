#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int x, y, h;
	double a, b, c;
	cout<<"Introduce la variable x: " ;
	cin>>x;
	cout<<"Introduce la variable y: ";
	cin>>y;
	cout<<"Introduce la altura h: ";
	cin>>h;
	a=(1+(pow(x,2)/y))/(pow(x,3)/(1+y));
	b=(1+((1/3)*sin(h))-((1/7)*cos(h)))/(2*h);
	c=sqrt(1+(pow((exp(x)/pow(x,2)),2)));
	
	cout<<"a--> " <<a;
	cout<<"b--> " <<b;
	cout<<"c--> " <<c;
	system("pause");
}
