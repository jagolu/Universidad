#include <iostream>

using namespace std;

class secuenciaCaracteres{
private:
	static const int max=100;
	char vector[max];
	int total;
public:
	secuenciaCaracteres()
		:total(0)
	{  }
	void aniade(char a){
		if(a!='#'){
			vector[total]=a;
			total++;
		}
	}
	void mostrar_vector(){
		for(int i=0;i<total;i++){
			cout<<vector[i]<<"  ";
		}
		cout<<endl;
	}
	void Es_Palindromo(){
		int c=0;
		for(int i=0;i<=(total/2);i++){
			char a, b;
			a=vector[i];
			b=vector[total-1-i];
			if(a!=b){
				c=1;
			}
		}
		if(c==0){
			cout<<"Es palindromo\n";
		}
		else{
			cout<<"No es palindromo\n";
		}
	}
	void modifica(int indice1, char a1){
		if(indice1<0 || total<=indice1){
			cout<<"Indice no valido\n";
		}
		else{
			cout<<"Indice valido, sustituyendo...\n";
			vector[indice1]=a1;
		}
		mostrar_vector();
	}
	void intercambia(int indice1, int indice2){
		if((indice1<0 || total<=indice1) || (indice2<0 || total<=indice2)){
			cout<<"Alguno de los indices no es valido\n";
		}
		else{
			cout<<"Indices validos, intercambiando...\n";
			char a, b;
			a=vector[indice1];
			b=vector[indice2];
			vector[indice1]=b;
			vector[indice2]=a;
		}
		mostrar_vector();
	}
	void invierte(){
		cout<<"\nInvirtiendo seuencia...\n";
		const int max1=100;
		char vector1[max1];
		for(int i=0;i<total;i++){
			int a;
			a=vector[total-1-i];
			vector1[i]=a;
		}
		for(int i=0;i<total;i++){
			int a;
			a=vector1[i];
			vector[i]=a;
		}
		mostrar_vector();
	}
	void elimina(int indice){
		if(indice<0 || total<=indice){
			cout<<"Indice no valido\n";
		}
		else{
			for(int i=indice;i<total;i++){
				char a, b;
				a=vector[i];
				b=vector[i+1];
				vector[i]=b;
				vector[i+1]=a;
			}
			total--;
		}
	}
	void elimina_mayus(){
		for(int i=0;i<total;i++){
			if('A'<=vector[i] && vector[i]<='Z'){
				elimina(i);
				i--;
				
			}
		}	
	}
	void elimina_mayus2(){
		int posicion_lectura, posicion_escritura=0;
		for(int i=0;i<total;i++){
			char a;
			posicion_lectura=i;
			a=vector[posicion_lectura];
			if('A'<=a && a<='Z'){
			}
			else{
				vector[posicion_escritura]=a;
				posicion_escritura++;
			}
		}
		total=posicion_escritura;
	}
	int muestra_total(){
		return total;
	}
	char muestra_indice(int indice){
		return vector[indice];
	}
	void eliminarepetidos2(){
		for(int i=0;i<total;i++){
			char a, b;
			a=vector[i];
			for(int j=i+1;j<total;j++){
				b=vector[j];
				if(a==b){
					elimina(j);
					j--;
				}
			}
		}
	}
	void eliminarepetidos3(){
		int posicion_escritura=0, posicion_lectura, c=0;
		for(int i=1;i<total;i++){
			char a, b;
			posicion_lectura=i;
			a=vector[posicion_lectura];
			for(int j=0;j<=posicion_escritura;j++){
				b=vector[j];
				if(a==b){
					c=1;
				}
			}
			if(c==0){
				posicion_escritura++;
				vector[posicion_escritura]=a;
			}
			c=0;
		}
		total=posicion_escritura+1;
	}
	void elimina_exceso(char aa){
		int c=0;
		for(int i=0;i<total;i++){
			if(aa==vector[i]){
				c=1;
			}
		}
		if(c==0){
			cout<<"EL caracter no esta en la secuencia\n";
		}
		else{
			for(int i=1;i<total;i++){
				char a, b;
				a=vector[i];
				b=vector[i-1];
				if(a==b){
					elimina(i);
					i--;
				}
			}
		}
		mostrar_vector();
	}
	void contadormayus(){
		const int max1=27;
		int vectormayus[max1];
		int total2=27;
		for(int i=0;i<total2;i++){
			vectormayus[i]=0;
		}
		for(int i=0;i<total;i++){
			char a;
			a=vector[i];
			if('A'<=a && a<='Z'){
				vectormayus[a-'A']=vectormayus[a-'A']+1;
			}
		}
		for(int i=0;i<total2;i++){
			int a;
			char b;
			a=vectormayus[i];
			if(a!=0){
				b=i+'A';
				cout<<b<<"---> "<<a<<endl;
			}
		}
	}
};
class vectornum{
private:
	static const int max1=100;
	int vector_num[max1];
	int total1;
public:
	vectornum()
		:total1(0)
	{  }
	void aniade(int a){
		if(a!=0){
			vector_num[total1]=a;
			total1++;
		}
	}
	void mostrar(){
		for(int i=0;i<total1;i++){
			cout<<vector_num[i]<<"  ";
		}
		cout<<endl;
	}
	void eliminaindice(int indice){
		if(indice<0 || total<=indice){
			cout<<"Indice no valido\n";
		}
		else{
			for(int i=indice;i<total;i++){
				char a, b;
				a=vector[i];
				b=vector[i+1];
				vector[i]=b;
				vector[i+1]=a;
			}
			total--;
		}
	}
	void escorrecta(){
		const int maximo=100;
		int vector_maximo[maximo];
		int a, b;
		b=vector_num[0];
		for(int i=0;i<total1;i++){
			a=vector_num[i]
			if(b>a){
				b=a;
			}
		}
		for(int i=0;
};

int main(){
	secuenciaCaracteres objeto;
	char a;
	int indice, indice1;
	do{
		cout<<"Introduzca un caracter: ";
		cin>>a;
		objeto.aniade(a);
	}while(a!='#');
	objeto.mostrar_vector();
	objeto.Es_Palindromo();
	cout<<"\nIntroduzca el indice del elemento a cambiar: ";
	cin>>indice;
	cout<<"Introduzca el caracater por el que desea cambiarlo: ";
	cin>>a;
	objeto.modifica(indice, a);
	cout<<"\nIntroduzca los dos indices de los elementos que desea intercambiar: ";
	cin>>indice;
	cin>>indice1;
	objeto.intercambia(indice, indice1);
	objeto.invierte();
	cout<<"\nIntroduzca el indice del elemento a eliminar: ";
	cin>>indice;
	objeto.elimina(indice);
	objeto.mostrar_vector();
	cout<<"Elija forma de eliminar las mayusculas (1/2): ";
	cin>>indice;
	if(indice==1){
		cout<<"Eliminando mayusculas (Forma 1)...\n";
		objeto.elimina_mayus();
		objeto.mostrar_vector();
	}
	else if(indice==2){
		cout<<"Eliminando mayusculas (forma 2)...\n";
		objeto.elimina_mayus2();
		objeto.mostrar_vector();
	}
	else{
		cout<<"Ningun metodo elegido\n";
	}
	cout<<"Introduzca la forma en la que desea eliminar los repetidos (1/2/3): ";
	cin>>indice;
	if(indice==1){
		const int max1=100;
		char vector_sin_repetidos[max1];
		int total1=0;
		int c=0;
		int total2=objeto.muestra_total();
		vector_sin_repetidos[0]=objeto.muestra_indice(0);
		for(int i=1;i<total2;i++){
			char a, b;
			a=objeto.muestra_indice(i);
			for(int j=0;j<=total1;j++){
				b=vector_sin_repetidos[j];
				if(a==b){
					c=1;
				}
			}
			if(c==0){
				total1++;
				vector_sin_repetidos[total1]=a;
			}
			c=0;
		}
		for(int i=0;i<=total1;i++){
			cout<<vector_sin_repetidos[i]<<"  ";
		}
		cout<<endl;
	}
	else{
		if(indice==2){
			objeto.eliminarepetidos2();
			objeto.mostrar_vector();
		}
		else if(indice==3){
			objeto.eliminarepetidos3();
			objeto.mostrar_vector();
		}
		else{
			cout<<"Eleccion no valida\n";
		}
	}
	cout<<"Caracter del que desea eliminar el exceso: ";
	cin>>a;
	objeto.elimina_exceso(a);
	cout<<"Contar mayusculas (1/2): ";
	cin>>indice;
	if(indice==1){
		cout<<"Contando mayusculas...\n";
		const int max1=100;
		int vector[max1];
		int total=27;
		for(int i=0;i<total;i++){
			vector[i]=0;
		}
		for(int i=0;i<objeto.muestra_total();i++){
			char a;
			a=objeto.muestra_indice(i);
			if('A'<=a && a<='Z'){
				vector[a-'A']=vector[a-'A']+1;
			}
		}
		for(int i=0;i<total;i++){
			int a;
			char b;
			a=vector[i];
			if(a!=0){
				b=i+'A';
				cout<<b<<"--> "<<a<<endl;
			}
		}
	}
	else if(indice==2){
		objeto.contadormayus();
	}
	else{
		cout<<"Metodo inexistente\n";
	}
	cout<<"\n\n\nCambiando a vector de numeros\n\n";
	vectornum objeto2;
	
	int n;
	do{
		cout<<"Introduzca un numero a la permutacion: ";
		cin>>n;
		objeto2.aniade(n);
	}while(n!=0);
	objeto2.mostrar();
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
