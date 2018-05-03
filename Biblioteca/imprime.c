#include<linalg.h>

void imprime(double **A, int diml, int dimc)
{	int i, j;
	
	for(i=0;i<diml;i++)
	{	for(j=0;j<dimc;j++)
			printf("%.4lf\t\t",A[i][j]);
	  
		puts("");
	}
	printf("\n------------------\n");	
}
