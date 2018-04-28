#include <iostream>

using namespace std ;

int main(){
	int uno, unoa, dos, dosa, tres, tresa, a;
	
	cout<<"Introduzca la cifra 1: ";
	cin>>uno;
	cout<<"Introduzca la cifra 2: ";
	cin>>dos;
	cout<<"Introduzca la cifra 3: ";
	cin>>tres;
	
	if(uno>dos && uno>tres){
		if(dos>tres){
			cout<<uno<<">"<<dos<<">"<<tres<<endl;
		}
		else if(tres>dos){
			cout<<uno<<">"<<tres<<">"<<dos<<endl;
		}
		else{
			cout<<uno<<">"<<dos<<"="<<tres<<endl;
		}
	}
	else if(dos>uno && dos>tres){
		if(uno>tres){
			cout<<dos<<">"<<uno<<">"<<tres<<endl;
		}
		else if(tres>uno){
			cout<<dos<<">"<<tres<<">"<<uno<<endl;
		}
		else{
			cout<<dos<<">"<<tres<<"="<<uno<<endl;
		}
	}
	else if(tres>uno && tres>dos){
		if(uno>dos){
			cout<<tres<<">"<<uno<<">"<<dos<<endl;
		}
		else if(dos>uno){
			cout<<tres<<">"<<dos<<">"<<uno<<endl;
		}
		else{
			cout<<tres<<">"<<dos<<"="<<uno<<endl;
		}
	}
	else{
		if(uno==dos && uno>tres){
			cout<<uno<<"="<<dos<<">"<<tres<<endl;
		}
		else if(uno==dos && uno<tres){
			cout<<tres<<">"<<dos<<"="<<uno<<endl;
		}
		else if(uno==tres && uno>dos){
			cout<<uno<<"="<<tres<<">"<<dos<<endl;
		}
		else if(uno==tres && uno<dos){
			cout<<dos<<">"<<uno<<"="<<tres<<endl;
		}
		else if(tres==dos && tres>uno){
			cout<<tres<<"="<<dos<<">"<<uno<<endl;
		}
		else if(tres==dos && tres<uno){
			cout<<uno<<">"<<tres<<"="<<dos<<endl;
		}
		else{
			cout<<uno<<"="<<dos<<"="<<tres<<endl;
		}
	}
	system("pause");
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
