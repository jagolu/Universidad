/*
Escribe un programa en C llamado contador, tal que cada vez que reciba una
señal que se pueda manejar, muestre por pantalla la señal y el número de veces que se ha
recibido ese tipo de señal, y un mensaje inicial indicando las señales que no puede manejar. En el
cuadro siguiente se muestra un ejemplo de ejecución del programa. 
*/
#include <stdio.h> 
#include <signal.h> 

static int j; 
static int contadores[31]; 
static void handler (int i){ 
	contadores[i]++; 
	printf("\n La señal %d , se ha realizado %d veces. " , i , 
	contadores[i]); 
} 

int main(){ 

struct sigaction sa; 
sa.sa_handler = handler; // ignora la señal 
sigemptyset(&sa.sa_mask); 
sa.sa_flags = SA_RESTART; 

int contadores[31]; 

for ( j = 1 ; j<=31 ; j++) contadores[j] = 0; 	
int i; 

for ( i = 1 ; i<=60 ; i++){ 
	if (sigaction(i, &sa, NULL) == -1) { 
		printf("error en el manejador");
	}
 }
while(1); 
}

