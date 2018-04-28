#include <iostream>

using namespace std;

int main(){
	double n, suspensos=0, aptos=0, excelente=0, sumanumeros=0, notaalta=0, total=0, aprobados=0;
	double paprobados, psuspensos, promedio;
	
	
	do{
		cout<<"Introduzca una nota entre 0 y 10: ";
		cin>>n;
		if(0<=n && n<=10){
			if(0<=n && n<5){
				suspensos=suspensos+1;
				total=total+1;
				sumanumeros=sumanumeros+n;
			}
			else{
				if(5<=n && n<8){
					aptos=aptos+1;
				}
				else{
				excelente=excelente+1;
				}
				aprobados=aprobados+1;
				total=total+1;
				sumanumeros=sumanumeros+n;
				
			}
			if(notaalta<=n){
				notaalta=n;
			}
		}
		
		if(n>10){
			cout<<"Esa nota no es valida"<<endl;
		}
	}while(n>=0);
	
	paprobados=(aprobados*100)/total;
	psuspensos=(suspensos*100)/total;
	promedio=sumanumeros/total;
	
	cout<<"Hay "<<suspensos<<" suspensos"<<endl;
	cout<<"Hay "<<aptos<<" aptos"<<endl;
	cout<<"Hay "<<excelente<<" excelentes"<<endl;
	cout<<"El porcentaje de suspensos es "<<psuspensos<<"%"<<endl;
	cout<<"El porcentaje de aprobados es "<<paprobados<<"%"<<endl;
	cout<<"El promedio es: "<<promedio<<endl;
	cout<<"La nota mas alta es: "<<notaalta<<endl;
	system("pause");
}
