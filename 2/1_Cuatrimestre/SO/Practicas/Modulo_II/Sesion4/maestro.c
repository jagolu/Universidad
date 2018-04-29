#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
/*
El intervalo de números naturales donde calcular los número primos se pasará como
argumento al programa maestro. El maestro creará dos procesos esclavos y dividirá el
intervalo en dos subintervalos de igual tamaño pasando cada subintervalo como
argumento a cada programa esclavo. Por ejemplo, si al maestro le proporcionamos el
intervalo entre 1000 y 2000, entonces un esclavo debe calcular y devolver los números
primos comprendidos en el subintervalo entre 1000 y 1500, y el otro esclavo entre 1501
y 2000. El maestro creará dos cauces sin nombre y se encargará de su redirección para
comunicarse con los procesos esclavos. El maestro irá recibiendo y mostrando en
pantalla (también uno a uno) los números primos calculados por los esclavos en orden
creciente. 
*/
#include<errno.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc, char * argv[]){
	
	int i, estado;
	char buffer[100000];
	int min1, min2, max1, max2;
	pid_t pid;
	int fd[2];
	char * arguments[4];
	char num1[20];
	char num2[20];
	int bytes;
	
	if(argc!=3){
		printf("Se necesitan 2 argumentos");
		exit(-1);
	}

	min1=strtol(argv[1], NULL, 10);
	max2=strtol(argv[2], NULL, 10);
	max1=min1+((max2-min1)/2);
	min2=max2-((max2-min1)/2)+1;
	
		printf("min1: %i, max1: %i", min1, max1);
		printf("min1: %i, max1: %i", min2, max2);
	pipe(fd);
		
	if((pid=fork())<0){
		perror("Error en 1er fork\n");
		exit(-1);
	}

	if(pid==0){
		sprintf(num1,"%d",min1);
		sprintf(num2,"%d",max1);
		arguments[0]="./esclavo";
		arguments[1]=num1;
		arguments[2]=num2;
		arguments[3]=NULL;
		close(fd[0]);
		close(STDOUT_FILENO);
		
		dup(fd[1]);
		if(execv("./esclavo", arguments)<0){
			perror("Error al ejecutar esclavo");
			exit(-1);
		}
		exit(0);
	}
	
	sleep(1);
		
	if((pid=fork())<0){
		perror("Error en 2o fork\n");
		exit(-1);
	}
	
	if(pid==0){
		sprintf(num1,"%d",min2);
		sprintf(num2,"%d",max2);
		arguments[0]="./esclavo";
		arguments[1]=num1;
		arguments[2]=num2;
		arguments[3]=NULL;
		
		close(fd[0]);
		close(STDOUT_FILENO);
		
		dup(fd[1]);
		if(execv("./esclavo", arguments)<0){
			perror("Error al ejecutar esclavo");
			exit(-1);
		}
		exit(0);
	}

	sleep(1);
	
	pid=wait(&estado);
	pid=wait(&estado);

	close(fd[1]);
	close(STDIN_FILENO);

	dup(fd[0]);

	if((bytes=read(fd[0], buffer, sizeof(buffer)))<0){
		perror("Error en read\n");
		exit(-1);
	}
	else{
		/*char salida[bytes];
		for(i=0;i<bytes;i++){
			salida[i]=buffer[i];
		}*/
		printf("\nLos primos en el rango (%d, %d), son:\n%s",min1,max2,buffer);
	}
	return 0;


}

