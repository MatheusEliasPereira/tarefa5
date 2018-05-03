#include<linalg.h>

double **copia(double **M, int diml, int dimc)
{	double **U;
	int i, j;
	
	U = (double**)malloc(diml*sizeof(double*));
	for(i=0;i<diml;i++)
		U[i] = (double*)malloc((dimc)*sizeof(double));
	
	for(i=0;i<diml;i++)
		for(j=0;j<dimc;j++)
			U[i][j] = M[i][j]; //copia matriz
	
	return U;
}
