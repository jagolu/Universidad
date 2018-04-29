#include <stdio.h>		
#include <stdlib.h>		
#include <sys/time.h>	

#define SIZE (1<<20)
#define WSIZE 8*sizeof(int)
#define COPY_PASTE 1

int lista[SIZE];
int resultado = 0;

int popcount1(int* array) {
	int i, j, numero, contador = 0;

	for (i = 0; i < SIZE; i++) {			

		numero = array[i];					
		
		for (j = 0; j < WSIZE; j++){		
			contador += numero & 0x1;		
			numero >>= 1;					
		}
	}

	return contador;
}

int popcount2(int* array) {
	int i, numero, contador = 0;

	for (i = 0; i < SIZE; i++) {

		numero = array[i];		
		
		while (numero) {
			contador += numero & 0x1;
			numero >>= 1;
		}
	}

	return contador;
}

int popcount3(int* array) {
	int i, numero, contador;

	for (i = 0; i < SIZE; i++) {

		numero = array[i];		
		
		asm("movl	%[n],%%eax		\n"		
"			testl	%%eax,%%eax		\n"		
"			je		fin				\n"		
"			movl	%[r],%%edx		\n"		
"bucle:								\n"
"			movl	%%eax, %%ecx	\n"		
"			andl	$1, %%ecx		\n"		
"			addl	%%ecx, %%edx	\n"		
"			sarl	%%eax			\n"		
"			jnc		bucle			\n"		
"			movl	%%edx, %[r]		\n"		
"fin:								\n"
		 :	[r] "+r"	(contador)	
		 :	[n] "r"		(numero)	
		);
	}

	return contador;
}

int popcount4(int* array) {
	int i, j, numero, contador = 0;

	for (i = 0; i < SIZE; i++) {

		numero = array[i];

		for (j = 0; j < 8; j++){
			contador += numero & 0x01010101;
			numero >>= 1;
		}
	}

	contador += (contador >> 16);
	contador += (contador >> 8);

	return contador & 0xFF;
}

int popcount5(unsigned* array){
	int i, res, count = 0;

	static const int SSE_mask[] __attribute__ ((aligned (16))) = {0x0f0f0f0f, 0x0f0f0f0f, 0x0f0f0f0f, 0x0f0f0f0f};
	static const int SSE_LUTb[] __attribute__ ((aligned (16))) = {0x02010100, 0x03020201, 0x03020201, 0x04030302};
			 													
	for (i=0; i<SIZE; i+=4){
		asm("movdqa		%[x], %%xmm0		\n"
"			 movdqa    	%%xmm0, %%xmm1		\n"
"			 psrlw		$4, %%xmm1			\n"
"			 pand      	%%xmm6, %%xmm0		\n"
"			 pand      	%%xmm6, %%xmm1		\n"
"			 movdqa    	%%xmm7, %%xmm2		\n"
"			 movdqa    	%%xmm7, %%xmm3		\n"
"			 pshufb    	%%xmm0, %%xmm2		\n"
"			 pshufb    	%%xmm1, %%xmm3		\n"
"			 paddb     	%%xmm2, %%xmm4		\n"
"			 paddb     	%%xmm3, %%xmm4		\n"
"			 pxor		%%xmm0, %%xmm0		\n"
"			 psadbw		%%xmm0, %%xmm4		\n"
"			 paddd		%%xmm4, %%xmm5		\n"
"			 movhlps   	%%xmm5, %%xmm0		\n"
"			 paddd     	%%xmm5, %%xmm0		\n"
"			 movd      	%%xmm0, %[res]		\n"
		:	 [res]	"=m"	(res)
		: 	 [x] 	"m" 	(array[i]),
			 [m] 	"m" 	(SSE_mask[0]),
			 [l] 	"m" 	(SSE_LUTb[0])
		);

		count += res;
		}

	return count;
}

void crono(int (*func)(), char* msg){
    struct timeval tv1,tv2;			
    long tv_usecs;					

    gettimeofday(&tv1,NULL);
    resultado = func(lista);
    gettimeofday(&tv2,NULL);

    tv_usecs = (tv2.tv_sec -tv1.tv_sec )*1E6 + (tv2.tv_usec-tv1.tv_usec);
    
    /*printf("Tiempo: %d\t", resultado);
    printf("%s:%9ld us\n", msg, tv_usecs);*/

	#if COPY_PASTE
		printf("%ld \n", tv_usecs);
	#else
		printf("Tiempo: %d\t", resultado);
	#endif
}

int main(){

	int i, sumabits1, sumabits2, sumabits3, sumabits4, sumabits5;

	for (i=0; i<SIZE; i++)
		lista[i] = i;
	crono(popcount1, "popcount1 (for/for)");
	crono(popcount2, "popcount1 (for/while)");
	crono(popcount3, "popcount1 (for/asm)");
	crono(popcount4, "popcount1 (libro)");
	crono(popcount5, "popcount1 (SSE3)");


    exit(0);
}
