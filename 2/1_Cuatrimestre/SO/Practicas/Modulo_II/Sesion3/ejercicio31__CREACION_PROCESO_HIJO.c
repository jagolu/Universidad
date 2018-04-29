/*
 Implementa un programa en C que tenga como argumento un número entero. Este
programa debe crear un proceso hijo que se encargará de comprobar si dicho número es un
número par o impar e informará al usuario con un mensaje que se enviará por la salida estándar.
A su vez, el proceso padre comprobará si dicho número es divisible por 4, e informará si lo es o
no usando igualmente la salida estándar. 
*/
#include<sys/types.h>	
#include<unistd.h>		 
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
	
	int num=strtol(argv[1],NULL,10);
	pid_t pid;

	if(argc!=2){
		printf("Se necesita un argumento\n");
		exit(-1);
	}

	if( (pid=fork()) <0){
		perror("Error al crear el proceso hijo\n");
		exit(-1);
	}

	if(pid==0){ //Se esta ejecutando el proceso hijo
		if( (num%2)==0){
			printf("%i es un numero par\n",num);
		}
		else{
			printf("%i es un numero impar\n", num);
		}
	}
	else{
		if( (num%4)==0){
			printf("%i es divisible entre 4\n",num);
		}
		else{
			printf("%i no es divisible entre 4\n", num);
		}
	}
}
