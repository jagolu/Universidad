/*
Programa una nueva orden que recorra la jerarquía de subdirectorios existentes a
partir de uno dado como argumento y devuelva la cuenta de todos aquellos archivos regulares
que tengan permiso de ejecución para el grupo y para otros. Además del nombre de los archivos
encontrados, deberá devolver sus números de inodo y la suma total de espacio ocupado por
dichos archivos. El formato de la nueva orden será:
$> ./buscar <pathname>
donde <pathname> especifica la ruta del directorio a partir del cual queremos que empiece a
analizar la estructura del árbol de subdirectorios. En caso de que no se le de argumento, tomará
como punto de partida el directorio actual. Ejemplo de la salida después de ejecutar el
programa:
Los i-nodos son:
./a.out 55
./bin/ej 123
./bin/ej2 87
...
Existen 24 archivos regulares con permiso x para grupo y otros
El tamaño total ocupado por dichos archivos es 2345674 bytes
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


int recorrerSubdirectoriosInodos(char * dirname){
	int in=0;
	struct dirent * subDirectorio;
	DIR * directorio;
	struct stat ato;
	if( (directorio=opendir(dirname))==NULL){
		printf("\nError al abrir el directorio %s\n" ,dirname, errno);
		perror("\nError en opendir\n");
		exit(EXIT_FAILURE);
	}
	while( (subDirectorio=readdir(directorio))!=NULL){
		if((strcmp(subDirectorio->d_name,".")!=0) && (strcmp(subDirectorio->d_name,"..")!=0)){
			char subDir[200];
			sprintf(subDir, "%s/%s", dirname, subDirectorio->d_name);
			if(stat(subDir, &ato)<0){
				printf("\nError al intentar acceder a los atributos de %s\n", subDir);
				perror("\nError en stat\n");
				exit(-1);
			}//miramos si es regular y si tiene permiso de ejecucion other y group
			if(S_ISREG(ato.st_mode) && (ato.st_mode & S_IXOTH) && (ato.st_mode & S_IXGRP) ){
				in=in+subDirectorio->d_ino;
				printf("%s: %ld inodos\n",subDir, subDirectorio->d_ino);
			}
			else if(ato.st_mode & S_IFDIR){
				in=in+recorrerSubdirectoriosInodos(subDir);
			}
		}
	}
	return in;
}


int main(int argc, char *argv[]){

	if(argc!=2){
		printf("\nError, se necesita dos argumento\n", errno);
		perror("\nError en open");
		exit(EXIT_FAILURE);
	}
	char dir[100];
	sprintf(dir, "./%s", argv[1]);
	printf("\nTotal de inodos: %i\n",recorrerSubdirectoriosInodos(dir));
}
	
