/*
Realiza un programa en C utilizando las llamadas al sistema necesarias que acepte
como entrada:
• Un argumento que representa el 'pathname' de un directorio.
• Otro argumento que es un número octal de 4 dígitos (similar al que se puede utilizar
para cambiar los permisos en la llamada al sistema chmod). Para convertir este argumento
tipo cadena a un tipo numérico puedes utilizar la función strtol. Consulta el manual en
línea para conocer sus argumentos.
El programa tiene que usar el número octal indicado en el segundo argumento para cambiar los
permisos de todos los archivos que se encuentren en el directorio indicado en el primer
argumento.
El programa debe proporcionar en la salida estándar una línea para cada archivo del directorio
que esté formada por:
<nombre_de_archivo> : <permisos_antiguos> <permisos_nuevos>
Si no se pueden cambiar los permisos de un determinado archivo se debe especificar la siguiente
información en la línea de salida:
<nombre_de_archivo> : <errno> <permisos_antiguos>


*/


#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>  	
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<dirent.h>


int main(int argc, char *argv[]){
	DIR * directorio;
	struct stat ato;
	struct dirent * subDirectorio;

	if(argc!=3){
		printf("\nError, se necesita dos argumento\n", errno);
		perror("\nError en open");
		exit(EXIT_FAILURE);
	}

	if( (directorio=opendir(argv[1]))==NULL){
		printf("\nError al abrir el directorio\n" , errno);
		perror("\nError en opendir\n");
		exit(EXIT_FAILURE);
	}

	long int newAto=strtol(argv[2], NULL, 8);

	while( (subDirectorio=readdir(directorio))!=NULL){
		//strcmp compara :: aqui nos quitamos el directorio actual y el padre
		if((strcmp(subDirectorio->d_name,".")!=0) && (strcmp(subDirectorio->d_name,"..")!=0)){
			char subDir[100];
			sprintf(subDir, "./%s/%s", argv[1], subDirectorio->d_name);	
			if(stat(subDir, &ato)<0){
				printf("\nError al intentar acceder a los atributos de %s\n", subDir);
				perror("\nError en stat\n");
				exit(-1);
			}
			if(chmod(subDir, newAto)<0){
				printf("\nError al intentar cambiar los atributos\n");
				perror("\nError en chmod");
				exit(-1);
			}
			else{	
				printf("%s:\t%o\t%ld\n",subDir,ato.st_mode, newAto);
			}
		}
	}
	if(closedir(directorio)<0){
		printf("\nError al cerrar el directorio\n");
		exit(-1);
	}
}
