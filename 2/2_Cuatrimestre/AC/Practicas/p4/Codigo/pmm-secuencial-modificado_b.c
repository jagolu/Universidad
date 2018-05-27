#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 5000
int m1[max][max], m2[max][max], r[max][max], m2T[max][max];

int main(int argc, char ** argv){
	int n, i, j, k, total;
	double time;
	struct timespec ini, fin;	
	int r1, r2, r3, r4;
	if(argc<2){
		fprintf(stderr, "Falta tamaño\n");
		exit(-1);
	}
	
	n=atoi(argv[1]);
	if(n>max) n=max;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			r[i][j]=0;
			m1[i][j]=2;
			m2[i][j]=4;
		}
	}
	
	clock_gettime(CLOCK_REALTIME, &ini);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++) m2T[i][j]=m2[j][i];
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			r1=0; r2=0; r3=0; r4=0;
			for(k=0;k<n;k+=4){
				r1+=m1[i][k]*m2T[i][k];
				r2+=m1[i][k+1]*m2T[i][k+1];
				r3+=m1[i][k+2]*m2T[i][k+2];
				r4+=m1[i][k+3]*m2T[i][k+3];
			}
			r[i][j]=r1+r2+r3+r4;
		}
	}
	clock_gettime(CLOCK_REALTIME, &fin);
	
	time=(double)(fin.tv_sec - ini.tv_sec)+(double)((fin.tv_nsec-ini.tv_nsec)/1.e+9);
	printf("Tiempo= %11.9f\n\t(0,0)=%d\n\t(%d, %d)=%d\n", time, r[0][0], n-1, n-1, r[n-1][n-1]);
}
