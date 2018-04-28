/*Este es un programa que a partir de dos datos de tipo double (real, otro_real). Primero al primer numero le suma 1
y al segundo numero le resta asi mismo el numero anterior. */
#include <iostream>
#include <cmath>

using namespace std;

int main (){
	long real, otro_real;
	real=2e34;
	otro_real=real+1;
	otro_real=otro_real-real;
	cout.precision(20);
	cout<<otro_real <<endl; 
	/*Es un problema de precision ya que al restarle a ese numero tan grande otro numero igual pero con un uno menos, el uno menos ese que tiene no es capaz
	de contarlo, y por eso el resultado da 0*/
	system("pause");
}
