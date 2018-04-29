/*
El programa esclavo tiene como argumentos el extremo inferior y superior del intervalo
sobre el que buscará números primos. Para identificar un número primo utiliza el
siguiente método concreto: un número n es primo si no es divisible por ningún k tal que
2 < k <= sqrt(n), donde sqrt corresponde a la función de cálculo de la raíz cuadrada
(consulte dicha función en el manual). El esclavo envía al maestro cada primo
encontrado como un dato entero (4 bytes) que escribe en la salida estándar, la cuál se
tiene que encontrar redireccionada a un cauce sin nombre. Los dos cauces sin nombre
necesarios, cada uno para comunicar cada esclavo con el maestro, los creará el maestro
inicialmente. Una vez que un esclavo haya calculado y enviado (uno a uno) al maestro
todos los primos en su correspondiente intervalo terminará.
*/
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<math.h>

int esPrimo(int n){
	int primo=1, i;
	int limit=sqrt(n);
	for(i=2;i<=limit;i++){
		if( (n%i)==0) primo=0;
	}
	return primo;
}


int main(int argc, char * argv[]){
	if(argc!=3){
		printf("Faltan argumentos");
		exit(-1);
	}

	int min=strtol(argv[1],NULL,10);
	int max=strtol(argv[2],NULL,10);
	int i;	

	if(min>=max){
		printf("El primer numero debe ser menor que el segundo");
		exit(-1);
	}	
	for(i=min;i<=max;i++){
		if(esPrimo(i)==1) printf("Es primo %i\n", i);	
	}	
}
