/*
Implementa un programa que lance cinco procesos hijo. Cada uno de ellos se
identificará en la salida estándar, mostrando un mensaje del tipo Soy el hijo PID. El proceso
Guía Práctica de Sistemas Operativos-97
padre simplemente tendrá que esperar la finalización de todos sus hijos y cada vez que detecte
la finalización de uno de sus hijos escribirá en la salida estándar un mensaje del tipo:
Acaba de finalizar mi hijo con <PID>
Sólo me quedan <NUM_HIJOS> hijos vivos
*/
#include<sys/types.h>	
#include<unistd.h>		 
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

	int i, num_hijos=5, status;
	pid_t child[5], pid2;
	
	for(i=1;i<=num_hijos;i++){
		if((child[i] = fork())<0) {//almacensmos la pid en el vector para conocer el orden
		    perror("Error en fork\n");
		    exit(-1);
		}
		if(child[i]==0) {//mostramos la pid de los 5 hijos
		    printf("Soy el hijo %i\n", getpid());
		    exit(0);
		}
		sleep(1);
	}
	pid2=waitpid(child[1], &status);
	printf("Ha terminado mi hijo 1, PID: %i\n", child[1]);
	pid2=waitpid(child[3], &status);
	printf("Ha terminado mi hijo 3, PID: %i\n", child[3]);
	pid2=waitpid(child[5], &status);
	printf("Ha terminado mi hijo 5, PID: %i\n", child[5]);
	pid2=waitpid(child[2], &status);
	printf("Ha terminado mi hijo 2, PID: %i\n", child[2]);
	pid2=waitpid(child[4], &status);
	printf("Ha terminado mi hijo 4, PID: %i\n", child[4]);
	/*for(i=num_hijos-1;i>=0;i--){
		child=wait(&status);
		printf("Acaba de terminar mi hijo: %i con PID: %i\n", i+1, getpid());
		printf("Me quedan %i hijos\n ", i);
	}*/

}

	
