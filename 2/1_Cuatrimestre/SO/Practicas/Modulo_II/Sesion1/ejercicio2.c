/*
Implementa un programa que realice la siguiente funcionalidad. El programa acepta como argumento el nombre de un archivo (pathname),
 lo abre y lo lee en bloques de tamaño 80 Bytes, y crea un nuevo archivo de salida, salida.txt, en el que debe aparecer la siguiente información:
	Bloque 1
	// Aquí van los primeros 80 Bytes del archivo pasado como argumento.
	Bloque 2
	// Aquí van los siguientes 80 Bytes del archivo pasado como argumento.
	...
	Guía Práctica de Sistemas Operativos-78
	Bloque n
	// Aquí van los siguientes 80 Bytes del archivo pasado como argumento.
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>  	
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
int tam=10;
char leyendo[];

int main(int argc, char *argv[]){
int archivo, salida;

if(argc!=2){
	printf("\nError, se necesita un archivo\n", errno);
	perror("\nError en open");
	exit(EXIT_FAILURE);
}

if( (archivo=open(argv[1],O_RDONLY))<0) {
	printf("\nError %d en open",errno);
	perror("\nError en open");
	exit(EXIT_FAILURE);
}
if( (salida=open("salida.txt", O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR))<0){
	printf("\nError %d en open", errno);
	perror("\nError en open");
	exit(EXIT_FAILURE);
}
if( lseek(salida,36, SEEK_SET)<0){
	perror("\nError en el seek");
	exit(-1);
} 
int cont=0, olala;
while((olala=read(archivo, leyendo, 80))>0){
	cont++;
	char escribir[tam];
	sprintf(escribir, "\nBloque %d\n", cont);
	if( write(salida, escribir, tam)==-1){
		perror("\nError en write");
		exit(-1);
	}
	if(write(salida, leyendo, olala)==-1){
		perror("\nError en write");
		exit(-1);
	}
	if(cont>=10 && cont<100) tam=11;
	else if(cont>=100) tam=12;
	
}

if( lseek(salida, 0, SEEK_SET)<0 ){
	perror("\nError en el seek");
	exit(-1);
}
int abc=cont+33;
char escribir[tam];
sprintf(escribir, "El numero de bloques total es %d", cont);
if(write(salida, escribir, abc)==-1){
	perror("\nError en el write");
	exit(-1);
}
close(archivo);
close(salida);

return EXIT_SUCCESS;
}
