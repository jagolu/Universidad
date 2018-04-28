#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double capital, interes, total;
	
	cout<<"Introduzca el capital: ";
	cin>>capital;
	cout<<"Introduzca el interes: ";
	cin>>interes;
	
	total=capital+(capital*(interes/100));
	cout<<"Su total es: " <<total <<" euros" <<endl;
	system("pause");
}
