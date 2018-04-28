/*Este es un programa que multiplica dos valores muy grandes*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	float chico;
	double grande;
	grande=2e+150;
	chico=grande;
	cout<<chico <<endl ;
	/*Es desbordamiento porque a un float no le cabe un double tan grande*/
	system("pause");
}
