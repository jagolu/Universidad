#include <iostream>

using namespace std;
int capitalizacion(char una_letra){
	if('A'<=una_letra && una_letra<='Z'){
		return una_letra;
	}
	else{
		if('a'<=una_letra && una_letra<='z'){
			return una_letra;
		}
		else{
			return una_letra;
		}
	}
}
int main(){
	char a;
	int nuevaletra;
	
	cout<<"Introduzca una letra mayuscula: ";
	cin>>a;
	nuevaletra=capitalizacion(a);
	if('A'<=a && a<='Z'){
		cout<<"La letra "<<a<<" es mayuscula ( "<<nuevaletra<<" en ASCII)"<<endl;
	}
	else{
		if('a'<=a && a<='z'){
			cout<<"La letra "<<a<<" es minuscula ( "<<nuevaletra<<" en ASCII)"<<endl;
		}
		else{
			cout<<"No es una letra ( "<<nuevaletra<<" en ASCII)"<<endl;
		}
	}
	system("pause");
}
