#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd,redireccion;
    char r0[]="<",r1[]=">";//las dos opciones de redireccion
    if (argc<4) {//controlamos los argumentos
        printf("Error falta de argumentos: ./a.out progrmama redireccion temporal\n");
    }

//comparamos el segundo argumento con las dos tipos de redirecciones.
    if (strcmp(argv[2],r0)==0) {//entrada-lectura
        redireccion=0;
        printf("redireccion es %d  IN\n",redireccion);

        if((fd=open(argv[3],O_RDONLY))<0) { //abrimos el archivo para lectura
            perror("\nError en open");
            exit(-1);
        }
    }
    if (strcmp(argv[2],r1)==0) {//salida-escritura
        redireccion=1;
        printf("redireccion es %d  OUT\n",redireccion);
        if((fd=open(argv[3],O_WRONLY))<0) {//abrimos el archivo para escritura
            perror("\nError en open");
            exit(-1);
        }
    }

    close(redireccion);// cerramos la redireccion elegida, ya que vamos a utilizar el archivo

	//hacemos la redireccion hacia el archivo.
	//al archivo fd con la orden de duplicar (F_DUPFD)
    if (fcntl(fd, F_DUPFD,redireccion)==-1) {
        perror("fcntl fallo");
        exit(-1);
    }

	//ejecutamos el subprograma dado por el argumento 1
    if(execlp(argv[1],argv[1],NULL)<0) {
        perror("\nError en el execv");
        exit(-1);
    }
    return(0);
}
