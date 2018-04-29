#include <stdio.h>		
#include <stdlib.h>		
#include <sys/time.h>	

#define SIZE (1<<20)			
#define WSIZE 8*sizeof(int)		
#define COPY_PASTE 1

int lista[SIZE];
int resultado = 0;

int parity1(int* array){
	int i, j, numero, paridad = 0, contador = 0;

	for (i = 0; i < SIZE; i++){			
		numero = array[i];				

		for (j = 0; j < WSIZE; j++){	
			paridad ^= numero & 0x1;	
			numero >>= 1;			
		}

		contador += paridad;			
	}

	return contador;
}

int parity2(int* array){
	int i, numero, paridad = 0, contador = 0;

	for (i = 0; i < SIZE; i++){

		numero = array[i];		

		while (numero) {
			paridad ^= numero & 0x1;
			numero >>= 1;
		}

		contador += paridad;
	}

	return contador;
}

int parity3(int* array){
	int i, numero, paridad = 0, contador = 0;

	for (i = 0; i < SIZE; i++){

		numero = array[i];		

		asm("movl	%[n],%%eax		\n"		
"			testl	%%eax,%%eax		\n"		
"			je		fin				\n"		
"			movl	%[p],%%edx		\n"		
"bucle:								\n"
"			movl	%%eax, %%ecx	\n"		
"			andl	$1, %%ecx		\n"		
"			xorl	%%ecx, %%edx	\n"		
"			sarl	%%eax			\n"		
"			jne		bucle			\n"		
"			movl	%%edx, %[p]		\n"		
"fin:								\n"
		 :	[p] "+r"	(paridad)	
		 :	[n] "r"		(numero)	

		);

		contador += paridad;
	}

	return contador;
}

int parity4(int* array){
	asm("pushl	%ebx				\n" 
"		movl	8(%ebp), %edi		\n"		
"		movl	$0, %ebx			\n"		
"		movl	$0, %ecx			\n"		
"		movl	$1, %esi			\n"		
"condicion:							\n"
"		movl	(%edi,%esi,4), %edx	\n"		
"		testl	%edx, %edx			\n"
"		je		for					\n"
"while:								\n"
"		movl	%edx, %eax			\n"
"		andl	$1, %eax			\n"
"		xorl	%eax, %ecx			\n"
"		sarl	%edx				\n"
"		jne		while				\n"
"for:								\n"
"		addl	%ecx, %ebx			\n"		
"		addl	$1, %esi			\n"		
"		cmpl	$1048576, %esi		\n"		
"		jne		condicion			\n"		
"		movl	%ebx, %eax			\n"		
"		popl	%ebx				\n"		

    );
}

void crono(int (*func)(), char* msg){
    struct timeval tv1,tv2;			
    long tv_usecs;					

    gettimeofday(&tv1,NULL);
    resultado = func(lista);
    gettimeofday(&tv2,NULL);

    tv_usecs = (tv2.tv_sec -tv1.tv_sec )*1E6 + (tv2.tv_usec-tv1.tv_usec);
    


	#if COPY_PASTE
		printf("%ld \n", tv_usecs);
	#else
		printf("Tiempo: %d\t", resultado);
	#endif
}

int main(){
	int i, paridad1, paridad2, paridad3, paridad4;

	for (i=0; i<SIZE; i++)
		lista[i] = i;
	crono(parity1, "parity1 (for/for)");
	crono(parity2, "parity2 (for/while)");
	crono(parity3, "parity3 (for/asm)");
	crono(parity4, "parity4 (asm)");


    exit(0);
}
