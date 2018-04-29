#include <stdlib.h>
#include <stdio.h>

#ifdef _OPENMP
	#include <omp.h>
#else
	#define omp_get_thread_num() 0
	#define omp_get_num_threads() 1
#endif

int main(int argc, char ** argv){
	int i, j;
	double begin, end, t;

	if(argc<2){
		printf("Falta el tamaño de la matriz y el del vector\n");
		exit(-1);
	}

	unsigned int N=atoi(argv[1]);	
	double v1[N], v2[N], m[N][N];

	for(i=0;i<N;i++){	
		v1[i]=i;
		v2[i]=0;
		for(j=0;j<N;j++){
			m[i][j]=i+j;
		}
	}

	begin=omp_get_wtime();
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			v2[i]=m[i][j]*v1[j];
		}
	}
	
	end=omp_get_wtime();
	
	t=end-begin;
	
	printf("Tiempo: %11.9f\tTamaño:%u\tv2[0]=%8.6fv2[%d]=%8.6f\n", t, N, v2[0], N-1, v2[N-1]);

	if(N==8 || N==11){
		for(i=0;i<N;i++){
			printf("v2[%d]=%5.2f\n",i,v2[i]);
		}
	}
}




















