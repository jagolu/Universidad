#include <stdio.h>
#include <omp.h>

main(){
	int i, n=7;
	int a[n], suma=0;

	for(i=0;i<n;i++) a[i]=i;

	#pragma omp parallel for firstprivate(suma) lastprivate(suma)
	for(i=0;i<n;i++){
		suma=suma+a[i];
		printf("thread %d suma a[%d] suma=%d\n", omp_get_thread_num(), i, suma);
	}

	printf("\nFuera de la construccion parallel suma=%d\n", suma);
}