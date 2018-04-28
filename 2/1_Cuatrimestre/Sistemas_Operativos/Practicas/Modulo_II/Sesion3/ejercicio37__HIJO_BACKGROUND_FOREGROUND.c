/*
Escribe un programa que acepte como argumentos el nombre de un programa, sus
argumentos si los tiene, y opcionalmente la cadena “bg”. Nuesto programa deberá ejecutar el
programa pasado como primer argumento en foreground si no se especifica la cadena “bg” y en
background en caso contrario. Si el programa tiene argumentos hay que ejecutarlo con éstos.
*/
#include<sys/types.h>	
#include<sys/wait.h>	
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

	pid_t pid;
	int i, bg, n_args;
	char * direction;
	
	if(argc<2){
		printf("Se necesitan mas argumentos\n");
		exit(-1);
	}

	
	if(strcmp(argv[argc-1],"bg")==0){
		bg=1;
		n_args=argc-1;
	}
	else{
		bg=0;
		n_args=argc;
	}

	char * args2[n_args];
	direction=argv[1];

	if(argc>2){
		for(i=2;i<argc;i++){
			if(i==argc-1){
				if(strcmp(argv[argc-1],"bg")!=0) args2[i-2]=argv[i];	
			}
			else{
				args2[i-2]=argv[i];
			}	
		}
		args2[n_args-1]=(char *)NULL;
	}
	if(bg==1){
		if( (pid=fork())<0){
			perror("Error en fork");
			exit(-1);
		}
		else if(pid==0){
			if((execvp(direction,args2))<0) {
				perror("\nError en el execv");
				exit(-1);
			}
		}
	}
	else {
		if((execvp(direction,args2))<0) {
	    		perror("\nError en el execv");
	    		exit(-1);
		}	
	}
	exit(0);
}
