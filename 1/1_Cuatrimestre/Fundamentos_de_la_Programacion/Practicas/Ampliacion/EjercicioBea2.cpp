#include <iostream>
#include <cmath>

using namespace std;

int main(){
	char n;
	double contadorletra=0, contadornumero=0, contadorespecial=0, fletra, fnum, fespecial, total=0, fmayor;
	
	do{
		cout<<"Introduzca una letra: ";
		cin>>n;
		
		if(('0'<=n && n<='9') || ('A'<=n && n<='Z') || ('a'<=n && n<='z')){
			if(('A'<=n && n<='Z') || ('a'<=n && n<='z')){
				contadorletra=contadorletra+1;
			}
			else{
				contadornumero=contadornumero+1;
			}
			total=total+1;
		}
		else{
			if(n!='!'){
				contadorespecial=contadorespecial+1;
				total=total+1;
			}
		}
		
	}while(n!='!');
	fletra=total/contadorletra;
	fnum=total/contadornumero;
	fespecial=total/contadorespecial;
	cout<<"La frecuencia de letras es: "<<fletra<<endl<<"La frecuencia de numeros es: "<<fnum<<endl<<"La frecuencia de caracteres especiales es: "<<fespecial<<endl;
	if(fletra>=fnum || fletra>=fespecial){
		cout<<"El caracter de moda son las letras."<<endl;
	}
	if(fnum>fletra || fnum>=fespecial){
		cout<<"El caracter de moda son los numeros."<<endl;
	}
	if(fespecial>fletra || fespecial>fnum){
		cout<<"El caracter de moda son los caracteres especiales"<<endl;
	}
	cout<<"letra-->"<<contadorletra<<endl<<"numero-->"<<contadornumero<<endl<<"especial--->"<<contadorespecial<<"total-->"<<total<<endl;
	system("pause");
}
	
