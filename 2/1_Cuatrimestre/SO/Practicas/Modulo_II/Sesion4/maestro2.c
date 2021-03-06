/* (C) Programmed by:
   Antonio Jimenez Martínez
   Andrés Ortiz Corrales
   Mariano Palomo Villafranca
Practica Sistemas Operativos: Modulo 2 - Sesion 4
Version:0.1
EJERCICIO 5
Este ejercicio se basa en la idea de utilizar varios procesos para realizar partes de una
computación en paralelo. Para ello, deberá construir un programa que siga el esquema de
computación maestro-esclavo, en el cual existen varios procesos trabajadores (esclavos)
idénticos y un único proceso que reparte trabajo y reúne resultados (maestro). Cada esclavo
es capaz de realizar una computación que le asigne el maestro y enviar a este último los
resultados para que sean mostrados en pantalla por el maestro.
El ejercicio concreto a programar consistirá en el cálculo de los números primos que hay en
un intervalo. Será necesario construir dos programas, maestro y esclavo, que darán lugar a
tres procesos, 1 maestro y 2 esclavos. Además se tendrá que tener en cuenta la siguiente
especificación:
	1. El intervalo de números naturales donde calcular los número primos se pasará como
argumento al programa maestro. El maestro creará dos procesos esclavos y dividirá
el intervalo en dos subintervalos de igual tamaño pasando cada subintervalo como
argumento a cada programa esclavo. Por ejemplo, si al maestro le proporcionamos el
intervalo entre 1000 y 2000, entonces un esclavo debe calcular y devolver los
números primos comprendidos en el subintervalo entre 1000 y 1500, y el otro esclavo
entre 1501 y 2000. El maestro irá recibiendo y mostrando en pantalla (también uno a
uno) los números primos calculados por los esclavos en orden creciente.
	2. El programa esclavo tiene como argumentos el extremo inferior y superior del
intervalo sobre el que buscará números primos. Para identificar un número primo
utiliza el siguiente método concreto: un número n es primo si no es divisible por
ningún k tal que 2 < k < sqrt(n), donde sqrt corresponde a la función de cálculo de la
raíz cuadrada (consulte dicha función en el manual). El esclavo envía al maestro cada
primo encontrado como un dato entero (4 bytes) que escribe en la salida estándar, la
cuál se tiene que encontrar redireccionada a un cauce sin nombre. Los dos cauces sin
nombre necesarios, cada uno para comunicar cada esclavo con el maestro, los creará
el maestro inicialmente. Una vez que un esclavo haya calculado y enviado (uno a uno)
al maestro todos los primos en su correspondiente intervalo terminará.
*/

#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<fcntl.h>


int main(int argc, char *argv[]) {

    int i, estado;
    pid_t pid;
    int min1=0,max1=0,min2=0,max2=0;
    int fd[2];
    char *n[4];
    char aux1[20];
    char aux2[20];
    char buffer[80];
    int final=0;
    if (argc==3) {//si los argumentos son correctos
        min1=strtol(argv[1],NULL,10);//min1 es el primer argumento
        max2=strtol(argv[2],NULL,10);//max2 es el segundo argumento
    }


    pipe(fd); // Llamada al sistema para crear un pipe


//se organizan los rangos
    max1=(max2+min1)/2;//calculamos max1
    min2=max1+1;//calculamos min2
    printf("Esclavo1 calcula el rango %d, %d .\n",min1,max1);
    sprintf(aux1,"%d",min1);
    sprintf(aux2,"%d",max1);
	
	//creamos la cadena de caracteres para llamar al subprograma
    n[0]="./esclavo";
    n[1]=aux1;
    n[2]=aux2;
    n[3]=NULL;//hay que dejar const  al final del vector.

//---------se lanza al primer hijo y calcula el primer rango--------------

    if ((pid = fork())<0) {//creamos un hijo
        perror("Error en fork\n");
        exit(-1);
    }
    if (pid==0) {//estamos en la ejecucion del hijo
        //Establecer la dirección del flujo de datos en el cauce cerrando
        // el descriptor de lectura de cauce en el proceso hijo
        close(fd[0]);

        //Redirigir la salida estándar para enviar datos al cauce
        //--------------------------------------------------------
        //Cerrar la salida estándar del proceso hijo
        close(STDOUT_FILENO);

        //Duplicar el descriptor de escritura en cauce en el descriptor
        //correspondiente a la salida estándar (stdout)
        dup(fd[1]);
        if ((execv("./esclavo",n))<0) {//ejecutamos el subprigrma primo con los argumentos almacenados en el vectro de caracteres n
            perror("\nError en el execv");
            exit(-1);
        }
        exit(0);
    }



    sleep(1);//hacemos sleep para que se puedan aprecias las ejecuciones de los esclavos

	// calcula el segundo rango--------------

    printf("Esclavo2 calcula el rango %d, %d .\n",min2,max2);
    sprintf(aux1,"%d",min2);
    sprintf(aux2,"%d",max2);
	//creamos la cadena de caracteres para llamar al subprograma
    n[0]="./esclavo";
    n[1]=aux1;
    n[2]=aux2;
    n[3]=NULL;//hay que dejar const  al final del vector.


	//---------se lanza al segundo hijo
    if ((pid = fork())<0) {//creamos el hijo
        perror("Error en fork\n");
        exit(-1);
    }
    if (pid==0) {//estmaos en la ejecucion del hijo
        //Establecer la dirección del flujo de datos en el cauce cerrando
        // el descriptor de lectura de cauce en el proceso hijo
        close(fd[0]);

        //Redirigir la salida estándar para enviar datos al cauce
        //--------------------------------------------------------
        //Cerrar la salida estándar del proceso hijo
        close(STDOUT_FILENO);

        //Duplicar el descriptor de escritura en cauce en el descriptor
        //correspondiente a la salida estándar (stdout)
        dup(fd[1]);
        if ((execv("./esclavo",n))<0) {//ejecutamos el subprigrma primo con los argumentos almacenados en el vectro de caracteres n
            perror("\nError en el execv");
            exit(-1);
        }
        exit(0);
    }


    sleep(1);
    //esperamos a que termine los hijos.
    pid=wait(&estado);
    pid=wait(&estado);


    // Estoy en el proceso padre porque PID != 0

    //Establecer la dirección del flujo de datos en el cauce cerrando
    // el descriptor de escritura en el cauce del proceso padre.
    close(fd[1]);

    //Redirigir la entrada estándar para tomar los datos del cauce.
    //Cerrar la entrada estándar del proceso padre
    close(STDIN_FILENO);

    //Duplicar el descriptor de lectura de cauce en el descriptor
    //correspondiente a la entrada estándar (stdin)
    dup(fd[0]);
    if ((final=read(fd[0],buffer,sizeof(buffer)))<0) {
        perror("\nError en el read");
        exit(-1);
    }
    else { //pasamos buffer a otra cadena ya que buffer tiene basura al final.
        char salida[final];
        for(i=0; i<=final; i++) {
            salida[i]=buffer[i];
        }
        printf("\nLos primos en el rango (%d, %d), son:\n%s",min1,max2,salida);//mostramso la salida.
	sleep(1);
    }

    return 0;
}
