#include <iostream>

using namespace std;

int main(){
	const int max=20; /*Declaramos un vector con un maximo de 100 elementos*/
	int vector[max];
	int total=0, a; /*Declaramos el total de elementos y lo inicializamos en 0*/
	
	do{
		cout<<"Introduzca un numero positivo (terminador=0): ";
		cin>>a;
		if(a!=0 && a>0){ /*Con este if el vector solo cogera los elementos distintos de 0, ya que 0 no vale porque es el terminador*/
			vector[total]=a;
			total++;
			/*Al ir incrementando el total el numero introducido se mete en una posicion consecutiva a la anterior, y se queda 1 valor por encima*/
		}
	}while(a!=0); /*Pararemos de introducir datos cuando el usuario introduzca el 0*/
	for(int i=0;i<total;i++){ /*Mostramos el vector*/
		cout<<vector[i]<<"  "; /*Al ir incrementando la i, se mostraran las posiciones del vector desde 0 hasta total-1 (ya que total se queda un valor por encima*/
	}cout<<endl;
	cout<<"NUEVO VECTOR: \n"; /*\n indica el final de linea*/
	const int max1=100; /*Crearemos un vector auxiliar en el que guardaremos los elementos repetidos del vector original*/
	int vector1[max1];
	int total1=0; /*Tambien inicializaremos el total del vector auxiliar en 0 (por lo tanto se quedara un valor por encima tambien)*/
	vector1[0]=vector[0]; /*Meteremos el primer elemento del vector original en el vector original (Para poder tener algo con que comparar*/
	int c=0; /*Utilizaremos c como variable booleana inicializada en 0*/
	for(int i=1;i<total;i++){ /*Con este for iremos recorriendo totas las posiciones del vector original*/
		int b;
		b=vector[i]; /*Guardaremos la posicion i del vector en b*/
		for(int k=i+1;k<=total;k++){ /*Con este for recorreremos el vector original desde la posicion ultima donde comparamos en el for anterior(por eso k=i+1)*/
		/*Haremos que valla desde i, hasta llegar a total*/
			int d;
			d=vector[k]; /*Guardamos el vector en las posiciones siguientes de por donde se quedo en el for anterior*/
			if(d==b){ /*Si en algun momento b encuentra un igual c pasara a valer 1*/
				c=1; 
			}
		}
		if(c==1){ /*Cuando c valga uno, añadira el elemento que hemos encontrado que es igual y lo guardara en el vector auxiliar aumentando en 1 el total del vector auxiliar (esta vez no se quedara por encima el total)*/
			total1++;
			vector1[total1]=b;
		}
		c=0; /*Para cuando hayamos cambiado el valor de c a 1, con esto lo cambiaremos a 0, y volveremos a comparar con el siguiente elemento*/
	}
	int contador=0; /*Inicializamos un contador a 0 que sera el numero de cambios realizados*/
	for(int i=0;i<total;i++){  /*Con este for iremos recorriendo totas las posiciones del vector original*/
		int b, d;
		b=vector[i]; /*Guardaremos la posicion i del vector en b*/
		for(int k=0;k<=total1;k++){/*Con este for recorreremos el vector auxiliar desde la posicion inicial*/
		/*Haremos que valla desde i, hasta llegar a total*/
			d=vector1[k];/*Guardamos el vector en las posiciones siguientes de por donde se quedo en el for anterior*/
			if(b==d){/*Si en algun momento b encuentra un igual c pasara a valer 1*/
				c=1;
			}
		}
		if(c==1){ /*Cuando c valga 1, cambiaremos las iguales a -1*/
			vector[i]=-1;
			contador++; /*Aumentamos el contador en 1 porque se ha realizado un cambio*/
		}
		c=0; /*Para cuando hayamos cambiado el valor de c a 1, con esto lo cambiaremos a 0, y volveremos a comparar con el siguiente elemento*/
	}
	cout<<"\nCambios realizados: "<<contador<<endl;
	cout<<endl;
	for(int i=0;i<total;i++){ /*Mostramos el vector*/
		cout<<vector[i]<<"  ";
	}
	cout<<endl;
}
