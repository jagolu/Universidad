/*Este es un programa que a partir de dos datos de tipo double (real, otro_real). Multiplica ambos datos. */
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double real, otro_real;
	real=1e+300;
	otro_real=1e+200;
	otro_real=otro_real*real;
	cout<<otro_real <<endl ;
	/*Aqui hay un problema de precision porque no son capaces de coger un valor tan grande y no son capaces de coger el infinito*/
	system("pause");
}
