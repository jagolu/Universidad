#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double gradosC, gradosF;
	cout<<"Introduce el numero de grados Celsius: ";
	cin>>gradosC;
	gradosF=(gradosC*180/100)+32;
	cout<<gradosF <<endl;
	
	system("pause");
}
