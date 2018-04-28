/*
Escribe un programa que suspenda la ejecución del proceso actual hasta que se
reciba la señal SIGUSR1. Consulta en el manual en línea sigemptyset para conocer las distintas
operaciones que permiten configurar el conjunto de señales de un proceso.
*/
#include<signal.h>

int main(){

	sigset_t new_mask;
	sigemptyset(&new_mask);
	sigfillset(&new_mask);
	sigdelset(&new_mask, SIGUSR1);
	sigsuspend(&new_mask);
}
